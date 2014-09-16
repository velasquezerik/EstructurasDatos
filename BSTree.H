/**
	@file BSTree.H
	@brief Clase Arbol Binario de Busqueda. 
	Arbol Binario de Busqueda (ABB). 
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014, 8/2014
*/

#ifndef BSTREE_H
#define	BSTREE_H

#include <iostream>
#include "BinNodeUtils.H"

/**
	@class BSTree
	@brief Arbol Binario de Busqueda
 */
template<class T> class BSTree
{

	private:
		BinNode<T> *root;				//cabecera o raiz del nodo

	public:
		/**
			@brief Constructor por omision de la clase
		*/
		BSTree()							//inicializamos el nodo en NULL
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
			return insertABB(getRoot(),Node);	
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
			return insertABB(getRoot(),node);
			
		}
		/**
			@brief remueve un nodo en el arbol
			@param key dato a ser eliminado
			@return retorna NULL en caso de no remover
		*/
		BinNode<T>* remove(T key)
		{
			if(!searchABB(getRoot(),key))
				return NULL;
			
			return removeFromABB(getRoot(),key);//remove
		}
		/**
			@brief busca un valor en el arbol
			@param key es el dato a buscar
			@return retorna NULL en caso de no encontrar el valor
		*/
		BinNode<T>* search(T key)
		{
			return searchABB(getRoot(),key);
		}	
		/**
			@brief destructor por omision de la clase
		*/
		~BSTree()
		{
			deleteBinNode(root);
		}
		
};//fin clase BSTree

#endif
