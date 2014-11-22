//File: Node.cpp
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int c, int e)
{
	coefficient = c;
	exponent = e;
}

Node::Node()
{
	coefficient = 0;
	exponent = 0;
}
