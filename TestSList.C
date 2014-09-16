#include <iostream>
#include "ListUtils.H"
using namespace std;

int main()
{
	SList<int> Lista;
	//insertamos elementos
	for(int i = 0; i < 10; i++)
	{
		Lista.insertFirst(i);
	}
	//Utilizamos el iterador
	cout<<"Valores de la lista"<<endl;
	for(SList<int>::Iterator it(Lista);it.hasCurrent();it.next())
	{
		cout<<it.getCurrent()->getData()<<" ";	
	}
	cout<<endl;
	cout<<"Valores menor de la lista"<<endl;
	cout<<searchMin(Lista)<<endl;
	
	//simpleSort(Lista);
	quickSort(Lista);
	cout<<"Valores ordenados de la lista"<<endl;
	for(SList<int>::Iterator it(Lista);it.hasCurrent();it.next())
	{
		cout<<it.getCurrent()->getData()<<" ";	
	}
	cout<<endl;
	SList<int> lista1;
	//probamos el intercambio entre listas
	lista1.swap(Lista);
	//probamos la asignacion estre listas
	Lista = lista1;
	if(lista1 == Lista)
	{
		cout<<"Las listas son Iguales"<<endl;
	}
	//Probamos los [] sobre la lista
	//OJO esta operacion hace muy lento el acceso a la misma
	for(int i = 0;i < Lista.getSize();i++)
	{
		cout<<Lista[i]<<" ";	
	}
	cout<<endl;
	
	return 0;
}
