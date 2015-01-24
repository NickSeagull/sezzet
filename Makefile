all:
		g++ -std=c++14 -g *.cc *h -o Test.o -lboost_system -lboost_filesystem -lminizip

