#include <iostream>
#include "ListUtils.H"
using namespace std;

void printSNode(DNode<int> * node)
{
	cout<<node->getData()<<" ";
}
void imprimirLista(DNode<int> & lista)
{
	DNode<int> * aux = &lista;
	aux = lista.getNext();
	while(aux != &lista)
	{
		cout<<aux->getData()<<" ";
		
		aux = aux->getNext();
	}
	cout<<endl;
}

int main()
{
	
	//prueba del constructor por omision
	DNode<int> node;
	DNode<int> * aux = new DNode<int>;
	cout<<"Valores por omision"<<endl;
	printSNode(&node);cout<<endl;
	printSNode(aux);cout<<endl;
	
	//constructores por copia
	DNode<int> node1(10);
	DNode<int> * aux1 = new DNode<int>(20);
	cout<<"Valores por copia"<<endl;
	printSNode(&node1);cout<<endl;
	printSNode(aux1);cout<<endl;
	
	//insertamos elementos en una lista simple
	DNode<int> lista;
	for(int i = 0; i < 10 ; i++)
	{
		lista.insertNext(i);
	}
	cout<<"Valores lista"<<endl;
	imprimirLista(lista);
	
	//insertamos elementos en una lista simple de manera ordenada
	DNode<int> listaOrdenada;
	for(int i = 0; i < 10 ; i++)
	{
		listaOrdenada.orderedInsertion(i);
	}
	cout<<"Valores lista ordenada"<<endl;
	imprimirLista(listaOrdenada);
	
	//utilizamos el iterador sobre nodo
	for(DNode<int>::Iterator it(&listaOrdenada); it.hasCurrent(); it.next())
	{
		cout<<it.getCurrent()->getData()<<" ";
	}
	cout<<endl;
	
	//simpleSort(lista);
	//quickSort(lista);
	//mergeSort(lista);
	sort(lista);
	cout<<"Valores lista ordenada"<<endl;
	imprimirLista(lista);
	
	cout<<"Valores menor de la lista"<<endl;
	cout<<searchMin(&lista)<<endl;

	delete aux;
	delete aux1;
	return 0;
}
