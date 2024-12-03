#include <iostream>
using namespace std;
#include <cmath>

class vector2d
{
private:
    float x, y;

public:
    vector2d() : x(0.0f), y(0.0f) // default
    {
        //...
    }
    vector2d(const vector2d &another) : // copying
                                        x(another.x),
                                        y(another.y)
    {
        //...
    }
    vector2d(float i, float j) : // initialization with a pair of real numbers
    x(i), y(j)
    {
        //...
    }

    vector2d operator+(const vector2d &another) const
    {
        return vector2d(x + another.x, y + another.y);
    }
    vector2d operator-(const vector2d &another) const
    {
        return vector2d(x - another.x, y - another.y);
    }

    vector2d operator*(float s) const
    {
        return vector2d(s * x, s * y);
    }
    vector2d operator/(float s) const
    {
        if (s == 0)
        {
            std::cerr << "Mistake: Divide into zero!\n";
            return vector2d(0, 0);
        }
        return vector2d(x / s, y / s);
    }

    float dotProduct(const vector2d &another) const
    {
        return x * another.x + y * another.y;
    }
    float crossProduct(const vector2d &another)
    {
        return x * another.y - y * another.x;
    }

    vector2d getOpposite() const
    {
        return vector2d(-x, -y);
    }

    vector2d &operator=(const vector2d &another)
    {
        if (this == &another)
        {
            return *this;
        }
        else
        {
            x = another.x;
            y = another.y;
        }
        return *this;
    }

    float length() const
    {
        return sqrt(pow((x), 2) + pow((y), 2));
        
    }
    void normalizechange()
    {
        float len = length();
        if (len != 0)
        {
            x /= len;
            y /= len;
        }
        else
            cerr << "Mistake, length=0" << "\n";
    }
    vector2d normalize() const
    {
        float len = length();
        if (len != 0)
        {
            return vector2d(x / len, y / len);
        }
        else
        {
            cerr << "Mistake, length=0" << "\n";
            return vector2d(0, 0);
        }
    }

    float getX() const
    {
        return x;
    }
    void setX(float value)
    {
        x = value;
    }
    float getY() const
    {
        return y;
    }
    void setY(float value)
    {
        y = value;
    }
    float operator[](int index) const
    {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
        else
        {
            cerr << "Mistake index" << "\n";
            return x;
        }
    }
    float &operator[](int index)
    {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
        else
        {
            cerr << "Mistake index" << "\n";
            return x;
        }
    }

    vector2d rotated(float angleInRadians) const
    {
        float X = x * cos(angleInRadians) - y * sin(angleInRadians);
        float Y = x * sin(angleInRadians) + y * cos(angleInRadians);
        return vector2d(X, Y);
    }

    float angleBetween(const vector2d &another) const
    {
        float dot = this->dotProduct(another);
        float len1 = this->length();
        float len2 = another.length();
        if (len1 == 0 || len2 == 0)
        {
            cerr << "Mistake, length=0" << "\n";
            return 0.0;
        }
        float cosTheta = dot / (len1 * len2);
        if (cosTheta > 1.0)
        {
            cosTheta = 1.0;
        }
        else if (cosTheta < -1.0)
        {
            cosTheta = -1.0;
        }
        return acos(cosTheta);
    }

    void out() const
    {
        cout << "x = " << x << " y = " << y << "\n";
    }

    friend std::ostream &operator<<(std::ostream &out, const vector2d &another)
    {
        out << "(" << another.x << ", " << another.y << ")";
        return out;
    }
    ~vector2d() // destructor
    {
        //
    }
};
int main()
{
    cout << "\nExercise 1" << "\n";
    // constructor 1
    vector2d constructor1another(3.5, 8.9);
    vector2d constructor1copy(constructor1another);
    cout << "Constructor 1\n";
    cout << "Constructor initialization\n";
    constructor1another.out();
    cout << "Constructor copy\n";
    constructor1copy.out();

    // constructor 2
    vector2d constructor2another(3, 4);
    vector2d constructor2copy(constructor2another);
    cout << "Constructor 2\n";
    cout << "Constructor initialization\n";
    constructor2another.out();
    cout << "Constructor copy\n";
    constructor2copy.out();

    cout << "\nExercise 2" << "\n";
    vector2d sum = constructor1another + constructor2another;
    cout << "Plus = " << sum.getX() << " " << sum.getY() << "\n";
    vector2d minus = constructor1another - constructor2another;
    cout << "Minus = " << minus.getX() << " " << minus.getY() << "\n";

    float dP = constructor1another.dotProduct(constructor2another);
    cout << "Skalyarniy dobutok = " << dP << "\n";
    float cP = fabs(constructor1another.crossProduct(constructor2another));
    cout << "Vectorniy dobutok = " << cP << "\n";

    cout << "\nExercise 3" << "\n";
    vector2d multiplication = constructor1another * 2.0;
    cout << "Multiplication = " << multiplication << "\n";
    vector2d dividing = constructor1another / 2.0;
    cout << "Dividing = " << dividing << "\n";

    cout << "\nExercise 4" << "\n";
    vector2d opposite = constructor1another.getOpposite();
    opposite.out();

    cout << "\nExercise 5" << "\n";
    cout << "Before assignment = ";
    constructor2another.out();
    constructor1another = constructor2another;
    cout << "After assignment = " << constructor1another.getX() << ", " << constructor1another.getY() << "\n";

    cout << "\nExercise 6" << "\n"; //////////////////////////////////?? 2 part of exercise
    vector2d newvect = constructor1another.normalize();
    cout << "Constructor1another" << newvect << " length = " << newvect.length() << "\n";

    constructor1another.normalizechange();
    cout << "Constructor1another by normalizechange" << constructor1another << " length = " << constructor1another.length() << "\n";

    cout << "\nExercise 7" << "\n";
    cout << "Length = " << constructor1another.length() << "\n";

    cout << "\nExercise 8" << "\n";
    cout << "Before getter and setter x = " << constructor1another.getX() << " y = " << constructor1another.getY() << "\n";
    constructor1another.setX(8.0);
    constructor1another.setY(2.0);
    cout << "After x = " << constructor1another.getX() << " y = " << constructor1another.getY() << "\n";

    cout << "Before [] x = " << constructor1another[0] << " y = " << constructor1another[1] << "\n";
    constructor1another[0] = (2.0);
    constructor1another[1] = (1.0);
    cout << "After x = " << constructor1another[0] << " y = " << constructor1another[1] << "\n";

    cout << "\nExercise 9" << "\n";
    vector2d rotatedV = constructor1another.rotated(M_PI / 4);
    cout << "After turn " << rotatedV << "\n";

    cout << "\nExercise 10" << "\n";
    float angle = constructor1another.angleBetween(constructor2another);
    cout << "Angle= " << angle * (180 / M_PI) << "\n";
    return 0;
}