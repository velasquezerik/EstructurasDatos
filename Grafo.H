/**
	@file Grafo.H
	@brief Clase Grafo, la cual representa un Grafo DIRIGIDO. 
	En este archivo encontramos 3 clases definidas: Clase NodoGrafo, la 
	cual representa el nodo o vértice del grafo; Clase ArcoGrafo, la cual 
	representa las aristas o arcos del Grafo; y la Clase Grafo la cual 
	representa un grafo implementado mediante el uso de listas (lista de 
	nodos y listas de Arcos). 
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2013, 4/2013

*/

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "DNode.H"
#include "Queue.H"
#include "Heap.H"

/**
	@class Bits
	@brief Representa los bits de control sobre los nodos y aristas 
	1 bit activado, 0 desactivado
 */
class Bits
{
	unsigned int visitado;
	int acumulado;
	bool expandido;
	
	public:
	/**
		@brief Constructor por omision de la clase Bits
	*/
	Bits()
	{
		visitado = 0;
		acumulado = -1;
		expandido = false;
	};
	/**
		@brief Destructor por omision de la clase Bits
	*/
	~Bits(){};

	/**
		@brief Operador de asignacion del nodo
		@param con Bits con la info a copiar
		@return La asignacion
	*/
	Bits& operator = (const Bits& con)
	{
		this->visitado = con.visitado;
		this->acumulado = con.acumulado;
		this->expandido = con.expandido;
		return *this;
	};
	/**
		@brief obetener Visitado
		@return el bit de visitado
	*/
	int getVisitado()
	{
		return visitado;
	};
	/**
		@brief obetener acumulado
		@return el bit de acumulado
	*/
	int getAcumulado()
	{
		return acumulado;
	};
	/**
		@brief Ver si esta expandido el nodo
		@return true si esta expandido, false caso contrario
	*/
	bool isExpandido()
	{
		return expandido;
	};
	/**
		@brief Reinicia todos los bits de control a 0
	*/
	void reset()
	{
		visitado = 0;
		acumulado = -1;
		expandido = false;
	};
	/**
		@brief Activa el bit de control Visitado
	*/
	void visitar()
	{
		visitado = 1;
	};
	/**
		@brief Expande el nodo
	*/
	void expandirNodo()
	{
		expandido = true;
	};
	/**
		@brief asigna un acumulado al nodo
		@param acumulado, valor a aumentar
	*/
	void aumentarAcumulado(int acumulado)
	{
			this->acumulado = acumulado;
	};
	/**
		@brief Verifica si el bit de control Visitado esta activado
		@return True si esta activado el bit, False de lo contrario
	*/
	bool estaVisitado()
	{
		return (visitado == 1);
	};
	
};
 
/**
	@class NodoGrafo
	@brief Representa los vertices o nodos de un Grafo. Contiene la 
	informacion o data de los nodos del Grafo.
 */
template <class NodeInfo> class NodoGrafo
{
	NodeInfo DataNodo;
	Bits control;
	
	public:
	
		NodoGrafo();
		NodoGrafo(NodeInfo info);
		NodoGrafo(NodoGrafo<NodeInfo> * nodo);
		~NodoGrafo();
		void setDataNode(NodeInfo info);
		NodeInfo & getDataNode();
		Bits & getBits();
		void reiniciarNodo();
		NodoGrafo<NodeInfo>& operator = (const NodoGrafo<NodeInfo> & nodo);
		
		
};

/**
	@brief Constructor por omision de la clase NodoGrafo
*/
template <class NodeInfo> 
NodoGrafo<NodeInfo>::NodoGrafo()
{
}

/**
	@brief Constructor parametrico de la clase NodoGrafo
	@param info la informacion con la cual se inicializara el nodo
	@return nada
*/
template <class NodeInfo> 
NodoGrafo<NodeInfo>::NodoGrafo(NodeInfo info)
{
	DataNodo = info;
}

/**
	@brief Constructor parametrico de la clase NodoGrafo
	@param nodo es el que contiene la info a copiar 
	@return nada
*/
template <class NodeInfo> 
NodoGrafo<NodeInfo>::NodoGrafo(NodoGrafo<NodeInfo> * nodo)
{
	this->DataNodo = nodo->getDataNode();
	this->control = nodo->getBits();
}

/**
	@brief destructor de la clase NodoGrafo
*/
template <class NodeInfo> 
NodoGrafo<NodeInfo>::~NodoGrafo()
{
}

/**
	@brief retorna la data del nodo
	@return la informacion almacenada en el nodo
*/
template <class NodeInfo> 
NodeInfo & NodoGrafo<NodeInfo>::getDataNode()
{
	return DataNodo;
}

/**
	@brief asigna la data del nodo
	@return nada
*/
template <class NodeInfo> 
void NodoGrafo<NodeInfo>::setDataNode(NodeInfo info)
{
	DataNodo = info;
}

/**
	@brief retorna la data del bit de control
	@return la informacion almacenada en el bits de control 
*/
template <class NodeInfo> 
Bits & NodoGrafo<NodeInfo>::getBits()
{
	return control;
}

/**
	@brief reinicia los bits de control del nodo
	@return nada
*/
template <class NodeInfo> 
void NodoGrafo<NodeInfo>::reiniciarNodo()
{
	control.reset();
}

/**
	@brief operador de asignacion del NodoGrafo
	@param nodo el nodo con la info a copiar
	@return La asignacion
*/
template <class NodeInfo> 
NodoGrafo<NodeInfo> & NodoGrafo<NodeInfo>::operator = (const NodoGrafo<NodeInfo> & nodo)
{
	this->DataNodo = nodo.DataNodo;
	this->control = nodo.control;
}

/*--------------------------------------------------------------------*/

/**
	@class ArcoGrafo
	@brief Representa los arcos o aristas de un Grafo. Contiene la 
	informacion o data de los arcos del Grafo.
 */
template <class ArcInfo,class NodeInfo> class ArcoGrafo
{
	ArcInfo DataArco;
	
	NodeInfo Origen;
	NodeInfo Destino;
	Bits control;
	
	public:
		ArcoGrafo();
		ArcoGrafo(ArcInfo info,NodeInfo origen,NodeInfo destino);
		~ArcoGrafo();
		ArcInfo & getDataArc();
		void setDataArc(ArcInfo info);
		NodeInfo & getNodoOrigen();
		void setNodoOrigen(NodeInfo origen);
		NodeInfo & getNodoDestino();
		void setNodoDestino(NodeInfo destino);
		Bits & getBits();
		void reiniciarArco();
		bool operator < (ArcoGrafo<ArcInfo,NodeInfo> & n1)
		{
			if(DataArco < n1.DataArco)
			{
				return true;
			}
			
			return false;
		};
		bool operator > (ArcoGrafo<ArcInfo,NodeInfo> & n1)
		{
			if(DataArco > n1.DataArco)
			{
				return true;
			}
			
			return false;
		};
};

/**
	@brief Constructor por omision de la clase ArcoGrafo
*/
template <class ArcInfo,class NodeInfo> 
ArcoGrafo<ArcInfo,NodeInfo>::ArcoGrafo()
{
}

/**
	@brief Constructor parametrico de la clase ArcoGrafo
	@param info la informacion con la cual se inicializara el arco
	@param origen el nodo origen del arco
	@param destino el nodo destino del arco
*/
template <class ArcInfo,class NodeInfo> 
ArcoGrafo<ArcInfo,NodeInfo>::ArcoGrafo(ArcInfo info,NodeInfo origen,NodeInfo destino)
{
	DataArco = info;
	this->origen = origen;
	this->destino = destino;
}

/**
	@brief destructor de la clase ArcoGrafo
*/
template <class ArcInfo,class NodeInfo> 
ArcoGrafo<ArcInfo,NodeInfo>::~ArcoGrafo()
{
}

/**
	@brief retorna la data del Arco
	@return la informacion almacenada en el arco
*/
template <class ArcInfo,class NodeInfo> 
ArcInfo & ArcoGrafo<ArcInfo,NodeInfo>::getDataArc()
{
	return DataArco;
}

/**
	@brief retorna el nodo origen del Arco
	@return la informacion del nodo origen en el arco
*/
template <class ArcInfo,class NodeInfo> 
NodeInfo & ArcoGrafo<ArcInfo,NodeInfo>::getNodoOrigen()
{
	return Origen;
}

/**
	@brief retorna el nodo destino del Arco
	@return la informacion del nodo destino en el arco
*/
template <class ArcInfo,class NodeInfo> 
NodeInfo & ArcoGrafo<ArcInfo,NodeInfo>::getNodoDestino()
{
	return Destino;
}

/**
	@brief asigna la info del arco
	@return nada
*/
template <class ArcInfo,class NodeInfo> 
void  ArcoGrafo<ArcInfo,NodeInfo>::setDataArc(ArcInfo info)
{
	DataArco = info;
}

/**
	@brief asigna la info del nodo origen del arco
	@return nada
*/
template <class ArcInfo,class NodeInfo> 
void  ArcoGrafo<ArcInfo,NodeInfo>::setNodoOrigen(NodeInfo origen)
{
	this->Origen = origen;
}

/**
	@brief asigna la info del nodo destino del arco
	@return nada
*/
template <class ArcInfo,class NodeInfo> 
void  ArcoGrafo<ArcInfo,NodeInfo>::setNodoDestino(NodeInfo destino)
{
	this->Destino = destino;
}


/**
	@brief obtiene los bits de control del arco
	@return los bits de control del arco
*/
template <class ArcInfo,class NodeInfo> 
Bits & ArcoGrafo<ArcInfo,NodeInfo>::getBits()
{
	return control;
}

/**
	@brief reinicia los bits de control del arco
	@return nada
*/
template <class ArcInfo,class NodeInfo> 
void  ArcoGrafo<ArcInfo,NodeInfo>::reiniciarArco()
{
	control.reset();
}

/*--------------------------------------------------------------------*/

/**
	@class Grafo
	@brief representa un grafo implementado mediante el uso de listas (lista de 
	nodos y listas de Arcos) de adyacencia.
 */
template <class NodeInfo,class ArcInfo> class Grafo
{
	DNode<NodoGrafo<NodeInfo> > ListaNodos;
	DNode<ArcoGrafo<ArcInfo,NodeInfo> > ListaArcos;
	unsigned int NumNodos;
	unsigned int NumArcos;
	
	public:
	
		Grafo();
		~Grafo();
		
		unsigned int getNumNodos();
		unsigned int getNumArcos();
		
		void insertarNodo(NodeInfo  info);
		bool buscarNodo(NodeInfo info);
		void eliminarNodo(NodeInfo info);
		
		void insertarArco(ArcInfo info,NodeInfo origen,NodeInfo destino);
		bool buscarArco(ArcInfo info,NodeInfo origen,NodeInfo destino);
		void eliminarArco(ArcInfo info,NodeInfo origen,NodeInfo destino);
		
		DNode<NodoGrafo<NodeInfo> > * getListaNodosPuntero();
		DNode<NodoGrafo<NodeInfo> > & getListaNodos();
		
		DNode<ArcoGrafo<ArcInfo,NodeInfo> > * getListaArcosPuntero();
		DNode<ArcoGrafo<ArcInfo,NodeInfo> > & getListaArcos();
	
		DNode<NodoGrafo<NodeInfo> > * getListaNodosAdyacentes(NodeInfo info);
		DNode<NodoGrafo<NodeInfo> > * getNodo(NodeInfo info);
		
		DNode<ArcoGrafo<ArcInfo,NodeInfo> > * getListaArcosAdyacentes(NodeInfo info);
		
		void resetGrafo();
		
		Grafo<NodeInfo,ArcInfo> & operator = ( Grafo<NodeInfo,ArcInfo> & gra);
		void VisitarNodo(NodeInfo info);
		bool VisitadoEsteNodo(NodeInfo info);
		void ExpandirNodo(NodeInfo info);
		bool ExpandidoEsteNodo(NodeInfo info);
		void aumentarAcumuladoNodo(NodeInfo info,int acumulado);
		int acumuladoDeEsteNodo(NodeInfo info);
};

/**
	@brief Constructor por omision de la clase Grafo
*/
template <class NodeInfo,class ArcInfo> 
Grafo<NodeInfo,ArcInfo>::Grafo()
{
	NumNodos = 0;
	NumArcos = 0;
}

/**
	@brief destructor de la clase Grafo
*/
template <class NodeInfo,class ArcInfo> 
Grafo<NodeInfo,ArcInfo>::~Grafo()
{
}

/**
	@brief Retorna el numero de Nodos en el grafo
	@return El numero de nodos del grafo >=0;
*/
template <class NodeInfo,class ArcInfo> 
unsigned int Grafo<NodeInfo,ArcInfo>::getNumNodos()
{
	return NumNodos;
}

/**
	@brief Retorna el numero de Arcos en el grafo
	@return El numero de Arcos del grafo >=0;
*/
template <class NodeInfo,class ArcInfo> 
unsigned int Grafo<NodeInfo,ArcInfo>::getNumArcos()
{
	return NumArcos;
}

/**
	@brief Inserta un nodo en el grafo. 
	Verifica que el nodo no se encuentre repetido
	@param info la informacion con la cual se inicializara el nodo
	@return Nada
*/
template <class NodeInfo,class ArcInfo> 
void Grafo<NodeInfo,ArcInfo>::insertarNodo(NodeInfo  info)
{
	//Verificamos que el nodo ya no este insertado
	bool insertado = this->buscarNodo(info);
	
	if(!insertado)
	{
		//creamos el nodo y lo insertamos
		DNode<NodoGrafo<NodeInfo> > * aux;
		aux = new DNode<NodoGrafo<NodeInfo> >;
		aux->getData().getDataNode() = info;
		ListaNodos.insertPrev(aux);
		
		NumNodos++;
	}
	
}

/**
	@brief Verifica si el nodo se encuentra insertado en el grafo
	@param info la informacion del nodo
	@return True si se encuentra, False de lo contrario
*/
template <class NodeInfo,class ArcInfo> 
bool Grafo<NodeInfo,ArcInfo>::buscarNodo(NodeInfo  info)
{
	//Verificamos que el nodo exista
	bool insertado = false;
	DNode<NodoGrafo<NodeInfo> > * aux;
	aux = &ListaNodos;
	aux = ListaNodos.getNext();
	while(aux != &ListaNodos)
	{
		if(aux->getData().getDataNode() == info)
		{
			insertado = true;
		}
		aux = aux->getNext();
	}
	
	return insertado;
}

/**
	@brief Elimina un nodo del grafo. 
	Elimina todos los arcos relacionados con ese Nodo
	@param info la informacion del nodo a eliminar
	@return Nada
*/
template <class NodeInfo,class ArcInfo> 
void Grafo<NodeInfo,ArcInfo>::eliminarNodo(NodeInfo  info)
{
	//Verificamos que el nodo ya no este insertado
	bool insertado = this->buscarNodo(info);
	
	if(insertado)
	{
		//eliminamos el nodo
		bool eliminado = false;
		DNode<NodoGrafo<NodeInfo> > * aux;
		aux = &ListaNodos;
		aux = ListaNodos.getNext();
		
		while((aux != &ListaNodos) && (!eliminado))
		{
			if(aux->getData().getDataNode() == info)
			{
				//obtengo el nodo... primero elimino todos los arcos 
				//que tengan referencia a el
				DNode<ArcoGrafo<ArcInfo,NodeInfo> > * aux1;
				aux1 = &ListaArcos;
				aux1 = ListaArcos.getNext();
				while(aux1 != &ListaArcos)
				{
					if((aux1->getData().getNodoOrigen() == info) || (aux1->getData().getNodoDestino() == info))
					{
						this->eliminarArco(aux1->getData().getDataArc(),aux1->getData().getNodoOrigen(),aux1->getData().getNodoDestino());
						aux1 = ListaArcos.getNext();
						
					}
					else
					{
						aux1 = aux1->getNext();
					}
					
				}
				
				aux->deleteNode();
				eliminado = true;
			}
			else
			{
				aux = aux->getNext();
			}
		}
		
		if(eliminado)
			NumNodos--;
	}
	
}

/**
	@brief Inserta un arco en el grafo. 
	Verifica que no se encuentre repetido dicho Arco.
	@param info la informacion con la cual se inicializara el arco
	@param origen el nodo origen del arco
	@param destino el nodo destino del arco
	@return Nada
*/
template <class NodeInfo,class ArcInfo> 
void Grafo<NodeInfo,ArcInfo>::insertarArco(ArcInfo info,NodeInfo origen,NodeInfo destino)
{
	//Verificamos que el nodo origen no este insertado
	bool insertado = this->buscarNodo(origen);
	
	if(!insertado)
	{
		this->insertarNodo(origen);
	}
	//Verificamos que el nodo destino no este insertado
	insertado = this->buscarNodo(destino);
	
	if(!insertado)
	{
		this->insertarNodo(destino);
	}
	
	//verificamos que el arco no exista
	if(!this->buscarArco(info,origen,destino))
	{
		DNode<ArcoGrafo<ArcInfo,NodeInfo> > * aux;
		aux = new DNode<ArcoGrafo<ArcInfo,NodeInfo> >;
		aux->getData().getDataArc() = info;
		aux->getData().getNodoOrigen() = origen;
		aux->getData().getNodoDestino() = destino;
		
		ListaArcos.insertPrev(aux);
		
		NumArcos++;
		
	}
	
}

/**
	@brief Verifica si el arco se encuentra insertado en el grafo
	@param info la informacion del arco
	@param origen el nodo origen del arco
	@param destino el nodo destino del arco
	@return True si se encuentra, False de lo contrario
*/
template <class NodeInfo,class ArcInfo> 
bool Grafo<NodeInfo,ArcInfo>::buscarArco(ArcInfo info,NodeInfo origen,NodeInfo destino)
{
	//Verificamos que el arco exista
	bool insertado = false;
	DNode<ArcoGrafo<ArcInfo,NodeInfo> > * aux;
	aux = &ListaArcos;
	aux = ListaArcos.getNext();
	while(aux != &ListaArcos)
	{
		if((aux->getData().getDataArc() == info) && (aux->getData().getNodoOrigen() == origen) && (aux->getData().getNodoDestino() == destino))
		{
			insertado = true;
		}
		aux = aux->getNext();
	}
	
	return insertado;
	
}

/**
	@brief Elimina un arco del grafo
	@param info la informacion del arco
	@param origen informacion del nodo origen del arco
	@param destino informacion del nodo destino del arco
	@return Nada
*/
template <class NodeInfo,class ArcInfo> 
void Grafo<NodeInfo,ArcInfo>::eliminarArco(ArcInfo info,NodeInfo origen,NodeInfo destino)
{
	//Verificamos que el nodo origen este insertado
	bool insertado = this->buscarNodo(origen);
	
	if(!insertado)
	{
		return;
	}
	//Verificamos que el nodo destino este insertado
	insertado = this->buscarNodo(destino);
	
	if(!insertado)
	{
		return;
	}
	
	//verificamos que el arco exista
	if(this->buscarArco(info,origen,destino))
	{
		//eliminamos el arco del grafo
		bool eliminado = false;
		DNode<ArcoGrafo<ArcInfo,NodeInfo> > * aux;
		aux = &ListaArcos;
		aux = ListaArcos.getNext();
		
		while((aux != &ListaArcos)&&(!eliminado))
		{
			if((aux->getData().getDataArc() == info) && (aux->getData().getNodoOrigen() == origen) && (aux->getData().getNodoDestino() == destino))
			{
				aux->deleteNode();
				eliminado = true;
			}
			else
			{
				aux = aux->getNext();
			}
			
		}
		
		if(eliminado)
			NumArcos--;
		
	}
	
}


/**
	@brief Retorna un puntero de la lista de nodos del grafo
	@return Lista de Nodos DNode<NodoGrafo<NodeInfo> > * que se encuentra
	dentro del grafo
*/
template <class NodeInfo,class ArcInfo>
DNode<NodoGrafo<NodeInfo> > * Grafo<NodeInfo,ArcInfo>::getListaNodosPuntero()
{
	return &ListaNodos;
}

/**
	@brief Retorna la lista de nodos en el grafo
	@return Lista de Nodos DNode<NodoGrafo<NodeInfo> > & que se encuentra
	dentro del grafo
*/
template <class NodeInfo,class ArcInfo>
DNode<NodoGrafo<NodeInfo> > & Grafo<NodeInfo,ArcInfo>::getListaNodos()
{
	return ListaNodos;
}

/**
	@brief Retorna un puntero de la lista de arcos en el grafo
	@return Lista de Arcos DNode<ArcoGrafo<ArcInfo,NodeInfo> > * que se encuentra
	dentro del grafo
*/
template <class NodeInfo,class ArcInfo>
DNode<ArcoGrafo<ArcInfo,NodeInfo> > * Grafo<NodeInfo,ArcInfo>::getListaArcosPuntero()
{
	return &ListaArcos;
}

/**
	@brief Retorna la lista de arcos en el grafo
	@return Lista de Arcos DNode<ArcoGrafo<ArcInfo,NodeInfo> > & que se encuentra
	dentro del grafo
*/
template <class NodeInfo,class ArcInfo>
DNode<ArcoGrafo<ArcInfo,NodeInfo> > & Grafo<NodeInfo,ArcInfo>::getListaArcos()
{
	return ListaArcos;
}

/**
	@brief Retorna la lista de nodos adyacentes de un nodo cualquiera en el grafo
	@return Lista de NodosAdyacentes  DNode<NodoGrafo<NodeInfo> > & que se encuentra
	dentro del grafo
*/
template <class NodeInfo,class ArcInfo>
DNode<NodoGrafo<NodeInfo> > * Grafo<NodeInfo,ArcInfo>::getListaNodosAdyacentes(NodeInfo info)
{
	DNode<NodoGrafo<NodeInfo> > * listaNodosAdyacentes = new DNode<NodoGrafo<NodeInfo> >;
	
	DNode<ArcoGrafo<ArcInfo,NodeInfo> > * aux;
	aux = &ListaArcos;
	aux = ListaArcos.getNext();
	while(aux != &ListaArcos)
	{
		if((aux->getData().getNodoOrigen() == info))
		{
			DNode<NodoGrafo<NodeInfo> > * ad;
			ad = this->getNodo(aux->getData().getNodoDestino());
			DNode<NodoGrafo<NodeInfo> > * ins;
			ins = new DNode<NodoGrafo<NodeInfo> > ;
			ins->getData() = ad->getData();
			listaNodosAdyacentes->insertPrev(ins);
		}
		aux = aux->getNext();
	}
	
	if(listaNodosAdyacentes->isEmpty())
		return NULL;
	
	return listaNodosAdyacentes;
}

/**
	@brief Retorna el puntero a un nodo en el grafo
	@return Retorna el pntero del NodoGrafo o NULL
*/
template <class NodeInfo,class ArcInfo>
DNode<NodoGrafo<NodeInfo> > * Grafo<NodeInfo,ArcInfo>::getNodo(NodeInfo info)
{
	DNode<NodoGrafo<NodeInfo> > * ret = NULL;
	DNode<NodoGrafo<NodeInfo> > * aux = NULL;
	bool encontrado = false;
	aux = &ListaNodos;
	aux = ListaNodos.getNext();
	while ((aux != &ListaNodos)&&(!encontrado))
	{
		if(aux->getData().getDataNode() == info)
		{
			encontrado = true;
			ret = aux;
		}
		aux = aux->getNext();
	}
	
	return ret;
}

/**
	@brief Reinicia todos los Bits de control de los nodos del grafo. 
	@return Nada
*/
template <class NodeInfo,class ArcInfo> 
void Grafo<NodeInfo,ArcInfo>::resetGrafo()
{
	DNode<NodoGrafo<NodeInfo> > * aux;
	//reiniciamos todos los nodos
	aux = &ListaNodos;
	aux = ListaNodos.getNext();
	while(aux != &ListaNodos)
	{
		aux->getData().reiniciarNodo();
		
		aux = aux->getNext();
	}
	
	//reiniciamos todos los arcos
	DNode<ArcoGrafo<ArcInfo,NodeInfo> > * aux1;
	aux1 = &ListaArcos;
	aux1 = ListaArcos.getNext();
	while(aux1 != &ListaArcos)
	{
		aux1->getData().reiniciarArco();
		aux1 = aux1->getNext();
	}
	
	
}

/**
	@brief Sobrecarga del operador de asignacion
	@return la copia del grafo
*/
template <class NodeInfo,class ArcInfo> 
Grafo<NodeInfo,ArcInfo>& Grafo<NodeInfo,ArcInfo>::operator = (Grafo<NodeInfo,ArcInfo> &gra)
{
  //copiamos la info
  this->NumArcos = gra.NumArcos;
  this->NumNodos = gra.NumNodos;
  
  //copiamos toda la info de los nodos
  DNode<NodoGrafo<NodeInfo> > * aux;
	aux = &gra.ListaNodos;
	aux = gra.ListaNodos.getNext();
	while(aux != &gra.ListaNodos)
	{
			DNode<NodoGrafo<NodeInfo> > * a;
		a = new DNode<NodoGrafo<NodeInfo> >;
				a->getData().getDataNode() = aux->getData().getDataNode();
		ListaNodos.insertPrev(a);
		
		aux = aux->getNext();
	}
  
  //copiamos toda la info de los arcos
  	DNode<ArcoGrafo<ArcInfo,NodeInfo> > * aux1;
	aux1 = &gra.ListaArcos;
	aux1 = gra.ListaArcos.getNext();
	while(aux1 != &gra.ListaArcos)
	{

		DNode<ArcoGrafo<ArcInfo,NodeInfo> > * b;
		b = new DNode<ArcoGrafo<ArcInfo,NodeInfo> >;
		b->getData().getDataArc() = aux1->getData().getDataArc();
		b->getData().getNodoOrigen() = aux1->getData().getNodoOrigen();
		b->getData().getNodoDestino() = aux1->getData().getNodoDestino();
		ListaArcos.insertPrev(b);
		aux1 = aux1->getNext();
	}
	
	
  return *this;  
  
}
/**
	@brief Cambia el bit de visitado del nodo
	@param info la informacion del nodo
	@return nada
*/
template <class NodeInfo,class ArcInfo> 
void  Grafo<NodeInfo,ArcInfo>::VisitarNodo(NodeInfo  info)
{
	//Verificamos que el nodo exista
	DNode<NodoGrafo<NodeInfo> > * aux;
	aux = &ListaNodos;
	aux = ListaNodos.getNext();
	while(aux != &ListaNodos)
	{
		if(aux->getData().getDataNode() == info)
		{
			aux->getData().getBits().visitar();
		}
		aux = aux->getNext();
	}
}

/**
	@brief verifica si un nodo ha sido visitado previamente
	@param info la informacion del nodo
	@return True si ha sido visitado, False en caso contrario
*/
template <class NodeInfo,class ArcInfo> 
bool  Grafo<NodeInfo,ArcInfo>::VisitadoEsteNodo(NodeInfo  info)
{
	//Verificamos que el nodo exista
	bool visi = false;
	DNode<NodoGrafo<NodeInfo> > * aux;
	aux = &ListaNodos;
	aux = ListaNodos.getNext();
	while(aux != &ListaNodos)
	{
		if(aux->getData().getDataNode() == info)
		{
			if(aux->getData().getBits().estaVisitado())
			{
				visi = true;
			}
		}
		aux = aux->getNext();
	}
	return visi;
}

/**
	@brief Retorna la lista de arcos adyacentes de un nodo cualquiera en el grafo
	@return Lista de ArcosAdyacentes  DNode<ArcoGrafo<ArcInfo,NodeInfo> > * que se encuentra
	dentro del grafo
*/
template <class NodeInfo,class ArcInfo>
DNode<ArcoGrafo<ArcInfo,NodeInfo> > * Grafo<NodeInfo,ArcInfo>::getListaArcosAdyacentes(NodeInfo info)
{
	DNode<ArcoGrafo<ArcInfo,NodeInfo> > * listaArcosAdyacentes = new DNode<ArcoGrafo<ArcInfo,NodeInfo> >;
	
	DNode<ArcoGrafo<ArcInfo,NodeInfo> > * aux;
	aux = &ListaArcos;
	aux = ListaArcos.getNext();
	while(aux != &ListaArcos)
	{
		if((aux->getData().getNodoOrigen() == info))
		{
			DNode<ArcoGrafo<ArcInfo,NodeInfo> > * aux1;
			aux1 = new DNode<ArcoGrafo<ArcInfo,NodeInfo> >;
			aux1->getData().getDataArc() = aux->getData().getDataArc();
			aux1->getData().getNodoOrigen() = aux->getData().getNodoOrigen();
			aux1->getData().getNodoDestino() = aux->getData().getNodoDestino();
			listaArcosAdyacentes->insertPrev(aux1);
		}
		aux = aux->getNext();
	}
	
	if(listaArcosAdyacentes->isEmpty())
		return NULL;
	
	return listaArcosAdyacentes;
}

/**
	@brief Cambia el bit de expandido del nodo
	@param info la informacion del nodo
	@return nada
*/
template <class NodeInfo,class ArcInfo> 
void  Grafo<NodeInfo,ArcInfo>::ExpandirNodo(NodeInfo  info)
{
	//Verificamos que el nodo exista
	DNode<NodoGrafo<NodeInfo> > * aux;
	aux = &ListaNodos;
	aux = ListaNodos.getNext();
	while(aux != &ListaNodos)
	{
		if(aux->getData().getDataNode() == info)
		{
			aux->getData().getBits().expandirNodo();
		}
		aux = aux->getNext();
	}
}

/**
	@brief verifica si un nodo ha sido expandido previamente
	@param info la informacion del nodo
	@return True si ha sido visitado, False en caso contrario
*/
template <class NodeInfo,class ArcInfo> 
bool  Grafo<NodeInfo,ArcInfo>::ExpandidoEsteNodo(NodeInfo  info)
{
	//Verificamos que el nodo exista
	bool visi = false;
	DNode<NodoGrafo<NodeInfo> > * aux;
	aux = &ListaNodos;
	aux = ListaNodos.getNext();
	while(aux != &ListaNodos)
	{
		if(aux->getData().getDataNode() == info)
		{
			if(aux->getData().getBits().isExpandido())
			{
				visi = true;
			}
		}
		aux = aux->getNext();
	}
	return visi;
}


/**
	@brief Cambia el acumulado de expandido del nodo
	@param info la informacion del nodo
	@return nada
*/
template <class NodeInfo,class ArcInfo> 
void  Grafo<NodeInfo,ArcInfo>::aumentarAcumuladoNodo(NodeInfo  info, int acumulado)
{
	//Verificamos que el nodo exista
	DNode<NodoGrafo<NodeInfo> > * aux;
	aux = &ListaNodos;
	aux = ListaNodos.getNext();
	while(aux != &ListaNodos)
	{
		if(aux->getData().getDataNode() == info)
		{
			aux->getData().getBits().aumentarAcumulado(acumulado);
		}
		aux = aux->getNext();
	}
}

/**
	@brief retorna el valor acumulado
	@param info la informacion del nodo
	@return valor acumulado
*/
template <class NodeInfo,class ArcInfo> 
int  Grafo<NodeInfo,ArcInfo>::acumuladoDeEsteNodo(NodeInfo  info)
{
	//Verificamos que el nodo exista
	int visi = -1;
	DNode<NodoGrafo<NodeInfo> > * aux;
	aux = &ListaNodos;
	aux = ListaNodos.getNext();
	while(aux != &ListaNodos)
	{
		if(aux->getData().getDataNode() == info)
		{
			visi = aux->getData().getBits().getAcumulado();
		}
		aux = aux->getNext();
	}
	return visi;
}


#endif
