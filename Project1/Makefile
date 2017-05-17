output : main.o HidCom.o Key.o DuckyParser.o
	g++ main.o Key.o HidCom.o DuckyParser.o -o output -std=c++11

main.o : main.cpp
	g++ -c main.cpp -std=c++11

Key.o : Key.cpp
	g++ -c Key.cpp -std=c++11
	
HidCom.o : HidCom.cpp
	g++ -c HidCom.cpp -std=c++11

DuckyParser.o : DuckyParser.cpp
	g++ -c DuckyParser.cpp -std=c++11

clean: 
	rm *.o output
