/**
	@file BinNode.H
	@brief Clase Nodo Binario. 
	Nodo Binario, para manejar arboles binarios
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014, 8/2014
*/

#ifndef BINNODE_H
#define	BINNODE_H

#include <iostream>
#include "ManejoExcepciones.H"

/**
	@class BinNode
	@brief Nodo binario para arboles binarios
 */
template<class T> class BinNode
{
	private:
		T dato;				//dato a almacenar en el nodo
		BinNode<T>* l;		//puntero a mi hijo izquierdo
		BinNode<T>* r;		//puntero a mi hijo derecho
		int height;			//altura

	public:
		/**
			@brief Constructor por omision de la clase
		*/
		BinNode()
		{
			l=NULL;
			r=NULL;
			height=0;
		}
		/**
			@brief Constructor por copia de la clase
		*/
		BinNode(T key)
		{
			l=NULL;
			r=NULL;
			dato = key;
			height=0;
		}
		/**
			@brief Obtenemos el puntero izquierdo
			@return puntero del hijo izquierdo BinNode<T>* 
		*/
		BinNode<T>*& getL()
		{
			return l;
		}
		/**
			@brief Obtenemos el puntero derecho
			@return puntero del hijo derecho BinNode<T>* 
		*/
		BinNode<T>*& getR()
		{
			return r;
		}
		/**
			@brief retorna la data almacenada en el nodo
			@return informacion almacenada en el nodo
		*/
		T & getData()
		{
			return dato;
		}
		/**
			@brief retorna la ddiferencia de altura
			@return diferencia del alturas entre los hijos del nodo
		*/
		int & getHeight()
		{
			return height;
		}
		/**
			@brief resetea el nodo 
			@return nada
		*/
		void resetNode()
		{
			l=NULL;
			r=NULL;
			height = 0;
		}
		/**
			@brief destructor por omision de la clase DNode
		*/
		~BinNode()
		{
		}
		/**
			@brief sobre carga del operador ==
			@param node nodo a comparar
			@return true si sus valores son iguales, false contrario
		*/
		bool operator == (BinNode<T> & node)
		{
			return (node.dato == this->dato);
		}
		/**
			@brief sobre carga del operador !=
			@param node nodo a comparar
			@return true si son diferentes, false contrario
		*/
		bool operator != (const BinNode<T> & node)const
		{
			return !(*this == node);
		}
		/**
			@brief sobre carga del operador =
			@param v vector a copiar
			@return la copia del vector
		*/
		BinNode<T> & operator = (BinNode<T> & node)
		{
			this->dato = node.dato;
			this->l = node.l;
			this->r = node.r;
			this->height = node.height;
			return *this;
		}
};//fin clase BinNode

#endif
