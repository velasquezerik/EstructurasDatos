#include <iostream>
#include "BinNodeUtils.H"

using namespace std;

int main()
{
	BinNode<int> * Node;			//declaro un nodo
	
	Node = new BinNode<int>(5);		//doy valor al nodo
	
	//declaro dos nodos que seran hijos de mi nodo
	BinNode<int> * Left = new BinNode<int>(4);
	BinNode<int> * Right = new BinNode<int>(6);
	
	//conecto mis nodos hijos a mi nodo
	Node->getL()=Left;
	Node->getR()= Right;
	
	preorder(Node);					//recorrido prefijo
	cout<<endl;
	inorder(Node);					//recorrido infijo
	cout<<endl;
	postorder(Node);				//recorrido postfijo
	cout<<endl;

	//Probamos Armar un Arbol a partir de sus Recorridos
	
	int pre[] = {5,4,6};
	int inf[] = {4,5,6};
	
	BinNode<int> * Raiz;			//declaro un nodo
	BinNode<int> * Raiz2;
	Raiz = buildTree(pre,inf,0,2,0,2);
	Raiz2 = buildTree(pre,inf,0,2,0,2);
	preorder(Raiz);					//recorrido prefijo
	cout<<endl;
	inorder(Raiz);					//recorrido infijo
	cout<<endl;
	postorder(Raiz);				//recorrido postfijo
	cout<<endl;

	//Probamos si los arboles son equivalentes
	if(areEquivalents(Raiz,Raiz2))
	{
		cout<<"Son Equivalentes"<<endl;
	}
	else
	{
		cout<<"NO son equivalentes"<<endl;
	}
		//Probamos si los arboles estan contenidos
	if(checkInTree(Raiz,Raiz2))
	{
		cout<<"Contenido"<<endl;
	}
	else
	{
		cout<<"NO contenido"<<endl;
	}
	deleteBinNode(Node);
	deleteBinNode(Raiz);
	deleteBinNode(Raiz2);
	
	return 0;	
}
