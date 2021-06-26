#include "compute.h"
#include "consts.h"
#include <cmath>
#include <iostream>
#include <float.h> 

Compute::Compute(){}

void Compute::get_points_and_input(std::vector<Point>& points, Point &input_point){
    compute_projections(points, input_point); 
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

void Compute::compute_projections(std::vector<Point> &points, Point &input_point){
    size_t quant_points = points.size();
    Point direction_vector; 
    Point temp_projection; 
    double from_proj_to_point; 
    double old_from_proj_to_point = DBL_MAX; 
    for (size_t i = 0; i < quant_points - 1; ++i){
        direction_vector = points[i + 1] - points[i];
        temp_projection = compute_one_projection(direction_vector, points[i], input_point);
        for (int j = 0; j < DIM; ++j){
            if (points[i][j] <  points[i + 1][j]){
                if (temp_projection[j] < points[i][j])
                    temp_projection[j] = points[i][j]; 
                else if (temp_projection[j] > points[i + 1][j])
                    temp_projection[j] = points[i + 1][j];
            } 
            else if (points[i][j] > points[i + 1][j]){
                if (temp_projection[j] > points[i][j])
                    temp_projection[j] = points[i][j]; 
                else if (temp_projection[j] < points[i + 1][j])
                    temp_projection[j] = points[i + 1][j];
            }
        }
        from_proj_to_point = input_point.dist_between(temp_projection);
        if (from_proj_to_point < old_from_proj_to_point){
            projections.clear();
            segments.clear();
            parameters.clear();
            projections.push_back(temp_projection);
            segments.push_back(i + 1);
            parameters.push_back(1);
            old_from_proj_to_point = from_proj_to_point;
        } else if (std::abs(from_proj_to_point - old_from_proj_to_point) <= ACCUR){
            projections.push_back(temp_projection);
            segments.push_back(i + 1);
            parameters.push_back(1);
        }
        
        
    
    }
}   

Point Compute::compute_one_projection(Point &direction_vector, Point &current_point, Point &input_point){
    double deviation;
    double vector_lenght = direction_vector.dist_between();

    Point cos = direction_vector / vector_lenght; 
    deviation = direction_vector * (current_point - input_point) / vector_lenght;
    return current_point - cos * deviation;

}
