#include <iostream>
#include "Queue.H"

using namespace std;


int main()
{
	Queue<int> colita;

	//insertamos elementos en la cola
	for(int i=0;i<10;i++)
	{
		colita.put(i);
	}

	//removemos algunos elementos de la cola
	cout<<"Elementos Removidos"<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<colita.front()<<" ";
	}
	cout<<endl;

	//removemos todos lo elementos de la cola y los mostramos
	cout<<"Elementos Finales"<<endl;
	while(!colita.isEmpty())
	{
		cout<<colita.front()<<" ";
	}
	cout<<endl;
	
	Queue<int> cola;
	//probamos el intercambio entre colas
	cola.swap(colita);
	//probamos la asignacion estre colas
	colita = cola;
	if(colita == cola)
	{
		cout<<"Cola son iguales"<<endl;
	}
	return 0;
}
