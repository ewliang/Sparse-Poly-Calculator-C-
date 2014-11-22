//File: MainProgram.cpp
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#include "SparsePoly.h"
#include "Node.h"
#include <iostream>

using namespace std;

int main()
{
	//Polynomial Creation
	SparsePoly poly1;
	SparsePoly poly2;

	Node *n1 = new Node(1,1);
	Node *n2 = new Node(2,3);
	Node *n3 = new Node(3,5);
	Node *n4 = new Node(4,7);
	Node *n5 = new Node(5,9);

	Node *m1 = new Node(6,1);
	Node *m2 = new Node(7,3);
	Node *m3 = new Node(8,4);

	poly1.Insert(n1);
	poly1.Insert(n2);
	poly1.Insert(n3);
	poly1.Insert(n4);
	poly1.Insert(n5);

	poly2.Insert(m1);
	poly2.Insert(m2);
	poly2.Insert(m3);

	cout << "<<POLYNOMIALS CREATED>>" << endl;

	cout << "Poly1: ";
	poly1.Display();

	cout << "Poly2: ";
	poly2.Display();

	//EMPTY CHECK
	cout << "<<EMPTY CHECK>>" << endl;
	if(poly1.IsEmpty())
	{
		cout << "Polynomial 1 is EMPTY" << endl << endl;
	}
	else
	{
		cout << "Polynomial 1 is NOT EMPTY" << endl << endl;
	}

	//INSERT ONE TERM
	cout << "<<Insert One Term>>" << endl;
	Node *nTerm = new Node(20, 8);
	poly1.Insert(nTerm);
	poly1.Display();

	//DELETE
	cout << "<<Deleting 2x^3 from Poly1>>" << endl;
	poly1.Delete(n2);
	poly1.Display();

	//ADD + Display
	cout << "SUM: ";
	poly1.Add(&poly2, add).Display();

	//MULTIPLY + Display
	cout << "PRODUCT: ";
	poly1.Multiply(&poly2).Display();

	cin.get();
	return 0;
}