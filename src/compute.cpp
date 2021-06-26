
#include "point.h"
#include "compute.h"
#include <vector>
#include <cmath>
#include <iostream>

Compute::Compute(){};

void Compute::get_points_and_input(std::vector<Point>& points, Point &input_point){
    compute_projections(); 
}

void Compute::display_projections(){
    if (projections.size() > 0){
        std::cout << "Projection(s):\n";
        for (size_t i = 0; i < projections.size(); ++i){
            std::cout << "Segment " << segments[i];
            std::cout << " parameter " << parameters[i]; 
            std::cout << " point "; 
            for (size_t j = 0; j < DIM; ++j){
                std::cout << projections[i][j] << ' '; 
            }
            std::cout << std::endl; 
        }
    }
}

