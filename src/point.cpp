/**
 * @file point.cpp
 * @brief  Implementing the Point interface.
 */

#include "point.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::invalid_argument;
using std::out_of_range;
using std::pow;
using std::sqrt;

Point::Point()
{
    point[0] = 0;
    point[1] = 0;
    point[2] = 0;
}

Point::Point(double x = 0, double y = 0, double z = 0)
{
    point[0] = x;
    point[1] = y;
    point[2] = z;
}

void Point::setPoint(double x = 0, double y = 0, double z = 0)
{
    point[0] = x;
    point[1] = y;
    point[2] = z;
}

void Point::printPoint() const
{
    cout << point[0] << ' ' << point[1] << ' ' << point[2] << endl;
}

double Point::dist_between()
{
    return sqrt(pow(point[0], 2) + pow(point[1], 2) + pow(point[2], 2));
}

double Point::dist_between(Point &right)
{
    return sqrt(pow(point[0] - right.point[0], 2) +
                pow(point[1] - right.point[1], 2) +
                pow(point[2] - right.point[2], 2));
}

double Point::sum_coordinates() const
{
    double sum_c = 0;
    for (size_t i = 0; i < DIM; ++i)
        sum_c += point[i];
    return sum_c;
}

Point operator-(const Point &left, const Point &right)
{
    return Point(left.point[0] - right.point[0], left.point[1] - right.point[1], left.point[2] - right.point[2]);
}

double operator*(const Point &left, const Point &right)
{
    return left.point[0] * right.point[0] + left.point[1] * right.point[1] + left.point[2] * right.point[2];
}

Point operator*(const Point &left, const double right)
{
    return Point(left.point[0] * right, left.point[1] * right, left.point[2] * right);
}

Point operator/(const Point &left, const double right)
{
    return Point(left.point[0] / right, left.point[1] / right, left.point[2] / right);
}

double &Point::operator[](const int index)
{
    if (!(index >= 0 && index < DIM))
    {
        throw out_of_range("Index: from 0 to 2");
    }
    return point[index];
}