/**
	@file BinNodeUtils.H
	@brief Clase Metodos utiles sobre alboles binarios
	Encontramos una gran variedad de algoritmos sobre arboles binarios
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013, 3/2014, 8/2014

*/



#ifndef BINNODEUTILS_H
#define BINNODEUTILS_H

#include <iostream>
#include "BinNode.H"
#include "BSTree.H"
#include "AVLTree.H"
#include "Vector.H"
#include "Heap.H"
#include "BinHeap.H"

using namespace std;

/**
	@brief Eliminar recursivamente el arbol
	@param Node cabecera del arbol
*/
template<class T>
void deleteBinNode(BinNode<T> * Node)
{
	if(Node == NULL)
	{
		return;
	}
	deleteBinNode(Node->getL());
	deleteBinNode(Node->getR());
	delete Node;
}

/**
	@brief Recorrido prefijo sobre un arbol binario
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void preorder(BinNode<T> * Node)
{
	if(Node==NULL)
		return;
	cout<<Node->getData()<<" ";			//mostramos el Valor
	preorder(Node->getL());				//izquierda en prefijo
	preorder(Node->getR());				//derecha en prefijo
}
/**
	@brief Recorrido infijo sobre un arbol binario
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void inorder(BinNode<T> * Node)
{
	if(Node==NULL)
		return;
	inorder(Node->getL());				//izquierda en infijo
	cout<<Node->getData()<<" ";			//mostramos el Valor
	inorder(Node->getR());				//derecha en infijo
}
/**
	@brief Recorrido postfijo sobre un arbol binario
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void postorder(BinNode<T> * Node)
{
	if(Node==NULL)
		return;
	postorder(Node->getL());				//izquierda en postfijo
	postorder(Node->getR());				//derecha en postfijo
	cout<<Node->getData()<<" ";			//mostramos el Valor
}

/**
	@brief Recorrido prefijo sobre un ABB
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void preorder(BSTree<T> & Node)
{
	preorder(Node.getRoot());
}
/**
	@brief Recorrido infijo sobre un ABB
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void inorder(BSTree<T> & Node)
{
	inorder(Node.getRoot());
}
/**
	@brief Recorrido postfijo sobre ABB
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void postorder(BSTree<T> & Node)
{
	postorder(Node.getRoot());
}

/**
	@brief Recorrido prefijo sobre un AVL
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void preorder(AVLTree<T> & Node)
{
	preorder(Node.getRoot());
}
/**
	@brief Recorrido infijo sobre un AVL
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void inorder(AVLTree<T> & Node)
{
	inorder(Node.getRoot());
}
/**
	@brief Recorrido postfijo sobre AVL
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void postorder(AVLTree<T> & Node)
{
	postorder(Node.getRoot());
}

/**
	@brief Recorrido prefijo sobre un Heap
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void preorder(BinHeap<T> & Node)
{
	preorder(Node.getRoot());
}
/**
	@brief Recorrido infijo sobre un Heap
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void inorder(BinHeap<T> & Node)
{
	inorder(Node.getRoot());
}
/**
	@brief Recorrido postfijo sobre Heap
	@param Node cabecera del arbol
	@return nada
*/
template<class T>
void postorder(BinHeap<T> & Node)
{
	postorder(Node.getRoot());
}

/**
	@brief Altura sobre arbol binario
	@param Node cabecera del arbol
	@return altura
*/
template<class T>
int height(BinNode<T> * Node)
{
	if(Node==NULL)
		return 0;
		
	int HL = height(Node->getL());				//izquierda en 
	int HR = height(Node->getR());				//derecha en 
	if(HL > HR)
	{
		return (1 + HL);
	}
	else
	{
		return (1 + HR);
	}
}

/**
	@brief Altura sobre arbol binario AVL
	@param Node cabecera del arbol
	@return altura
*/
template<class T>
int heightAVL(BinNode<T> * Node)
{
	if(Node==NULL)
	{
		return 0;
	}
	else
	{
		return Node->getHeight();
	}
}

/**
	@brief Actualiza la Altura arbol binario AVL
	@param Node cabecera del arbol
*/
template<class T>
void updateHeightAVL(BinNode<T> * Node)
{
	if(Node!=NULL)
	{
		Node->getHeight() = 1 + max(heightAVL(Node->getL()),heightAVL(Node->getR()));
	}
}

/**
	@brief Actualiza la Altura arbol binario
	@param Node cabecera del arbol
*/
template<class T>
void updateHeight(BinNode<T> * Node)
{
	if(Node!=NULL)
	{
		Node->getHeight() = 1 + max(heightAVL(Node->getL()),heightAVL(Node->getR()));
	}
}

/**
	@brief Rotar a la Izquierda un Arbol Binario
	@param Node cabecera del arbol
*/
template<class T>
void rotateLeft(BinNode<T> *& Node)
{
	if((Node == NULL))
	{
		return;
	}
	
	BinNode<T> * aux = Node->getL();
	Node->getL() = aux->getR();
	aux->getR() = Node;
	updateHeightAVL(Node);
	updateHeightAVL(aux);
	
	Node = aux;
}
/**
	@brief Rotar a la Derecha un Arbol Binario
	@param Node cabecera del arbol
*/
template<class T>
void rotateRight(BinNode<T> *& Node)
{
	if((Node == NULL))
	{
		return;
	}
	
	BinNode<T> * aux = Node->getR();
	Node->getR() = aux->getL();
	aux->getL() = Node;
	updateHeightAVL(Node);
	updateHeightAVL(aux);
	
	Node = aux;
}
/**
	@brief Doble Rotacion a la izquierda un Arbol Binario
	@param Node cabecera del arbol
*/
template<class T>
void doubleRotationLeft(BinNode<T> *& Node)
{
	if((Node == NULL))
	{
		return;
	}
	rotateRight(Node->getL());
	rotateLeft(Node);
}

/**
	@brief Doble Rotacion a la derecha un Arbol Binario
	@param Node cabecera del arbol
*/
template<class T>
void doubleRotationRight(BinNode<T> *& Node)
{
	if((Node == NULL))
	{
		return;
	}
	
	rotateLeft(Node->getR());
	rotateRight(Node);
	
}

/**
	@brief Balanceamos un Arbol Binario AVL
	@param Node cabecera del arbol
*/
template<class T>
void balancingAVL(BinNode<T> *& Node)
{
	if(Node != NULL)
	{
		
		if((heightAVL(Node->getL()) - heightAVL(Node->getR())) == 2)
		{
				if(heightAVL(Node->getL()->getL()) >= heightAVL(Node->getL()->getR()))
				{
					rotateLeft(Node);
				}
				else
				{
					doubleRotationLeft(Node);
				}
		}
		else
		{
			if((heightAVL(Node->getR()) - heightAVL(Node->getL())) == 2)
			{
					if(heightAVL(Node->getR()->getR()) >= heightAVL(Node->getR()->getL()))
					{
						rotateRight(Node);
					}
					else
					{
						doubleRotationRight(Node);
					}
			}
		}
	}	
}

/**
	@brief insercion en un arbol binario de busqueda (ABB)
	@param Root cabecera del arbol
	@param Node nodo a ser insertado
	@return nodo insertado
*/
template<class T>
BinNode<T>* insertABB(BinNode<T>*& Root, BinNode<T>* Node)
{
	if(Root == NULL)
	{
		Root = Node;
		return Root;
	}
	
	//si clave menor a Root
	if(Node->getData() < Root->getData())
	{
		return insertABB(Root->getL(),Node);
	}
	else
	{
		//si clave mayor a Root
		if(Node->getData() > Root->getData())
		{
			return insertABB(Root->getR(),Node);
		}
	}
	
	//clave repetida
	return NULL;
}

/**
	@brief insercion en un arbol binario balanceado de busqueda (AVL)
	@param Root cabecera del arbol
	@param Node nodo a ser insertado
	@return nodo insertado
*/
template<class T>
BinNode<T>* insertAVL(BinNode<T>*& Root, BinNode<T>* Node)
{
	if(Root == NULL)
	{
		Root = Node;
		balancingAVL(Root);
		updateHeightAVL(Root);
		return Root;
	}
	
	//si clave menor a Root
	if(Node->getData() < Root->getData())
	{
		BinNode<T> * aux = insertAVL(Root->getL(),Node);
		balancingAVL(Root);
		updateHeightAVL(Root);
		return aux;
	}
	else
	{
		//si clave mayor a Root
		if(Node->getData() > Root->getData())
		{
			BinNode<T> * aux = insertAVL(Root->getR(),Node);
			balancingAVL(Root);
			updateHeightAVL(Root);
			return aux;
		}
	}
	balancingAVL(Root);
	updateHeightAVL(Root);
	return NULL;
}

/**
	@brief insercion en un monticulo binario Heap
	@param Root cabecera del arbol
	@param Node nodo a ser insertado
	@return nodo insertado
*/
template<class T>
BinNode<T>* insertHeapMin(BinNode<T>*& Root, BinNode<T>* Node)
{
	return NULL;
}

/**
	@brief insercion en un monticulo binario Heap
	@param Root cabecera del arbol
	@param Node nodo a ser insertado
	@return nodo insertado
*/
template<class T>
BinNode<T>* insertHeapMax(BinNode<T>*& Root, BinNode<T>* Node)
{
	return NULL;
}


/**
	@brief metodo de busqueda en un arbol binario de busqueda (ABB)
	@param root cabecera del arbol
	@param key nodo a ser buscado
	@return nodo encontrado
*/
template<class T>
BinNode<T>* searchABB(BinNode<T>* root, T key)
{
	if(root == NULL)
		return NULL;
		
	//si key menor a Root
	if(key < root->getData())
	{
		return searchABB(root->getL(),key);
	}
	else
	{
		//si key mayor a Root
		if(key > root->getData())
		{
			return searchABB(root->getR(),key);
		}
	}
	
	//clave no se encuentra
	return root;
}


/**
	@brief metodo de busqueda en un arbol binario balanceado de busqueda (AVL)
	@param root cabecera del arbol
	@param key nodo a ser buscado
	@return nodo encontrado
*/
template<class T>
BinNode<T>* searchAVL(BinNode<T>* root, T key)
{
	if(root == NULL)
		return NULL;
		
	//si key menor a Root
	if(key < root->getData())
	{
		return searchAVL(root->getL(),key);
	}
	else
	{
		//si key mayor a Root
		if(key > root->getData())
		{
			return searchAVL(root->getR(),key);
		}
	}
	
	//clave no se encuentra
	return root;
}

/**
	@brief metodo de busqueda en un arbol binario
	@param root cabecera del arbol
	@param key nodo a ser buscado
	@return nodo encontrado
*/
template<class T>
bool searchNode(BinNode<T>* root, T key)
{
	if(root == NULL)
		return false;

	if(key == root->getData())
	{
		return true;
	}
	
	return ((searchNode(root->getL(),key)) or (searchNode(root->getR(),key)));

}

/**
	@brief metodo de busqueda en un monticulo binario
	@param root cabecera del arbol
	@param key nodo a ser buscado
	@return nodo encontrado
*/
template<class T>
BinNode<T>* searchHeap(BinNode<T>* root, T key)
{
	if(root == NULL)
		return NULL;

	if(key == root->getData())
	{
		return root;
	}
	BinNode<T>* left = searchHeap(root->getL(),key);
	BinNode<T>* right = searchHeap(root->getR(),key);
	
	if(left != NULL)
	{
		return left;
	}
	else
	{
		if(right != NULL)
		{
			return right;
		}
		else
		{
			return NULL;
		}
	}

}

/**
	@brief armar un arbol binario a traves del recorrido prefijo e infijo
	@return cabecera del arbol armado
*/
template<class T>
BinNode<T>* buildTree( T pre[], T inf[], int l_pre, int r_pre, int l_inf, int r_inf)
{
	//verificamos indices 
	if(r_pre<l_pre)
		return NULL;

	if(r_inf<l_inf)
		return NULL;	
		
	//creamos el nodo Raiz
	BinNode<T>* Raiz = new BinNode<T>(pre[l_pre]);
	
	//verificamos si es un nodo unico
	if(r_pre==l_pre)
	{
		return Raiz;
	}
	
	//contamos el numero de nodos de la rama Izquierda
	int i=0;
	for(int j=l_inf;j<r_inf;++j)
	{
		if(pre[l_pre]==inf[j])
		{
			i=j-l_inf;
			break;
		}
	}
	//mandamos a armar el subArbol Izquierdo
	Raiz->getL()=buildTree(pre, inf, l_pre+1, l_pre+i, l_inf, (i-1)+l_inf);
	//mandamos a armar el subArbol Derecho
	Raiz->getR()=buildTree(pre,inf,l_pre+i+1, r_pre, l_inf+i+1, r_inf);

	return Raiz;
	
}

/**
	@brief creamos un heap a partir de un ABB
	@return cabecera del heap armado
*/
template<class T>
BinNode<T>* buildABHeap(Vector<T> &heap,int l,int r)
{

	if(l>r)
		return NULL;

	if(l==0 or r==0)
		return NULL;


	BinNode<T> * Raiz = new BinNode<T>(heap[l]);

	int Izq = 2*l;
	int Der = 2*l+1;

	Raiz->getL()=buildABHeap(heap,Izq,r);
	Raiz->getR()=buildABHeap(heap,Der,r);


	return Raiz;

}

/**
	@brief metodo que compara dos arboles binarios y verifica sin son equivalentes
	@param t1 raiz del primer arbol
	@param t2 raiz del segundo arbol
	@return verdadero en caso de ser equivalentes, falso en caso contrario
*/
template<class T>
bool areEquivalents(BinNode<T>* t1, BinNode<T>* t2)
{
	if((t1 == NULL) and (t2 == NULL))
	{
		return true;
	}
	if((t1 == NULL) or (t2 == NULL))
	{
		return false;
	}
	if(t1->getData() != t2->getData())
	{
		return false;
	}
	
	return ((areEquivalents(t1->getL(),t2->getL())) and (areEquivalents(t1->getR(),t2->getR())));
}

/**
	@brief verifica cada nodo del arbol y verifica si su subarbol es equivalente
	@param root arbol principal
	@param Node subarbol a verificar
	@return verdadero si el subarbol se encuentra
*/
template<class T>
void checkInTreeRec(BinNode<T>* root, BinNode<T> * Node, bool & value)
{
	if(value)
	{
		return;
	}
	if(root == NULL)
	{
		value = areEquivalents(root,Node);
		return;
	}
	value = areEquivalents(root,Node);
	checkInTreeRec(root->getL(),Node, value);
	checkInTreeRec(root->getR(),Node, value);
	
}

/**
	@brief metodo que verifica si un arbol esta contenido dentro de otro
	@param root raiz del Arbol principal
	@param t raiz del arbol a buscar
	@return verdadero en caso de estar contenico, falso en caso contrario
*/
template<class T>
bool checkInTree(BinNode<T>* root, BinNode<T>* t)
{
	bool value = false;
	checkInTreeRec(root,t,value);
	return value;
}

/**
	@brief submetodo de deleteNode
	@param root raiz del Arbol principal
	@param key clave del nodo a eliminar
	@return verdadero en caso de ser eliminado, falso en caso contrario
*/
template<class T>
bool deleteNodeRec(BinNode<T>* root, T key)
{
	if(root == NULL)
	{
		return false;
	}
	if(root->getL() != NULL)
	{
		if(root->getL()->getData() == key)
		{
			delete root->getL();
			root->getL()=NULL;
			return true;
		}
	}
	if(root->getR() != NULL)
	{
		if(root->getR()->getData() == key)
		{
			delete root->getR();
			root->getR()=NULL;
			return true;
		}
	}
	
}

/**
	@brief metodo elimina un nodo y su subarbol
	@param root raiz del Arbol principal
	@param key clave del nodo a eliminar
	@return verdadero en caso de ser eliminado, falso en caso contrario
*/
template<class T>
bool deleteNode(BinNode<T>* root, T key)
{
	if(!searchNode(root,key))
	{
		return false;
	}
	
	return deleteNodeRec(root,key);
}



/**
	@brief metodo unir exclusivamente arboles binarios de busqueda
	@param ts raiz izquierda
	@param tg raiz derecha
	@return arbol unido
*/
template<class T>
BinNode<T>* joinExclusive(BinNode<T>*& ts,BinNode<T>*& tg)
{
	if(ts == NULL)
	{
		return tg;
	}
	if(tg == NULL)
	{
		return ts;
	}
	
	tg->getL() = joinExclusive(ts->getR(),tg->getL());
	
	ts->getR() = tg;
	
	BinNode<T> * retVal = ts;
	
	ts = tg = NULL;
	
	return retVal;
}


/**
	@brief remover de un ABB
	@param root raiz del Arbol principal
	@param key clave del nodo a eliminar
	@return nodo eliminado
*/
template<class T>
BinNode<T> * removeFromABB(BinNode<T> *& root, T & key)
{
	if(root == NULL)
	{
		return NULL;
	}
	
	if(key < root->getData())
	{
		return removeFromABB(root->getL(),key);
	}
	if(key > root->getData())
	{
		return removeFromABB(root->getR(),key);
	}
	
	BinNode<T> * retVal = root;
	
	root = joinExclusive(root->getL(),root->getR());
	
	retVal->resetNode();
	
	return retVal;
}

/**
	@brief remover un caso especial de un AVL
	@param root raiz a remover
	@return nodo eliminado
*/
template<class T>
BinNode<T> * removeMinAVL(BinNode<T> *& root)
{	
	if(root == NULL)
	{
		throw NullNode();
	}
	
	if(root->getL() != NULL)
	{
		BinNode<T> * aux = removeMinAVL(root->getL());
		balancingAVL(root);
		updateHeightAVL(root);
		return aux;
	}
	else
	{
		BinNode<T> * aux = root;
		root = root->getR();
		balancingAVL(root);
		updateHeightAVL(root);
		return aux;
	}
}

/**
	@brief remover de un AVL
	@param root raiz del Arbol principal
	@param key clave del nodo a eliminar
	@return nodo eliminado
*/
template<class T>
BinNode<T> * removeFromAVL(BinNode<T> *& root, T & key)
{	
	BinNode<T> * aux;
	if(root == NULL)
	{
		return NULL;
	}
	
	if(key < root->getData())
	{
		return removeFromABB(root->getL(),key);
	}
	if(key > root->getData())
	{
		return removeFromABB(root->getR(),key);
	}
	
	if((root->getL()==NULL) and (root->getR()==NULL) )
	{
		//es una hoja
		aux = root;
		root = NULL;
	}
	else
	{
		if(root->getL()==NULL)
		{
			//izquierdo vacio
			aux = root;
			root = root->getR();
			aux->resetNode();
		}
		else
		{
			if(root->getR()==NULL)
			{
				//derecho vacio
				aux = root;
				root = root->getL();
				aux->resetNode();
			}
			else
			{
				aux = removeMinAVL(root->getR());
				
			}
		}
	}
	balancingAVL(root);
	updateHeightAVL(root);
	return aux;
}

/**
	@brief remover de un Heap
	@param root raiz del Arbol principal
	@param key clave del nodo a eliminar
	@return nodo eliminado
*/
template<class T>
BinNode<T> * removeFromHeap(BinNode<T> *& root, T & key)
{
	return NULL;
}

#endif

