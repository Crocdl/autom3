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
    std::cout<<"Move left "<<curr_pos.x<<std::endl;
    if((curr_pos.x-1)>=0){
        std::cout<<"Wall: "<<map->cells[curr_pos.x-1][curr_pos.y].wall<<std::endl;
        if(map->cells[curr_pos.x-1][curr_pos.y].wall == " "){
            curr_pos.x-=1;
            print();
            return true;
        }else return false;
    }else return false;
}
bool Robot::up() {
    std::cout<<"Move down"<<std::endl;
    if((curr_pos.y-1)>=0){
        std::cout<<"Wall: "<<map->cells[curr_pos.x][curr_pos.y-1].wall<<std::endl;
        if(map->cells[curr_pos.x][curr_pos.y-1].wall == " "){
            curr_pos.y+=1;
            print();
            return true;
        }else return false;
    }else return false;
}
bool Robot::right(){
    std::cout<<"Move right"<<std::endl;
    if((curr_pos.x+1)<map->cells.size()){
        std::cout<<map->cells[curr_pos.x+1][curr_pos.y].wall<<std::endl;
        if(map->cells[curr_pos.x+1][curr_pos.y].wall == " "){
            curr_pos.x+=1;
            print();
            return true;
        }else return false;
    }else return false;
}
bool Robot::down() {
    std::cout<<"Move down"<<std::endl;
    if((curr_pos.y+1)<map->cells.size()){
        std::cout<<"Wall: "<<map->cells[curr_pos.x][curr_pos.y+1].wall<<std::endl;
        if(map->cells[curr_pos.x][curr_pos.y+1].wall == " "){
            curr_pos.y+=1;
            print();
            return true;
        }else return false;
    }else return false;
}
bool Robot::left_rotate() {
    view = static_cast<direction>((static_cast<int>(view)+1)%4);
    print();
    return true;
}
bool Robot::right_rotate() {
    view = static_cast<direction>((static_cast<int>(view)-1)%4);
    print();
    return true;
}
void Robot::print(){
    std::cout<<"Map print, position: "<<curr_pos.x<<" "<<curr_pos.y<<std::endl;
    auto m = map->cells;
    for(size_t i = 0; i<m.size();i++){
        std::cout<<std::endl;
        for(size_t j = 0; j<m[i].size(); j++){
            std::cout<<std::internal<<std::setw(8)<<"  |------------|   ";
        }
        std::cout<<std::endl;
        for(size_t j = 0; j<m[i].size(); j++){
            if(((size_t )curr_pos.x == j) && ((size_t)curr_pos.y == i)){
                switch (view) {
                    case UP_:
                        std::cout << "|    ^       |" ;
                        break;
                    case DOWN_:
                        std::cout << "|   \\/      |" ;
                        break;
                    case LEFT_:
                        std::cout << "|    <       |" ;
                        break;
                    case RIGHT_:
                        std::cout << "|    >       |" ;

                        break;
                }
            }else{
                std::string res= "|"+m[i][j].wall+"|";
                std::cout<<std::internal<<std::setw(14)<<res;
                std::cout<<std::setw(1)<<"     ";
            }
        }
        std::cout<<std::endl;
        for(size_t j = 0; j<m[i].size(); j++){
            std::cout<<"  |------------|   ";
        }
        std::cout<<std::endl;
        }
    }


