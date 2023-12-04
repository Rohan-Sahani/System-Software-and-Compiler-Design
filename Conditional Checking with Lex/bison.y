%{
#include<stdio.h>
extern int yylex();
extern int yywrap();
extern int yyparse();
%}
%token WH IF DO FOR OP CP OCB CCB CMP SC ASG ID NUM COMMA OPR
%%
start: swh | mwh | dowh | sif | mif;
swh: WH OP cmplst CP stmt {printf("VALID SINGLE WHILE STATEMENT\n");};
mwh: WH OP cmplst CP OCB stlst CCB {printf("VALID MULTI WHILE STATEMENT\n");}
dowh: DO OCB stlst CCB WH OP cmplst CP SC {printf("VALID DOWHILE\n:");}
sif: IF OP cmplst CP stmt {printf("VALID SINGLE IF STATEMENT\n");}
mif: IF OP cmplst CP OCB stlst CCB {printf("VALID MULTI IF STATEMENT\n");}
cmplst: cmpn COMMA cmplst | cmpn;
cmpn: ID CMP ID | ID CMP NUM;
stlst: stmt stlst | stmt;
stmt: ID ASG ID OPR SC| ID ASG ID OPR NUM SC| ID ASG NUM OPR ID SC| ID ASG NUM OPR
NUM SC| ID ASG ID SC | ID ASG NUM SC | start {printf("NESTED INSIDE A");} ;
%% int yyerror(char *str)
{
 printf("%s", str);
}
main()
{
 yyparse();
}