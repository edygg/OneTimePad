remove_files: exe
	rm *.o

exe: main.cpp OneTimePad.o
	g++ main.o OneTimePad.o -o onetimepad

main.cpp: OneTimePad.o
	g++ -c main.cpp

OneTimePad.o:
	g++ -c OneTimePad.cpp 