#include <iostream>
#include "ListUtils.H"
using namespace std;

int main()
{
	DList<int> Lista;
	//insertamos elementos
	for(int i = 0; i < 10; i++)
	{
		Lista.insertFirst(i);
	}
	//Utilizamos el iterador
	cout<<"Valores lista"<<endl;
	for(DList<int>::Iterator it(Lista);it.hasCurrent();it.next())
	{
		cout<<it.getCurrent()->getData()<<" ";	
	}
	cout<<endl;
	cout<<"Valores menor de la lista"<<endl;
	cout<<searchMin(Lista)<<endl;
	
	//simpleSort(Lista);
	//quickSort(Lista);
	//mergeSort(Lista);
	sort(Lista);
	cout<<"Valores lista ordenada"<<endl;
	for(DList<int>::Iterator it(Lista);it.hasCurrent();it.next())
	{
		cout<<it.getCurrent()->getData()<<" ";	
	}
	cout<<endl;
	DList<int> lista2;
	//probamos el intercambio entre listas
	lista2.swap(Lista);
	//probamos la asignacion estre listas
	Lista = lista2;
	if(lista2 == Lista)
	{
		cout<<"Listas son iguales"<<endl;
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
