/**
	@file Stack.H
	@brief Clase Pila. 
	Pilas implementadas mediante el uso de listas.
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014

*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "ManejoExcepciones.H"
#include "ListUtils.H"

using namespace std;

/**
	@class Stack
	@brief Pila implementada mediante listas 
 */
template <class T> class Stack
{
	private:
		DNode<T> stack;				//Lista simple que usaremos como pila
		size_t num_ele;				//numero de elementos en la pila
	public:
	/**
		@brief Constructor por omision de la clase
	*/
	Stack()
	{
		num_ele=0;				//iniciamos el numero de elementos en 0
	}
	/**
		@brief Destructor por omision de la clase
	*/
	~Stack()
	{
		while(!stack.isEmpty())
		{
			delete stack.removeNext();
		}
	}
	/**
		@brief inserto un elemento en la pila
		@param data es el elemento a insertar
		@return nada
	*/
	void push(const T data)
	{
		DNode<T>* node;
		try
		{
			node = new DNode<T>(data);
		}
		catch(bad_alloc &e)
		{
			throw NoMemory();
		}
		stack.insertNext(node);
		++num_ele;				//incrementamos el numero de elementos
	}
	/**
		@brief remover el primer elemento en la pila
		@return elemento removido
	*/
	T pop()
	{
		//verificamos que la pila no este vacia
		if(stack.isEmpty())
		{
			throw EmptyStack();
		}
		//removemos el elemento y retornamos el valor
		DNode<T> * aux = stack.removeNext();
		T data = aux->getData();
		--num_ele;				//decrementamos el numero de elementos
		delete aux;
		return data;
	}
	/**
		@brief observamos el primer elemento en la pila
		@return primer elemento 
	*/
	T top()
	{
		//verificamos que la pila no este vacia
		if(stack.isEmpty())
		{
			throw EmptyStack();
		}
		//mostramos el primer elemento
		return stack.getNext()->getData();
	}
	/**
		@brief verifica si la pila  esta vacio
		@return True si esta vacio, False en caso contrario
	*/
	bool isEmpty()
	{
		return stack.isEmpty();			//retornamos si la lista esta vacia
	}
	/**
		@brief ver el numero elementos en la pila
		@return numero de elementos dentro de la pila
	*/
	size_t size() const
	{
		return num_ele;				//retornamos el numero de elementos
	}
	/**
		@brief permite intercambiar los elementos de dos pilas
		@param node,puntero al nodo a intercambiar
		@return nada
	*/
	void swap(Stack<T> * node)
	{
		std::swap(num_ele,node->num_ele);
		stack.swap(node->stack);
	}
	/**
		@brief permite intercambiar los elementos de dos colas
		@param node,puntero al nodo a intercambiar
		@return nada
	*/
	void swap(Stack<T> & node)
	{
		this->swap(&node);
	}
	/**
		@brief sobre carga del operador ==
		@param node nodo a comparar
		@return true si son iguales, false contrario
	*/
	bool operator == (Stack<T> & node)
	{
		if(node.num_ele != this->num_ele)
		{
			return false;
		}
		DNode<T> * aux = &stack;
		DNode<T> * bux = &node.stack;
		aux = stack.getNext();
		bux = node.stack.getNext();
		while((aux != &stack) and (bux != &node.stack))
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
	Stack<T> & operator = (Stack<T> & node)
	{
		if(!isEmpty())
		{
			throw NotEmptyStack();
		}
		num_ele = node.num_ele;
		DNode<T> * bux = &node.stack;
		bux = node.stack.getNext();
		while((bux != &node.stack))
		{
			stack.insertPrev(bux->getData());
			bux = bux->getNext();
		}
		return *this;
	}
	/**
		@brief sobre carga del operador !=
		@param node nodo a comparar
		@return true si son diferentes, false contrario
	*/
	bool operator != (const Stack<T> & node)const
	{
		return !(*this == node);
	}
};//fin clase Stack


#endif
