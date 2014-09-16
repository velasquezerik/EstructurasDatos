/**
	@file SNode.H
	@brief Clase Nodo simple. 
	Nodo Simple enlazado circular.
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014

*/

#ifndef SNODE_H
#define SNODE_H

#include <iostream>
#include "ManejoExcepciones.H"

using namespace std;

/**
	@class Snode
	@brief Nodo simple enlazado circular
 */
template<class T> class SNode
{
	private:
		T data;						//Dato a almacenar en el nodo
		SNode<T> *next;				//Puntero al siguiente Nodo
	//atributos publicos de la clase
	public:
	/**
		@brief Constructor por omision de la clase SNode
	*/
	SNode()
	{
		next=this;
	}
	/**
		@brief Destructor por omision de la clase SNode
	*/
	~SNode()
	{
		while(!this->isEmpty())
		{
			delete this->removeNext();
		}
	}
	/**
		@brief Constructor por copia de la clase SNode
	*/
	SNode(const T dat)
	{
		data=dat;
		next=this;
	}
	/**
		@brief obtener el valor del dato
		@return el dato almacenado en el nodo
	*/
	T& getData()
	{
		if(this == NULL)
		{
			throw NullNode();
		}
		return data;	
	}
	/**
		@brief reseteamos el nodo
		@return nada
	*/
	void reset()
	{
		if(this == NULL)
		{
			throw NullNode();
		}
		next = this;
	}
	/**
		@brief verificamos si esta vacia la lista
		@return True si esta vacia, False en caso contrario
	*/
	bool isEmpty()
	{
		if(this == NULL)
		{
			throw NullNode();
		}
		return (next == this);
	}
	
	/**
		@brief obtener el siguiente nodo
		@return el puntero del siguiente nodo
	*/
	SNode<T>*& getNext()
	{	
		if(this == NULL)
		{
			throw NullNode();
		}
		return next;	
	}

	/**
		@brief inserto un nodo
		@param node nodo a insertar
		@return nada
	*/
	void insertNext(SNode<T> * node)
	{
		if(this == NULL)
		{
			throw NullNode();
		}
		if(node == NULL)
		{
			throw NullNode();
		}
		if(!node->isEmpty())
		{
			throw NodeNotUnitarian();
		}
		node->next = this->next;		//siguiente del nodo a insertar sera el siguiente de mi nodo actual
		this->next = node;				//el siguiente de mi nodo actual sera el nodo a insertar
	}
	/**
		@brief inserto un nodo
		@param node nodo a insertar
		@return nada
	*/
	void insertNext(const T data)
	{
		SNode<T> * node;
		try
		{
			node = new SNode<T>(data);
		}
		catch(bad_alloc &e)
		{
			throw NoMemory();
		}
		this->insertNext(node);
	}
	/**
		@brief inserto una lista despues de this
		@param list lista a insertar a insertar
		@return nada
	*/
	void concatList(SNode<T> * list)
	{
		if(list == NULL)
		{
			throw NullNode();
		}
		SNode<T> aux;
		while(!list->isEmpty())
		{
			aux.insertNext(list->removeNext());
		}
		while(!aux.isEmpty())
		{
			this->insertNext(aux.removeNext());
		}
	}
		/**
		@brief inserto una lista despues de this
		@param list lista a insertar a insertar
		@return nada
	*/
	void concatList(SNode<T> & list)
	{
		this->concatList(&list);
	}
	/**
		@brief remover el siguiente nodo
		@return nodo que fue removido
	*/
	SNode<T>* removeNext()
	{
		if(this == NULL)
		{
			throw NullNode();
		}
		if(this->isEmpty())
		{
			throw NodeUnitarian();
		}
		SNode<T> *aux;					//definimos un nodo auxiliar donde se almacenara la informacion para no perderla
		aux = this->next;				//nodo aux sera el siguiente a mi nodo actual
		this->next = aux->next;			//el siguiente de mi nodo actual sera el siguiente aux
		aux->reset();					//reseteo el nodo aux y queda eliminado de la lista
		return aux;
	}

	/**
		@brief insertar ordenado siguiendo el criterio de menor a mayor
		@param node nodo a ser insertado
		@return nada
	*/
	void orderedInsertion(SNode<T> *node)
	{
		if(this == NULL)
		{
			throw NullNode();
		}
		if(node == NULL)
		{
			throw NullNode();
		}
		if(!node->isEmpty())
		{
			throw NodeNotUnitarian();
		}
		SNode<T> *aux;
		SNode<T> *aux2;
		aux = this;									//obtengo el siguiente nodo a mi nodo actual
		aux2 = aux;
		aux = aux->getNext();						//mantengo una referencia a mi nodo actual
		while(aux != this)							//mientras mi nodo siguiente no sea mi nodo actual
		{
			if( node->getData() < aux->getData())	//verifico que el dato de mi nodo a insertar sea menor al nodo siguiente
			{
				
				aux2->insertNext(node);				//inserto y termino el metodo
				return;
			}
			aux2 = aux;								//me muevo al siguiente nodo de la lista
			aux = aux->getNext();
		}
		aux2->insertNext(node);						//inserto el nodo en la ultima posicion de la lista		
	}
	/**
		@brief insertar ordenado siguiendo el criterio de menor a mayor
		@param node nodo a ser insertado
		@return nada
	*/
	void orderedInsertion(const T data)
	{
		SNode<T> * node;
		try
		{
			node = new SNode<T>(data);
		}
		catch(bad_alloc &e)
		{
			throw NoMemory();
		}
		this->orderedInsertion(node);
	}
	/**
		@brief sobre carga del operador ==
		@param node nodo a comparar
		@return true si son iguales, false contrario
	*/
	bool operator == (const SNode<T> & node)const
	{
		if(this->data != node.data)
		{
			return false;
		}
		if(this->next != node.next)
		{
			return false;
		}
		return true;
	}
	/**
		@brief sobre carga del operador =
		@param v vector a copiar
		@return la copia del vector
	*/
	const SNode<T> & operator = (const SNode<T> & node)
	{
		if(!isEmpty())
		{
			throw NodeNotUnitarian();
		}
		this->data = node.data;
		this->next = node.next;
		return *this;
	}
	/**
		@brief sobre carga del operador !=
		@param node nodo a comparar
		@return true si son diferentes, false contrario
	*/
	bool operator != (const SNode<T> & node)const
	{
		return !(*this == node);
	}
	/**
		@brief permite intercambiar los elementos de dos nodos
		@param node,puntero al nodo a intercambiar
		@return nada
	*/
	void swap(SNode<T> * node)
	{
		if(this == NULL)
		{
			throw NullNode();
		}
		if(node == NULL)
		{
			throw NullNode();
		}
		if(node->isEmpty() and isEmpty())
		{
			return;
		}
		if(isEmpty())
		{
			SNode<T> aux;
			while(!node->isEmpty())
			{
				aux.insertNext(node->removeNext());
			}
			while(!aux.isEmpty())
			{
				this->insertNext(aux.removeNext());
			}
			return;
		}
		if(node->isEmpty())
		{
			SNode<T> aux;
			while(!isEmpty())
			{
				aux.insertNext(this->removeNext());
			}
			while(!aux.isEmpty())
			{
				node->insertNext(aux.removeNext());
			}
			return;
		}
		SNode<T> aux;
		while(!isEmpty())
		{
			aux.insertNext(this->removeNext());
		}
		SNode<T> aux1;
		while(!node->isEmpty())
		{
			aux1.insertNext(node->removeNext());
		}
		while(!aux.isEmpty())
		{
			this->insertNext(aux.removeNext());
		}
		while(!aux1.isEmpty())
		{
			node->insertNext(aux1.removeNext());
		}
	}
	/**
		@brief permite intercambiar los elementos de dos nodos
		@param node,puntero al nodo a intercambiar
		@return nada
	*/
	void swap(SNode<T> &node)
	{
		this->swap(&node);
	}
/**
	@class Iterator
	@brief Iterador sobre Nodos simples enlazados circulares
 */
	class Iterator
	{
		private:
			SNode<T> * head;				//puntero a la cabecera de la lista
			SNode<T> * curr;				//puntero al nodo actual
		public:

			/**
				@brief Constructor por omision de la clase
			*/
			Iterator()
			{
				head = curr = NULL;
			}
			/**
				@brief Constructor por copia de nodo cabecera 
			*/
			Iterator(SNode<T> * head_ptr)
			{
				if(head_ptr == NULL)
				{
					throw NullNode();
				}
				head = head_ptr;
				curr = head->getNext();
			}
			/**
				@brief Constructor por copia de nodo cabecera 
			*/
			Iterator(SNode<T> & head_ptr)
			{
				head = &head_ptr;
				curr = head->getNext();
			}
			/**
				@brief Constructor por copia 
			*/
			Iterator(SNode<T> * head_ptr, SNode<T> * curr_ptr)
			{
				if(head_ptr == NULL)
				{
					throw NullNode();
				}
				if(curr_ptr == NULL)
				{
					throw NullNode();
				}
				head = head_ptr;
				curr = curr_ptr;
			}
			/**
				@brief Constructor por copia de otro iterador 
			*/
			Iterator(const Iterator &  itor)
			{
				head = itor.head;
				curr = itor.curr;
			}
			/**
				@brief Sobre escritura del operador igual (=)
				@param itor iterador a copiar
				@return la copia del iterador
			*/
			Iterator & operator = (const Iterator & itor)
			{
				if (this == &itor)
				{
					return *this;
				}
				head = itor.head;
				curr = itor.curr;
				
				return *this;
			}
			/**
				@brief Sobre escritura del operador igual (=)
				@param head_ptr
				@return la copia del iterador
			*/
			Iterator & operator = (SNode<T> * head_ptr)
			{
				if(head_ptr == NULL)
				{
					throw NullNode();
				}
				head = head_ptr;
				curr = head->getNext();
				return *this;
			}
			/**
				@brief reiniciamos el iterador en el primer elemento de la lista
				@return nada
			*/
			void resetFirst()
			{
				curr = head->getNext();
			}
			/**
				@brief defino cual es el elemento actual
				@param new_curr nodo que sera actual
				@return nada
			*/
			void setCurrent(SNode<T> * new_curr)
			{
				if(new_curr == NULL)
				{
					throw NullNode();
				}
				curr = new_curr;
			}
			/**
				@brief reseteo el iterador
				@return nada
			*/
			void reset(SNode<T> * new_head, SNode<T> * new_curr)
			{
				if(new_head == NULL)
				{
					throw NullNode();
				}
				if(new_curr == NULL)
				{
					throw NullNode();
				}
				head = new_head;
				curr = new_curr;
			}
			/**
				@brief reseteo el iterador
				@return nada
			*/
			void reset(SNode<T> * new_head)
			{
				if(new_head == NULL)
				{
					throw NullNode();
				}
				head = new_head;
				curr = head->getNext();;
			}
			/**
				@brief verifico si mi actual es diferente a la cabecera de la lista
				@return True si es distinto a la cabecera, False en caso contrario
			*/
			bool hasCurrent() const
			{
				return (curr != head);
			}
			/**
				@brief obtengo el nodo actual 
				@return el nodo actual 
			*/
			SNode<T> * getCurrent()
			{
				if (hasCurrent())
				{
					return curr;
				}
				return NULL;
			}
			/**
				@brief verifico si estoy en el primer nodo de la lista
				@return True si estoy en el primer nodo, False en caso contrario
			*/
			bool isInFirst() const 
			{ 
				return (curr == head->next); 
			}
			/**
				@brief muevo el iterador al nodo siguiente de la lista
				@return nada
			*/
			void next()
			{
				curr = curr->getNext();
			}
			/**
				@brief definimos el operador de comparacion (==)
				@return True si son iguales, False en caso contrario
			*/
			bool operator == (const Iterator & it) const 
			{ 
				return curr == it.curr; 
			}
			/**
				@brief definimos el operador distinto (!=)
				@return True si son distintos, False en caso contrario
			*/
			bool operator != (const Iterator & it) const 
			{ 
				return curr != it.curr; 
			}
			/**
				@brief remuevo el elemento actual de la lista
				@return puntero del elemento eliminado
			*/
			SNode<T> * del()
			{							
				SNode<T> * current = getCurrent();
				next();							
				current->del();			
				return current;
			}
	};//fin clase Iterator

};//fin clase SNode

#endif 
