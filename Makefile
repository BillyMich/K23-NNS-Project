run2D:
	gcc -o program main/main.c modules/Graph.c modules/Node.c modules/Neighbors.c modules/Dimension.c
	./program datasets/dummy.bin 2
	rm program

run3D:
	gcc -o main main.c -DtypeOfDimension=3
	./main
	rm main

clean:
	rm -f program
	rm -f *.o