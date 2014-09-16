/**
	@file Vector.H
	@brief Clase Parametrica Vector Dinamico. 
	Vector Parametrico Dinamico parametrico, generado de manera secuencial.
	Contiene manejo de Excepciones
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014

*/

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "ManejoExcepciones.H"

using namespace std;

/**
	@class Vector
	@brief Vector dinamico,secuencial
 */
template<class T> class Vector
{
	private:
		T * vec;					//puntero a el elemento tipo T
		int size;					//numero de elementos de tipo T almacenados
	
	
	/**
		@brief particion del ordenamiento rapido
		@param l valor izquierdo de inicio
		@param r valor derecho de finalizacion
	*/
	int partition(int l, int r) 
	{
		int i = l - 1, j = r;
		T   pivot = vec[r];

		while (1)
		{
			while (vec[++i]< pivot);

			while (pivot < vec[--j])
				if (j == l)
					break;

			if (i >= j)
				break;

			std::swap(vec[i], vec[j]);
		}
		std::swap(vec[i], vec[r]);

		return i;
	}	
	/**
		@brief Ordenamiento rapido
		@param l valor izquierdo de inicio
		@param r valor derecho de finalizacion
	*/
	void quickSort(const int l,const int r)
	{
		int i;

		if (r <= l) 
			return;

		i = this->partition(l, r);

		if (i - l > r - i) 
		{
			this->quickSort(i + 1, r);
			this->quickSort(l, i - 1);
		}
		else 
		{
			this->quickSort(l, i - 1);
			this->quickSort(i + 1, r);
		} 
	}
	/**
		@brief encuentra la posicion en donde se encuentra un elemento
		@param data elemento a ser encontrado
		@return la posicion del elemento, o -1 en caso de no encontrarse
	*/
	int findPos(const T & data)
	{
		for(int i=0;i<size;i++)
		{
			if(data==vec[i])
			{
				return i;
			}
					
		}
		return -1;
	}
	/**
		@brief acceder a un elemento del vector
		@param pos posicion del elemento a acceder
		@return informacion del elemento
	*/
	T & access(int pos)
	{
		if((pos < 0) or (pos>=size))
		{
			throw BadPos();
		}
		return vec[pos];
			
	}
	public:
	/**
		@brief Constructor por omision de la clase
	*/
	Vector()
	{
		vec=NULL;					
		size=0;						
	}

	/**
		@brief Destructor por omision de la clase
	*/
	~Vector()
	{
		delete [] vec;
	}
	
	/**
		@brief Constructor por copia de la clase
	*/
	Vector(const Vector<T> & v)
	{
		try
		{
			vec = new T[v.size];
		}
		catch(bad_alloc &e)
		{
			throw NoMemory();
		}
		*this = v;
		/*size=v.size;
		for(int i = 0;i < v.size; i++)
		{
			vec[i] = v.vec[i];
		}*/
		
	}
	/**
		@brief obtener la cabecera del vector
		@return obtengo el puntero que maneja al vector
	*/
	T *& getVec()
	{
		return vec;
	}
	/**
		@brief ver el tamaño del vector
		@return el tamaño del vector
	*/
	int getSize()
	{
		return size;
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
		@brief inserta in elemento en la ultima posicion
		@param data elemento a ser insertado
		@return nada
	*/
	void insert(const T data)
	{
		T * aux;
		aux=vec;
		try
		{
			vec = new T[size +1];
		}
		catch(bad_alloc &e)
		{
			throw NoMemory();
		}
		for(int i=0;i<size;i++)
		{
			vec[i]=aux[i];
		}
		vec[size]=data;
		size++;
		delete [] aux;
	}
	/**
		@brief inserta in elemento en la ultima posicion
		@param data elemento a ser insertado
		@return nada
	*/
	void insert(const Vector<T> & v)
	{
		T * aux;
		aux = vec;
		try
		{
			vec = new T[size + v.size];
		}
		catch(bad_alloc &e)
		{
			throw NoMemory();
		}
		for(int i=0;i<size;i++)
		{
			vec[i]=aux[i];
		}
		for(int i = size; i < (size + v.size);i++)
		{
			vec[i]=v.vec[i-size];
		}
		size=size+v.size;
		delete [] aux;		
	}
	/**
		@brief elimina el elemento de la ultima posicion del vector
		@return nada
	*/
	void removeLast()
	{
		T * aux;
		aux=vec;
		if(size>0)
		{
			try
			{
				vec = new T[size -1];
			}
			catch(bad_alloc &e)
			{
				throw NoMemory();
			}
			for(int i=0;i<size-1;i++)
			{
				vec[i]=aux[i];
			}
			size--;
			delete [] aux;
		}
	}
	/**
		@brief elimina el elemento cualquiera del vector
		@param data elemento a ser removido
		@return nada
	*/
	void remove(const T data)
	{
		int pos = this->findPos(data);
		if(pos == -1)
		{
			return;
		}
		else
		{
			T * aux;
			aux=vec;
			try
			{
				vec = new T[size -1];
			}
			catch(bad_alloc &e)
			{
				throw NoMemory();
			}
			for(int i=0;i<pos;i++)
			{
				vec[i]=aux[i];
			}
			for(int i=(pos+1);i<size;i++)
			{
				vec[i-1]=aux[i];
			}
			size--;
			delete [] aux;
			
		}
	}
	/**
		@brief sobre carga del operador =
		@param v vector a copiar
		@return la copia del vector
	*/
	const Vector<T> & operator = (const Vector<T> & v)
	{
		if(size!=0)
		{
			delete [] vec;
		}
		try
		{
			vec = new T[v.size];
		}
		catch(bad_alloc &e)
		{
			throw NoMemory();
		}
		for(int i = 0;i < v.size; i++)
		{
			vec[i] = v.vec[i];
		}
		size=v.size;
		return *this;
	}
	/**
		@brief sobre carga del operador ==
		@param v vector a copiar
		@return true si son iguales, false contrario
	*/
	bool operator == (const Vector<T> & v)const
	{
		if(size != v.size)
		{
			return false;
		}
		for(int i = 0 ;i < size; i++)
		{
			if(vec[i]!=v.vec[i])
			{
				return false;
			}
		}
		return true;
	}
	/**
		@brief sobre carga del operador !=
		@param v vector a copiar
		@return true si son diferentes, false contrario
	*/
	bool operator != (const Vector<T> & v)const
	{
		return !(*this == v);
	}
	
	/**
		@brief ordena el vector usando el algoritmo Quicksort
	*/
	void sort()
	{
		quickSort(0,size-1);
	}
	
};//fin clase Vector
#endif 
