#include <iostream>
#include <cstring>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <typename T>
class Transformer {
public:
    virtual T operator()(const T& ch) const = 0;
    virtual ~Transformer() = default;
};

template <typename T>
class String {
private:
    T* data;
    size_t length;

    void allocateAndCopy(const T* source, size_t len) {
        data = new T[len + 1];
        std::copy(source, source + len, data);
        data[len] = T(); 
        length = len;
    }

public:
    // Default Constructor
    String() : data(nullptr), length(0) {}

    // Copy Constructor
    String(const String& other) {
        allocateAndCopy(other.data, other.length);
    }

    // Move Constructor
    String(String&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    // Constructor from C-style string
    String(const T* cstr) {
        size_t len = 0;
        while (cstr[len] != T()) ++len;
        allocateAndCopy(cstr, len);
    }

    // Constructor with repeated character
    String(T ch, size_t count) {
        data = new T[count + 1];
        std::fill(data, data + count, ch);
        data[count] = T();
        length = count;
    }

    // Constructor from iterators
    String(const T* begin, const T* end) {
        if (begin > end) throw std::invalid_argument("Begin cannot be after end");
        allocateAndCopy(begin, end - begin);
    }

    // Destructor
    ~String() { delete[] data; }

    // Copy Assignment
    String& operator=(const String& other) {
        if (this == &other) return *this;
        delete[] data;
        allocateAndCopy(other.data, other.length);
        return *this;
    }

    // Move Assignment
    String& operator=(String&& other) noexcept {
        if (this == &other) return *this;
        delete[] data;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
        return *this;
    }

    // Get Length
    size_t size() const { return length; }

    // Check if Empty
    bool empty() const { return length == 0; }

    // Clear the string
    void clear() {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    // Access operator []
    T& operator[](size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= length) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Substring
    String substring(size_t start, size_t len) const {
        if (start >= length) throw std::out_of_range("Start index out of range");
        size_t actualLength = std::min(len, length - start);
        return String(data + start, data + start + actualLength);
    }

    // Concatenation
    String operator+(const String& other) const {
        String result;
        result.data = new T[length + other.length + 1];
        std::copy(data, data + length, result.data);
        std::copy(other.data, other.data + other.length, result.data + length);
        result.length = length + other.length;
        result.data[result.length] = T();
        return result;
    }

    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    // Repeat String
    String operator*(size_t times) const {
        String result;
        result.data = new T[length * times + 1];
        for (size_t i = 0; i < times; ++i) {
            std::copy(data, data + length, result.data + i * length);
        }
        result.length = length * times;
        result.data[result.length] = T();
        return result;
    }

    // Comparison Operators
    bool operator==(const String& other) const {
        if (length != other.length) return false;
        return std::equal(data, data + length, other.data);
    }

    bool operator!=(const String& other) const { return !(*this == other); }

    bool operator<(const String& other) const {
        return std::lexicographical_compare(data, data + length, other.data, other.data + other.length);
    }

    bool operator>(const String& other) const { return other < *this; }

    bool operator<=(const String& other) const { return !(other < *this); }

    bool operator>=(const String& other) const { return !(*this < other); }

    // Apply Transformation (Dynamic Polymorphism)
    void apply(const Transformer<T>& transformer) {
        for (size_t i = 0; i < length; ++i) {
            data[i] = transformer(data[i]);
        }
    }

    // Apply Transformation (Static Polymorphism)
    template <typename Trans>
    void modify(const Trans& transformer) {
        for (size_t i = 0; i < length; ++i) {
            data[i] = transformer(data[i]);
        }
    }

    // Output for char specialization
    template <typename U = T>
    typename std::enable_if<std::is_same<U, char>::value, void>::type
    print() const {
        if (data) std::cout << data << std::endl;
    }
};

// Example Transformer Subclass
class ToUpper : public Transformer<char> {
public:
    char operator()(const char& ch) const override {
        return std::toupper(ch);
    }
};

int main() {
    try {
        // Examples
        String<char> str1("Hello");
        String<char> str2('!', 3);
        String<char> str3 = str1 + str2;

        str3.print();

        str3.apply(ToUpper());
        str3.print();

        String<char> repeated = str3 * 2;
        repeated.print();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
