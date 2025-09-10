main: DBConnection.cpp
	g++ -std=c++17 -o main DBConnection.cpp  -lgtest -lgtest_main -lpthread -lgmock
lib: -I/usr/local/include -L/usr/local/lib