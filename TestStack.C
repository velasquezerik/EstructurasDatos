#include <iostream>
#include "Stack.H"

using namespace std;


int main()
{
	Stack<int> pilita;

	//insertamos elementos en la pila
	for(int i=0;i<10;i++)
	{
		pilita.push(i);
	}

	//removemos algunos elementos de la pila
	cout<<"Elementos Removidos"<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<pilita.pop()<<" ";
	}
	cout<<endl;

	//removemos todos lo elementos de la pila y los mostramos
	cout<<"Elementos Finales"<<endl;
	while(!pilita.isEmpty())
	{
		cout<<pilita.pop()<<" ";
	}
	cout<<endl;
	
	Stack<int> pila;
	//probamos el intercambio entre pilas
	pila.swap(pilita);
	//probamos la asignacion entre pilas
	pilita = pila;
	if(pilita == pila)
	{
		cout<<"Pila son iguales"<<endl;
	}

	return 0;
}
