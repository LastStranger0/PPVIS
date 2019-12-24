#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#define dict dictionary
using namespace std;

class dict {
public:
	dict(string en, string ru, dict* l, dict* r);
	dict();
	void operator+=(dict* newnode);
	void operator-=(string en);
	dict* operator[](string searc);
	dict* search(dict* root, string searc);
	void operator() (string newslovo);
	int count_of_words(dict* root);
	void fromdoc(string filename);
	string engret();
	string rusret();
	void newstring(string en, string ru);
	//vector<vector<string> > balansing(vector<vector<string> > result);
private:
	dict* left, * right;
	string eng, rus;
};
