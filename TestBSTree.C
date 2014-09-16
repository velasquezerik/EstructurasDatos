#include <iostream>
#include "BinNodeUtils.H"

using namespace std;

int main()
{
	BSTree<int> ABB;				//declaro un ABB
	
	//probamos el metodo de insertar
	for(int i = 0;i < 10; i++)
	{
		BinNode<int>* Node = new BinNode<int>(i);
		ABB.insert(Node);
	}
	
	//verificamos el metodo de buscar
	BinNode<int>* aux = ABB.search(3);
	if(aux != NULL)
	{
		cout<<"El Nodo si se enuentra en el Arbol"<<endl;
	}
	aux = ABB.remove(3);
	if(aux != NULL)
	{
		delete aux;
		cout<<"El Nodo si se removio del Arbol"<<endl;
	}
	
	//preorder(ABB.getRoot());				//recorrido prefijo
	preorder(ABB);
	cout<<endl;
	//inorder(ABB.getRoot());					//recorrido infijo
	inorder(ABB);
	cout<<endl;
	//postorder(ABB.getRoot());				//recorrido postfijo
	postorder(ABB);
	cout<<endl;

	return 0;	
}
