#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>
#include <iomanip>

template <typename T>
class Matrix {
private:
    size_t rows, cols;
    std::vector<T> data;

    size_t index(int row, int col) const {
        row = (row < 0) ? rows + row : row;
        col = (col < 0) ? cols + col : col;
        if (row >= rows || col >= cols || row < 0 || col < 0)
            throw std::out_of_range("Index out of range");
        return row * cols + col;
    }

public:
    Matrix(size_t rows, size_t cols, const T& value = T())
    : rows(rows), cols(cols), data(rows * cols, value) {}


    T& at(int row, int col) {
        return data[index(row, col)];
    }

    const T& at(int row, int col) const {
        return data[index(row, col)];
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << std::setw(5) << at(i, j) << " ";
            }
            std::cout << "\n";
        }
    }

    template <typename U>
    Matrix<U> convert() const {
        Matrix<U> result(rows, cols);
        for (size_t i = 0; i < rows * cols; ++i) {
            result.at(i / cols, i % cols) = static_cast<U>(data[i]);
        }
        return result;
    }

    template <size_t NewRows, size_t NewCols>
    Matrix<T> resize(T defaultValue) const {
        Matrix<T> result(NewRows, NewCols, defaultValue);
        for (size_t i = 0; i < std::min(rows, NewRows); ++i) {
            for (size_t j = 0; j < std::min(cols, NewCols); ++j) {
                result.at(i, j) = this->at(i, j);
            }
        }
        return result;
    }

    template <int RowStart, int RowEnd, int ColStart, int ColEnd>
    Matrix<T> submatrix() const {
        int r1 = (RowStart < 0) ? rows + RowStart : RowStart;
        int r2 = (RowEnd < 0) ? rows + RowEnd : RowEnd;
        int c1 = (ColStart < 0) ? cols + ColStart : ColStart;
        int c2 = (ColEnd < 0) ? cols + ColEnd : ColEnd;

        if (r1 > r2 || c1 > c2 || r1 < 0 || r2 >= rows || c1 < 0 || c2 >= cols)
            throw std::out_of_range("Invalid submatrix range");

        Matrix<T> result(r2 - r1 + 1, c2 - c1 + 1);
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                result.at(i - r1, j - c1) = this->at(i, j);
            }
        }
        return result;
    }

    template <typename U>
    void put(const Matrix<U>& other, size_t rowStart, size_t colStart) {
        for (size_t i = 0; i < other.getRows(); ++i) {
            for (size_t j = 0; j < other.getCols(); ++j) {
                if (rowStart + i >= rows || colStart + j >= cols)
                    throw std::out_of_range("Insert out of range");
                this->at(rowStart + i, colStart + j) = static_cast<T>(other.at(i, j));
            }
        }
    }
};

int main() {
    Matrix<int> mat(4, 5, 0);
    int value = 1;
    for (size_t i = 0; i < mat.getRows(); ++i) {
        for (size_t j = 0; j < mat.getCols(); ++j) {
            mat.at(i, j) = value++;
        }
    }

    std::cout << "Original Matrix:" << std::endl;
    mat.print();

    auto sub = mat.submatrix<1, 2, 2, 4>();
    std::cout << "Submatrix (1,2 to 2,4):" << std::endl;
    sub.print();

    auto resized = mat.resize<6, 7>(-1);
    std::cout << "Resized Matrix (6x7):" << std::endl;
    resized.print();

    auto converted = mat.convert<double>();
    std::cout << "Converted Matrix (to double):" << std::endl;
    converted.print();

    Matrix<int> smallMat(2, 2, 20);
    smallMat.at(1, 1) = 23;
    mat.put(smallMat, 1, 2);
    std::cout << "Matrix after put operation:" << std::endl;
    mat.print();

    return 0;
}
