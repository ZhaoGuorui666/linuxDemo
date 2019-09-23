proj1:main.o func1.o func2.o func3.o
	gcc main.o func1.o func2.o func3.o -o proj1
main.o:
	gcc main.c -c
func1.o:
	gcc func1.c -c
func2.o:
	gcc func2.c -c
func3.o:
	gcc func3.c -c
clean:
	rm -f main.o func1.o func2.o func3.o
