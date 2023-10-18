run2D:
	gcc -o main main.c -DtypeOfDimension=2
	./main
	rm main

run3D:
	gcc -o main main.c -DtypeOfDimension=3
	./main
	rm main