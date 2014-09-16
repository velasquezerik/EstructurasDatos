#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	
	if(argc != 3)
	{
		cout<<"Error: <nombreArchivo> <cantidadDatos>"<<endl;
		return 1;
	}
	string nombreArchivo = argv[1];
	int cantidadDatos = atoi(argv[2]);
	cout<<"Nombre Archivo: "<<argv[1]<<endl<<"Cantidad de datos: "<<argv[2]<<endl;
	if(cantidadDatos < 1)
	{
		cout<<"Error: Cantidad Negativa"<<endl;
		return 1;
	}
	
	ofstream arch;
	clock_t ini;
	clock_t fin;
	arch.open(nombreArchivo.c_str());
	if(!arch)
	{
		cout<<"Error: NO Abrio el archivo "<<nombreArchivo<<endl;
	}
	else
	{
		ini = clock();
		for(int i = 0; i < cantidadDatos; i++)
		{
			arch<<rand()<<endl;
		}
		
		arch.close();
		fin = clock();
	}
	
	cout<<"Tiempo: "<<(fin - ini)/1000<<" ms"<<endl;
	
	return 0;
}
