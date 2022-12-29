$(CC) = gcc



main: main.c
	$(CC)  main.c -o main.out

clean:
	rm -rf *.o main
	