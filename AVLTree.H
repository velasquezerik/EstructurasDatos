/**
	@file AVLTree.H
	@brief Clase Arbol Binario Balanceado de Busqueda. 
	Arbol Binario Balanceado de Busqueda (AVL). 
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 8/2014
*/


#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "BinNodeUtils.H"

/**
	@class AVLTree
	@brief Arbol Binario Balanceado de Busqueda
 */
template<class T> class AVLTree
{
	private:
		BinNode<T> *root;				//cabecera o raiz del nodo

	public:
		/**
			@brief Constructor por omision de la clase
		*/
		AVLTree()							//inicializamos el nodo en NULL
		{
			root=NULL;
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
			@brief inserto un nodo en el arbol
			@param Node es el nodo a insertar
			@return retorna NULL en caso de insercion fallida
		*/
		BinNode<T>* insert(BinNode<T>* Node)
		{
			if(Node == NULL)
			{
				throw NullNode();
			}
			return insertAVL(getRoot(),Node);	
		}
		/**
			@brief inserto un valor en el arbol binario
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
			return insertAVL(getRoot(),node);
			
		}
		/**
			@brief remueve un nodo en el arbol
			@param key dato a ser eliminado
			@return retorna NULL en caso de no remover
		*/
		BinNode<T>* remove(T key)
		{
			if(!searchAVL(getRoot(),key))
				return NULL;
			
			return removeFromAVL(getRoot(),key);//remove
		}
		/**
			@brief busca un valor en el arbol
			@param key es el dato a buscar
			@return retorna NULL en caso de no encontrar el valor
		*/
		BinNode<T>* search(T key)
		{
			return searchAVL(getRoot(),key);
		}	
		/**
			@brief destructor por omision de la clase
		*/
		~AVLTree()
		{
			deleteBinNode(root);
		}
	
};//fin clase AVLTree


#endif
