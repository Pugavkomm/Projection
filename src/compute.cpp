#include "compute.h"
#include "consts.h"
#include <cmath>
#include <iostream>
#include <float.h> 

Compute::Compute(){}

Compute::Compute(std::vector<Point> &line, Point &input_point){
    this->input_point = input_point;
    compute_projections(line); 
}

void Compute::get_points_and_input(std::vector<Point>& line, Point &input_point){
    this->input_point = input_point;
    compute_projections(line); 
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

void Compute::compute_projections(std::vector<Point> &line){
    size_t quant_points = line.size();
    Point direction_vector; 
    double from_proj_to_point; 
    double old_from_proj_to_point = DBL_MAX; 
    for (size_t i = 0; i < quant_points - 1; ++i){
        direction_vector = line[i + 1] - line[i];
        compute_one_projection(direction_vector, line[i]);
        check_position(line[i], line[i + 1]);
        from_proj_to_point = input_point.dist_between(temp_projection);
        if (from_proj_to_point < old_from_proj_to_point){
            projections.clear();
            segments.clear();
            parameters.clear();
            projections.push_back(temp_projection);
            segments.push_back(i + 1);
            parameters.push_back(current_parameter);
            old_from_proj_to_point = from_proj_to_point;
        } else if (std::abs(from_proj_to_point - old_from_proj_to_point) <= ACCUR){
            projections.push_back(temp_projection);
            segments.push_back(i + 1);
            parameters.push_back(current_parameter);
        }
    }
}   

void Compute::compute_one_projection(Point &direction_vector, Point &current_point){
    double deviation;
    double vector_lenght = direction_vector.dist_between();
    Point cos = direction_vector / vector_lenght; 
    deviation = direction_vector * (current_point - input_point) / vector_lenght;
    temp_projection = current_point - cos * deviation;

}

void Compute::check_position(Point &begin, Point &end){
    current_parameter = 1.0 - temp_projection.dist_between(end) / 
                        begin.dist_between(end);
    if (current_parameter < 0)
    {
        temp_projection = begin;
        current_parameter = 0;
    }
    else if (current_parameter > 1)
    {
        temp_projection = end;    
        current_parameter = 1;
    }
}