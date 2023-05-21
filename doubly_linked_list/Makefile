run: build/main.exe
	./build/main.exe

build/main.exe: src/main.cpp
	g++ -std=c++17 -Iinclude src/main.cpp -o build/main.exe

clean:
	rm build/*.exe
