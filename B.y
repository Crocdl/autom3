%{  #include "ast/ast.h"
    #include "ast/robot_function.cpp"
    #include <iostream>
    #define YYSTYPE val
    struct val
    {
        int i;
        bool b;
        std::string s;
        std::shared_ptr<ASTNode> a;
        Type t;
    };
    #include <stdio.h>
    #include <FlexLexer.h>
    #include <any>
    extern FILE* yyin;
    extern int yylex();
    void yyerror(const char*);
    std::string map_name = "maze.txt";
    auto container = std::make_shared<VariableContainer>();
    auto container_ = std::make_shared<ParseVariableContainer>();
    int l = 0;
    ASTNode *tree;
    auto map  = std::make_shared<Map>(map_name);
    auto robot = std::make_shared<Robot>(map, 100);

%}
    %token INTEGER STRING BOOL
    %token LEFT RIGHT FORWARD BACK
    %token LEFTROT RIGHTROT
    %token TYPE_INTEGER TYPE_STRING TYPE_BOOL
    %token ID
    %token BEG EN
    %token FUNC RETURN
    %token ENTER DO UNTIL
    %token ARRAY
    %token ENDL
    %token EoF
    %token LOGOPERATOR
    %token CALL
    %token MEAS BIND DEMOLISH
%%
    program:
        program group {std::cout<<"group->program"<<std::endl;}
        | program variable_defenition {$1.a->addChildren($2.a); std::cout<<"variable_defenition->program"<<std::endl;}
        | program assigning_defenition {$1.a->addChildren($2.a); std::cout<<"assigning_defenition->program"<<std::endl;}
        | program cycle {$1.a->addChildren($2.a); std::cout<<"cycle->program"<<std::endl;}
        | program function {$1.a->addChildren($2.a); std::cout<<"function->program"<<std::endl;}
        | program robot_rotate_comand {$1.a->addChildren($2.a); std::cout<<"robot_rotate_comand->program"<<std::endl;}
        | program sentence {$1.a->addChildren($2.a); std::cout<<"function->program"<<std::endl;}
        | program EoF {container_->print();$1.a->execute();std::cout<<"val"<<std::endl;container->print();}
        |   {$$.a = std::make_shared<StartNode>(container); std::cout<<"Start"<<std::endl; container_->Up(); container->Up();}
        ;
    robot_move_comand:
        LEFT {
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<MoveRobotNode>(container,robot, map, direction::LEFT_));
        $$.a = n;
        }
        | RIGHT {
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<MoveRobotNode>(container,robot, map, direction::RIGHT_));
        $$.a = n;
        }
        | FORWARD {
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<MoveRobotNode>(container,robot, map, direction::UP_));
        $$.a = n;
        }
        | BACK {
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<MoveRobotNode>(container,robot, map, direction::DOWN_));
        $$.a = n;
        }
        ;
    robot_rotate_comand:
        LEFTROT {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<RotateRobotNode>(container,robot, map, false));
            $$.a = n;
         }
        |RIGHTROT {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<RotateRobotNode>(container,robot, map, true));
            $$.a = n;
        }
        ;
    reflector:
        MEAS {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<RobotMeasureNode>(container,robot, map));
            $$.a = n;
        }
        ;
    demolish:
        DEMOLISH {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<DemolishRobotNode>(container,robot, map));
            $$.a = n
        }

    bind:
        BIND ID ';'{
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<RobotBindNode>(container,robot, map, $2.s));
            $$.a = n;
        }
        ;
    value:
        INTEGER {std::cout<<"get NUMBER"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ValueNode>(container, std::any($1.i)));
            $$.a = n;
        }
        | STRING {std::cout<<"get STRING"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ValueNode>(container, std::any($1.s)));
            $$.a = n;
        }
        | BOOL {std::cout<<"get BOOL"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ValueNode>(container, std::any($1.b)));
            $$.a = n;
        }
        | function_call_end { std::cout<<"get function call"<<std::endl;
            $$.a = $1.a;
        }
        | ID  {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableNode>(container, $1.s));
            if(!container_->find($1.s)) throw std::runtime_error("Variable already exist"+$1.s);
            $$.a = n;
        }
        | ID '[' INTEGER ']' {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableArrayNode>(container, $1.s, $3.i));
            if(!container_->find($1.s)) throw std::runtime_error("Variable already exist"+$1.s);
            $$.a = n;
            std::cout<<"get Array"<<std::endl;
        }
        | robot_move_comand{ $$.a = $1.a;}
        | robot_rotate_comand {$$.a = $1.a;}
        | reflector {$$.a = $1.a;};
        | demolish {$$.a = $1.a;};
        ;
    type_coversion:
        '(' TYPE_INTEGER ')' expresion {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<TypeConversionNode>(container, $2.s, Type::INT_));
            n -> addChildren($4.a);
            $$.a = n;
        }
        |'(' TYPE_BOOL ')' expresion
        {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<TypeConversionNode>(container, $2.s, Type::BOOL_));
            n -> addChildren($4.a);
            $$.a = n;
        }
        |'(' TYPE_STRING ')' expresion{
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<TypeConversionNode>(container, $2.s, Type::STR_));
            n -> addChildren($4.a);
            $$.a = n;
        }
        ;

    function_argument:
        ID '=' expresion {
            std::cout<<"function_argument"<<std::endl;
            container_->push($1.s);
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionVariableDefinitionNode>(container, $1.s));
            n->addChildren($3.a);
            $$.a = n;
        }
        | ID '=' logical_expresion {
            std::cout<<"function_argument"<<std::endl;
            container_->push($1.s);
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionVariableDefinitionNode>(container, $1.s));
            n->addChildren($3.a);
            $$.a = n;
        }
        | function_argument ',' ID '=' expresion {
            std::cout<<"function_argument"<<std::endl;
            container_->push($3.s);
            $1.a->addChildren($5.a);
            std::dynamic_pointer_cast<FunctionVariableDefinitionNode>($1.a)->addName($3.s);
            $$.a = $1.a;
        }
        | function_argument ',' ID '=' logical_expresion {
            std::cout<<"function_argument"<<std::endl;
            container_->push($3.s);
            $1.a->addChildren($5.a);
            std::dynamic_pointer_cast<FunctionVariableDefinitionNode>($1.a)->addName($3.s);
            $$.a = $1.a;
        }
        ;
    function_declaration_begin:
        TYPE_INTEGER FUNC ID {
            std::cout<<"function_declaration_begin"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionStartNode>(container, $3.s, Type::INT_));
            container_->Up();
            $$.a = n;
        }
        | TYPE_STRING FUNC ID {
            std::cout<<"function_declaration_begin"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionStartNode>(container, $3.s, Type::STR_));
            container_->Up();
            $$.a = n;
        }
        | TYPE_BOOL FUNC ID {
            std::cout<<"function_declaration_begin"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionStartNode>(container, $3.s, Type::BOOL_));
            container_->Up();
            $$.a = n;
        }
        ;
    function_declaration_end:
        function_declaration_begin '(' function_argument ')'{
            std::cout<<"function_declaration_end"<<std::endl;
            $1.a->addChildren($3.a);
            $$.a = $1.a;
        }
        | function_declaration_begin '(' ')'{
            $$.a = $1.a;
        }
        ;
    function:
        function_declaration_end group {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionDefinitionNode>(container, std::dynamic_pointer_cast<FunctionStartNode>($1.a)->getName(), $1.a));
            std::cout<<"function_declaration_end+group"<<std::endl;$1.a->addChildren($2.a); $$.a = n;
            container_->Down();
        }
        | function_declaration_end sentence {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionDefinitionNode>(container, std::dynamic_pointer_cast<FunctionStartNode>($1.a)->getName(), $1.a));
            std::cout<<"function_declaration_end->function"<<std::endl;$1.a->addChildren($2.a); $$.a = n;
            container_->Down();
        }
    function_call_begin:
        ID '('expresion {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionCallNode>(container, $1.s));
            n->addChildren($3.a);
            $$.a = n;
        }
        | ID '(' logical_expresion {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionCallNode>(container, $1.s));
            n->addChildren($3.a);
            $$.a = n;
        }
        | function_call_begin ',' expresion {$1.a->addChildren($3.a);}
        | function_call_begin ',' logical_expresion {$1.a->addChildren($3.a);}
    function_call_end:
        | function_call_begin ')' {$$.a = $1.a;}
        ;
    cycle:
        ENTER logical_expresion DO sentence UNTIL logical_expresion {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<CycleNode>($2.a, $4.a, $6.a));
            $$.a = n;
        }
        | ENTER logical_expresion DO group UNTIL logical_expresion{
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<CycleNode>($2.a, $4.a, $6.a));
            $$.a = n;
        }
    sentence:
        variable_defenition {$$.a = $1.a;}
        | assigning_defenition{$$.a = $1.a;}
        | call_function{$$.a = $1.a;}
        | return {$$.a = $1.a;}
        | robot_rotate_comand ';'{$$.a = $1.a;}
        | bind {$$.a = $1.a;}
        ;
    return:
        RETURN ID ';'{
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionReturnNode>());
        auto n1 = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableNode>(container, $2.s));
        n->addChildren(n1);
        $$.a = n;
        }
        | RETURN expresion ';'{
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionReturnNode>());
        n->addChildren($2.a);
        $$.a = n;
        }
        | RETURN logical_expresion ';'{
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionReturnNode>());
        n->addChildren($2.a);
        $$.a = n;
        }
        ;
    group_variable_defenition:
        TYPE_INTEGER ID '=' expresion
        {
            container_->push($2.s);
            std::cout<<"TYPE_INTEGER ID '=' expresion -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string($2.s), Type::INT_));
            n->addChildren($4.a);
            $$.a = n;
            $$.t = Type::INT_;
            }
        | TYPE_INTEGER ID
        {
            container_->push($2.s);
            std::cout<<"TYPE_INTEGER ID '=' expresion -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string($2.s), Type::INT_));
            auto n1 = std::dynamic_pointer_cast<ASTNode>(std::make_shared<DefaultValueNode>(Type::INT_));
            n->addChildren(n1);
            $$.a = n;
            $$.t = Type::INT_;
            }
        | TYPE_STRING ID '=' expresion
        {
            container_->push($2.s);
            std::cout<<"TYPE_INTEGER ID '=' expresion -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string($2.s), Type::STR_));
            n->addChildren($4.a);
            $$.a = n;
            $$.t = Type::STR_;
            }
        | TYPE_STRING ID
        {
            container_->push($2.s);
            std::cout<<"TYPE_STRING ID -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string($2.s), Type::STR_));
            auto n1 = std::dynamic_pointer_cast<ASTNode>(std::make_shared<DefaultValueNode>(Type::STR_));
            n->addChildren(n1);
            $$.a = n;
            $$.t = Type::STR_;
            }
        | TYPE_BOOL ID '=' expresion
        {
            container_->push($2.s);
            std::cout<<"TYPE_BOOL ID '=' expresion -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string($2.s), Type::BOOL_));
            n->addChildren($4.a);
            $$.a = n;
            $$.t = Type::BOOL_;
            }
        | TYPE_BOOL ID
        {
            container_->push($2.s);
            std::cout<<"TYPE_BOOL ID  -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string($2.s), Type::BOOL_));
            auto n1 = std::dynamic_pointer_cast<ASTNode>(std::make_shared<DefaultValueNode>(Type::BOOL_));
            n->addChildren(n1);
            $$.a = n;
            $$.t = Type::BOOL_;
        }
        | group_variable_defenition ',' ID '=' expresion
        {
        container_->push($3.s);
        std::cout<<"group_variable_defenition ',' ID '=' expresion -> group_variable_defenition"<<std::endl;
        $1.a->addChildren($5.a);
        std::dynamic_pointer_cast<VariableDefinitionNode>($1.a)->addVariableName($3.s);
        $$.a = $1.a;
        }
        | group_variable_defenition ',' ID
        {
        std::cout<<"group_variable_defenition ',' ID '=' expresion -> group_variable_defenition"<<std::endl;
        container_->push($3.s);
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<DefaultValueNode>($1.t));
        $1.a->addChildren(n);
        std::dynamic_pointer_cast<VariableDefinitionNode>($1.a)->addVariableName($3.s);
        $$.a = $1.a;
        }
        ;
    assigning_value:
        ID '=' expresion{
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<EqualNode>(container, $1.s));
            n->addChildren($3.a);
            $$.a = n;
        }
        | ID '[' expresion ']' '=' expresion{
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<EqualArrayNode>(container, $1.s, 0));
            n->addChildren($6.a);
            n->addChildren($3.a);
            $$.a = n;
        }
        | ID '=' call_function {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<EqualNode>(container, $1.s));
            n->addChildren($3.a);
            $$.a = n;
        }
        ;
    call_function:
        CALL '(' ID ',' ID ')'{
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionCallOperatorNode>(container,$3.s, $5.s));
            $$.a = n
        }
    expresion:
        logical_expresion {$$.a = $1.a}
        | type_coversion {$$.a = $1.a;}
        | value {$$.a = $1.a}
        | expresion '-' value {
            std::cout<<"expresion '-' -> expresion"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ArithmeticNode>(container, Operation::MIN));
            n->addChildren($1.a);
            n->addChildren($3.a);
            $$.a = n;
            std::cout<<"MIN something"<<std::endl;}
        | expresion '+' value {
            std::cout<<"expresion '+' -> expresion"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ArithmeticNode>(container, Operation::PLUS));
            n->addChildren($1.a);
            n->addChildren($3.a);
            $$.a = n;
            std::cout<<"PLUS somethinf"<<std::endl;}
        ;
    logical_expresion:
        value {$$.a = $1.a}
        | logical_expresion '=' value {
            std::cout<<"expresion EQUAL -> expresion"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<LogicalArithmeticNode>(container, LogicalOperators::QL));
            n->addChildren($1.a);
            n->addChildren($3.a);
            $$.a = n;
            std::cout<<"QL something"<<std::endl;
            }
        | logical_expresion LOGOPERATOR value {
            std::cout<<"expresion LOGOPERATOR -> expresion"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<LogicalArithmeticNode>(container, $2.s));
            n->addChildren($1.a);
            n->addChildren($3.a);
            $$.a = n;
            std::cout<<"Compare something"<<std::endl;
            }
        ;
    group_array_defenition:
        ARRAY TYPE_INTEGER ID{
            auto n = std::make_shared<VariableArrayDefinitionNode>(container, $3.s, Type::INT_);
            $$.a = n;
            container_->push($3.s);
        }
        | ARRAY TYPE_STRING ID{
           auto n = std::make_shared<VariableArrayDefinitionNode>(container, $3.s, Type::STR_);
           $$.a = n;
           container_->push($3.s);
        }
        | ARRAY TYPE_BOOL ID{
           auto n = std::make_shared<VariableArrayDefinitionNode>(container, $3.s, Type::BOOL_);
           $$.a = n;
           container_->push($3.s);
        }
        | group_array_defenition ',' ID{
            std::dynamic_pointer_cast<VariableArrayDefinitionNode>($1.a)->addVariableName($3.s);
            $$.a = $1.a;
        }
        ;
    variable_defenition:
        group_variable_defenition ';'{$$.a = $1.a;}
        | group_array_defenition ';'{$$.a = $1.a;}
        ;
    assigning_defenition:
        assigning_value ';'{$$.a = $1.a;}
        ;
    gropu_beg:
            BEG {std::cout<<"Begin of gropup"<<std::endl; $$.a = std::make_shared<StartNode>(container)}
            | gropu_beg function{$1.a->addChildren($2.a); $$.a = $1.a;}
            | gropu_beg variable_defenition {std::cout<<"variable_defenition->group"<<std::endl;$1.a->addChildren($2.a); $$.a = $1.a;}
            | gropu_beg return {$1.a->addChildren($2.a);}
            | gropu_beg assigning_defenition {$1.a->addChildren($2.a);}
            | gropu_beg cycle {$1.a->addChildren($2.a); $$.a = $1.a;}
    group:
        gropu_beg EN {$$.a = $1.a;}
        ;
%%
int main() {
    yyin = fopen ("./test.txt", "r");
    try{
    yyparse();
    } catch(std::runtime_error b){
    std::cout<<b.what()<<std::endl;
    container->print();
    }
    fclose (yyin);
    std::cout << "Hello, World!" << std::endl;
}
    

