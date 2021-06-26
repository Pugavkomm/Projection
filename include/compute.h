/**
 * @file compute.h
 * @brief Compute class interface
 */

#ifndef COMPUTE
#define COMPUTE
#include "point.h"
#include <vector>

class Compute{
    public:
        Compute();
        void get_points_and_input(std::vector<Point> &points, Point &input_point);
        void display_projections();
    private:
        Point cos(Point &direction_vector, double vector_length); 
        void compute_projections(std::vector<Point>& points, Point &input_point); 
        Point compute_one_projection(Point &direction_vector, Point &current_point, Point &input_point);
        
        std::vector<unsigned int> segments; 
        std::vector<float> parameters; 
        std::vector<Point> projections;
};
#endif