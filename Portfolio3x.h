#ifndef PORT3_H
#define PORT3_H

#include <vector>

#include <iostream>

using namespace std;

class Port3 {
public:
	
	Port3(int rowval, int colval, int birthnm, int survivalminimum, int sirvuvalmaximum);
	~Port3();
	
	void makefirstcells();

	void movetogeneration();


	void displaygridlayout() const;

	

	

private: 
	int rowval;
	int colval;
	int birthnm;
	int survivalminimum;
	int survivalmaximum;
	vector<vector<bool>> gridlayout;
	vector<vector<bool>> buffermode;

	int neighboringcellstracker(int a, int b) const;
	bool withinrange(int a, int b) const;


};

#endif