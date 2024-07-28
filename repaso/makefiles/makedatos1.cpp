#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

int main()
{
	int posicion;
	int step;
	int i;
	srand(time(0));

    ofstream file("datos1.dat");   // abrir archivo de datos
    
    
	posicion = 0;
	i = 0;
	while(posicion > -100 && posicion <100)
	{
		step = rand()%3 -1;
		posicion += step;
		//cout << i << " "<< posicion << endl;
        file << i << " "<< posicion << endl;    //insertar los datos en el archivo
		i++;                             
	}

    file.close();                         //cerrar el archivo 

return 0;
}
