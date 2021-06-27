/**
 * @file point.h
 * @brief Point class interface
 */
#ifndef POINT
#define POINT
#include "consts.h"
/**
     * @brief Point is point in 3D space (because constant DIM = 3)
     * 
     */
class Point
{

public:
    /**
         * @brief Default constructor that defines a point at the origin.
         */
    Point();

    /**
         * @brief The constructor defines point.
         * @param x, y, z are coordinates of input point.
         */
    Point(double x, double y, double z);

    /**
         * @brief The method sets the coordinates of the point.
         * @param x, y, z are coordinates of input.
         */
    void setPoint(double x, double y, double z);

    /**
         * @brief The method prints point.
         * @param left left operand.
         * @param right right operand.
         */
    void printPoint() const;

    /**
        * @brief Calculates the sum of the squares of the coordinates of a point
        * @returns the sum of the squares of the coordinates of a point
        */
    double dist_between();

    /**
         * @brief Computes the distance between two input points
         * @param right second point
         * @returns distance between this point and the second point
         */
    double dist_between(Point &right);

    /**
         * @brief Computes sum of coordinates point.
         * @returns sum of coordinates point.
         * 
         */
    double sum_coordinates() const;

    /**
         * @brief The operator calculates a point that is the difference between all coordinates of the other two points.
         * @param left left operand.
         * @param right right operand.
         */
    friend Point operator-(const Point &, const Point &);

    /**
         * @brief The operator calculates the dot product.
         * @param left left operand (Point).
         * @param right right operand (Point).
         * @returns dot product.
         */
    friend double operator*(const Point &, const Point &);

    /**
         * @brief The operator calculates the multiplication point by double.
         * @param left left operand (Point).
         * @param right right operand (double).
         */
    friend Point operator*(const Point &, const double);

    /**
         * @brief The operator сalculates left per double number
         * @param left left operand (Point).
         * @param right right operand (double).
         */
    friend Point operator/(const Point &, const double);

    /**
         * @brief Indexing operator. It returns the x, y, z coordinate depending on the index from the range [0, 2]. 
         * @param index: 0 -- x, 1 -- y, 2 -- z. 
         */
    double &operator[](const int);

private:
    /**
     * @brief point(x, y, z)
     * 
     */
    double point[DIM];
};
#endif