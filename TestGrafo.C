#include <iostream>
#include "Grafo.H"
#include "GrafoUtils.H"

using namespace std;

int main()
{
	//creamos el grafo
	//Grafo<TipoDatoNodo,TipoDatoArco>
	Grafo<int,int> g;
	
	
	//insertamos un nodo
	//creamos la info a insertar en el nodo
	int x = 5;
	int z = 6;
	int w = 8;
	//la funcion insertarNodo(NodeInfo) tiene las validaciones necesarias
	//verifica que el nodo no este repetido entre otras cosas.
	g.insertarNodo(x);
	g.insertarNodo(z);
	g.insertarNodo(w);
	
	//buscar un nodo dentro del grafo, Retorna True si se encuentra, False de lo contrario
	//Grafo.buscarNodo(NodeInfo)
	if(g.buscarNodo(x))
	{
		cout<<x<<" esta insertado"<<endl;
	}
	
	//insertamos un arco
	//creamos la info a insertar en el arco
	int y = 0;
	//la funcion insertarArco(ArcInfo,NodeInfoOrigen,NodeInfodestino)
	//verifica que el nodo origen exista, en caso contrario crea ese nodo y lo inserta
	//verifica que el nodo destino exista, en caso contrario crea el nodo y lo inserta
	//verifica que ese arco no exista previamente y lo inserta en el grafo
	g.insertarArco(y,x,z);
	
	//buscar un arco dentro del grafo, Retorna True si se encuentra, False de lo contrario
	//Grafo.buscarArco(ArcInfo,NodeInfoOrigen,NodeInfoDestino)
	if(g.buscarArco(y,x,z))
	{
		cout<<y<<" arco esta insertado"<<endl;
	}
	
	//obtenemos el numero de Nodos
	cout<<"Numero Nodos: "<< g.getNumNodos() <<endl;
	
	//obtenemos el numero de Arcos
	cout<<"Numero Arcos: "<< g.getNumArcos() <<endl;
	

	//eliminamos un Nodo
	g.eliminarNodo(x);
	//g.eliminarArco(y,x,z);

	cout<<"Despues de Eliminar un Nodo"<<endl;
	//obtenemos el numero de Nodos
	cout<<"Numero Nodos: "<< g.getNumNodos() <<endl;
	
	//obtenemos el numero de Arcos
	cout<<"Numero Arcos: "<< g.getNumArcos() <<endl;
	
	
	/*//obtenemos la lista de los nodos que se encuentran en el grafo
	//DNode<NodoGrafo<NodeInfo> >
	DNode<NodoGrafo<int> > listaNodos;
	listaNodos = g.getListaNodos(); //Metodo Recomendado*/
	
	DNode<NodoGrafo<int> > *aux,*aux1;
	aux=g.getListaNodosPuntero();
	aux1=aux->getNext();
	while(aux1 != aux)
	{
		cout<<aux1->getData().getDataNode()<<endl;
		aux1=aux1->getNext();	
	}
	/*
	//obtenemos la lista de arcos que se encuentran en el grafo
	//DNode<ArcoGrafo<ArcInfo,NodeInfo> >
	DNode<ArcoGrafo<int,int> > listaArcos;
	listaArcos = g.getListaArcos(); //Metodo Recomendado*/
	
	
	
	//aplicamos el recorrido en profundidad
	cout<<"Num nodos visitados Profundidad: "<<recorridoProfundidad(g)<<endl;
	
	//aplicamos el recorrido en amplitud
	cout<<"Num nodos visitados Amplitud: "<<recorridoAmplitud(g)<<endl;
	
	
	
	//operador de asignacion
	Grafo<int,int> g1;
	g1 = g;
	if(g1.buscarNodo(w))
	{
		cout<<w<<" esta insertado"<<endl;
	}
	
	return 0;
}

