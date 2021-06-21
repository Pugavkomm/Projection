/**
 * @file point.cpp
 * @brief  Implementing the Point interface.
 */

#include "point.h"
#include <stdexcept>
#include <iostream>
using std::invalid_argument;
using std::out_of_range; 
using std::cout; 
using std::endl; 

Point::Point(){
    /**
     * @brief Default constructor that defines a point at the origin.
     */
    point[0] = 0; 
    point[1] = 0; 
    point[2] = 0;
}
Point::Point(double x = 0, double y = 0, double z = 0){
    /**
     * @brief The constructor defines point.
     * @param x, y, z are coordinates of input point.
     */
    point[0] = x; 
    point[1] = y; 
    point[2] = z;
}

void Point::setPoint(double x = 0, double y = 0, double z = 0){
    /**
     * @brief The method sets the coordinates of the point.
     * @param x, y, z are coordinates of input.
     */
    point[0] = x;
    point[1] = y;
    point[2] = z; 
}

void Point::printPoint() const {
    /**
     * @brief The method prints point.
     * @param left left operand.
     * @param right right operand.
     */
    cout << point[0] << ' ' << point[1] << ' ' << point[2]  << endl;     
}

double Point::sum_coordinates() const{
    /**
     * @brief Computes sum of coordinates point.
     * @returns sum of coordinates point.
     * 
     */
    double sum_c = 0; 
    for (size_t i = 0; i < DIM; ++i)
        sum_c += point[i];
    return sum_c;
}

Point operator- (const Point& left, const Point &right){
    /**
     * @brief The operator calculates a point that is the difference between all coordinates of the other two points.
     * @param left left operand.
     * @param right right operand.
     */
    return Point(left.point[0] - right.point[0], left.point[1] - 
        right.point[1], left.point[2] - right.point[2]); 
}

Point operator* (const Point& left, const Point &right){
    /**
     * @brief The operator calculates the multiplication two points.
     * @param left left operand (Point).
     * @param right right operand (Point).
     */
    return Point(left.point[0] * right.point[0], left.point[1] * 
        right.point[1], left.point[2] * right.point[2]); 
    
}

Point operator* (const Point& left, const double right){
    /**
     * @brief The operator calculates the multiplication point by double.
     * @param left left operand (Point).
     * @param right right operand (double).
     */
    return Point(left.point[0] * right, left.point[1] * right, left.point[2] * right);
}

Point operator/ (const Point& left, const Point &right){
    /**
     * @brief The operator сalculates the division of the coordinates of points
     * @param left left operand (Point).
     * @param right right operand (Point).
     */
    return Point(left.point[0] / right.point[0], left.point[1] /
        right.point[1], left.point[2] / right.point[2]); 
    
}

Point operator/ (const Point& left, const double right){
    /**
     * @brief The operator сalculates left per double number
     * @param left left operand (Point).
     * @param right right operand (double).
     */
    return Point(left.point[0] / right, left.point[1] / right, left.point[2] / right);

}


double& Point::operator[] (const int index){
    /**
     * @brief Indexing operator. It returns the x, y, z coordinate depending on the index from the range [0, 2]. 
     * @param index: 0 -- x, 1 -- y, 2 -- z. 
     */
    if (!(index >= 0 && index < 3)){
        throw out_of_range("Index: from 0 to 2");
    }
    return point[index];
}