all:
		g++ -std=c++14 -g *.cc *h -o Test.o -Iinclude/libarchive -Llib/libarchive -lboost_system -lboost_filesystem -llibarchive

