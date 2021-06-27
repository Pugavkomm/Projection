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
        Compute(std::vector<Point> &line, Point &input_point);
        void get_points_and_input(std::vector<Point> &line, Point &input_point);
        void display_projections();
    private:
        void compute_projections(std::vector<Point>& line); 
        void compute_one_projection(Point &direction_vector, Point &current_point);
        void check_position(Point &start_point, Point &end_point);
        Point input_point;
        Point temp_projection;
        double current_parameter; 
        std::vector<unsigned int> segments; 
        std::vector<float> parameters; 
        std::vector<Point> projections;
};
#endif