//
// Created by дмитрий on 17.08.2024.
//
#include "robot.h"
#include<iomanip>

void Robot::make_endurance() {
    endurance["wood"] = 50;
    endurance["iron"] = 100;
    endurance["glass"] = 10;
}
int Robot::getEndurance(std::string &n){
    std::vector<std::string> str;
    int c =0;
    if(n == " ") return 0;
    for(size_t i = 0; i<n.length();i++){
        if(n[i]=='|'){
            str.push_back(n.substr(c, i-c));
            c = i;
        }
    }
    str.push_back(n.substr(c, n.length() - c));
    int res = 0;
    for(auto &i: str){
        std::cout<<i<<" =matirial"<<std::endl;
        res+=endurance[i];
    }
    std::cout<<res<<" =end"<<std::endl;
    return (res/str.size());
}
int Robot::demolish() {
    auto mov_pos = curr_pos;
    std::string wall;
    int a;
    std::cout<<"Drill"<<std::endl;
    switch (view) {
        case RIGHT_:
            mov_pos.y -= 1;
            if (mov_pos.y>=0){
                a = getEndurance(map->cells[mov_pos.x][mov_pos.y].wall);
            }else{
                return 0;
            }
            if(a<drill){
                drill -= a;
                map->cells[mov_pos.x][mov_pos.y].wall = " ";
            }else{
                drill = 0;
            }
            right();
            return drill;
            break;
        case DOWN_:
            mov_pos.x += 1;
            if (mov_pos.x<map->cells.size()){
                a = getEndurance(map->cells[mov_pos.x][mov_pos.y].wall);
            }else{
                return 0;
            }
            if(a<drill){
                drill -= a;
                map->cells[mov_pos.x][mov_pos.y].wall = " ";
            }else{
                drill = 0;
            }
            down();
            return drill;
            break;
        case LEFT_:
            mov_pos.y += 1;
            if (mov_pos.y<map->cells.size()){
                a = getEndurance(map->cells[mov_pos.x][mov_pos.y].wall);
            }else{
                return 0;
            }
            std::cout<<a<<" "<<drill<<" "<<drill - a<<std::endl;
            if(a<drill){
                std::cout<<"Drilling "<<map->cells[mov_pos.x][mov_pos.y].wall<<"it"<<std::endl;
                drill -= a;
                map->cells[mov_pos.x][mov_pos.y].wall = " ";
            }else{
                drill = 0;
            }
            left();
            return drill;
            break;
        case UP_:
            mov_pos.x -= 1;
            if (mov_pos.x>=0){
                a = getEndurance(map->cells[mov_pos.x][mov_pos.y].wall);
            }else{
                return 0;
            }
            if(a<drill){
                drill -= a;
                map->cells[mov_pos.x][mov_pos.y].wall = " ";
            }else{
                drill = 0;
            }
            up();
            return drill;
            break;
    }
}
u_int Robot::measure() {
    auto mov_pos = curr_pos;
    int offset = 0;
    std::cout<<"Start measure"<<std::endl;
    switch (view) {
        case RIGHT_:
            while (mov_pos.y>=0){
                if(map->cells[mov_pos.x][mov_pos.y].wall!= " "){
                    reflector = map->cells[mov_pos.x][mov_pos.y].wall;
                    return offset;
                }
                mov_pos.y -= 1;
                offset++;
            }
            reflector = "_";
            return offset;
            break;
        case DOWN_:
            while (mov_pos.x<map->cells.size()){
                if(map->cells[mov_pos.x][mov_pos.y].wall!=" "){
                    reflector = map->cells[mov_pos.x][mov_pos.y].wall;
                    return offset;
                }
                mov_pos.x += 1;
                offset++;
            }
            reflector = "_";
            return offset;
            break;
        case LEFT_:
            while (mov_pos.y<map->cells.size()){
                if(map->cells[mov_pos.x][mov_pos.y].wall!=" " ){
                    reflector = map->cells[mov_pos.x][mov_pos.y].wall;
                    return offset;
                }
                mov_pos.y += 1;
                offset++;
            }
            reflector = "_";
            return offset;
            break;
        case UP_:
            while (mov_pos.x>=0){
                std::cout<<"Start measure "<<mov_pos.x<<" "<<mov_pos.y<<std::endl;
                if(map->cells[mov_pos.x][mov_pos.y].wall!=" "){
                    reflector = map->cells[mov_pos.x][mov_pos.y].wall;
                    return offset;
                }
                mov_pos.x -= 1;
                offset++;
            }
            reflector = "_";
            return offset;
            break;
    }
}

bool Robot::up() {
    std::cout<<"Move up "<<curr_pos.x<<std::endl;
    if((curr_pos.x-1)>=0){
        std::cout<<"Wall: "<<map->cells[curr_pos.x-1][curr_pos.y].wall<<std::endl;
        if(map->cells[curr_pos.x-1][curr_pos.y].wall == " "){
            curr_pos.x-=1;
            print();
            return true;
        }else return false;
    }else return false;
}
bool Robot::right() {
    std::cout<<"Move right"<<std::endl;
    if((curr_pos.y-1)>=0){
        std::cout<<"Wall: "<<map->cells[curr_pos.x][curr_pos.y-1].wall<<std::endl;
        if(map->cells[curr_pos.x][curr_pos.y-1].wall == " "){
            curr_pos.y-=1;
            print();
            return true;
        }else return false;
    }else return false;
}
bool Robot::down(){
    std::cout<<"Move down"<<std::endl;
    if((curr_pos.x+1)<map->cells.size()){
        std::cout<<map->cells[curr_pos.x+1][curr_pos.y].wall<<std::endl;
        if(map->cells[curr_pos.x+1][curr_pos.y].wall == " "){
            curr_pos.x+=1;
            print();
            return true;
        }else return false;
    }else return false;
}
bool Robot::left() {
    std::cout<<"Move left"<<std::endl;
    if((curr_pos.y+1)<map->cells.size()){
        std::cout<<"Wall: "<<map->cells[curr_pos.x][curr_pos.y+1].wall<<"Pos: "<<curr_pos.x<<" "<<curr_pos.y+1<<std::endl;
        if(map->cells[curr_pos.x][curr_pos.y+1].wall == " "){
            curr_pos.y+=1;
            print();
            return true;
        }else return false;
    }else return false;
}
bool Robot::left_rotate() {
    std::cout<<static_cast<int>(view)<<" L view dir: "<<((static_cast<int>(view)+1)%4)<<std::endl;
    view = static_cast<direction>((static_cast<int>(view)+1)%4);
    print();
    return true;
}
bool Robot::right_rotate() {
    std::cout<<static_cast<int>(view)<<" R view dir: "<<(abs((static_cast<int>(view)+3)%4))<<std::endl;
    view = static_cast<direction>(abs((static_cast<int>(view)+3)%4));
    print();
    return true;
}
bool Robot::move(direction d) {
    bool c;
    switch (view) {
        case LEFT_:
            switch (d) {
                case LEFT_:
                    return down();
                    break;
                case UP_:
                    return left();
                    break;
                case RIGHT_:
                    return up();
                    break;
                case DOWN_:
                    return right();
                    break;
            }
            break;
        case UP_:
            switch (d) {
                case LEFT_:
                    std::cout<<"11111"<<std::endl;
                    return left();
                    break;
                case UP_:
                    return up();
                    break;
                case RIGHT_:
                    return right();
                    break;
                case DOWN_:
                    return down();
                    break;
            }
            break;
        case RIGHT_:
            switch (d) {
                case LEFT_:
                    return up();
                    break;
                case UP_:
                    return right();
                    break;
                case RIGHT_:
                    return down();
                    break;
                case DOWN_:
                    return left();
                    break;
            }
            break;
        case DOWN_:
            switch (d) {
                case LEFT_:
                    return right();
                    break;
                case UP_:
                    return down();
                    break;
                case RIGHT_:
                    return left();
                    break;
                case DOWN_:
                    return up();
                    break;
            }
            break;
    }
}
void Robot::print(){
    std::cout<<"Map print, position: "<<curr_pos.x<<" "<<curr_pos.y<<std::endl;
    auto m = map->cells;
    for(size_t i = 0; i<m.size();i++){
        std::cout<<std::endl;
        for(int j =  m[i].size()-1; j>-1; j--){
            std::cout<<std::internal<<std::setw(8)<<"  |------------|   ";
        }
        std::cout<<std::endl;
        for(int j = m[i].size()-1; j>=0; j--){
            if(((size_t )curr_pos.x == i) && ((size_t)curr_pos.y == j)){
                switch (view) {
                    case UP_:
                        std::cout<<"U";
                        std::cout << "|    ^       |" ;
                        break;
                    case DOWN_:
                        std::cout<<"D";
                        std::cout << "|   \\/      |" ;
                        break;
                    case LEFT_:
                        std::cout<<"L";
                        std::cout << "|    <       |" ;
                        break;
                    case RIGHT_:
                        std::cout<<"R";
                        std::cout << "|    >       |" ;
                        break;
                    default:
                        std::cout<<"What is going!"<<std::endl;
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


