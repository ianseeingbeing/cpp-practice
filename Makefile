app.out: main.cpp include/calculations.cpp
	g++ main.cpp include/calculations.cpp -o app.out

clean:
	rm app.out