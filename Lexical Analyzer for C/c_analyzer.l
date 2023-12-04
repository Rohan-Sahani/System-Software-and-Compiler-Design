%{
/* Lexical Analyzer for simple c hello world program*/
int keyword = 0, pre = 0, literal = 0, identifier = 0, oper = 0, header = 0;
%}
%option noyywrap
keyword int|char|void|return|while|for|else|if|bool|const
digit [0-9]
letter [a-zA-Z]
preprocessor #include|#define|#ifdef|#ifndef
operator ("+")+|("-")+|"*"|("=")+|"\\"|("&")+|("|")+|("<")+|(">")+|"^"|"."|sizeof|"{"|"}"|"("|")"
%%
[\t ]+
{keyword} {printf("%s is a keyword\n", yytext); keyword++;}
{preprocessor} {printf("%s is a preprocessor directive\n", yytext); pre++;}
"<".+">" {printf("%s is a header file\n", yytext); header++;}
{digit}+ |
"\"".*"\"" |
("'"."'") |
"false" |
"true" |
{digit}*"."{digit}+ |
"NULL" {printf("%s is a literal\n", yytext); literal++;}
{operator} {printf("%s is a operator\n", yytext); oper++;}
(_*{letter}+{digit}*)+ {printf("%s is a identifier\n", yytext); identifier++;}
. {}
%%
int main() {
yyin = fopen("input.txt", "r");
yylex();
printf("Number of keywords = %d\n", keyword);
printf("Number of header = %d\n", header);
printf("Number of preprocessor = %d\n", pre);
printf("Number of literals = %d\n", literal);
printf("Number of identifier = %d\n", identifier);
printf("Number of operators = %d\n", oper);
}