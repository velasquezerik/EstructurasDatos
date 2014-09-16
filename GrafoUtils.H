#ifndef GRAFOUTILS_H
#define GRAFOUTILS_H

#include <iostream>
#include "Grafo.H"


/**
	@brief Recorrido en profundidad sobre un nodo recursivo
	@param grafo es el grafo sobre el cual se le realiza el recorrido
	@param nodo el cual sera visitado
	@param num numero de nodos visitados hasta el momento
	@return numero de nodos visitados
*/
template <class NodeInfo,class ArcInfo> 
void visitarNodo(Grafo<NodeInfo,ArcInfo> & grafo, NodoGrafo<NodeInfo> & nodo,unsigned int &num)
{
		
	//visitamos el nodo
	grafo.VisitarNodo(nodo.getDataNode());
	num++;
	
	//mostramos la info del Nodo
	std::cout<<nodo.getDataNode()<<std::endl;
	
	//obtenemos los nodos adyacentes a el
	DNode<NodoGrafo<NodeInfo> > * listaNodosAdyacentes;
	
	listaNodosAdyacentes = grafo.getListaNodosAdyacentes(nodo.getDataNode());
	
	if(listaNodosAdyacentes == NULL)
		return;
	
	DNode<NodoGrafo<NodeInfo> > * aux;
	
	
	aux = listaNodosAdyacentes;
	aux = listaNodosAdyacentes->getNext();
	while(aux != listaNodosAdyacentes)
	{
		//si no esta visitado... lo visitamos
		if(!grafo.VisitadoEsteNodo(aux->getData().getDataNode()))
		{
				visitarNodo(grafo,aux->getData(),num);
		}
		
		aux = aux->getNext();
	}
}


/**
	@brief Recorrido en profundidad sobre un Grafo
	@param grafo es el grafo sobre el cual se le realiza el recorrido
	@return numero de nodos visitados
*/
template <class NodeInfo,class ArcInfo> 
int recorridoProfundidad(Grafo<NodeInfo,ArcInfo> & grafo)
{
	unsigned int num = 0;

	//reiniciamos el grafo
	grafo.resetGrafo();
	DNode<NodoGrafo<NodeInfo> > listaNodos;
	listaNodos = grafo.getListaNodos(); //Metodo Recomendado

	if(!listaNodos.isEmpty())
		visitarNodo(grafo,listaNodos.getNext()->getData(),num);


	return num;
}

/**
	@brief Recorrido en amplitud sobre un Grafo
	@param grafo es el grafo sobre el cual se le realiza el recorrido
	@return numero de nodos visitados
*/
template <class NodeInfo,class ArcInfo> 
int recorridoAmplitud(Grafo<NodeInfo,ArcInfo> & grafo)
{
	unsigned int num = 0;
	//cola de arcos
	Queue<NodoGrafo<NodeInfo> > queue;

	//reiniciamos el grafo
	grafo.resetGrafo();
	
	DNode<NodoGrafo<NodeInfo> > listaNodos;
	listaNodos = grafo.getListaNodos(); //Metodo Recomendado
	
	//metemos el primer nodo en la cola
	queue.put(listaNodos.getNext()->getData());
	
	//mientras la cola de arcos no este vacia
	while(!queue.isEmpty())
	{
		//saco el nodo y lo visito
		NodoGrafo<NodeInfo> nodo;
		nodo = queue.front();
		
		grafo.VisitarNodo(nodo.getDataNode());
		num++;
		
		//imprimimos el valor de nodo
		std::cout<<nodo.getDataNode()<<std::endl;
		
		//obtenemos todos sus nodos adyacentes
		DNode<NodoGrafo<NodeInfo> > * listaNodosAdyacentes;
		listaNodosAdyacentes = grafo.getListaNodosAdyacentes(nodo.getDataNode());
			
		//los metemos en la cola
		if(listaNodosAdyacentes != NULL)
		{
			DNode<NodoGrafo<NodeInfo> > * aux;
			aux = listaNodosAdyacentes;
			aux = listaNodosAdyacentes->getNext();
			while(aux != listaNodosAdyacentes)
			{
				//si no esta visitado... lo visitamos y que no este ya en la cola
				if(!grafo.VisitadoEsteNodo(aux->getData().getDataNode()))
				{
						grafo.VisitarNodo(aux->getData().getDataNode());
						queue.put(aux->getData());
				}
				
				aux = aux->getNext();
			}
			
		}
		
	}


	return num;
}


/**
	@brief Recorrido en amplitud sobre un Grafo
	@param grafo es el grafo sobre el cual se le realiza el recorrido
	@return numero de nodos visitados
*/
template <class NodeInfo,class ArcInfo> 
void caminoMinimoDijkstra(Grafo<NodeInfo,ArcInfo> & grafo , NodeInfo & nodoInicio, DNode<NodoGrafo<NodeInfo> > & lista)
{
	unsigned int num = 0;
	//Lista Arcos
	DNode<ArcoGrafo<ArcInfo,NodeInfo> > * ListaArcos;
	
	//reiniciamos el grafo
	grafo.resetGrafo();
	
	//veo si el nodo no ha sido expandido
	if(grafo.ExpandidoEsteNodo(nodoInicio))
	{
		return;
	}
	grafo.ExpandirNodo(nodoInicio);
	DNode<NodoGrafo<NodeInfo> > * nodito = new DNode<NodoGrafo<NodeInfo> >;
	nodito->getData().getDataNode() = nodoInicio;
	lista.insertPrev(nodito);
	ListaArcos = grafo.getListaArcosAdyacentes(nodoInicio); //Metodo Recomendado
	
	//ordenamos los arcos de menor a mayor
	Heap < ArcoGrafo<ArcInfo,NodeInfo> > heap;
	if(ListaArcos != NULL)
	{
		//pasamos todos los elementos al heap
		DNode<ArcoGrafo<ArcInfo,NodeInfo> > *aux,*aux1;
		aux = ListaArcos;
		aux1 = aux->getNext();
		while(aux1 != aux)
		{
			int acu = grafo.acumuladoDeEsteNodo(aux1->getData().getNodoDestino());
			if(acu != -1)
			{
				if(acu > aux1->getData().getDataArc().getValue())
				{
					grafo.aumentarAcumuladoNodo(aux1->getData().getNodoDestino(),aux1->getData().getDataArc().getValue());
				}
			}
			else
			{
				grafo.aumentarAcumuladoNodo(aux1->getData().getNodoDestino(),aux1->getData().getDataArc().getValue());
			}
			heap.insert(aux1->getData());
			aux1 = aux1->getNext();
		}
	}
	
	//mientras la lista de arcos no este vacia
	while(!heap.isEmpty())
	{
		ArcoGrafo<ArcInfo,NodeInfo> arco = heap.deleteMin();
		
		caminoMinimoDijkstra(grafo , arco.getNodoDestino(),lista );
		
	}


}




#endif
