/*Clase Termino, usada para formar polinomios
Realizada por:
Erik Velasquez*/

#ifndef TERMINO_H
#define TERMINO_H

#include<iostream>
using namespace std;

class Termino
{

	float coef;		//coeficiente 
	int exp;		//exponente

	public:

	Termino(){};
	~Termino(){};
	
	//obtener el coeficiente
	float get_coef()
	{
		return coef;
	};	
	
	//obtener el exponente
	int get_exp();

	//asignar coeficiente
	void set_coef(float p)
	{
		coef=p;
	};
	
	//asignar exponente
	void set_exp(int );

	//sobrecarga operador <<
	friend ostream& operator << (ostream&, const Termino&);

	//sobrecarga operador >>
        friend istream& operator >> (istream&, Termino&);

};

//obtener exponente
int Termino::get_exp()
{
	return exp;
}

//asignar exponente
void Termino::set_exp(int x)
{
	exp=x;
}


#endif










