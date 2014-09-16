#include <iostream>
#include <fstream>
#include "BinNodeUtils.H"

using namespace std;

void insertarAVL(AVLTree<int> &AVL,string nomArch)
{
	ifstream arch;
	arch.open(nomArch.c_str());
	if(!arch)
	{
		cout<<"Error: NO Abrio el archivo "<<nomArch<<endl;
	}
	else
	{
		int value;
		while(arch>>value)
		{
			AVL.insert(value);
		}
		arch.close();
	}
}
void insertarBST(BSTree<int> &ABB,string nomArch)
{
	ifstream arch;
	arch.open(nomArch.c_str());
	if(!arch)
	{
		cout<<"Error: NO Abrio el archivo "<<nomArch<<endl;
	}
	else
	{
		int value;
		while(arch>>value)
		{
			ABB.insert(value);
		}
		arch.close();
	}
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout<<"Error: <nombreArchivo> "<<endl;
		return 1;
	}
	string nomArch = argv[1];
	AVLTree<int> AVL;				//declaro un AVL
	BSTree<int> ABB;				//declaro un ABB
	
	//inserto AVL
	clock_t ini;
	clock_t fin;
	ini = clock();
	insertarAVL(AVL,nomArch);
	fin = clock();
	cout<<"Tiempo: "<<(fin - ini)/1000<<" ms"<<endl;
	ini = clock();
	insertarBST(ABB,nomArch);
	fin = clock();
	cout<<"Tiempo: "<<(fin - ini)/1000<<" ms"<<endl;
	
	return 0;
}
