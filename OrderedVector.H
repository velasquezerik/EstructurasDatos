/**
	@file OrderedVector.H
	@brief Clase Parametrica Vector Dinamico Ordenado. 
	Vector Parametrico Dinamico Ordenado, generado de manera secuencial.
	Contiene manejo de Excepciones
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014

*/

#ifndef ORDEREDVECTOR_H
#define ORDEREDVECTOR_H
#include <iostream>
#include "ManejoExcepciones.H"


using namespace std;

/**
	@class Vector
	@brief Vector dinamico,secuencial
 */
template<class T> class OrderedVector
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
		@brief Busqueda binaria, siempre que el vector este ordenado
		@param val valor a buscar
		@param l indice izquierdo de busqueda
		@param r indice derecho de busqueda
		@return la posicion en la que se deberia encontrar el valor
	*/
	int binarySearch(const T val)
	{
		//indice medio del vector
		int m;
		int l = 0;
		int r = size-1;
		while(l<=r)
		{
			m = (l+r)/2;
			
			if(val < vec[m])	//menor--- izquieda
			{
				r = m - 1;
			}
			else
			{
				if(vec[m] < val)	//mayor ---- derecha
				{
					l = m + 1;
				}
				else
				{
					if(vec[m] = val)
					{
						return m;
					}
					return -1;
					
				}
			}
		}
		if(vec[m] = val)
		{
			return m;
		}
		return -1;
	}
	/**
		@brief encuentra la posicion en donde se encuentra un elemento
		@param data elemento a ser encontrado
		@return la posicion del elemento, o -1 en caso de no encontrarse
	*/
	int findPos(const T & data)
	{
		return this->binarySearch(data);
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
	OrderedVector()
	{
		vec=NULL;					
		size=0;						
	}

	/**
		@brief Destructor por omision de la clase
	*/
	~OrderedVector()
	{
		delete [] vec;
	}
	
	/**
		@brief Constructor por copia de la clase
	*/
	OrderedVector(const OrderedVector<T> & v)
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
		aux = vec;
		try
		{
			vec = new T[size +1];
		}
		catch(bad_alloc &e)
		{
			throw NoMemory();
		}
		//inserto los menores a data
		int i = 0;
		while(i < size)
		{
			if(aux[i] < data)
			{
				vec[i] = aux[i];
				i++;
				continue;
			}
			break;
		}
		//inserto el elemento que quiero
		vec[i] = data;
		i++;
		//inserto el resto
		while(i < (size+1) )
		{
			vec[i] = aux[i-1];
			i++;
		}
		size++;
		delete [] aux;
	}
	/**
		@brief inserta in elemento en la ultima posicion
		@param data elemento a ser insertado
		@return nada
	*/
	void insert(const OrderedVector<T> & v)
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
		this->quickSort(0,size-1);
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
	const OrderedVector<T> & operator = (const OrderedVector<T> & v)
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
	bool operator == (const OrderedVector<T> & v)const
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
	bool operator != (const OrderedVector<T> & v)const
	{
		return !(*this == v);
	}
	
};//fin clase OrderedVector





#endif
