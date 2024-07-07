all:  myshell.o mv.o grep_ls.o  ps.o
	gcc myshell.o mv.o grep_ls.o ps.o -lreadline
myshell.o: myshell.c
	gcc -c myshell.c
mv.o: mv.c
	gcc -c mv.c
grep_ls.o: grep_ls.c
	gcc -c grep_ls.c

ps.o: ps.c
	gcc -c ps.c
