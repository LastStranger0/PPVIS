#include "dict.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

dict::dict(string en, string ru, dict* l, dict* r) :
	eng(en), rus(ru), left(l), right(r)
{
}

dict::dict() : left(NULL), right(NULL)
{};

void dict::operator+=(dict* newnode) {
	dict* t = this;
	bool find = 1;
	if (t->eng == newnode->eng) {
		return;
	}
	while (find && t) {
		bool findl = false, findr = false;
		t->eng < newnode->eng ? findr = 1 : findl = 1;
		if (findr == 1) {
			if (t->right != NULL) {
				t = t->right;
			}
			else {
				t->right = newnode;
				find = 0;
				findl = false;
				findr = false;
			}
		}
		if (findl == 1) {
			if (t->left != NULL) {
				t = t->left;
			}
			else {
				t->left = newnode;
				find = 0;
				findl = false;
				findr = false;
			}
		}
	}
}



void dict::newstring(string en, string ru) {
	this->eng = en;
	this->rus = ru;
}

string dict::engret() {
	return this->eng;
}

string dict::rusret() {
	return this->rus;
}

void dict::operator-=(string en) {
	dict* del, * prev_del, * r, * prev_r;
	del = this;
	prev_del = NULL;
	while (del != NULL && del->eng != en) {
		prev_del = del;
		if (del->eng > en) del = del->left;
		else del = del->right;
	}
	if (del == NULL) {
		return;
	}
	if (del->right == NULL) r = del->right;
	else {
		prev_r = del;
		r = del->left;
		while (r->right != NULL) {
			prev_r = r;
			r = r->right;
		}
		if (prev_r == del) r->right = del->right;
		else {
			r->right = del->right;
			prev_r->right = r->left;
			r->left = prev_r;
		}
	}
	if (del != this)
		if (del->eng < prev_del->eng) {
			prev_del->left = r;
		}
		else prev_del->right = r;
	delete del;
}

dict* dict::search(dict* root, string find) {
	dict* t = root;
	bool fin = 1, findl = 0, findr = 0;
	while (fin)
	{
		if (find == t->eng) return t;
		if (find < t->eng) findl = 1;
		else if (find > t->eng) findr = 1;
		if (findl) {
			if (find == t->eng) return t;
			else {
				if (t->left != NULL) {
					return search(t->left, find);
				}
				else return NULL;
			}
		}
		if (findr) {
			if (find == t->eng) return t;
			else {
				if (t->right != NULL) {
					return search(t->right, find);
				}
				else return NULL;
			}
		}
	}
}

dict* dict::operator[](string find) {
	return search(this, find);
}


void dict::operator() (string newslovo) {
	this->rus = newslovo;
}

//vector<vector<string> > dict::balansing(vector<vector<string>> result) {
//	vector<string> temp;
//	temp.push_back(this->eng);
//	temp.push_back(this->rus);
//	result.push_back(temp);
//
//}

int dict::count_of_words(dict* root) {
	if (root->left == NULL && root->right == NULL) return 1;
	int left, right;
	if (root->left != NULL) left = count_of_words(root->left);
	else left = 0;
	if (root->right != NULL) right = count_of_words(root->right);
	else right = 0;
	return left + right + 1;
}

void dict::fromdoc(string filname) {
	ifstream file(filname + ".txt");
	string ru, en;
	file >> en >> ru;
	this->eng = en;
	this->rus = ru;
	while (!file.eof()) {
		file >> en >> ru;
		dict* temp = new dict(en, ru, NULL, NULL);
		*this += temp;
	}
}
