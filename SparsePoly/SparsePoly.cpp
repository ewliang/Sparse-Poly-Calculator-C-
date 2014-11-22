//File: SparsePoly.cpp
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#include "SparsePoly.h"
#include "Node.h"
#include <iostream>

using namespace std;

SparsePoly::SparsePoly()
{
	polySize = 0;
}

bool SparsePoly::IsEmpty()
{
	if(polySize == 0)
		return true;
	else
		return false;
}

void SparsePoly::Insert(Node *newNode)
{
	 if (polySize == 0)
		 {
			  polynomial.push_back(newNode);
			  polySize++;
		 }

	 else
	 {
		  for (int i = 0; i < polySize; i++) //inserting out of order Nodes
		  {
			  if (polynomial[i]->exponent == newNode->exponent) //combining like terms
			  {
				  Node* tempNode = new Node(polynomial[i]->coefficient + newNode->coefficient, newNode->exponent);
				  polynomial[i] = tempNode;
				  return;
			  }
			  if (polynomial[i]->exponent > newNode->exponent)
			  {
				  polynomial.insert(polynomial.begin() + i, newNode); //insert newNode in proper order
				  polySize++;
				  return;
			  }
		  }
		  polynomial.push_back(newNode); //insert new Node at end
		  polySize++;
	 }
}

void SparsePoly::Delete(Node *targetNode)
{
	if (polySize == 0) //empty polynomial
	{
		return;
	}

	for(int i = 0; i < polySize; i++)
	{
		if(polynomial[i]->exponent == targetNode->exponent)
		{
			delete[] polynomial[i]; //deletes the node from dynamic memory as well
			polynomial.erase(polynomial.begin() + i); //deletes from vector
			polySize--;
		}
	}
}

SparsePoly SparsePoly::Add(SparsePoly *operand2, enum state myState)
{
	SparsePoly sum;
	SparsePoly temp;

	if(myState == add)
	{
		for (int i = 0; i < this->polySize; i++)
		{
			sum.Insert(this->polynomial[i]);
		}
		for (int j = 0; j < operand2->polySize; j++)
		{
			sum.Insert(operand2->polynomial[j]);
		}
	}
	return sum;
}

SparsePoly SparsePoly::Multiply(SparsePoly *operand2)
{
	SparsePoly product;
	Node *tempNode;
	//FOIL
	for(int i = 0; i < this->polySize; i++)
	{
		for(int j = 0; j < operand2->polySize; j++)
		{
			tempNode = new Node(this->polynomial[i]->coefficient * operand2->polynomial[j]->coefficient, this->polynomial[i]->exponent + operand2->polynomial[j]->exponent);
			product.Insert(tempNode);
		}
	}
	return product;
}

void SparsePoly::Display()
{
	if(polySize != 0)
	{
		for(int i = 0; i < polySize; i++)
		{
			cout << polynomial[i]->coefficient;
			cout << "x^" << polynomial[i]->exponent << " ";
		}
		cout << endl << endl;
	}
}