/**
 * @file compute.cpp
 * @brief  Implementing the Compute interface.
 */
#include "compute.h"
#include "read_data.h"
#include "consts.h"
#include <cmath>
#include <iostream>
#include <float.h>

Compute::Compute() {}

Compute::Compute(std::vector<Point> &line, Point &input_point)
{
    this->input_point = input_point;
    compute_projections(line);
}

Compute::Compute(std::string &namefile, Point &input_point)
{
    this->input_point = input_point;
    std::vector<Point> line;
    Read_Data file(namefile);
    file.read_to_line(line);
    file.close();
    compute_projections(line);
}

void Compute::set_line_and_input(std::vector<Point> &line, Point &input_point)
{
    this->input_point = input_point;
    compute_projections(line);
}

void Compute::set_file_and_input(std::string &namefile, Point &input_point)
{
    this->input_point = input_point;
    std::vector<Point> line;
    Read_Data file(namefile);
    file.read_to_line(line);
    file.close();
    compute_projections(line);
}

void Compute::display_projections()
{
    if (projections.size() > 0)
    {
        std::cout << "Projection(s):\n";
        for (size_t i = 0; i < projections.size(); ++i)
        {
            std::cout << "Segment " << segments[i];
            std::cout << " parameter " << parameters[i];
            std::cout << " point ";
            for (size_t j = 0; j < DIM; ++j)
            {
                std::cout << projections[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
}

void Compute::compute_projections(std::vector<Point> &line)
{
    size_t quant_points = line.size();
    Point direction_vector;
    double from_proj_to_point;
    double old_from_proj_to_point = DBL_MAX;
    for (size_t i = 0; i < quant_points - 1; ++i)
    {
        compute_one_projection(line[i], line[i + 1]);
        from_proj_to_point = input_point.dist_between(temp_projection);
        if (from_proj_to_point < old_from_proj_to_point)
        {
            projections.clear();
            segments.clear();
            parameters.clear();
            projections.push_back(temp_projection);
            segments.push_back(i + 1);
            parameters.push_back(current_parameter);
            old_from_proj_to_point = from_proj_to_point;
        }
        else if (std::abs(from_proj_to_point - old_from_proj_to_point) <= ACCUR)
        {
            projections.push_back(temp_projection);
            segments.push_back(i + 1);
            parameters.push_back(current_parameter);
        }
    }
}

void Compute::compute_one_projection(Point &begin, Point &end)
{
    double dist_beg_to_proj;
    Point vector_fr_beg_to_proj;
    Point direction_vector = end - begin;
    double vector_length = direction_vector.dist_between();
    Point cos = direction_vector / vector_length;
    double deviation = direction_vector * (begin - input_point) / vector_length;
    temp_projection = begin - cos * deviation;
    vector_fr_beg_to_proj = temp_projection - begin;
    dist_beg_to_proj = vector_fr_beg_to_proj.dist_between();
    // check parameter and direction
    current_parameter = dist_beg_to_proj / vector_length * (cos * vector_fr_beg_to_proj / dist_beg_to_proj);
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