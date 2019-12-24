#include "dict.h"
#include <string>
#include <iostream>
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
	if (this->eng == newnode->eng) {
		return;
	}
	while (find && t) {
		bool findl = false, findr = false;
		this->eng > t->eng ? findr = 1 : findl = 1;
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
	if (root->eng == find) return root;
	dict* result = new dict();
	if (root->left != NULL) {
		result = search(root->left, find);
		if (result != NULL) return result;
	}
	if (root->right != NULL) {
		result = search(root->right, find);
		if (result != NULL) return result;
	}
	return NULL;
}

dict* dict::operator[](string find) {
	return(search(this, find));

}


void dict::redach(dict* noderedach, string newslovo) {
	noderedach->rus = newslovo;
}

int dict::count_of_words(dict* root) {
	if (root->left == NULL && root->right == NULL) return 1;
	int left, right;
	if (root->left != NULL) left = count_of_words(root->left);
	else left = 0;
	if (root->right != NULL) right = count_of_words(root->right);
	else right = 0;
	return left + right + 1;
}

dict dict::fromdoc(string filname) {
	ifstream file(filname + ".txt");
	string ru, en;
	file >> en >> ru;
	dict root(en, ru, NULL, NULL);
	return root;
}
