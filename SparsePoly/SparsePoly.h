//File: SparsePoly.h
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#include "Node.h"
#include <vector>
using namespace std;

enum state{add = 0, multiply = 1};

class SparsePoly
{
public:
	int polySize;
	vector<Node*> polynomial;

	SparsePoly();
	SparsePoly(int size);
	//~SparsePoly();

	bool IsEmpty();
	void Insert(Node *newNode);
	void Delete(Node *targetNode);
	SparsePoly Add(SparsePoly *operand2, enum state myState);
	SparsePoly Multiply(SparsePoly *operand2);
	void Display();
};