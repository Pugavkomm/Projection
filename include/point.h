#ifndef POINT
#define POINT
#define DIM 3 // 3D space
class Point{
    public:
        Point();
        Point(double x, double y, double z);
        void setPoint(double x, double y, double z);
        void printPoint() const; 
        friend Point operator-(const Point&, const Point &); 
        double &operator[] (const int);

        
        
    private:
        double point[DIM];
};
#endif