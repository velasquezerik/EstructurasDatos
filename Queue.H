/**
	@file Queue.H
	@brief Clase Cola usando como principal las listas dobles. 
	Clase cola
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014

*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "ManejoExcepciones.H"
#include "DNode.H"

using namespace std;

/**
	@class Queue
	@brief Cola implementada mediante listas dobles
 */
template <class T> class Queue
{
	private:
		DNode<T> cola;				//lista doble que usaremos para emular la cola
		size_t num_ele;				//numero de elementos en la cola
	public:
	/**
		@brief Constructor por omision de la clase 
	*/
	Queue()
	{
		num_ele=0;				//inicializamos elementos en cola 0
	}
	/**
		@brief Destructor por omision de la clase
	*/
	~Queue()
	{
		while(!cola.isEmpty())
		{
			delete cola.removeNext();
		}
	}
	/**
		@brief insertar un elemento en la cola
		@param data elemento a ser insertado
		@return nada
	*/
	void put(const T data)
	{
		DNode<T> * node;
		try
		{
			node = new DNode<T>(data);
		}
		catch(bad_alloc &e)
		{
			throw NoMemory();
		}
		//insertamos el nodo en la lista que emula la cola
		cola.insertNext(node);
		++num_ele;				//incrementamos el numero de elementos en cola
	}
	/**
		@brief removemos el primer elemento de la cola
		@return el primer elemento de la cola
	*/
	T  front()
	{
		//verificamos que la cola no este vacia
		if(cola.isEmpty())
		{
			throw EmptyQueue();
		}
		--num_ele;				//decrementamos el numero de elementos
		DNode<T> * aux = cola.removePrev();
		T data = aux->getData();
		delete aux;
		//removemos el primer nodo y retornamos el valor
		return data;
	}
	/**
		@brief observamos el primer elemento de la cola
		@return el primer elemento de la cola
	*/
	T get()
	{
		//verificamos que la cola no este vacia
		if(cola.isEmpty())
		{
			throw EmptyQueue();
		}
		//mostramos el primer valor de la cola
		return cola.getPrev()->getData();
	}
	/**
		@brief verifica si la cola esta vacia
		@return True si la cola esta vacia, False en caso contrario
	*/
	bool isEmpty()
	{
		return cola.isEmpty();			//retornamos si la lista esta vacia
	}
	/**
		@brief vemos el numero de elementos que posee la cola
		@return numero de elementos que posee la cola >=0
	*/
	size_t size() const
	{
		return num_ele;				//retornamos el numero de elementos
	}
	/**
		@brief permite intercambiar los elementos de dos colas
		@param node,puntero al nodo a intercambiar
		@return nada
	*/
	void swap(Queue<T> * node)
	{
		std::swap(num_ele,node->num_ele);
		cola.swap(node->cola);
	}
	/**
		@brief permite intercambiar los elementos de dos colas
		@param node,puntero al nodo a intercambiar
		@return nada
	*/
	void swap(Queue<T> & node)
	{
		this->swap(&node);
	}
	/**
		@brief sobre carga del operador ==
		@param node nodo a comparar
		@return true si son iguales, false contrario
	*/
	bool operator == (Queue<T> & node)
	{
		if(node.num_ele != this->num_ele)
		{
			return false;
		}
		DNode<T> * aux = &cola;
		DNode<T> * bux = &node.cola;
		aux = cola.getNext();
		bux = node.cola.getNext();
		while((aux != &cola) and (bux != &node.cola))
		{
			if(aux->getData() != bux->getData())
			{
				return false;
			}
			aux = aux->getNext();
			bux = bux->getNext();
		}
		return true;
	}
	/**
		@brief sobre carga del operador =
		@param v vector a copiar
		@return la copia del vector
	*/
	Queue<T> & operator = (Queue<T> & node)
	{
		if(!isEmpty())
		{
			throw NotEmptyQueue();
		}
		num_ele = node.num_ele;
		DNode<T> * bux = &node.cola;
		bux = node.cola.getNext();
		while((bux != &node.cola))
		{
			cola.insertPrev(bux->getData());
			bux = bux->getNext();
		}
		return *this;
	}
	/**
		@brief sobre carga del operador !=
		@param node nodo a comparar
		@return true si son diferentes, false contrario
	*/
	bool operator != (const Queue<T> & node)const
	{
		return !(*this == node);
	}
};//fin clase Queue




#endif
