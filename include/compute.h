/**
 * @file compute.h
 * @brief Compute class interface.
 */
#ifndef COMPUTE
#define COMPUTE
#include "point.h"
#include <vector>
/**
 * @brief Basic computing class.
 * 
 */
class Compute{
    public:
        /**
         * @brief Construct a new Compute object.
         * 
         */
        Compute(); 
        /**
         * @brief Construct a new Compute object. This constructor calls the method @ref compute_projections
         * 
         * @param line the input line (sequence of points).
         * @param input_point the input point that is projected onto the line.
         */

        Compute(std::vector<Point> &line, Point &input_point);
        /**
         * @brief Get the points and input object. After it, This method calls @ref compute_projections
         * @param line input line (sequence of points).
         * @param input_point he input point that is projected onto the line.
         */
        void get_points_and_input(std::vector<Point> &line, Point &input_point);
        /**
         * @brief displays found values
         * 
         */
        void display_projections();

    private:
        /**
         * @brief Compute all projections and save save in @ref projections
         * 
         * @param line the input line (sequence of points).
         */
        void compute_projections(std::vector<Point>& line); 
        
        /**
         * @brief Compute all projections and save save in @ref temp_projection
         * 
         * @param direction_vector 
         * @param begin start line.
         * @param end end line.
         */
        void compute_one_projection(Point &begin, Point &end);

        /**
         * @brief the input point that is projected onto the line.
         * 
         */
        Point input_point;

        /**
         * @brief temp projection (use in methods).
         * 
         */
        Point temp_projection;

        /**
         * @brief current parameter(use in methods).
         * 
         */
        double current_parameter; 

        /**
         * @brief found numbers of segmetns.
         * 
         */
        std::vector<unsigned int> segments; 

        /**
         * @brief found parameters.
         * 
         */
        std::vector<float> parameters; 

        /**
         * @brief found projections.
         * 
         */
        std::vector<Point> projections;
};
#endif