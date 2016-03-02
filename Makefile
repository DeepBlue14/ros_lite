all:
	g++ -pthread -o CorridorTraversal.exe src/CorridorTraversal.cpp src/cbc_sim.cpp
	g++ -pthread -o Test.exe src/Test.cpp src/cbc_sim.cpp

clean:
	rm Test.exe CorridorTraversal.exe *~
