#include <iostream>
#include <forward_list>

using namespace std;

template<typename Container>
void print(Container& cont, char c) {
	for (auto i = cont.begin(); i != cont.end(); ++i) {
		if (i != cont.begin()) {
			cout << c;
		}
		cout << *i;
	}
	cout << endl;
}

template<typename Container>

void distrib(Container &cont0, Container &cont1, Container &cont2) {
	Container tmp = cont0;
	for (auto i = tmp.begin(); i != tmp.end(); ++i) {
		if (cont0.front() < 0) {
			cont2.push_front(cont0.front());
			cont2.sort();
		}
		else {
			cont1.push_front(cont0.front());
			cont1.sort();
		}
		cont0.pop_front();
	};
}

int main()
{
	forward_list<int> zer = { 2, 3, -4, 5, 1, -2, 6 }; // Задаём исходный список
	forward_list<int> pos = {};
	forward_list<int> neg = {};

	print(zer, ',');

	distrib(zer, pos, neg);

	print(zer, ',');
	print(neg, ',');
	print(pos, ',');

	return 0;
}