#ifndef _POLINOMIO
#define _POLINOMIO

#include<iostream>
#include"DNode.H"
#include"Termino.H"

using namespace std;
class Polinomio
{

	//atributos
	DNode<Termino> Lista;

	//metodos
	public:

	Polinomio();
	~Polinomio();


	void insertar_Terminos(Termino &);

	void mostrar_polinomio();

};

Polinomio::Polinomio()
{
}
Polinomio::~Polinomio()
{
}

void Polinomio::insertar_Terminos(Termino &t)
{
	DNode<Termino>*aux;		//nodo del polinomio
	
	aux= new DNode<Termino>(t);	//damos la informacion al nodo

	Lista.insertNext(aux);		//insertamos en la lista de polinomios
}

void Polinomio::mostrar_polinomio()
{

	DNode<Termino>* aux;

	aux= Lista.getNext();

	while(aux!= &Lista)
	{
		cout<<aux->getData().get_coef()<<endl;
		cout<<aux->getData().get_exp()<<endl;

		aux= aux->getNext();
	}	
	
}
















#endif
