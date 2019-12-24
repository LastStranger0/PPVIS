#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <vector>
using namespace std;

struct Node {

	vector <char> drt;                           //Информационное поле
	vector <char> teg_information;
	vector<char> tegs;
	Node* current_level, * next_level;
};
Node* tree = NULL;
ifstream fin;





void push(vector <char> a, vector<char> tag_inform, Node** t, int level_now, int level_need)
{

	if ((*t) == NULL)                   //Если дерева не существует
	{

		(*t) = new Node;                //Выделяем память
		(*t)->drt = a;                //Кладем в выделенное место аргумент a
		(*t)->tegs = tag_inform;
		(*t)->current_level = (*t)->next_level = NULL;       //Очищаем память для следующего роста
		return;                         //Заложили семечко, выходим
	}
	if ((*t)->current_level != NULL)
	{
		//cout << "F";

		push(a, tag_inform, &(*t)->current_level, level_now, level_need);
		return;
	}
	if (level_now < level_need)
	{
		//cout << "a";

		push(a, tag_inform, &(*t)->next_level,  level_now + 1, level_need);

	}
	if (level_now == level_need)
	{
		//cout << "w";

		push(a, tag_inform, &(*t)->current_level, level_now, level_need);

	}

}
void print(Node* t, int level)
{
	if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
	else //Иначе
	{
		for (int i = 0; i < level; i++)
			cout << " ";
		for (int i = 0; i < t->drt.size(); i++)
			cout << t->drt[i];

		if (t->teg_information.size() > 0) {
			cout << endl;
			for (int i = 0; i < level; i++)
				cout << " ";
			for (int i = 0; i < t->teg_information.size(); i++)
				cout << t->teg_information[i];
		}
		cout << endl;
		print(t->next_level, level + 1);                   //С помощью рекурсивного посещаем правое поддерево
		for (int i = 0; i < level - 1; i++)
			cout << " ";
		cout << "/";
		for (int i = 0; i < t->drt.size(); i++) {
			cout << t->drt[i];
			if (t->drt[i] == ' ') {
			cout << '>';
				break;
			}
		}
		cout << endl;
		print(t->current_level, level);


	}
}
void proverkaTegov(vector <char>* ch2, vector <char>* ccccr, vector <char>* text) {
	int begin = 0,
		end = 0;
	char tm[700];
	while ((*ch2)[0] == ' ')
		(*ch2).erase((*ch2).begin());
	while (end == 0) {
		for (int i = 0; i < (*ch2).size(); i++)
		{
			if ((*ch2)[i] == '<')
			{
				begin = i;
			}
			if ((*ch2)[i] == '>')
			{
				end = i;
				break;
			}
		}
		fin.getline(tm, 700);
		for (int i = 0; tm[i] != NULL; i++){
			(*ch2).push_back(tm[i]);
		}
	}

	if (begin != 0)
	{
		for (int i = 0; i < begin; i++)
		{
			(*text).push_back((*ch2)[i]);
		}
		for (int i = begin; i <= end; i++)
		{
			(*ccccr).push_back((*ch2)[i]);
		}
		for (int i = 0; i <= end; i++)
		{
			(*ch2).erase((*ch2).begin());
		}
		return;
	}
	for (int i = begin; i <= end; i++)
	{
		(*ccccr).push_back((*ch2)[i]);
	}
	for (int i = 0; i <= end; i++)
	{
		(*ch2).erase((*ch2).begin());
	}

}

void pushText(vector <char> a, Node** t, int level_now, int level_need)
{

	if ((*t) == NULL)                   //Если дерева не существует
	{
		return;
	}
	if ((*t)->current_level != NULL)
	{
		//cout << "F";

		pushText(a, &(*t)->current_level, level_now, level_need);
		return;
	}
	if (level_now < level_need)
	{
		//cout << "a";

		pushText(a, &(*t)->next_level, level_now + 1, level_need);

	}
	if (level_now == level_need)
	{
		//cout << "w";

		pushText(a, &(*t)->current_level, level_now, level_need);
		(*t)->teg_information = a;
	}

}

vector<char> videlenie(vector<char>* otchislenie) {
	vector<char> result;
	int begin = 0,
		end = 0;
	bool firstbegin = 1;
	while ((*otchislenie)[0] == ' ')
		(*otchislenie).erase((*otchislenie).begin());
	for (int i = 0; i < otchislenie->size(); i++) {
		if ((*otchislenie)[i] == ' ' && firstbegin) {
			begin = i;
			firstbegin = 0;
		}
		if ((*otchislenie)[i] == '>') {
			end = i;
			break;
		}
	}
	if (begin != end) {
		for (int i = begin; i < end; i++) {
			result.push_back((*otchislenie)[i]);
		}
	//	for (int i = begin; i <= end; i++) {
		//	otchislenie->erase(otchislenie->begin() + begin);
	//	}
		//otchislenie->push_back('>');
	}
	return result;
}
int main()
{
	int teg,
		level = 0,
		cdata_check = 0;
	char ch[50];
	vector <char> ch2;
	vector <char> ccccr;
	vector <char> text;
	vector<char> tags;
	fin.open("testxml.xml");
	fin.getline(ch, 50);



	while (!fin.eof()) {






		fin.getline(ch, 50);

		for (int i = 0; ch[i] != NULL; i++) {
			ch2.push_back(ch[i]);
		}
		while (ch2.size())
		{
			ccccr.clear();
			tags.clear();
			tags = videlenie(&ch2);

			proverkaTegov(&ch2, &ccccr, &text);


			if (ccccr[1] != '/' && ccccr[1] != '!')
			{
				level++;
				push(ccccr,tags, &tree, 1, level);


			}

			if (ccccr[1] == '/')
			{
				if (text.size() > 0)
				{
					pushText(text, &tree, 1, level);
				}
				level--;
			}
			text.clear();
		}

	}
	print(tree, level);
	fin.close();
}
