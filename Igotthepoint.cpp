#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(double x_value, double y_value)
    {
        x = x_value;
        y = y_value;
    }

    double operator-(Point other)
    {
        double x_diff = x - other.x;
        double y_diff = y - other.y;

        return sqrt((x_diff * x_diff) + (y_diff * y_diff));
    }

    bool operator==(Point other)
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(Point other)
    {
        return !(*this == other);
    }

    Point operator/(Point other)
    {
        double mid_x = (x + other.x) / 2;
        double mid_y = (y + other.y) / 2;

        return Point(mid_x, mid_y);
    }

    Point operator*(double number)
    {
        return Point(x * number, y * number);
    }

    double operator[](int index)
    {
        if (index == 0)
        {
            return x;
        }
        else if (index == 1)
        {
            return y;
        }
        else
        {
            cout << "Invalid index" << endl;
            return 0;
        }
    }

    Point& operator++()
    {
        x++;
        return *this;
    }

    Point operator++(int)
    {
        Point old_point = *this;
        y++;
        return old_point;
    }

    Point& operator--()
    {
        x--;
        return *this;
    }

    Point operator--(int)
    {
        Point old_point = *this;
        y--;
        return old_point;
    }

    friend ostream& operator<<(ostream& out, Point point);
    friend istream& operator>>(istream& in, Point& point);
};

ostream& operator<<(ostream& out, Point point)
{
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

istream& operator>>(istream& in, Point& point)
{
    char left_parenthesis;
    char comma;
    char right_parenthesis;

    in >> left_parenthesis >> point.x >> comma >> point.y >> right_parenthesis;

    return in;
}

int main()
{
    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);

    cout << "Point 1: " << p1 << endl;
    cout << "Point 2: " << p2 << endl;

    cout << "Distance: " << p1 - p2 << endl;
    cout << "Are they equal? " << (p1 == p2) << endl;
    cout << "Are they not equal? " << (p1 != p2) << endl;
    cout << "Midpoint: " << p1 / p2 << endl;

    cout << "Point multiplied by 2: " << p1 * 2 << endl;

    cout << "X coordinate using [0]: " << p1[0] << endl;
    cout << "Y coordinate using [1]: " << p1[1] << endl;

    ++p1;
    cout << "After ++p1: " << p1 << endl;

    p1++;
    cout << "After p1++: " << p1 << endl;

    --p1;
    cout << "After --p1: " << p1 << endl;

    p1--;
    cout << "After p1--: " << p1 << endl;

    Point user_point;

    cout << "Enter a point like (4, 7): ";
    cin >> user_point;

    cout << "You entered: " << user_point << endl;

    return 0;
}