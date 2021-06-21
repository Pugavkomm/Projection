#include "point.h"
#include <iostream>
using std::cout; 
using std::endl; 

Point::Point(){
    point[0] = 0; 
    point[1] = 0; 
    point[2] = 0;
}
Point::Point(double x = 0, double y = 0, double z = 0){
    point[0] = x; 
    point[1] = y; 
    point[2] = z;
}

void Point::setPoint(double x = 0, double y = 0, double z = 0){
    point[0] = x;
    point[1] = y;
    point[2] = z; 
}

void Point::printPoint() const {
    cout << point[0] << ' ' << point[1] << ' ' << point[2]  << endl;     
}

Point operator- (const Point& left, const Point &right){
    return Point(left.point[0] - right.point[0], left.point[1] - 
        right.point[1], left.point[2] - right.point[2]); 
}

double& Point::operator[] (const int index){
    return point[index];
}