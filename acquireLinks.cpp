/*
* acquireLinks.cpp
*
*  Created on: Mar 19, 2017
*      Author: Mustafa
*/

//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
#include "includes.h"
//#include <sstream>
using namespace std;

void acquireLinks1(vector<Link> &links) {
	string line;
	string subline;
	float f;

	ifstream myfile("graph.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			subline = line[4];
			istringstream istr(subline);
			istr >> f;
			Link newlink(line[0], line[2], f);
			links.push_back(newlink);
			// cout << line[2] << '\n';
			//line="";

		}
		myfile.close();
	}

	else cout << "Unable to open file";
}


