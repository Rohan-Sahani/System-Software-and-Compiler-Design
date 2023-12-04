The commands to run are :

flex *.l
byacc -d *.y
gcc lex.yy.c y.tab.c

Then ./a.out