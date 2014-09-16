/**
	@file TableHash.H
	@brief Clase Tabla Hash. 
	Manejo de tabla hash usando manejo de colision listas Dobles.
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 8/2014

*/

#ifndef TABLEHASH_H
#define TABLEHASH_H

#include <iostream>
#include "ManejoExcepciones.H"
#include "ListUtils.H"

using namespace std;

/**
	@class TableHash
	@brief Tabla hash
 */
template<class T> class TableHash
{
	private:
	
		DNode<T>  * data;		//tabla de listas de datos
		int size;				//tamaño de la tabla
		
		/**
			@brief funcion Hash de la clase
			@param clave a ser evaluada
			@return una posicion valida dentro de la tabla
		*/
		int functionHash( T clave)
		{
			int pos = (clave%size);
			if(pos < 0 or pos >=size)
			{
				throw BadPos();
			}
			return pos;
		}
		
	public:
	
		/**
			@brief constructor de la clase
			@param size tamaño que debera tener la tabla
		*/
		TableHash( int size)
		{
			if(size < 1)
			{
				throw ValueNull();
			}
			this->size = size;
			try
			{
				data = new DNode<T> [size];
			}
			catch(bad_alloc &e)
			{
				throw NoMemory();
			}
		}
		/**
			@brief insertar un elemento en la tabla
			@param clave a ser insertada
		*/
		void insertData( T clave)
		{
			int pos = functionHash(clave);
			data[pos].insertNext(clave);
		}
		/**
			@brief busca un elemento en la tabla
			@param clave a ser buscada
			@return verdadero si se encuentra en la tabla, falso en caso contrario			
		*/
		bool search( T clave)
		{
			
			int pos = functionHash(clave);
			
			DNode<T> * aux = &data[pos];
			aux = data[pos].getNext();
			while(aux != &data[pos])
			{
				if(aux->getData() == clave)
				{
					return true;
				}
				aux = aux->getNext();
			}
			return false;
		}
		/**
			@brief busca un elemento en la tabla
			@param clave a ser buscada
			@return devuelve la referencia ese elemento			
		*/
		T & searchData( T clave)
		{
			//T nulo;
			int pos = functionHash(clave);
			
			DNode<T> * aux = &data[pos];
			aux = data[pos].getNext();
			while(aux != &data[pos])
			{
				if(aux->getData() == clave)
				{
					return aux->getData();
				}
				aux = aux->getNext();
			}
			throw NotData();
			//return nulo;
		}
		/**
			@brief elimina un elemento en la tabla
			@param clave a ser eliminada		
		*/
		void deleteData( T clave)
		{
			int pos = functionHash(clave);
			
			DNode<T> * aux = &data[pos];
			aux = data[pos].getNext();
			while(aux != &data[pos])
			{
				if(aux->getData() == clave)
				{
					aux=aux->getNext();
					delete aux->removePrev();
					return;
				}
				aux = aux->getNext();
			}
		}
		/**
			@brief Imprime toda la info que esta en la tabla		
		*/
		void printAllData()
		{
			for(int i = 0; i < size; i++)
			{
				DNode<T> * aux = &data[i];
				aux = data[i].getNext();
				while(aux != &data[i])
				{
					std::cout<<aux->getData()<<endl;
					aux = aux->getNext();
				}
			}
			delete [] data;
		}
		/**
			@brief destructor por omision		
		*/
		~TableHash()
		{
			for(int i = 0; i < size; i++)
			{
				while(!data[i].isEmpty())
				{
					delete data[i].removeNext();
				}
			}
			delete [] data;
		}
		/**
			@brief Obtener el vector de lista de datos
			@return devuelve el vector de listas de datos
		*/
		DNode<T>* getData()
		{
			return data;
		}
		/**
			@brief Obtener el tamaño de la tabla
			@return devuelve el tamaño de la tabla
		*/
		int getSize()
		{
			return size;
		}
};//fin clase TableHash

#endif 
