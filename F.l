%{
    #include "ast/ast.h"
    #define YYSTYPE val
    struct val
    {
        int i;
        bool b;
        std::string s;
        ASTNode *a;
    };
    #include "lab.tab.h"
    #include <stdlib.h>
    #include <iostream>
    void yyerror (char const *s){
        fprintf (stderr, "%s\n", s);
    }
%}
%%
true {
    yylval.b = true;
    std::cout<<"true <- BOOL"<<std::endl;
    return BOOL;
}
false {
    yylval.b = false;
    return BOOL;
}
undefined {
     yylval.b = false;
     return BOOL;
}
call {
    return CALL;
}
bool { return TYPE_BOOL; }
int { return TYPE_INTEGER; }
str { return TYPE_STRING;}
return {
    return RETURN;
}
enter {
    return ENTER;
}
do {
    return DO;
}
until {
    return UNTIL;
}
(!=|>|<) {
    std::cout<<"LOGOPERATOR"<<std::endl;
    yylval.s = std::string(yytext);
    std::cout<<yylval.s<<std::endl;
    return LOGOPERATOR;
}
[\+\-\&\|\!\=\,\[\]\{\}\/\*\.\;\(\)]   {
    return *yytext;
}
start {
    return BEG;
}
stop {
    return EN;
}
array\ of {
    return ARRAY;
}
function {
    return FUNC;
}
left {
    return LEFT;
}
right {
    return RIGHT;
}
forward {
    return FORWARD;
}
back {
    return BACK;
}
left_rotate {
    return LEFTROT;
}
right_rotate {
    return RIGHTROT;
}
\/HELP\\ {
return EoF;
}
((\'.*\')|(\".*\")) {
    yylval.s = std::string(yytext);
    yylval.s = yylval.s.substr(1, yylval.s.length()-2);
    return STRING;
}
[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.s = std::string(yytext);
    std::cout<<yylval.s<<" <- ID"<<std::endl;
    return ID;
}
[0-9]+ {
    yylval.i = atoi(yytext);
    std::cout<<"Integer -> "<<yytext<<std::endl;
    return INTEGER;
}
[ \t|\n] {

}
%%
int yywrap(void)
    { return 1;}