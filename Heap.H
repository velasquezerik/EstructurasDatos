/**
	@file Heap.H
	@brief Clase Monticulo Binario. 
	Realizada mediante el uso de vectores dinamicos.
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014

*/

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "VectorUtils.H"
#include "BinNodeUtils.H"
#include "ManejoExcepciones.H"

using namespace std;

/**
	@class Heap
	@brief Monticulo binario
 */
template<class T> class Heap
{
	private:
		Vector<T> heap;				//Vector de elementos del Heap
		size_t num;					//numero de elementos en el Heap
		/**
			@brief flotar un elemento
			@param i, posicion del elemento a ser flotado
		*/
		void flotar(int i)
		{
			T e = heap[i];
			int p = i/2;
				while ((e < heap[p]) and (i > 1)) 
				{
					std::swap(heap[i],heap[p]);
					i = p;
					p = (int) i/2;
				}
		}
		/**
			@brief undir un elemento
			@param i, posicion del elemento a ser unido
		*/
		void hundir(int i) 
		{
			if(i==0 or i==num)
			{
				return;
			}

			T e = heap[i];
			int j, c;
			j = i;   
			c = 2 * i;
			while (c <= num) 
			{
				if (c + 1 <= num)
				{ 
					if (heap[c + 1] < heap[c])
						c = c + 1;
				}
				if (e > heap[c])
				{
					  std::swap(heap[j],heap[c]);
				}
				j = c;       
				c = 2 * j;
			}
		}

	public:
		/**
			@brief Constructor por omision de la clase
		*/
		Heap()
		{
			num = 0;
			T nada;
			heap.insert(nada);
		}
		/**
			@brief destructor por omision de la clase
		*/
		~Heap(){/*empty*/}
		/**
			@brief inserto un elemento en el monticulo
			@param e es el elemento a ser insertado
			@return nada
		*/
		void insert(T data) 
		{
			heap.insert(data);
			++num;
			if (num > 1)
			{
				flotar(num);
			}
		}
		/**
			@brief retorna el elemento min de monticulo
			@return Elemento min del monticulo
		*/
		T & getMin() 
		{
			if(num < 1)
			{
				throw EmptyHeap();
			}
			return heap[1];
		}
		/**
			@brief eliminamos el min elemento en el monticulo
			@return el min elemento eliminado
		*/
		T deleteMin() 
		{
			if(num < 1)
			{
				throw EmptyHeap();
			}
			T data = heap[1];
			heap[1] = heap[num];
			heap.removeLast();
			num--;
			if (!this->isEmpty())
			{
				hundir(1);
			}
			return data;
		}
		/**
			@brief imprimimos los elementos del monticulo
			@return nada
		*/
		void printHeap() 
		{    
			for (int i = 1; i <= num; i++)
			{
					cout << heap[i] << " ";
			}
		}
		/**
			@brief verifica si el monticulo esta vacio
			@return True si esta vacio, False en caso contrario
		*/
		bool isEmpty()
		{
			return (num == 0);
		}
		/**
			@brief obtenemos el arbol binario equivalente a el monticulo
			@return la raiz del arbol binario
		*/
		BinNode<T>* getAB()
		{
			return buildABHeap(heap,1,num);
		}
		int getSize()
		{
			return num;
		}
   
};//fin clase Heap

#endif
