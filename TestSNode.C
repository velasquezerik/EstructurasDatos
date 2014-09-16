#include <iostream>
#include "ListUtils.H"
using namespace std;

void printSNode(SNode<int> * node)
{
	cout<<node->getData()<<" ";
}
void imprimirLista(SNode<int> & lista)
{
	SNode<int> * aux = &lista;
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
	SNode<int> node;
	SNode<int> * aux = new SNode<int>;
	cout<<"Valores por omision"<<endl;
	printSNode(&node);cout<<endl;
	printSNode(aux);cout<<endl;
	
	//constructores por copia
	SNode<int> node1(10);
	SNode<int> * aux1 = new SNode<int>(20);
	cout<<"Valores por copia"<<endl;
	printSNode(&node1);cout<<endl;
	printSNode(aux1);cout<<endl;
	
	//insertamos elementos en una lista simple
	SNode<int> lista;
	for(int i = 0; i < 10 ; i++)
	{
		lista.insertNext(i);
	}
	cout<<"Valores de la lista"<<endl;
	imprimirLista(lista);
	
	//insertamos elementos en una lista simple de manera ordenada
	SNode<int> listaOrdenada;
	for(int i = 0; i < 10 ; i++)
	{
		listaOrdenada.orderedInsertion(i);
	}
	cout<<"Valores de lista Ordenada"<<endl;
	imprimirLista(listaOrdenada);
	
	//utilizamos el iterador sobre nodo
	cout<<"Valores lista ordenada usando iterador"<<endl;
	for(SNode<int>::Iterator it(&listaOrdenada); it.hasCurrent(); it.next())
	{
		cout<<it.getCurrent()->getData()<<" ";
	}
	cout<<endl;
	
	cout<<"Valores lista ordenada"<<endl;
	simpleSort(lista);
	//quickSort(lista);
	
	imprimirLista(lista);
	
	cout<<"Valores minimo de la lista"<<endl;
	cout<<searchMin(&lista)<<endl;	
	
	delete aux;
	delete aux1;
	return 0;
}
