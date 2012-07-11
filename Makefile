all:
	gcc main.c init.c force.c plant.c numerical.c -o main

clean:
	rm main output.txt
