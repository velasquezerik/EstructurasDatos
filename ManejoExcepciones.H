#ifndef MANEJOEXCEPCIONES_H
#define MANEJOEXCEPCIONES_H
#include <iostream>
#include <exception>
using namespace std;

class NoMemory : public exception
{
	public:
		const char* what() const throw()
		{
			return "Problemas al apartar la memoria";
		}
};
class BadPos : public exception
{
	public:
		const char* what() const throw()
		{
			return "Posicion no valida del Vector";
		}
};
class NullNode : public exception
{
	public:
		const char* what() const throw()
		{
			return "Nodo es Nulo(NULL)";
		}
};

class NodeNotUnitarian : public exception
{
	public:
		const char* what() const throw()
		{
			return "Nodo contiene varios elementos enlazados";
		}
};
class NodeUnitarian : public exception
{
	public:
		const char* what() const throw()
		{
			return "Nodo NO contiene nodos enlazados";
		}
};
class EmptyStack : public exception
{
	public:
		const char* what() const throw()
		{
			return "Pila vacia, no contiene elementos";
		}
};
class EmptyQueue : public exception
{
	public:
		const char* what() const throw()
		{
			return "Cola vacia, no contiene elementos";
		}
};
class EmptyHeap : public exception
{
	public:
		const char* what() const throw()
		{
			return "Heap vacio, no contiene elementos";
		}
};
class ValueNull : public exception
{
	public:
		const char* what() const throw()
		{
			return "Valor inicializado es incorrecto";
		}
};
class NotData : public exception
{
	public:
		const char* what() const throw()
		{
			return "La data no se encuentra";
		}
};

class NotEmptyStack : public exception
{
	public:
		const char* what() const throw()
		{
			return "Pila contiene elementos";
		}
};
class NotEmptyQueue : public exception
{
	public:
		const char* what() const throw()
		{
			return "Cola contiene elementos";
		}
};
class NotTypeHeap : public exception
{
	public:
		const char* what() const throw()
		{
			return "Tipo inicializacion de Heap Incorrecta (0 o 1)";
		}
};

#endif
