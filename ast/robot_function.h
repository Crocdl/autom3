//
// Created by дмитрий on 24.08.2024.
//

#ifndef LAB3_ROBOT_FUNCTION_H
#define LAB3_ROBOT_FUNCTION_H
#include "ast.h"
#include "../robot/robot.h"
#endif //LAB3_ROBOT_FUNCTION_H
class RobotNode: public ASTNode{
public:
    std::shared_ptr<Robot> robot;
    std::shared_ptr<Map> map;
    RobotNode(std::shared_ptr<VariableContainer> &c, std::shared_ptr<Robot> r, std::shared_ptr<Map> m):
    ASTNode(c), robot(r), map(m){}

};
class MoveRobotNode: public RobotNode{
public:
    direction dir;
    MoveRobotNode(std::shared_ptr<VariableContainer> &c, std::shared_ptr<Robot> r, std::shared_ptr<Map> m, direction d): RobotNode(c, r, m), dir(d){}
    std::any execute() override{
        switch (dir) {
            case LEFT_:
                return robot->left();
            case UP_:
                return robot->up();
            case RIGHT_:
                return robot->right();
            case DOWN_:
                return robot->down();
        }
    }
};
class RotateRobotNode: public RobotNode{
public:
    bool side;
    RotateRobotNode(std::shared_ptr<VariableContainer> &c, std::shared_ptr<Robot> r, std::shared_ptr<Map> m, bool d): RobotNode(c, r, m), side(d){}
    std::any execute() override{
        return {};
    }
};