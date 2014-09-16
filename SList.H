/**
	@file SList.H
	@brief Clase Lista Simple enlazada. 
	Lista Simple enlazada circular.
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014

*/

#ifndef SLIST_H
#define SLIST_H

#include <iostream>
#include "SNode.H"

using namespace std;

/**
	@class SList
	@brief Clase Lista Simple enlazada circular
 */
template<class T> class SList
{
	private:
		SNode<T> Node;				//Puntero al siguiente Nodo
		unsigned int size;

		/**
			@brief acceder a un elemento de la lista
			@param pos posicion del elemento a acceder
			@return informacion del elemento
		*/
		T & access(int pos)
		{
			if((pos < 0) or (pos >= size))
			{
				throw BadPos();
			}
			SNode<T> * aux = &Node;
			aux = Node.getNext();
			for(int i = 0;i<pos;i++)
			{
				aux = aux->getNext();
			}
			return aux->getData();
				
		}
	//atributos publicos de la clase
	public:
		/**
			@brief Constructor por omision de la clase 
		*/
		SList()
		{
			size = 0;
		}
		/**
			@brief Destructor por omision de la clase 
		*/
		~SList(){/*Empty*/}
		/**
			@brief insertar un elemento al inicio
			@param node nodo a ser insertado
			@return nada
		*/
		void insertFirst(SNode<T> *node)
		{
			Node.insertNext(node);	
			size++;
		}
		/**
			@brief insertar un elemento al inicio
			@param data valor a ser insertado
			@return nada
		*/
		void insertFirst(T data)
		{
			Node.insertNext(data);	
			size++;
		}
		/**
			@brief devuelve el primer elemento de la lista
			@return el primer elemento de la lista
		*/
		SNode<T>* getFirstNode()
		{
			return Node.getNext();
		}
		/**
			@brief devuelve el primer elemento de la lista
			@return el primer elemento de la lista
		*/
		T & getFirst()
		{
			return Node.getNext()->getData();
		}
		/**
			@brief remueve el primer elemento de la lista
			@return el elemento removido de la lista
		*/
		T removeFirst()
		{
			if(!Node.isEmpty())
			{
				size--;
			}
			return Node.removeNext()->getData();
		}
		/**
			@brief insertar ordenado siguiendo el criterio de menor a mayor
			@param node nodo a ser insertado
			@return nada
		*/
		void orderedInsertion(SNode<T> * node)
		{
			Node.orderedInsertion(node);
			size++;
		}
		/**
			@brief insertar ordenado siguiendo el criterio de menor a mayor
			@param data valor a ser insertado
			@return nada
		*/
		void orderedInsertion(T data)
		{
			Node.orderedInsertion(data);
			size++;
		}
		/**
			@brief obtener la cabecera de  la lista
			@return la cabecera de la lista
		*/
		SNode<T>& getNode()
		{
			return Node;
		}
		/**
			@brief verificamos si esta vacia la lista
			@return True si esta vacia, False en caso contrario
		*/
		bool isEmpty()
		{
			return Node.isEmpty();
		}
		/**
			@brief verificamos si esta vacia la lista
			@return True si esta vacia, False en caso contrario
		*/
		int getSize()
		{
			return size;
		}
		/**
			@brief permite intercambiar los elementos de dos nodos
			@param node,puntero al nodo a intercambiar
			@return nada
		*/
		void swap(SList<T> * node)
		{
			Node.swap(node->getNode());
			std::swap(size,node->size);
		}
		/**
			@brief permite intercambiar los elementos de dos nodos
			@param node,puntero al nodo a intercambiar
			@return nada
		*/
		void swap(SList<T> & node)
		{
			this->swap(&node);
		}
		/**
			@brief sobre carga del operador ==
			@param node nodo a comparar
			@return true si son iguales, false contrario
		*/
		bool operator == (SList<T> & node)
		{
			if(node.size != this->size)
			{
				return false;
			}
			SNode<T> * aux = &Node;
			SNode<T> * bux = &node.Node;
			aux = Node.getNext();
			bux = node.Node.getNext();
			while((aux != &Node) and (bux != &node.Node))
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
		SList<T> & operator = (SList<T> & node)
		{
			if(!isEmpty())
			{
				throw NodeNotUnitarian();
			}
			SNode<T> aux;
			SNode<T> * bux = &node.Node;
			bux = node.Node.getNext();
			while((bux != &node.Node))
			{
				aux.insertNext(bux->getData());
				bux = bux->getNext();
			}
			while(!aux.isEmpty())
			{
				this->insertFirst(aux.removeNext());
			}
			return *this;
		}
		/**
			@brief sobre carga del operador !=
			@param node nodo a comparar
			@return true si son diferentes, false contrario
		*/
		bool operator != (const SList<T> & node)const
		{
			return !(*this == node);
		}
		/**
			@brief sobre carga del operador []
			@param i posicion a buscar
			@return elemento en ese posicion
		*/
		T & operator [] (const int i)
		{
			return access(i);
		}
		/**
			@class Iterator
			@brief Iterador sobre Listas Simples
		 */
		class Iterator
		{

			private:
				SList<T> * list;
				SNode<T> * current;
			public:

				/**
					@brief Constructor por copia de la clase
				*/
				Iterator(SList<T> & l)
				{
					list = &l;
					current=list->getFirstNode();
				}
				/**
					@brief verifico si mi actual es diferente a la cabecera de la lista
					@return True si es distinto a la cabecera, False en caso contrario
				*/
				bool hasCurrent()
				{ 
					return current != &list->getNode(); 
				}
				/**
					@brief obtengo el nodo actual 
					@return el nodo actual 
				*/
				SNode<T> * getCurrent()
				{
					if ( !this->hasCurrent())
						return NULL;

					return current;
				}
				/**
					@brief muevo el iterador al nodo siguiente de la lista
					@return nada
				*/
				void next()
				{
					current = current->getNext();
				}
				/**
					@brief reiniciamos el iterador en el primer elemento de la lista
					@return nada
				*/
				void resetFirst() 
				{ 
					current = list->getNext(); 
				}
		};//fin clase Iterator

};//fin clase SList



#endif 
