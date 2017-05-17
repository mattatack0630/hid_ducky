output: 
	g++ main.o Key.o HidCom.o DuckyParser.o -o output -std=c++11

main.o:
	g++ -c main.cpp -std=c++11

Key.o :
	g++ -c Key.cpp -std=c++11
	
HidCom.o :
	g++ -c HidCom.cpp -std=c++11

DuckyParser.o :
	g++ -c DuckyParser.cpp -std=c++11

clean: 
	rm *.o output
