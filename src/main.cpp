/**
 * @file main.cpp
 * @author M.M. Pugavko (slavapugavko2@gmail.com)
 * @mainpage Projection of line
 * The program takes three arguments: name_file x y z
    name_file is file with line
    x, y and z  are coordinates of the point 
    The program prints output of the following form
    segment n parameter s point x y z
    n is number of segment of line
    s is a parameter that shows the part of the segment that the projection falls on. This parameter ranges from 0 to 1.
    The minimum distance to the line is defined as a perpendicular. If the perpendicular does not fall on the segment, then the nearest edge of the segment is selected
    Example: 
    
        ./main data.dat 1 1 1 
    
    Output: 

        Segment 2 parameter 0.75 point 1.75 0.75 0
        Segment 3 parameter 0.25 point 2.25 1 0.25
    
 * @brief main file
 * @version 1.1
 * @date 2021-06-21
 */
#include "point.h"
#include <iostream>
#include <vector> 
#include <fstream>
#include <string> 
#include <cmath>
#include <stdexcept>
#include <sstream> 
#include <float.h>
using std::invalid_argument; 
using std::abs; 
using std::sqrt; 
using std::cout;
using std::endl; 
using std::vector; 
using std::string; 
using std::ofstream; 
using std::ifstream; 
using std::stringstream; 
/**
 * @brief Distance measurement accuracy
 */
#define ACCUR 1e-7 // Distance Accuracy
/**
 * @brief Calculates the sum of the squares of the coordinates of a point
 * @param x, y, z -- Point coordinates
 * @returns the sum of the squares of the coordinates of a point
 */ 
#define DIST(x, y, z) sqrt(x * x + y * y + z * z) 
/**
 * @brief Computes the distance between two input points
 * @param (x1, x2, y1, y2, z1, z2) two input points.
 * @returns distance between two input point.
 */ 
#define DIST_BETWEEN(x1, x2, y1, y2, z1, z2) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) // The distance between two points 

void read_line(vector<Point>& points, string namefile);
void calculate_projections(vector<Point> &points, Point &input_point);
void projection_print(vector<Point>& all_projections, vector <Point>& points, 
                                                        vector<unsigned int>& segments);



int main(int argc, char* argv[]){
    if (argc < 5){
        throw invalid_argument("Error"); 
    }
    Point input_point; 
    double ax; 

    for (int i = 0; i < DIM; ++i){    
        stringstream convert(argv[i + 2]); 
        convert >> ax; 
        input_point[i] = ax; 
    }
    cout << "Point:\n"; 
    input_point.printPoint(); 
    vector<Point> points; 
    string namefile = argv[1]; 
    cout << "Start Read\n";
    read_line(points, namefile); 
    cout << "End Read\n";
    calculate_projections(points, input_point); 

    return 0; 
}


void read_line(vector<Point>& points, string namefile){
    /**
     * @brief Read a line from a file
     * @param points the vector of dots. The data from the file is written to this vector.
     * @param namefile the name input file. 
     */
    Point temp; 
    double read_point[DIM]; 
    ifstream file(namefile); 
    if(!file){
        throw invalid_argument("File not found!"); 
    } else{ 
        int i = 0; 
        while (file >> read_point[i]){
            i++; 
            if (i == DIM){
                i = 0; 
                temp.setPoint(read_point[0], read_point[1], read_point[2]);
                points.push_back(temp); 
                
            }
        }
    }
    file.close();
}


void projection_print(vector<Point>& all_projections, vector <Point>& points, 
                                                        vector<unsigned int>& segments){
    /**
     * @brief Prinnts all projections, parameters and segments.
     * @param all_projections all found projections.
     * @param points a line.
     * @param segments all found projections.
     */
    cout << "Projection:\n"; 
    for (size_t i = 0; i < all_projections.size(); ++i){
        cout << "Segment " << segments[i];
        cout << " parameter " << (1.0f - (DIST_BETWEEN(all_projections[i][0], points[segments[i]][0], 
                                all_projections[i][1], points[segments[i]][1],
                                all_projections[i][2], points[segments[i]][2]) / 
                                DIST_BETWEEN(points[segments[i] - 1][0], 
                                points[segments[i]][0], points[segments[i] - 1][1], 
                                points[segments[i]][1], points[segments[i] - 1][2], 
                                points[segments[i]][2])));
        cout  << " point " << all_projections[i][0] << ' ' << all_projections[i][1] << ' ' 
            << all_projections[i][2] << endl;
    }
}


void calculate_projections(vector<Point> &points, Point &input_point){ // TODO add const
    /**
     * @brief Computes all projections.
     * @param points a line.
     * @param input_point an input point. 
     */
    size_t quant_points = points.size();
    Point direction_vector; 
    Point temp_projection; 
    vector<Point> all_projections; 
    vector<unsigned int> segments; 
    vector<float> parameters; 
    Point cos; 
    double vector_length; 
    double P; 
    double from_proj_to_point; 
    double old_from_proj_to_point = DBL_MAX;
    vector<double> distances; 
    for (size_t i = 0; i < quant_points - 1; ++i){
        direction_vector = points[i + 1] - points[i]; 
        vector_length = DIST(direction_vector[0], direction_vector[1], direction_vector[2]); 
        P = 0; 
        P = (direction_vector * (points[i] - input_point)).sum_coordinates();
        P /= vector_length; 
        cos = direction_vector / vector_length; 
        temp_projection = points[i] - cos * P;
        // Offset by segment, if necessary
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
        from_proj_to_point = DIST_BETWEEN(input_point[0], temp_projection[0], 
                                          input_point[1], temp_projection[1],
                                          input_point[2], temp_projection[2]);
        if (from_proj_to_point < old_from_proj_to_point){
            all_projections.clear(); 
            segments.clear(); 
            parameters.clear();
            all_projections.push_back(temp_projection); 
            segments.push_back(i + 1);
            old_from_proj_to_point = from_proj_to_point;
        }
        else if (abs(from_proj_to_point - old_from_proj_to_point) <= ACCUR){
            all_projections.push_back(temp_projection); 
            segments.push_back(i + 1); 
        } 
    }
    projection_print(all_projections, points, segments); 
}
