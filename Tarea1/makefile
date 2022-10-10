FLAGS = -g -Wall 
#FLAGS = -O2

all: main test_Rubik test_Idea test_Rubik_Solver test_Idea test_Rotate test_Path test_State

main: main.cpp Rubik_Solver.o Rubik.o Path.o State.o Idea.o State_Operator.o RotateU.o RotateD.o RotateL.o RotateR.o RotateF.o RotateB.o
	g++ $(FLAGS) -o main Rubik.o Path.o State.o Idea.o Rubik_Solver.o State_Operator.o RotateU.o RotateD.o RotateL.o RotateR.o RotateF.o RotateB.o main.cpp 

State_Operator.o: State_Operator.cpp State_Operator.h
	g++ $(FLAGS) -c State_Operator.cpp

RotateU.o: RotateU.cpp RotateU.h State_Operator.h
	g++ $(FLAGS) -c RotateU.cpp

RotateD.o: RotateD.cpp RotateD.h State_Operator.h 
	g++ $(FLAGS) -c RotateD.cpp

RotateL.o: RotateL.cpp RotateL.h State_Operator.h 
	g++ $(FLAGS) -c RotateL.cpp

RotateR.o: RotateR.cpp RotateR.h State_Operator.h 
	g++ $(FLAGS) -c RotateR.cpp

RotateF.o: RotateF.cpp RotateF.h State_Operator.h 
	g++ $(FLAGS) -c RotateF.cpp

RotateB.o: RotateB.cpp RotateB.h State_Operator.h 
	g++ $(FLAGS) -c RotateB.cpp

test_Rubik: test_Rubik.cpp Rubik.o  
	g++ $(FLAGS) -o test_Rubik Rubik.o test_Rubik.cpp

test_Path: test_Path.cpp Path.o 
	g++ $(FLAGS) -o test_Path Path.o test_Path.cpp

test_Rotate: test_Rotate.cpp State.o State_Operator.o RotateU.o RotateD.o RotateL.o RotateR.o RotateF.o RotateB.o Rubik.o Path.o
	g++ $(FLAGS) -o test_Rotate State.o State_Operator.o RotateU.o RotateD.o RotateL.o RotateR.o RotateF.o RotateB.o Rubik.o Path.o test_Rotate.cpp

test_State: test_State.cpp State.o Rubik.o Path.o
	g++ $(FLAGS) -o test_State Rubik.o State.o Path.o test_State.cpp

test_Idea: test_Idea.cpp Idea.o State.o Path.o Rubik.o 
	g++ $(FLAGS) -o test_Idea Rubik.o Path.o State.o Idea.o test_Idea.cpp

test_Rubik_Solver: test_Rubik_Solver.cpp Rubik_Solver.o Rubik.o Path.o State.o Idea.o State_Operator.o RotateU.o RotateD.o RotateL.o RotateR.o RotateF.o RotateB.o
	g++ $(FLAGS) -o test_Rubik_Solver Rubik.o Path.o State.o Idea.o Rubik_Solver.o State_Operator.o RotateU.o RotateD.o RotateL.o RotateR.o RotateF.o RotateB.o test_Rubik_Solver.cpp 

Idea.o: Idea.cpp Idea.h State.o
	g++ $(FLAGS) -c Idea.cpp

State.o: State.cpp State.h
	g++ $(FLAGS) -c State.cpp

Rubik.o: Rubik.cpp Rubik.h 
	g++ $(FLAGS) -c Rubik.cpp

Path.o: Path.cpp Path.h
	g++ $(FLAGS) -c Path.cpp

clean: 
	rm -rf test_Rubik test_Rubik_Solver test_Idea test_State test_Path test_Rotate html latex main *.o 

run:
	./main