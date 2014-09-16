#include <iostream>
#include "TableHash.H"
using namespace std;

struct Persona
{
	int cedula;
	string nombre;
	
	Persona()
	{
		cedula = 0;
		nombre = "";
	}
	Persona(int ced,string nom)
	{
		cedula = ced;
		nombre = nom;
	}
	bool operator == (Persona & p)
	{
		return (cedula == p.cedula);
	}
	int operator % (int & tam)
	{
		return (cedula%tam);
	}
};

int main()
{
	/*
	 * Es necesario que la clase T tenga los operadores == , = , y % definidos
	*/
	//Definimos la tablaHash de Persona y definimos su tamaño
	TableHash<Persona> table(100);
	
	//insertamos Personas en la tabla
	for(int i = 0; i < 10; i++)
	{
		Persona persona(i*200,"Juan");
		table.insertData(persona);
	}
	
	//buscamos una persona en la tabla
	Persona per(200,"Juan");
	if(table.search(per))
	{
		cout<<"Persona Encontrada"<<endl;
	}
	
	//eliminamos a la persona
	table.deleteData(per);
	if(!table.search(per))
	{
		cout<<"Persona Fue Eliminada"<<endl;
	}

	return 0;
}
