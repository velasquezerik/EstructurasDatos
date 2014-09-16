/**
	@file DList.H
	@brief Clase Lista Doble enlazada. 
	Lista Doble enlazada circular.
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014

*/
#ifndef DLIST_H
#define DLIST_H


#include <iostream>
#include "DNode.H"

using namespace std;

/**
	@class DList
	@brief Clase Lista Doble enlazada circular
 */
template<class T> class DList
{
	private:
		DNode<T> Node;				//Puntero al siguiente Nodo
		size_t size;
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
			DNode<T> * aux = &Node;
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
		DList()
		{
			size = 0;
		}
		/**
			@brief Destructor por omision de la clase 
		*/
		~DList(){/*Empty*/}
		/**
			@brief insertar un elemento al inicio
			@param node nodo a ser insertado
			@return nada
		*/
		void insertFirst(DNode<T> *node)
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
			@brief insertar un elemento al final
			@param node nodo a ser insertado
			@return nada
		*/
		void insertLast(DNode<T> *node)
		{
			Node.insertPrev(node);	
			size++;
		}
		/**
			@brief insertar un elemento al final
			@param data valor a ser insertado
			@return nada
		*/
		void insertLast(T data)
		{
			Node.insertPrev(data);	
			size++;
		}
		/**
			@brief devuelve el primer elemento de la lista
			@return el primer elemento de la lista
		*/
		DNode<T>* getFirstNode()
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
			@brief devuelve el ultimo elemento de la lista
			@return el ultimo elemento de la lista
		*/
		DNode<T>* getLastNode()
		{
			return Node.getPrev();
		}
		/**
			@brief devuelve el ultimo elemento de la lista
			@return el ultimo elemento de la lista
		*/
		T & getLast()
		{
			return Node.getPrev()->getData();
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
			@brief remueve el ultimo elemento de la lista
			@return el elemento removido de la lista
		*/
		T removeLast()
		{
			if(!Node.isEmpty())
			{
				size--;
			}
			return Node.removePrev()->getData();
		}
		/**
			@brief insertar ordenado siguiendo el criterio de menor a mayor
			@param node nodo a ser insertado
			@return nada
		*/
		void orderedInsertion(DNode<T> * node)
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
		DNode<T>& getNode()
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
		void swap(DList<T> * node)
		{
			Node.swap(node->getNode());
			std::swap(size,node->size);
		}
		/**
			@brief permite intercambiar los elementos de dos nodos
			@param node,puntero al nodo a intercambiar
			@return nada
		*/
		void swap(DList<T> & node)
		{
			this->swap(&node);
		}
		/**
			@brief sobre carga del operador ==
			@param node nodo a comparar
			@return true si son iguales, false contrario
		*/
		bool operator == (DList<T> & node)
		{
			if(node.size != this->size)
			{
				return false;
			}
			DNode<T> * aux = &Node;
			DNode<T> * bux = &node.Node;
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
		DList<T> & operator = (DList<T> & node)
		{
			if(!isEmpty())
			{
				throw NodeNotUnitarian();
			}
			DNode<T> * bux = &node.Node;
			bux = node.Node.getNext();
			while((bux != &node.Node))
			{
				this->insertLast(bux->getData());
				bux = bux->getNext();
			}
			return *this;
		}
		/**
			@brief sobre carga del operador !=
			@param node nodo a comparar
			@return true si son diferentes, false contrario
		*/
		bool operator != (const DList<T> & node)const
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
				DList<T> * list;
				DNode<T> * current;
			public:

				/**
					@brief Constructor por copia de la clase
				*/
				Iterator(DList<T> & l)
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
				DNode<T> * getCurrent()
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
					@brief muevo el iterador al nodo anterior de la lista
					@return nada
				*/
				void prev()
				{
					current = current->getPrev();
				}
				/**
					@brief reiniciamos el iterador en el primer elemento de la lista
					@return nada
				*/
				void resetFirst() 
				{ 
					current = list->getNext(); 
				}
				/**
					@brief reiniciamos el iterador en el ultimo elemento de la lista
					@return nada
				*/
				void resetLast() 
				{ 
					current = list->getPrev(); 
				}
		};//fin clase Iterator

};//fin clase DList




#endif
