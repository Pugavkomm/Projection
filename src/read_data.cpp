/**
 * @file read_data.cpp
 * @brief  Implementing the Compute interface.
*/

#include <read_data.h>
#include <stdexcept>
#include "point.h"
#include "consts.h"
Read_Data::Read_Data(const std::string& namefile){
    file.open(namefile);
    if(!file.is_open()){
        throw std::invalid_argument("File not found!"); 
    }
}

void Read_Data::open(const std::string& namefile){
    if (file.is_open())
        file.close(); 
    file.open(namefile);
    if(!file.is_open()){
        throw std::invalid_argument("File not found!"); 
    }
}

void Read_Data::close(){
    if (file.is_open())
        file.close(); 
}

void Read_Data::read_to_line(std::vector<Point>& line){
    int i = 0;
    double read_point[DIM];
    Point temp; 
    if (!file.is_open())
        throw std::invalid_argument("File not opend");
    while(file >> read_point[i]){
        i++;
        if (i == DIM){
            i = 0; 
            temp.setPoint(read_point[0], read_point[1], read_point[2]);
            line.push_back(temp);
        }   
    }
    file.clear();
    file.seekg(0);
}