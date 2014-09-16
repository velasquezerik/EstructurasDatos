#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"Polinomio.H"


using namespace std;

void sumarListas(DNode<int> &L1,DNode<int> &L2, DNode<int> &Suma)
{

	if(L1.isEmpty() and L2.isEmpty())
		return;

	if(!Suma.isEmpty())
		return;


	DNode<int> *aux1,*aux2;

	int llevo=0;
	aux1= L1.getNext();
	aux2= L2.getNext();


	while(aux1!=&L1 and aux2!=&L2)
	{
		int valor = aux1->getData()+aux2->getData()+llevo;

		if(valor>9)
		{
			llevo=1;
			valor= valor%10;
		}
		else
		{
			llevo=0;
		}
	
		DNode<int> *s;
		s= new DNode<int>(valor);
		Suma.insertNext(s);

		aux1=aux1->getNext();
		aux2=aux2->getNext();
	}

	while(aux1!=&L1)
	{
		int valor = aux1->getData()+llevo;

		if(valor>9)
		{
			llevo=1;
			valor= valor%10;
		}
		else
		{
			llevo=0;
		}
	
		DNode<int> *s;
		s= new DNode<int>(valor);
		Suma.insertNext(s);

		aux1=aux1->getNext();

	}	

	while(aux2!=&L2)
	{
		int valor = aux2->getData()+llevo;

		if(valor>9)
		{
			llevo=1;
			valor= valor%10;
		}
		else
		{
			llevo=0;
		}
	
		DNode<int> *s;
		s= new DNode<int>(valor);
		Suma.insertNext(s);
		aux2=aux2->getNext();
	}

	if(llevo==1)
	{
		
		DNode<int> *s;
		s= new DNode<int>(llevo);
		Suma.insertNext(s);
	}
}



int main()
{
	/*Polinomio p;

	Termino h;
	for(int i=0;i<5;i++)
	{
		int ex;
		float co;
		cout<<"Exp: ";cin>>ex;
		cout<<"Coef: ";cin>>co;
		h.set_coef(co);
		h.set_exp(ex);
	
		p.insertar_Terminos(h);	
	}
	
	p.mostrar_polinomio();*/	

	DNode<int> L1,L2,Suma;

	for(int i=0;i<10;i++)
	{
		DNode<int>* aux;
		int p = rand()%10;
		aux= new DNode<int>(p);	
		L1.insertNext(aux);
	}
	for(int i=0;i<17;i++)
	{
		DNode<int>* aux;
		int p = rand()%10;
		aux= new DNode<int>(p);	
		L2.insertNext(aux);
	}

	sumarListas(L1,L2,Suma);

	for(DNode<int>::Iterator it(L1); it.hasCurrent();it.next())
	{
		cout<<it.getCurrent()->getData();
	}	
	cout<<endl;
	for(DNode<int>::Iterator it(L2); it.hasCurrent();it.next())
	{
		cout<<it.getCurrent()->getData();
	}	
	cout<<endl;
	for(DNode<int>::Iterator it(Suma); it.hasCurrent();it.next())
	{
		cout<<it.getCurrent()->getData();
	}	
	cout<<endl;

return 0;
}
