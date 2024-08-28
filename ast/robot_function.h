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
        std::cout<<"robot move"<<dir<<std::endl;
        return robot->move(dir);
    }
};
class RotateRobotNode: public RobotNode{
public:
    bool side;
    RotateRobotNode(std::shared_ptr<VariableContainer> &c, std::shared_ptr<Robot> r, std::shared_ptr<Map> m, bool d): RobotNode(c, r, m), side(d){}
    std::any execute() override{
        if(side){
            return robot->right_rotate();
        }
        return robot->left_rotate();
    }
};
class RobotMeasureNode: public RobotNode{
public:
    RobotMeasureNode(std::shared_ptr<VariableContainer> &c, std::shared_ptr<Robot> r, std::shared_ptr<Map> m): RobotNode(c, r, m){}
    std::any execute() override{
        std::cout<<"Execute RobotMeasureNode "+robot->refVar<<std::endl;
        int res = robot->measure();
        if(robot->refVar!=" "){
            std::cout<<"Write in refVar "+robot->reflector<<std::endl;
            auto b = std::any(robot->reflector);
            variable->setValue(robot->refVar, b);
        }
        return res;
    }

};
class RobotBindNode: public RobotNode{
public:
    std::string bind_name;
    RobotBindNode(std::shared_ptr<VariableContainer> &c, std::shared_ptr<Robot> r, std::shared_ptr<Map> m, std::string &d): RobotNode(c, r, m), bind_name(d){}
    std::any execute() override{
        auto b = variable->find(bind_name);
        if(b->value.type() == typeid(std::string)){
            robot->refVar = bind_name;
        }
        return {};
    }
};
class DemolishRobotNode: public RobotNode{
public:
    DemolishRobotNode(std::shared_ptr<VariableContainer> &c, std::shared_ptr<Robot> r, std::shared_ptr<Map> m): RobotNode(c, r, m){}
    std::any execute() override{
        return robot->demolish();
    }

};