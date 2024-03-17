#include <iostream>
#include <fstream>

using namespace std;

int main() {

  //abrir un archivo en write mode      //std::
  ofstream outfile;
  outfile.open("misdatosEULER.dat");

  
  
  std::cout << "Hello World en cpp en mybinder\n";

  int N = 300;

  float arr_y[N];         //vector y
  arr_y[0] = 1 ;           //valor inicial de y

  float val_inicial = 0;
  float val_final= 6;
  float h = (val_final - val_inicial) / N ;
  std::cout << "el valor de h es: " << h << " \n";  

  std::cout << "------------------- VECTOR TIEMPO" << " \n";  
  float arr_t[N];             //defino el arreglo t
  for (int i = 0; i<N; i++){
    //cout << "valor del indice " << i << " \n";
    arr_t[i] = val_inicial + i * h ;
    //std::cout << arr_t[i] << " \n";
  
  //AHORA DESEO LLENAR EL VECTOR DE Y arra_y
  //std::cout << "------------------ VECTOR Y" << " \n";
  //std::cout << arr_y[0] << " \n";
  //std::cout << arr_y[200] << " \n";
  
    //std::cout << "valor del indice " << i << " \n";
    arr_y[i+1] = arr_y[i] - h * arr_y[i] ;
    //std::cout << arr_y[i] << " \n";


    //INSERTAR LOS VALORES CALCULADOS AL .DAT
    outfile << arr_t[i] << "," << arr_y[i] << std::endl;

    //break;
  }
  
  //cerrar el archivo antes abierto
  outfile.close(); 
    
                            //AHORA PROCEDO A HACER EL RUNGE KUTTA 
    
    outfile.open("misdatosRunge.dat");

    
    cout << "------------------- VECTOR TIEMPO" << " \n";  
    //float arr_t[N];             //defino el arreglo t
    
    for (int i = 0; i<N; i++) {
        //cout << i << endl;
        
        arr_t[i] = val_inicial + i * h ;
        
        float k1 = h * -arr_y[i] ;
        float k2 = h * -( arr_y[i] + k1/2) ;
        float k3 = h * -( arr_y[i] + k2/2 ) ;
        float k4 = h * -(arr_y[i] + k3) ;
        
        arr_y[i+1] = arr_y[i] + (1.0/6)*(k1 + 2*k2 + 2*k3 + k4) ; 
        
        //cout << arr_y[i] << endl;
        //cout << arr_y[i+1] << endl;
        
        outfile << arr_t[i] << "," << arr_y[i] << endl;
        
        
        //break;
    }
    
    
    
    outfile.close();   //cerrar el archivo que hicimos antes misdatosRunde.dat
    
    
    
    
    
    
}
  