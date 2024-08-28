//
// Created by дмитрий on 17.08.2024.
//

#ifndef LAB3_ROBOT_H
#define LAB3_ROBOT_H

#endif //LAB3_ROBOT_H

#include <vector>
#include "../map/map.h"
#include <map>
struct position{
    int x;
    int y;
};
class Robot{
private:
    std::shared_ptr<Map> map;
    position curr_pos;
    direction view;
    std::map<std::string , int> endurance;

public:
    u_int drill;
    std::string reflector;
    std::string refVar;
    Robot(std::shared_ptr<Map> &map, int drill): map(map), drill(drill), reflector(), view(UP_), refVar(" "){
        curr_pos.x = 0;
        curr_pos.y = 0;
        make_endurance();
    }
    void make_endurance();
    int getEndurance(std::string &n);
    int demolish();
    u_int measure();
    bool left();
    bool right();
    bool up();
    bool down();
    bool left_rotate();
    bool right_rotate();
    void print();
    bool move(direction d);
};