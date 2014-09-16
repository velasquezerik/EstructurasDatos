#include <iostream>
#include "BinNodeUtils.H"

using namespace std;

void printAVLPreorder(BinNode<int> * root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->getData()<<"-"<<root->getHeight()<<" ";
	printAVLPreorder(root->getL());
	printAVLPreorder(root->getR()); 
}

int main()
{
	AVLTree<int> AVL;				//declaro un AVL
	
	//probamos el metodo de insertar
	cout<<"Insertando"<<endl;
	for(int i = 0;i < 10; i++)
	{
		BinNode<int>* Node = new BinNode<int>(i);
		AVL.insert(Node);
	}
	printAVLPreorder(AVL.getRoot());
	cout<<endl;
	//verificamos el metodo de buscar
	cout<<"Buscando"<<endl;
	BinNode<int>* aux = AVL.search(3);
	if(aux != NULL)
	{
		cout<<"El Nodo si se enuentra en el Arbol"<<endl;
	}
	cout<<"Eliminando"<<endl;
	aux = AVL.remove(3);
	if(aux != NULL)
	{
		delete aux;
		cout<<"El Nodo si se removio del Arbol"<<endl;
	}
	
	cout<<"Recorridos"<<endl;
	//preorder(AVL.getRoot());				//recorrido prefijo
	preorder(AVL);
	cout<<endl;
	//inorder(AVL.getRoot());					//recorrido infijo
	inorder(AVL);
	cout<<endl;
	//postorder(AVL.getRoot());				//recorrido postfijo
	postorder(AVL);
	cout<<endl;
	printAVLPreorder(AVL.getRoot());
	cout<<endl;
	
	return 0;	
}
