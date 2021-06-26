/**
 * @file compute.h
 * @brief Compute class interface
 */
#ifndef COMPUTE
#define COMPUTE
class Compute{
    public:
        Compute();
        void get_points_and_input(std::vector<Point> &points, Point &input_point);
        void display_projections();
    private:
        Point cos(Point &direction_vector, double vector_length); 
        //double deviation()
        Point compute_projections(); 

        std::vector<unsigned int> segments; 
        std::vector<float> parameters; 
        std::vector<Point> projections;
        

};
#endif