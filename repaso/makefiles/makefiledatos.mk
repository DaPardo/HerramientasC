all: plot.pdf plot1.pdf

plot.pdf: plotdatos.py datos.dat makedatos.py
	python3 plotdatos.py


plot1.pdf: plotdatos1.py datos1.dat makedatos1.cpp
	python3 plotdatos1.py

datos.dat: makedatos.py
	python3 makedatos.py

datos1.dat: makedatos1.cpp
	g++ makedatos1.cpp -o makedatos1
	./makedatos1


