object=hstring.o main.o list.o
test:$(object)
	cc -o test $(object)
hstring.o:hstring.h all.h hstring.cpp
	cc -c hstring.cpp
main.o:main.cpp
	cc -c main.cpp
list.o:list.h all.h list.cpp
	cc -c list.cpp
clean:
	rm $(object)
	