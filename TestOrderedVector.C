#include <iostream>
#include "OrderedVector.H"
#include "VectorUtils.H"
using namespace std;

void imprimirVector(OrderedVector<int> & vector)
{
	//verificamos acceso al vector
	cout<<"Vector[...]: "<<endl;
	for(int i=0;i<vector.getSize();i++)
	{
		cout<<vector[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	cout<<"Prueba de Vector Ordenado parametrico secuencial"<<endl;
	cout<<"el cual contiene manejo de excepciones simples"<<endl;
	//constructor por omision
	OrderedVector<int> vector;
	//insertamos elementos
	int a = 2;
	vector.insert(a);
	vector.insert(10);
	for(int i=3;i<12;i++)
	{
		vector.insert(i);
	}
	
	//verificamos acceso al vector
	cout<<"Vector[1]: "<<vector[1]<<endl;
	imprimirVector(vector);
	
	//constructor por copia
	OrderedVector<int> vector2(vector);
	
	//verificamos operador ==
	if(vector == vector2)
	{
		cout<<"vectores iguales"<<endl;
	}
	
	//verificamos operador =
	OrderedVector<int> vector3;
	vector3 = vector;
	vector3.insert(4);
	
	//verificamos operador !=
	if(vector != vector3)
	{
		cout<<"vectores diferentes"<<endl;
	}
	
	//removemos el ultimo elemento
	vector.removeLast();
	
	//removemos un elementos cualquiera
	vector.remove(a);
	vector.remove(10);
	
	//insertamos otro vector al vector
	vector.insert(vector2);
		
	//imprimimos el valor final del vector ordenado
	//selectionSort(vector);
	
	imprimirVector(vector);
	
return 0;
}
