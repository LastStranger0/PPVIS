#include <iostream>
#include <cstddef>
#include <vector>
#include <utility>
#include <list>
using namespace std;

class A {
public:
	A(int q, int m);
	int q;
	int m;
	bool operator>(A);
	bool operator< (A);
	bool operator<= (A);
	bool operator>= (A);
	bool operator== (A);
};

A::A(int q1, int m1) : q(q1), m(m1) {

}

bool A::operator>(A obj) {
	int sum1 = this->q + this->m;
	int sum2 = obj.q + obj.m;
	return (sum1>sum2);
}

bool A::operator<(A obj) {
	int sum1 = this->q + this->m;
	int sum2 = obj.q + obj.m;
	return (sum1 < sum2);
}

bool A::operator>=(A obj) {
	int sum1 = this->q + this->m;
	int sum2 = obj.q + obj.m;
	return (sum1 >= sum2);
}

bool A::operator<=(A obj) {
	int sum1 = this->q + this->m;
	int sum2 = obj.q + obj.m;
	return (sum1 <= sum2);
}

bool A::operator==(A obj) {
	int sum1 = this->q + this->m;
	int sum2 = obj.q + obj.m;
	return (sum1 == sum2);
}


template<typename T>
void shakerSort(T * array, size_t size) {
	for (size_t left = 0, right = size - 1 ; left < right;) {
		for (size_t id = left; id < right; id++) {
			if ((*array)[id + 1] < (*array)[id]) {
				swap((*array)[id], (*array)[id + 1]);
			}
		}
		right--;
		for (size_t id = right; id > left; id--) {
			if ((*array)[id - 1] > (*array)[id]) {
				swap((*array)[id], (*array)[id - 1]);
			}
		}
		left++;
	}
}

template<typename K>
list<K> to_list(K * array, size_t size) {
	list<K> result;
	for(size_t i = 0; i < size; i++){
		result.push_back(array[i]);
	}
	return result;
}

template<typename M>
list<M> StrandSort(list<M> array, size_t size) {
	if (array.size() <= 1)
	{
		return array;
	}
	list<M> result;
	list<M> sublist;
	while (!array.empty())
	{
		sublist.push_back(array.front());
		array.pop_front();
		for (typename list<M>::iterator it = array.begin(); it != array.end();)
		{
			if (sublist.back() <= *it)
			{
				sublist.push_back(*it);
				it = array.erase(it);
			}
			else
			{
				it++;
			}
		}
		result.merge(sublist);
	}
	return result;
}

template<typename L>
void strandSort(L* array, size_t size) {
	list<L> temp = to_list(array, size);
	temp = StrandSort(temp, size);
	int i = 0;
	for (typename list<L>::iterator it = temp.begin(); it != temp.end(); it++) {
		array[i] = *it;
		i++;
	}
}
template<typename C>
void strandSort(vector<C>& array, size_t size) {
	list<C> temp;
	for (int i = 0; i < size; i++) {
		temp.push_back(array[i]);
	}
	temp = StrandSort(temp, size);
	int i = 0;
	for (typename list<C>::iterator it = temp.begin(); it != temp.end(); it++) {
		array[i] = *it;
		i++;
	}
}


int main()
{
	vector<A> mass{ {5,7}, {3, 5}, {4,6}, {2,4}, {1,3} };
	vector<int> a = { 5, 3, 7, 10, 2, 8, 7, 1, 9, 4 };
	int ma[] = { 5, 3, 7, 10, 2, 8, 7, 1, 9, 4 };
	shakerSort(&mass, mass.size());
	//strandSort(mass, mass.size());
	//strandSort(a, 10);
	for (int i = 0; i < mass.size(); i++) {
		cout << mass[i].m+mass[i].q << ' ';
	}
}
