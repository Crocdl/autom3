//
// Created by дмитрий on 17.08.2024.
//
#include "robot.h"
#include<iomanip>
u_int Robot::measure() {
    auto mov_pos = curr_pos;
    int offset = 0;
    switch (view) {
        case LEFT_:
            while (map->cells[mov_pos.x][mov_pos.y].wall.compare("") && mov_pos.y>=0){
                mov_pos.y -= 1;
                offset++;
            }
            reflector = map->cells[mov_pos.x][mov_pos.y].wall;
            return offset;
            break;
        case UP_:
            while (map->cells[mov_pos.x][mov_pos.y].wall.compare(" ") && mov_pos.y>=0){
                mov_pos.x += 1;
                offset++;
            }
            reflector = map->cells[mov_pos.x][mov_pos.y].wall;
            return offset;
            break;
        case RIGHT_:
            while (map->cells[mov_pos.x][mov_pos.y].wall.compare(" ") && mov_pos.y>=0){
                mov_pos.y += 1;
                offset++;
            }
            reflector = map->cells[mov_pos.x][mov_pos.y].wall;
            return offset;
            break;
        case DOWN_:
            while (map->cells[mov_pos.x][mov_pos.y].wall.compare(" ") && mov_pos.y>=0){
                mov_pos.x -= 1;
                offset++;
            }
            reflector = map->cells[mov_pos.x][mov_pos.y].wall;
            return offset;
            break;
    }
}

bool Robot::left() {
    if((curr_pos.x+1)>=0){
        curr_pos.x-=1;
        return true;
    }else return false;
}
bool Robot::up() {
    if((curr_pos.y+1)<map->size.second){
        if(map->cells[curr_pos.x][curr_pos.y].wall == " "){
            curr_pos.y+=1;
            return true;
        }else return false;
    }else return false;
}
bool Robot::right(){
    if((curr_pos.y+1)<map->size.first){
        if(map->cells[curr_pos.x][curr_pos.y].wall == " "){
            curr_pos.y+=1;
            return true;
        }else return false;
    }else return false;
}
bool Robot::down() {
    if((curr_pos.y-1)>=0){
        if(map->cells[curr_pos.x][curr_pos.y].wall == " "){
            curr_pos.y+=1;
            return true;
        }else return false;
    }else return false;
}
bool Robot::left_rotate() {
    view = static_cast<direction>((static_cast<int>(view)-1)%4);
    return true;
}
bool Robot::right_rotate() {
    view = static_cast<direction>((static_cast<int>(view)+1)%4);
    return true;
}
void Robot::print(){
    std::cout<<"Map print"<<std::endl;
    auto m = map->cells;
    for(size_t i = 0; i<m.size();i++){
        std::cout<<std::endl;
        for(size_t j = 0; j<m[i].size(); j++){
            std::cout<<std::internal<<std::setw(8)<<"  |------------|   ";
        }
        std::cout<<std::endl;
        for(size_t j = 0; j<m[i].size(); j++){
            view = DOWN_;
            if((curr_pos.x == i) && (curr_pos.y == j)){
                switch (view) {
                    case UP_:
                        std::cout << "|      ^       |" ;
                        break;
                    case DOWN_:
                        std::cout << "|     \\/      |" ;
                        break;
                    case LEFT_:
                        std::cout << "|      <       |" ;
                        break;
                    case RIGHT_:
                        std::cout << "|      >       |" ;

                        break;
                }
            }else{
                std::cout<<std::internal<<std::setw(10)<<"|"<<m[i][j].wall<<std::setw(1)<<"|";
            }
        }
        std::cout<<std::endl;
        for(size_t j = 0; j<m[i].size(); j++){
            std::cout<<"  |------------|   ";
        }
        std::cout<<std::endl;
        }
    }


