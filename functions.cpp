/*
* functions.cpp
*
*  Created on: Mar 18, 2017
*      Author: Mustafa
*/

//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
#include "functions.h"


using namespace std;

vector<Link> myLink;
void acquireLinks(vector<Link> &links) {

	char c1, c2;
	float linkCost;
	cout << "Enter link info (e.g. a b 3) :";
	cin >> c1 >> c2 >> linkCost;
	Link newlink(c1, c2, linkCost);
	links.push_back(newlink);
	string line;
	ifstream myfile("graph.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";



}


