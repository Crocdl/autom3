//
// Created by дмитрий on 17.08.2024.
//

#pragma once
#include <stack>
#include <iostream>
#include <vector>
#include <any>
#include <unordered_map>
#include <set>
enum Operation {MIN, PLUS};
enum LogicalOperators{QL, NQL, LSS, GRT};
inline LogicalOperators StrLog(std::string &in){
    if (in == "!="){return NQL;}
    if (in == ">"){return GRT;}
    if (in == "<"){return LSS;}
    return QL;
}
enum Type{INT_, STR_, BOOL_};
struct Variable{
    std::any value;
    bool isArray;
    Variable(std::any &val, bool ar): value(val), isArray(ar){}
};
LogicalOperators StrLog(std::string &in);
struct IContainerContext {
    virtual void Up() = 0;
    virtual void Down() = 0;
    virtual void push(const std::string& name,  Variable & value) = 0;
//    virtual Variable& getVariable(const std::string& name) = 0;
//    virtual void addFunction(const std::string& name, const ArgList& args) = 0;
//    virtual const Function& getFunction(const std::string& name) const = 0;
    virtual ~IContainerContext() = default;
};

class ASTNode;
class VariableContainer: public IContainerContext{
    std::vector<std::unordered_map<std::string, std::shared_ptr<Variable>>> variable;
    std::vector<std::unordered_map<std::string, std::shared_ptr<ASTNode>>> function;
public:
    void push (const std::string& name,  Variable &value) override {if(variable[variable.size()-1].emplace(name, std::make_shared<Variable>(value)).second) { }else{throw std::runtime_error("Variable already exist");}}
    void push(const std::string& name,  std::any &val, bool ar) {if(variable[variable.size()-1].emplace(name, std::make_shared<Variable>(val, ar)).second) { }else{throw std::runtime_error("Variable already exist");}}
    void Fpush(const std::string& name, std::shared_ptr<ASTNode> &a){if(function[function.size()-1].emplace(name, a).second){std::cout<<"Function "<<name<<" was added!"<<std::endl;}else{throw std::runtime_error("Function already exist");}}
    void Up() override{variable.resize(variable.size()+1);function.resize(function.size()+1);}
    void Down() override{variable.resize(variable.size()-1);function.resize(function.size()-1);}
    void print() {
        std::cout << "Variable value: " << std::endl;
        for (size_t i = variable.size(); i > 0; i--) {
            for (auto &j: variable[i - 1]) {
                std::cout << j.first;
                if (j.second->value.type() == typeid(int)) {
                    std::cout << " " << std::any_cast<int>(j.second->value) << std::endl;
                    continue;
                }
                if (j.second->value.type() == typeid(bool)) {
                    std::cout << " " << std::any_cast<bool>(j.second->value) << std::endl;
                    continue;
                }
                if (j.second->value.type() == typeid(std::string)) {
                    std::cout << " " << std::any_cast<std::string>(j.second->value) << std::endl;
                    continue;
                }
                if (j.second->value.type() == typeid(std::vector<int>)) {
                    auto n = std::any_cast<std::vector<int>>(j.second->value);
                    for (auto &l: n)
                        std::cout << " " << l;
                    std::cout << std::endl;
                    continue;
                }
                if (j.second->value.type() == typeid(std::vector<bool>)) {
                    auto n = std::any_cast<std::vector<bool>>(j.second->value);
                    for (const auto &l: n)
                        std::cout << " " << l;
                    std::cout << std::endl;
                    continue;
                }
                if (j.second->value.type() == typeid(std::vector<std::string>)) {
                    auto n = std::any_cast<std::vector<std::string>>(j.second->value);
                    for (auto &l: n)
                        std::cout << " " << l;
                    std::cout << std::endl;
                    continue;
                }
            }
        }
        for(size_t i=0; i<function.size();i++){
            for(auto &j:function[i])
                std::cout<<j.first<<std::endl;
        }
    }
    std::shared_ptr<Variable> find(std::string &in){
        for(size_t i = variable.size(); i>0; i--){
            auto res = variable[i-1].find(in);
            if(res!=variable[i-1].end()){return res->second;}
        }
        throw std::runtime_error("Variable didn't exist "+in +" !");
    }
    std::shared_ptr<ASTNode> Ffind(std::string &in){
        for(size_t i = function.size(); i>0; i--){
            auto res = function[i-1].find(in);
            if(res!=function[i-1].end()){return res->second;}
        }
        throw std::runtime_error("Function didn't exist "+in +" !");
    }
    void setValue(std::string &in, std::any &val){
        std::cout<<in<<" "<<std::endl;
        for(size_t i = variable.size();i>0;i--){
            if(variable[i-1].find(in)!=variable[i-1].end()){
                if(variable[i-1].find(in)->second->value.type() != val.type())  throw std::runtime_error(in+" assignment error");
                variable[i-1].find(in)->second->value = val;
                variable[i-1].find(in)->second->isArray = false;
                return;
            }
        }
        throw std::runtime_error("Variable didn't exist "+in +" !");
    }
    void setAValue(std::string &in, std::any &val, size_t index){
        std::cout<<"Help"<<std::endl;
        for(size_t i = variable.size();i>0;i--){
            if(variable[i-1].find(in)!=variable[i-1].end()){
                auto find = variable[i-1].find(in);
                if(!find->second->isArray) throw std::runtime_error(in + "isn't array");
                auto res = find->second->value;
                if (res.type() == typeid(std::vector<std::string>)){
                    auto ar = std::any_cast<std::vector<std::string>>(res);
                    if(typeid(std::string) != val.type())  throw std::runtime_error(in +" assignment error");
                    if(ar.size()<=index)
                        ar.resize(index+1);
                    ar[index] = std::any_cast<std::string>(val);
                    find->second->value = std::any(ar);
                }
                else if (res.type() == typeid(std::vector<bool>)){
                    auto ar = std::any_cast<std::vector<bool>>(res);
                    if(typeid(bool) != val.type())  throw std::runtime_error(in +" assignment error");
                    if(ar.size()<=index) ar.resize(index+1);
                    ar[index] = std::any_cast<bool>(val);
                    find->second->value = std::any(ar);
                }
                else if (res.type() == typeid(std::vector<int>)){
                    auto ar = std::any_cast<std::vector<int>>(res);
                    if(typeid(int) != val.type())  throw std::runtime_error(in +" assignment error");
                    if(ar.size()<=index)
                        ar.resize(index+1);
                    ar[index] = std::any_cast<int>(val);
                    find->second->value = std::any(ar);
                }
                return;
            }
        }
        throw std::runtime_error("Variable didn't exist "+in +" !");
    }
//    void addFunction(std::string &n, std::shared_ptr<ASTNode> &a){function.insert({n, a});}
//    std::shared_ptr<ASTNode> &getFunction(std::string &n){return function.find(n)->second;}
//    unsigned int checkVariableExisting(const std::string& name) {
//        for (unsigned int i = stores.size(); i > 0; --i)
//            if (stores[i-1]->varStore.count(name) > 0)
//                return i;
//        return 0;
//    }
//ч

//    bool checkExisting(const std::string& name) {
//        return checkVariableExisting(name) || checkFunctionExisting(name);
//    }
//    bool checkCurrentExisting(const std::string& name) {
//        return  checkVariableExisting(name) == stores.size()
//                || checkFunctionExisting(name) == stores.size();
//    }
};
class ParseVariableContainer: public IContainerContext{
    std::vector<std::set<std::string>> variable;
    std::vector<std::set<std::string>> function;
public:
    void push(const std::string& name) {if(variable[variable.size()-1].emplace(name).second) { }else{throw std::runtime_error("Variable already exist");}}
    void push(const std::string &name, Variable &value) override{}
    void Up() override{variable.resize(variable.size()+1);function.resize(variable.size()+1);}
    void Down() override{variable.resize(variable.size()-1);function.resize(variable.size()-1);}
    void print(){
        for(auto &i: variable){
            for(auto &j: i)
                std::cout<<j<<std::endl;
            std::cout<<"------------------"<<std::endl;
        }
    }
    bool find(std::string &in){
        for(size_t i = variable.size(); i>0; i--){
            auto res = variable[i-1].find(in);
            if(res!=variable[i-1].end()){return true;}
        }
        std::cout<<"get4"<<std::endl;
        throw std::runtime_error("Variable didn't exist");
    }


};
class ASTNode{
public:
    std::vector<std::shared_ptr<ASTNode>> children;
    std::shared_ptr<VariableContainer> variable;
    explicit ASTNode(std::shared_ptr<VariableContainer> &c):variable(c){}
    ASTNode() = default;
    void addChildren(std::shared_ptr<ASTNode> &in){children.push_back(in);}
    virtual std::any execute(){return std::any();}
    virtual ~ASTNode(){}
};
class StartNode: public ASTNode{
public:
    StartNode(std::shared_ptr<VariableContainer> &c):ASTNode(c){}
    std::any execute() override{
        std::cout<<"Execute StartNode"<<std::endl;
        for(auto &i:children){
            i->execute();
        }
        return {};
    }
};
class TypeConversionNode: public ASTNode{
    Type type;
    Type type2;
    bool IsArray;
    std::string name;
public:
    TypeConversionNode(std::shared_ptr<VariableContainer> &c, std::string n, Type t): ASTNode(c), type(t), name(std::move (n)){}
    std::any execute() override{
        std::cout<<"Execute TypeConversionNode"<<std::endl;
        auto value = children[0]->execute();
        if (value.type() == typeid(int)){
            type2 = INT_;
            IsArray = false;
        }
        if (value.type() == typeid(bool)){
            type2 = BOOL_;
            IsArray = false;
        }
        if (value.type() == typeid(std::string)){
            type2 = STR_;
            IsArray = false;
        }
        if (value.type() == typeid(std::vector<int>)){
            type2 = INT_;
            IsArray = true;
        }
        if (value.type() == typeid(std::vector<bool>)){
            type2 = BOOL_;
            IsArray = true;
        }
        if (value.type() == typeid(std::vector<std::string>)){
            type2 = STR_;
            IsArray = true;
        }
        std::cout<<type<<" "<<type2<<" "<<IsArray<<std::endl;
        switch(type){
            case INT_:
                switch (type2) {
                    case BOOL_:
                        if (IsArray) {
                            auto ar = std::any_cast<std::vector<bool>>(value);
                            std::vector<int> out;
                            out.resize(ar.size());
                            for (const auto &i: ar) {
                                out.push_back(i);
                            }
                            return {out};
                            break;
                        } else {
                            auto val = std::any_cast<bool>(value);
                            return {(int) val};
                        }
                    case INT_:
                        return value;
                    case STR_:
                        throw std::runtime_error("Avalible convercsion from str to int");
                }
            case BOOL_:
                switch (type2) {
                    case INT_:
                        if(IsArray){
                                auto ar = std::any_cast<std::vector<int>>(value);
                                std::vector<bool> out;
                                out.resize(ar.size());
                                for(const auto &i: ar){
                                    out.push_back(i);
                                }
                                return {out};
                        }else{
                            auto val = std::any_cast<int>(value);
                            return {(bool)val};
                        }
                    case BOOL_:
                        return value;
                    case STR_:
                        throw std::runtime_error("Unvalible convercsion from str to int");
                        break;

                }
            case STR_:
                std::string res = "";
                switch (type2) {
                    case INT_:
                        if (IsArray) {
                                std::cout<<"Here"<<std::endl;
                                auto ar = std::any_cast<std::vector<int>>(value);
                                for (auto &i: ar)
                                    res += std::to_string(i);
                                break;
                        }else{
                            return std::to_string(std::any_cast<int>(value));
                            break;
                        }
                    case BOOL_:
                        if (IsArray){
                            auto ar = std::any_cast<std::vector<bool>>(value);
                            for(const auto &i: ar)
                                res += std::to_string(i);
                            break;
                        }else{
                            return std::to_string(std::any_cast<bool>(value));
                            break;
                        }
                    case STR_:
                        if(IsArray){
                            auto ar = std::any_cast<std::vector<std::string>>(value);
                            for(auto &i: ar)
                                res += i;
                            break;
                        }else{
                            return value;
                        }
                }
                return {res};
        }
        return {};
    }
};
class VariableNode: public ASTNode{
public:
    std::string name;
    VariableNode(std::shared_ptr<VariableContainer> &c, std::string n): ASTNode(c), name(std::move(n)){}
    std::any execute() override{
        std::cout<<"VariableNode "<<name<<std::endl;
        auto find = variable->find(name);
//        if(find->isArray) throw std::runtime_error(name+" is array");
        return find->value;
    }
};
class VariableArrayNode: public ASTNode{
public:
    std::string name;
    size_t index;
    VariableArrayNode(std::shared_ptr<VariableContainer> &c, std::string n, int i): ASTNode(c), name(std::move(n)){ if(i>-1){index = i;}else{throw std::runtime_error("Out of array range");}}
    std::any execute() override{
        std::cout<<"VariableArrayNode "<<name<<std::endl;
        auto find = variable->find(name);
        if (!find->isArray) throw std::runtime_error(name+"Not an array");
        auto res = find->value;
        if (res.type() == typeid(std::vector<std::string>)){
            auto ar = std::any_cast<std::vector<std::string>>(res);
            if(ar.size()<=index)throw std::runtime_error("Out of array range");
            return {ar[index]};
        }
        if (res.type() == typeid(std::vector<bool>)){
            auto ar = std::any_cast<std::vector<bool>>(res);
            if(ar.size()<=index)throw std::runtime_error("Out of array range");
            return {ar[index]};
        }
        if (res.type() == typeid(std::vector<int>)){
            auto ar = std::any_cast<std::vector<int>>(res);
            if(ar.size()<=index)throw std::runtime_error("Out of array range");
            return {ar[index]};
        }
        return {};
    }
};
class ValueNode: public ASTNode{
public:
    std::any value;
    std::any execute() override{    if (value.type()== typeid(int))std::cout<<"Execute ValueNode "<<std::any_cast<int>(value)<<std::endl;return value;}
    ValueNode(std::shared_ptr<VariableContainer> &c, std::any v): ASTNode(c), value(std::move(v)){}
};
class DefaultValueNode: public ASTNode{
public:
    Type type;
    DefaultValueNode( Type t): type(t){}
    std::any execute() override{
        switch (type) {
            case INT_:
                return {0};
                break;
            case STR_:
                return {std::string ("")};
                break;
            case BOOL_:
                return {false};
                break;
        }
        return {};
    }
};
class VariableDefinitionNode: public ASTNode{
public:
    std::vector<std::string> name;
    Type type;
    VariableDefinitionNode(std::shared_ptr<VariableContainer> &in, std::string &n, Type t): ASTNode(in), type(t){name.push_back(n);}
    VariableDefinitionNode(std::shared_ptr<VariableContainer> &in, std::string n, Type t): ASTNode(in), type(t){name.push_back(std::move(n));}
    void addVariableName(std::string &in){name.push_back(in);}
    std::any execute() override{
        std::cout<<"Execute VariableDefinitionNode "<<children.size()<<std::endl;
        for(size_t i = 0; i< children.size(); i++){
            std::any op1 = children[i]->execute();
            switch (type) {
                case INT_:
                    if(op1.type()!= typeid(int))
                        throw std::runtime_error("Wrong type of expression");
                    break;
                case STR_:
                    if(op1.type()!= typeid(std::string))
                        throw std::runtime_error("Wrong type of expression");
                    break;
                case BOOL_:
                    if(op1.type()!= typeid(bool))
                        throw std::runtime_error("Wrong type of expression");
                    break;
            }
            std::cout<<"VariableDefinitionNode: "<<name[i]<<std::endl;
            variable->push(name[i], op1, false);
        }
        return std::any();
    }
};
class VariableArrayDefinitionNode: public ASTNode{
public:
    std::vector<std::string> name;
    Type type;
    VariableArrayDefinitionNode(std::shared_ptr<VariableContainer> &in, std::string n, Type t): ASTNode(in), type(t){name.push_back(std::move(n));}
    void addVariableName(std::string &in){name.push_back(in);}
    std::any execute() override{
        std::cout<<"Execute VariableArrayDefinitionNode "<<children.size()<<std::endl;
        for(size_t i = 0; i< name.size(); i++){
            std::cout<<"VariableArrayDefinitionNode: "<<name[i]<<std::endl;
            std::any p;
            switch (type) {
                case INT_:
                    p = std::any(std::vector<int>());
                    variable->push(name[i], p, true);
                    break;
                case STR_:
                    p = std::any(std::vector<std::string>());
                    variable->push(name[i], p, true);
                    break;
                case BOOL_:
                    p = std::any(std::vector<bool>());
                    variable->push(name[i], p, true);
                    break;
            }
        }
        return std::any();
    }
};
class EqualNode: public ASTNode{
public:
    std::string name;
    EqualNode(std::shared_ptr<VariableContainer> &in, std::string &n): ASTNode(in), name(n){}
    std::any execute() override{
        std::cout<<"EqualNode"<<std::endl;
        auto val = children[0]->execute();
        variable->setValue(name, val);
        return {};
    }
};
class EqualArrayNode: public ASTNode{
public:
    std::string name;
    size_t index;
    EqualArrayNode(std::shared_ptr<VariableContainer> &in, std::string &n, int i): ASTNode(in), name(n){if(i>-1){index = i;}else{throw std::runtime_error("Out of array range");}}
    std::any execute() override{
        std::cout<<"EqualArrayNode"<<std::endl;
        auto val = children[0]->execute();
        if(children.size() == 2){
            auto in = children[1]->execute();
            std::cout<<"EqualArrayNode with expresion"<<std::endl;
            if(in.type() == typeid(int)){
                int check = std::any_cast<int>(in);
                if(check>-1){
                    index = check;
                }else{
                    throw std::runtime_error("Out of array range");
                }
            }else{
                throw std::runtime_error("Error of index type");
            }
        }
        std::cout<<index<<std::endl;
        std::cout<<"set Value"<<std::endl;
        variable->setAValue(name, val, index);
        return {};
    }
};
class FunctionException{
    std::any value;
public:
    FunctionException(std::any &val): value(val){}
    const std::any &getVal() const {return value;}
};
class FunctionReturnNode: public ASTNode{
    std::any execute() override{
        auto res = children[0]->execute();
        throw FunctionException(res);
    }
};
class FunctionVariableDefinitionNode: public ASTNode{
    std::vector<std::string> name;
    std::vector<std::shared_ptr<ASTNode>> adoptedChildren;
public:
    FunctionVariableDefinitionNode(std::shared_ptr<VariableContainer> &c, std::string &n): ASTNode(c){name.push_back(n);}
    void addName(std::string &n){name.push_back(n);}
    void addAdopted(std::vector<std::shared_ptr<ASTNode>> &in){adoptedChildren = in;}
    std::any execute() override{
        std::cout<<"FunctionVariableDefinitionNode "<<name.size()<<std::endl;
        for(size_t i = 0; i<adoptedChildren.size(); i++){
            std::cout<<name[i]<<std::endl;
            auto res = adoptedChildren[i]->execute();
            variable->push(name[i], res, false);
        }
        for(size_t i = adoptedChildren.size(); i<children.size(); i++){
            std::cout<<name[i]<<std::endl;
            auto res = children[i]->execute();
            variable->push(name[i], res, false);
        }
        adoptedChildren.clear();
        return {children.size()};
    }
};
class FunctionStartNode: public ASTNode{
private:
    std::string name;
    Type type;
public:
    FunctionStartNode(std::shared_ptr<VariableContainer> &c, const std::string &n, Type t):ASTNode(c), name(n), type(t){}
    std::string &getName(){return name;}
    std::any execute() override{
        std::cout<<"FunctionStartNode "<<name<<std::endl;
        variable->Up();
        children[0]->execute();
        try {
            children[1]->execute();
        }catch (const FunctionException &ex){
            variable->Down();
            auto res = ex.getVal();
            switch (type) {
                case INT_:
                    if (typeid(int)!= res.type())
                        throw std::runtime_error("Erorre type of function return");
                    std::cout<<"return int"<<std::endl;
                    return res;
                    break;
                case STR_:
                    if (typeid(std::string)!= res.type())
                        throw std::runtime_error("Erorre type of function return");
                    std::cout<<"return str"<<std::endl;
                    return res;
                    break;
                case BOOL_:
                    if (typeid(bool)!= res.type())
                        throw std::runtime_error("Erorre type of function return");
                    std::cout<<"return bool"<<std::endl;
                    return res;
                    break;
            }
            return {};
        }
        return {};
    }
};
class FunctionDefinitionNode: public ASTNode{
    std::string name;
    std::shared_ptr<ASTNode> func;
public:
    FunctionDefinitionNode(std::shared_ptr<VariableContainer> &c, std::string &n, std::shared_ptr<ASTNode> &f): ASTNode(c), name(n), func(f){}
    std::any execute() override{
        std::cout<<"Execute FunctionDefinitionNode "<<name<<std::endl;
        variable->Fpush(name, func);
        return {};
    }
};
class FunctionCallNode: public ASTNode{
    std::string Fname;
public:
    FunctionCallNode(std::shared_ptr<VariableContainer> &c, std::string &n): ASTNode(c), Fname(n){}
    std::any execute() override{
        std::cout<<"FunctionCallNode "<<Fname<<std::endl;
        auto func = variable->Ffind(Fname);
        auto funcdef = std::dynamic_pointer_cast<FunctionVariableDefinitionNode>(func->children[0]);
        funcdef->addAdopted(children);
        return func->execute();
    }
};
class FunctionCallOperatorNode: public ASTNode{
    std::string Fname;
    std::string Aname;
public:
    FunctionCallOperatorNode(std::shared_ptr<VariableContainer> &c, std::string &n, std::string &a): ASTNode(c), Fname(n), Aname(a){}
    std::any execute() override{
        std::cout<<"FunctionCallOperatorNode "<<Fname<<std::endl;
        auto res = variable->find(Fname);
        if (res->value.type() != typeid(std::string)) throw std::runtime_error("Not str");
        auto funcName = std::any_cast<std::string>(res->value);
        auto func = variable->Ffind(funcName);
        auto arg = variable->find(Aname);
        if(arg->value.type() != typeid(std::vector<std::string>)) throw std::runtime_error("Not str");
        auto _arg = std::any_cast<std::vector<std::string>>(arg->value);
        auto funcdef = std::dynamic_pointer_cast<FunctionVariableDefinitionNode>(func->children[0]);
        std::vector<std::shared_ptr<ASTNode>> chil;
        for(size_t i = 0; i<_arg.size(); i++){
            auto n = std::make_shared<ValueNode>(variable,variable->find(_arg[i])->value);
            chil.push_back(n);
        }
        funcdef->addAdopted(chil);
        return func->execute();
    }
};
class ArithmeticNode: public ASTNode {
public:
    Operation op;
    ArithmeticNode(std::shared_ptr<VariableContainer> &c, Operation in): ASTNode(c), op(in){}
    std::any execute() override{
        std::cout<<"Execute ArithmeticNode "<<children.size()<<std::endl;
        auto op1 = children[0]->execute();
        auto op2 = children[1]->execute();
        if(op1.type() == op2.type()){
            if(op1.type() == typeid(int)){
                int op1_ = std::any_cast<int>(op1);
                int op2_ = std::any_cast<int>(op2);
                std::cout<<"Execute ArithmeticNode for int"<<std::endl;
                int value;
                switch (op) {
                    case MIN:
                        value = op1_ - op2_;
                        break;
                    case PLUS:
                        value = op1_ + op2_;
                        break;
                    }
                return value;
            }else if(op1.type() == typeid(bool)){
                bool op1_ = std::any_cast<bool>(op1);
                bool op2_ = std::any_cast<bool>(op2);
                bool value;
                switch (op) {
                    case MIN:
                        value = !(op1_ || op2_);
                        break;
                    case PLUS:
                        value = op1_ || op2_;
                        break;
                }
                return value;
            }else if(op1.type() == typeid(std::string)){
                auto op1_ = std::any_cast<std::string>(op1);
                auto op2_ = std::any_cast<std::string>(op2);
                std::string value;
                switch (op) {
                    case MIN:
                        value = op1_ + op2_;
                        break;
                    case PLUS:
                        for(size_t i = 0; i<(op1_.size() - op2_.size());i++){
                            std::string temp = op1_.substr(i, op2_.size());
                            if (temp != op2_){value+=temp;}
                        }
                        break;
                }
                return value;
            }
        }else{
            throw std::runtime_error("Operation between different types");
        }
        return std::any();
    }
};
class LogicalArithmeticNode: public ASTNode{
public:
    LogicalOperators op;
    LogicalArithmeticNode(std::shared_ptr<VariableContainer> &c, LogicalOperators in): ASTNode(c), op(in){}
    LogicalArithmeticNode(std::shared_ptr<VariableContainer> &c, std::string &in) :ASTNode(c){ op = StrLog(in);}
    std::any execute() {
        std::cout << "Execute LogicalArithmeticNode " << children.size() << std::endl;
        auto op1 = children[0]->execute();
        auto op2 = children[1]->execute();
        if (op1.type() == op2.type()) {
            if (op1.type() == typeid(int)) {
                int op1_ = std::any_cast<int>(op1);
                int op2_ = std::any_cast<int>(op2);
                std::cout << "Execute LogicalArithmeticNode for int" << std::endl;
                bool value;
                switch (op) {
                    case QL:
                        value = op1_ == op2_;
                        break;
                    case NQL:
                        value = op1_ != op2_;
                        break;
                    case LSS:
                        value = op1_ < op2_;
                        break;
                    case GRT:
                        value = op1_ > op2_;
                        break;
                }
                return value;
            } else if (op1.type() == typeid(bool)) {
                bool op1_ = std::any_cast<bool>(op1);
                bool op2_ = std::any_cast<bool>(op2);
                bool value;
                switch (op) {
                    case QL:
                        value = op1_ == op2_;
                        break;
                    case NQL:
                        value = op1_ != op2_;
                        break;
                    case LSS:
                        value = op1_ < op2_;
                        break;
                    case GRT:
                        value = op1_ > op2_;
                        break;
                }
                return value;
            } else if (op1.type() == typeid(std::string)) {
                auto op1_ = std::any_cast<std::string>(op1);
                auto op2_ = std::any_cast<std::string>(op2);
                bool value;
                switch (op) {
                    case QL:
                        value = op1_ == op2_;
                        break;
                    case NQL:
                        value = op1_ != op2_;
                        break;
                    case LSS:
                        value = op1_ < op2_;
                        break;
                    case GRT:
                        value = op1_ > op2_;
                        break;
                }
                return value;
            }
        } else {
            throw std::runtime_error("Operation between different types");
        }
        return {};
    }
};

class CycleNode: public ASTNode{
public:
    CycleNode(std::shared_ptr<ASTNode> &Econdition, std::shared_ptr<ASTNode> &body, std::shared_ptr<ASTNode> &Ocondition){
        addChildren(Econdition);
        addChildren(body);
        addChildren(Ocondition);
    }
    std::any execute() override{
        std::cout<<"CycleNode Execute"<<std::endl;
        bool condition = std::any_cast<bool>(children[0]->execute());
        std::cout<<"get IN condition "<<condition<<std::endl;
        if(condition){
            do {
                children[1]->execute();
            } while (std::any_cast<bool>(children[2]->execute()));
        }
        return {};
    }
};

