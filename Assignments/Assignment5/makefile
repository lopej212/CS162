lib: libMain.o Album.o Book.o Movie.o Patron.o LibraryItem.o Library.o
	g++ -g libMain.o Album.o Book.o Movie.o Patron.o LibraryItem.o Library.o -o lib 

libMain.o: libMain.cpp Library.hpp
	g++ -c libMain.cpp

Album.o: Album.cpp Album.hpp LibraryItem.hpp
	g++ -c Album.cpp

Book.o: Book.cpp Book.hpp LibraryItem.hpp
	g++ -c Book.cpp

Movie.o: Movie.cpp Movie.hpp LibraryItem.hpp
	g++ -c Movie.cpp

Patron.o: Patron.cpp Patron.hpp LibraryItem.hpp
	g++ -c Patron.cpp

LibraryItem.o: LibraryItem.cpp Library.hpp 
	g++ -c LibraryItem.cpp

Library.o: Library.cpp Library.hpp Book.hpp Album.hpp Movie.hpp Patron.hpp
	g++ -c Library.cpp

clean:
	rm -f *.o
