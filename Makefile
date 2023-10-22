run2D:
	gcc -o program main/main.c modules/Graph.c
	./program file.txt 2
	rm main

run3D:
	gcc -o main .main.c 
	./main
	rm main