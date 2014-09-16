/**
	@file ListUtils.H
	@brief Metodos varios sobre manejo de listas
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014

*/
#ifndef LISTUTILS_H
#define LISTUTILS_H
#include <iostream>
#include "ManejoExcepciones.H"
#include "SNode.H"
#include "SList.H"
#include "DNode.H"
#include "DList.H"
#include "List.H"

//metodos de ordenamiento sobre SNode
/**
	@brief Ordena la lista la lista
	@param list, puntero al nodo cabecera de la lista
*/
template<class T>
void simpleSort(SNode<T> * list)
{
	if(list == NULL)
	{
		throw NullNode();
	}
	SNode<T> otra;
	while(!list->isEmpty())
	{
		otra.insertNext(list->removeNext());
	}
	while(!otra.isEmpty())
	{
		list->orderedInsertion(otra.removeNext());
	}
}
/**
	@brief Ordena la lista la lista
	@param list, nodo cabecera de la lista
*/
template<class T>
void simpleSort(SNode<T> & list)
{
	simpleSort(&list);
}
/**
	@brief Ordena la lista la lista
	@param list, puntero al nodo cabecera de la lista
*/
template<class T>
void simpleSort(SList<T> * list)
{
	if(list == NULL)
	{
		throw NullNode();
	}
	simpleSort(list->getNode());
}
/**
	@brief Ordena la lista la lista
	@param list, nodo cabecera de la lista
*/
template<class T>
void simpleSort(SList<T> & list)
{
	simpleSort(list.getNode());
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, puntero al nodo cabecera de la lista
*/
template<class T>
void quickSort(SNode<T> * list)
{
	if(list == NULL)
	{
		throw NullNode();
	}
	if(list->isEmpty())
	{
		return;
	}
	//escogemos el pivote
	SNode<T> * pivot = list->removeNext();
	SNode<T> smaller;
	SNode<T> bigger;
	//hacemos la particion
	while(!list->isEmpty())
	{
		SNode<T> * node = list->removeNext();
		if(node->getData() < pivot->getData())
		{
			smaller.insertNext(node);
		}
		else
		{
			bigger.insertNext(node);
		}
	}
	//llamadas recursivas
	quickSort(&smaller);
	quickSort(&bigger);
	
	//unimos las listas
	list->insertNext(pivot);
	list->concatList(smaller);
	pivot->concatList(bigger);
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, nodo cabecera de la lista
*/
template<class T>
void quickSort(SNode<T> & list)
{
	quickSort(&list);
}

/**
	@brief Ordena la lista usando QuickSort
	@param list, puntero al nodo cabecera de la lista
*/
template<class T>
void quickSort(SList<T> * list)
{
	quickSort(list->getNode());
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, nodo cabecera de la lista
*/
template<class T>
void quickSort(SList<T> & list)
{
	quickSort(list.getNode());
}

//metodos varios sobre SNode
/**
	@brief Busca el menor Nodo de la lista
	@param head, puntero al nodo cabecera de la lista
	@return el menor nodo de la lista
*/
template<class T>
SNode<T>* searchMinNode(SNode<T> * head)
{
	if(head == NULL)
	{
		throw NullNode();
	}
	SNode<T> * aux = head;
	aux = head->getNext();
	SNode<T> * min = head;
	while(aux != head)
	{
		if(min->getData() > aux->getData())
		{
			min = aux;
		}
		aux = aux->getNext();
	}
	if(min != head)
	{
		return min;
	}
	return NULL;
}
/**
	@brief Busca el menor Nodo de la lista
	@param head, puntero al nodo cabecera de la lista
	@return el menor nodo de la lista, NULL en caso de la lista vacia
*/
template<class T>
SNode<T>* searchMinNode(SNode<T> & head)
{
	return searchMinNode(&head);
}

/**
	@brief Busca el menor valor de la lista
	@param head, puntero al nodo cabecera de la lista
	@return el menor elemento de la lista
*/
template<class T>
T searchMin(SNode<T> * head)
{
	if(head == NULL)
	{
		throw NullNode();
	}
	SNode<T> * aux = head;
	aux = head->getNext();
	SNode<T> * min = head->getNext();
	while(aux != head)
	{
		if(min->getData() > aux->getData())
		{
			min = aux;
		}
		aux = aux->getNext();
	}
	if(min != head)
	{
		return min->getData();
	}
	return min->getData();
}
/**
	@brief Busca el menor valor de la lista
	@param head, nodo cabecera de la lista
	@return el menor elemento de la lista
*/
template<class T>
T searchMin(SNode<T> & head)
{
	return searchMin(&head);
}
/**
	@brief Busca el menor valor de la lista
	@param head, nodo cabecera de la lista
	@return el menor elemento de la lista
*/
template<class T>
T searchMin(SList<T> & head)
{
	return searchMin(head.getNode());
}
/**
	@brief Busca el menor valor de la lista
	@param head, puntero al nodo cabecera de la lista
	@return el menor elemento de la lista
*/
template<class T>
T searchMin(SList<T> * head)
{
	if(head == NULL)
	{
		throw NullNode();
	}
	return searchMin(head->getNode());
}
//metodos de ordenamiento sobre DNode
/**
	@brief Ordena la lista la lista
	@param list, puntero al nodo cabecera de la lista
*/
template<class T>
void simpleSort(DNode<T> * list)
{
	if(list == NULL)
	{
		throw NullNode();
	}
	DNode<T> otra;
	while(!list->isEmpty())
	{
		otra.orderedInsertion(list->removeNext());
	}
	list->swap(otra);
}
/**
	@brief Ordena la lista la lista
	@param list, nodo cabecera de la lista
*/
template<class T>
void simpleSort(DNode<T> & list)
{
	simpleSort(&list);
}
/**
	@brief Ordena la lista la lista
	@param list, puntero al nodo cabecera de la lista
*/
template<class T>
void simpleSort(DList<T> * list)
{
	if(list == NULL)
	{
		throw NullNode();
	}
	simpleSort(list->getNode());
}
/**
	@brief Ordena la lista la lista
	@param list, nodo cabecera de la lista
*/
template<class T>
void simpleSort(DList<T> & list)
{
	simpleSort(list.getNode());
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, puntero al nodo cabecera de la lista
*/
template<class T>
void quickSort(DNode<T> * list)
{
	if(list == NULL)
	{
		throw NullNode();
	}
	if(list->isEmpty())
	{
		return;
	}
	//escogemos el pivote
	DNode<T> * pivot = list->removeNext();
	DNode<T> smaller;
	DNode<T> bigger;
	//hacemos la particion
	while(!list->isEmpty())
	{
		DNode<T> * node = list->removeNext();
		if(node->getData() < pivot->getData())
		{
			smaller.insertPrev(node);
		}
		else
		{
			bigger.insertPrev(node);
		}
	}
	//llamadas recursivas
	quickSort(&smaller);
	quickSort(&bigger);
	
	//unimos las listas
	list->concatList(smaller);
	list->insertPrev(pivot);
	list->concatList(bigger);
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, nodo cabecera de la lista
*/
template<class T>
void quickSort(DNode<T> & list)
{
	quickSort(&list);
}

/**
	@brief Ordena la lista usando QuickSort
	@param list, puntero al nodo cabecera de la lista
*/
template<class T>
void quickSort(DList<T> * list)
{
	quickSort(list->getNode());
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, nodo cabecera de la lista
*/
template<class T>
void quickSort(DList<T> & list)
{
	quickSort(list.getNode());
}
/**
	@brief Mezcla las listas l,r en list
	@param l,r listas a mezclar,list resultado de la mezcla
*/
template<class T>
void mergeList(DNode<T> * l,DNode<T> * r, DNode<T> * list)
{
	if(l == NULL or r == NULL or list == NULL)
	{
		throw NullNode();
	}
	while(!l->isEmpty() and !r->isEmpty())
	{
		if(l->getNext()->getData() < r->getNext()->getData())
		{
			list->insertPrev(l->removeNext());
		}
		else
		{
			list->insertPrev(r->removeNext());
		}
	}
	if(l->isEmpty())
	{
		list->concatList(r);
	}
	else
	{
		list->concatList(l);
	}
}
/**
	@brief Ordena la lista usando MergeSort
	@param list, puntero nodo cabecera de la lista
*/
template<class T>
void mergeSort(DNode<T> * list)
{
	if(list == NULL)
	{
		throw NullNode();
	}
	if(list->isUnitarianOrEmpty())
	{
		return;
	}
	DNode<T> left,right;
	list->splitList(left,right);
	//llamadas recursivas
	mergeSort(&left);
	mergeSort(&right);
	
	mergeList(&left,&right,list);
}
/**
	@brief Ordena la lista usando MergeSort
	@param list, nodo cabecera de la lista
*/
template<class T>
void mergeSort(DNode<T> & list)
{
	mergeSort(&list);
}
/**
	@brief Ordena la lista usando MergeSort
	@param list, nodo cabecera de la lista
*/
template<class T>
void mergeSort(DList<T> * list)
{
	mergeSort(list->getNode());
}
/**
	@brief Ordena la lista usando MergeSort
	@param list, nodo cabecera de la lista
*/
template<class T>
void mergeSort(DList<T> & list)
{
	mergeSort(list.getNode());
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, puntero nodo cabecera de la lista
*/
template<class T>
void sort(DNode<T> * list)
{
	quickSort(list);
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, nodo cabecera de la lista
*/
template<class T>
void sort(DNode<T> & list)
{
	quickSort(list);
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, puntero nodo cabecera de la lista
*/
template<class T>
void sort(DList<T> * list)
{
	quickSort(list);
}
/**
	@brief Ordena la lista usando QuickSort
	@param list, nodo cabecera de la lista
*/
template<class T>
void sort(DList<T> & list)
{
	quickSort(list);
}
//metodos varios sobre DNode
/**
	@brief Busca el menor Nodo de la lista
	@param head, puntero al nodo cabecera de la lista
	@return el menor nodo de la lista
*/
template<class T>
DNode<T>* searchMinNode(DNode<T> * head)
{
	if(head == NULL)
	{
		throw NullNode();
	}
	DNode<T> * aux = head;
	aux = head->getNext();
	DNode<T> * min = head;
	while(aux != head)
	{
		if(min->getData() > aux->getData())
		{
			min = aux;
		}
		aux = aux->getNext();
	}
	if(min != head)
	{
		return min;
	}
	return NULL;
}
/**
	@brief Busca el menor Nodo de la lista
	@param head, puntero al nodo cabecera de la lista
	@return el menor nodo de la lista, NULL en caso de la lista vacia
*/
template<class T>
DNode<T>* searchMinNode(DNode<T> & head)
{
	return searchMinNode(&head);
}

/**
	@brief Busca el menor valor de la lista
	@param head, puntero al nodo cabecera de la lista
	@return el menor elemento de la lista
*/
template<class T>
T searchMin(DNode<T> * head)
{
	if(head == NULL)
	{
		throw NullNode();
	}
	DNode<T> * aux = head;
	aux = head->getNext();
	DNode<T> * min = head->getNext();
	while(aux != head)
	{
		if(min->getData() > aux->getData())
		{
			min = aux;
		}
		aux = aux->getNext();
	}
	if(min != head)
	{
		return min->getData();
	}
	return min->getData();
}
/**
	@brief Busca el menor valor de la lista
	@param head, nodo cabecera de la lista
	@return el menor elemento de la lista
*/
template<class T>
T searchMin(DNode<T> & head)
{
	return searchMin(&head);
}
/**
	@brief Busca el menor valor de la lista
	@param head, nodo cabecera de la lista
	@return el menor elemento de la lista
*/
template<class T>
T searchMin(DList<T> & head)
{
	return searchMin(head.getNode());
}
/**
	@brief Busca el menor valor de la lista
	@param head, puntero al nodo cabecera de la lista
	@return el menor elemento de la lista
*/
template<class T>
T searchMin(DList<T> * head)
{
	if(head == NULL)
	{
		throw NullNode();
	}
	return searchMin(head->getNode());
}

#endif
