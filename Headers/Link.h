/*
* Link.h
*
*  Created on: Mar 18, 2017
*      Author: Mustafa
*/

#ifndef LINK_H
#define LINK_H
#include "includes.h"
//#include <iostream>
//#include <vector>

using namespace std;

class Link {
private:
	char c1, c2;
	float linkCost;
public:
	Link();
	Link(char c1, char c2, float linkCost);
	~Link();
	void operator=(Link &link);

	char getC1();
	char getC2();
	float getLinkCost();

};
#endif
