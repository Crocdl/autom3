//
// Created by дмитрий on 17.08.2024.
//

#ifndef LAB3_MAP_H
#define LAB3_MAP_H

#endif //LAB3_MAP_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
// 1 - left, 2 - up, 3 - right, 4 - down
enum direction {LEFT_, UP_, RIGHT_, DOWN_};
class Cell{
public:
    std::string wall;
};
class Map{
public:
    std::vector<std::vector<Cell>> cells;
    std::pair<size_t , size_t> size;
    Map(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;

        while (std::getline(file, line)) {
            std::vector<Cell> row;
            std::stringstream ss(line);
            Cell cell;

            while (std::getline(ss, cell.wall, ',')) {
                row.push_back(cell);
            }

            cells.push_back(row);
        }
        for(auto i:cells){
            for(auto j:i)
                std::cout<<j.wall<<" ";
            std::cout<<std::endl;
        }

    }
};
