#include <iostream>
#include "BinNodeUtils.H"

using namespace std;

void printHeapPreorder(BinNode<int> * root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->getData()<<"-"<<root->getHeight()<<" ";
	printHeapPreorder(root->getL());
	printHeapPreorder(root->getR()); 
}


int main()
{
	BinHeap<int> heap;				//declaro un heap
	
	//probamos el metodo de insertar
	for(int i = 0;i < 10; i++)
	{
		//BinNode<int>* Node = new BinNode<int>(i);
		//heap.insert(Node);
		heap.insert(i);
	}
	
	//verificamos el metodo de buscar
	BinNode<int>* aux = heap.search(3);
	if(aux != NULL)
	{
		cout<<"El Nodo si se enuentra en el Arbol"<<endl;
	}
	aux = heap.remove(3);
	if(aux != NULL)
	{
		delete aux;
		cout<<"El Nodo si se removio del Arbol"<<endl;
	}
	
	//preorder(heap.getRoot());				//recorrido prefijo
	preorder(heap);
	cout<<endl;
	//inorder(heap.getRoot());					//recorrido infijo
	inorder(heap);
	cout<<endl;
	//postorder(heap.getRoot());				//recorrido postfijo
	postorder(heap);
	cout<<endl;
	
	return 0;
}
