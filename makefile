all : graf

graf : main.cpp graf.cpp
	g++ -O2 -std=c++11 -D NDEBUG main.cpp graf.cpp -o graf
	
del :
	rm graf
debug :
	g++ -g main.cpp graf.cpp -o graf_debug 
	gdb graf_debug

view:
	lynx doxygen/html/index.html
