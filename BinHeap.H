/**
	@file BinHeap.H
	@brief Clase Monticulo Binario
	Monticulo Binario o Heap
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 8/2014
*/

#ifndef BINHEAP_H
#define BINHEAP_H

#include <iostream>
#include "BinNodeUtils.H"

/**
	@class BinHeap
	@brief Monticulo Binario
 */
template<class T> class BinHeap
{
	private:
		BinNode<T> *root;		//cabecera o raiz del nodo
		unsigned int type;		//Heap de Minimos o Maximos (0=Minimo,1=Maximo)

	public:
		/**
			@brief Constructor por omision de la clase
		*/
		BinHeap(unsigned int type = 0)							//inicializamos el nodo en NULL
		{
			if(type != 0 and type != 1)
			{
				throw NotTypeHeap();
			}
			root=NULL;
			this->type = type;
		}
		/**
			@brief Constructor por copia de la clase
		*/
		BinHeap(Vector<T> &heap,unsigned int type = 0)							//inicializamos el nodo en NULL
		{
			if(type != 0 and type != 1)
			{
				throw NotTypeHeap();
			}
			root = buildABHeap(heap,1,heap.getSize());
			this->type = type;
		}
		/**
			@brief Obtenemos la raiz del arbol
			@return puntero de la raiz BinNode<T>* 
		*/
		BinNode<T>*& getRoot()				//retornamos la raiz del arbol
		{
			return root;
		}
		/**
			@brief inserto un nodo en el monticulo
			@param Node es el nodo a insertar
			@return retorna NULL en caso de insercion fallida
		*/
		BinNode<T>* insert(BinNode<T>* Node)
		{
			if(Node == NULL)
			{
				throw NullNode();
			}
			if(type == 0)
			{
				return insertHeapMin(getRoot(),Node);	
			}
			else
			{
				return insertHeapMax(getRoot(),Node);	
			}
			
		}
		/**
			@brief inserto un valor en el monticulo
			@param data es el valor a insertar
			@return retorna NULL en caso de insercion fallida
		*/
		BinNode<T>* insert(T data)
		{
			BinNode<T> * node;
			try
			{
				node = new BinNode<T>(data);
			}
			catch(bad_alloc &e)
			{
				throw NoMemory();
			}
			return this->insert(node);
		}
		/**
			@brief remueve un nodo en el monticulo
			@param key dato a ser eliminado
			@return retorna NULL en caso de no remover
		*/
		BinNode<T>* remove(T key)
		{
			return removeFromHeap(getRoot(),key);//remove
		}
		/**
			@brief busca un valor en el monticulo
			@param key es el dato a buscar
			@return retorna NULL en caso de no encontrar el valor
		*/
		BinNode<T>* search(T key)
		{
			return searchHeap(getRoot(),key);
		}	
		/**
			@brief destructor por omision de la clase
		*/
		~BinHeap()
		{
			deleteBinNode(root);
		}
	
};//fin clase BinHeap


#endif
