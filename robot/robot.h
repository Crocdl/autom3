//
// Created by дмитрий on 17.08.2024.
//

#ifndef LAB3_ROBOT_H
#define LAB3_ROBOT_H

#endif //LAB3_ROBOT_H

#include <vector>
#include "../map/map.h"
struct position{
    int x;
    int y;
};
class Robot{
private:
    std::shared_ptr<Map> map;
    u_int drill;
    std::string reflector;
    position curr_pos;
    direction view;
public:
    Robot(std::shared_ptr<Map> &map, int drill): map(map), drill(drill), reflector(), view(UP_){
        curr_pos.x = 0;
        curr_pos.y = 0;
    }
    u_int measure();
    bool left();
    bool right();
    bool up();
    bool down();
    bool left_rotate();
    bool right_rotate();
    void print();
};