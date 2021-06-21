/**
 * @file point.h
 * @brief Point class interface
 */
#ifndef POINT
#define POINT
#define DIM 3 // 3D space
class Point{
    public:
        Point();
        Point(double x, double y, double z);
        void setPoint(double x, double y, double z);
        void printPoint() const; 
        double sum_coordinates() const; 
        friend Point operator- (const Point&, const Point&); 
        friend Point operator* (const Point&, const Point&);
        friend Point operator* (const Point&, const double);
        friend Point operator/ (const Point&, const Point&);
        friend Point operator/ (const Point&, const double);

        friend Point operator/ (const Point&, const double);
        double &operator[] (const int);
    private:
        double point[DIM];
};
#endif