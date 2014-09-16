/**
	@file VectorUtils.H
	@brief Metodos utiles sobre vectores
	Encontramos una gran variedad de algoritmos sobre vectores
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 12/2013

*/


#ifndef VECTORUTILS_H
#define VECTORUTILS_H
#include <iostream>
#include "Vector.H"
#include "OrderedVector.H"

using namespace std;

/**
	@brief Busqueda binaria, siempre que el vector este ordenado
	@param vec vector ordenado
	@param val valor a buscar
	@param l indice izquierdo de busqueda
	@param r indice derecho de busqueda
	@return la posicion en la que se deberia encontrar el valor
*/
template<class T>
int binarySearch(T vec[], const T val, int l, int r)
{
	//indice medio del vector
	int m;
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
				return m;
			}
		}
	}
	return m;
}
/**
	@brief Busqueda secuencial de un elemento en el vector
	@param vec vector desordenado
	@param val valor a buscar
	@param l indice izquierdo de busqueda
	@param r indice derecho de busqueda
	@return -1 si no se encuentra o la posicion en la que se encuentra
*/
template<class T>
int sequentialSearch(T vec[], const T val, int l, int r)
{
	for(int i = l;i<=r;i++)
	{
		if(vec[i] == val)
		{
			return i;
		}
	}
	
	return -1;
}

/**
	@brief Ordenamiento por seleccion
	@param vec vector desordenado
	@param size cantidad de elementos del vector
*/
template<class T>
void selectionSort2(T vec[], const int size)
{
	for(int i = 0; i < size-1; i++ )
	{
		int min = i;
		//buscamos el menor elemento en el vector
		for(int j = i+1; j < size ; j++)
		{
			if(vec[j] < vec[min])
			{
				min = j;
			}
		}
		//intercambiamos el menor
		if(vec[min] < vec[i])
		{
			T aux = vec[i];
			vec[i] = vec[min];
			vec[min] = aux;
		}
	}
}
/**
	@brief Ordenamiento por seleccion
	@param a vector desordenado
	@param n cantidad de elementos del vector
*/
template <class T>
void selectionSort(T a[],const unsigned n)
{
  int i,j, min;

  for (i = 0; i < n - 1; i++)
  {
    min = i;

    for (j = i + 1; j < n; j++)
      if (a[j] < a[min])
        min = j;

      if (a[min] < a[i])
        std::swap(a[min], a[i]);
  }
}

/**
	@brief Ordenamiento por seleccion
	@param v vector desordenado
*/
template<class T>
void selectionSort(Vector<T> & v)
{
	selectionSort(v.getVec(),v.getSize());
}

/**
	@brief Ordenamiento por insercion
	@param vec vector desordenado
	@param l valor izquierdo de inicio
	@param r valor derecho de finalizacion
*/
template<class T>
void insertionSort(T vec[], const int l,const int r)
{
	for(int i = l; i <= r; i++)
	{
		T aux = vec[i];		//valor a buscarle su posicion
		int j = i;
		for(j = i;(j > l) and (aux < vec[j-1]);j--)
		{
			vec[j] = vec[j-1];
		}
		vec[j] = aux;
		
	}
}
/**
	@brief Ordenamiento por insercion
	@param vec vector desordenado
	@param n cantidad de elementos
*/
template <class T>
void insertionSort2(T a[], unsigned n)
{
	int i,j;

	for (i = 1; i < n; i++)
	{
		j=i;
		while( j > 0 && a[j - 1] > a[j])
		{
			std::swap(a[j], a[j - 1]);
			j--;
		}
	}
}

/**
	@brief Ordenamiento por insercion
	@param v vector desordenado
*/
template<class T>
void insertionSort(Vector<T> & v)
{
	//insertionSort(v.getVec(),0,v.getSize()-1);
	insertionSort2(v.getVec(),v.getSize());
}

/**
	@brief mezcla ordenada
	@param vec vector desordenado
	@param l valor izquierdo de inicio
	@param m valor medio
	@param r valor derecho de finalizacion
*/
template<class T>
void merge(T a[],T b[], const int l,const int m,const int r)
{
	int h,i,j,k;
    h=l;
    i=l;
    j=m+1;
    while((h<=m)&&(j<=r))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>m)
    {
        for(k=j; k<=r; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=m; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=l; k<=r; k++) 
		a[k]=b[k];
}

/**
	@brief Ordenamiento por mezcla
	@param vec vector desordenado
	@param l valor izquierdo de inicio
	@param r valor derecho de finalizacion
*/
template<class T>
void mergeSort(T vec[],T aux[], const int l,const int r)
{
	if(l >= r)
	{
		return;
	}
	
	const int m = (l + r)/2;
	
	mergeSort<T>(vec,aux,l,m);
	mergeSort<T>(vec,aux,m+1,r);
	merge<T>(vec,aux,l,m,r);
	
}

/**
	@brief Ordenamiento por mezcla
	@param vec vector desordenado
*/
template<class T>
void mergeSort(Vector<T> & v)
{
	T aux[v.getSize()];
	mergeSort(v.getVec(),aux,0,v.getSize()-1);
}

/**
	@brief particion del ordenamiento rapido
	@param a vector desordenado
	@param l valor izquierdo de inicio
	@param r valor derecho de finalizacion
*/
template <class T>
static int partition(T a[], int l, int r) {
	int i = l - 1, j = r;
	T   pivot = a[r];

	while (1)
	{
		while (a[++i]< pivot);

		while (pivot < a[--j])
			if (j == l)
				break;

		if (i >= j)
			break;

		std::swap(a[i], a[j]);
	}
	std::swap(a[i], a[r]);

	return i;
}

/**
	@brief Ordenamiento rapido
	@param vec vector desordenado
	@param l valor izquierdo de inicio
	@param r valor derecho de finalizacion
*/
template<class T>
void quickSort(T vec[],const int l,const int r)
{
  int i;

  if (r <= l) 
    return;

  i = partition(vec, l, r);

  if (i - l > r - i) {
      quickSort(vec, i + 1, r);
      quickSort(vec, l, i - 1);
  }
  else {
      quickSort(vec, l, i - 1);
      quickSort(vec, i + 1, r);
  } 
}

/**
	@brief Ordenamiento rapido
	@param v vector desordenado
*/
template<class T>
void quickSort(Vector<T> & v)
{
	quickSort(v.getVec(),0,v.getSize()-1);
}
/**
	@brief Ordenamiento burbuja mejorado
	@param a vector desordenado
	@param n tamaño del vector
*/
template <class T>
void bubbleSort2(T a[], unsigned n)
{
  int i,j;
  bool salir = true;
  
  for (i = 0; i < n-1; i++)
  {
    for (j = n-1; j > i; j--)
      if (a[j] < a[j-1])
      {
	std::swap(a[j-1], a[j]);
	salir = false;
      }
    if(salir)
      return;
    salir = true;
  }
}
/**
	@brief Ordenamiento burbuja mejorado
	@param v vector desorordenado
*/
template <class T>
void bubbleSort2(Vector<T> & v)
{
	bubbleSort2(v.getVec(),v.getSize());
}
/**
	@brief Ordenamiento burbuja 
	@param a vector desordenado
	@param n tamaño del vector
*/
template <class T>
void bubbleSort(T a[], unsigned n)
{
  int i,j;
  for (i = 0; i < n-1; i++)
    for (j = n-1; j > i; j--)
      if (a[j] < a[j-1])
	std::swap(a[j-1], a[j]);
}
/**
	@brief Ordenamiento burbuja 
	@param v vector desordenado
*/
template <class T>
void bubbleSort(Vector<T> & v)
{
	bubbleSort(v.getVec(),v.getSize());
}

#endif
