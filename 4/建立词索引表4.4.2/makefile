object=hstring.o main.o
test:$(object)
	cc -o test $(object)
hstring.o:hstring.h all.h hstring.cpp
	cc -c hstring.cpp
main.o:main.cpp
	cc -c main.cpp
clean:
	rm $(object)
	