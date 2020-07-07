solve:transform generate solve.o sudoku.o
	g++ -o solve solve.o sudoku.o
transform:solve generate transform.o sudoku.o
	g++ -o transform transform.o sudoku.o
generate:transform solve generate.o sudoku.o
	g++ -o generate generate.o sudoku.o
sudoku.o:sudoku.h sudoku.cpp
	g++ -c sudoku.cpp
solve.o:solve.cpp sudoku.h
	g++ -c solve.cpp
generate.o:generate.cpp sudoku.h
	g++ -c generate.cpp
transform.o:transform.cpp sudoku.h
	g++ -c transform.cpp
