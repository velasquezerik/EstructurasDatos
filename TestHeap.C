#include <iostream>
#include <stdlib.h>
#include "Heap.H"
using namespace std;

int main()
{
	Heap<int> heap;

	for(int i =0;i<10;i++)
	{
		int v = rand()%20;
		heap.insert(v);
	}
	cout<<"Heap"<<endl;
	heap.printHeap();
	cout<<endl;

	cout<<"Mostramos el menor Elemento: "<<heap.getMin()<<endl;

	for(int i = 0;i<5;i++)
	{
		int p = heap.deleteMin();
	}
	
	cout<<"Heap"<<endl;
	heap.printHeap();
	cout<<endl;

	//BinNode<int> * M = heap.getAB();

	//preorder(M);
	cout<<endl;

	return 0;
}

