explode: lab1.o main.o  # Compiling to executable file "explode"
	$(CC) -o $@ $?

lab1.o: lab1.c # Compile Lab1 object file to a c file
	$(CC) -c $?

main.o: main.c # Compile Main object file to a c file
	$(CC) -c $?

clean:
	-rm -f *.o
	@echo "All clean!"
