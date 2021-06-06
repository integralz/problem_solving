#include <iostream>
#include <vector>
using namespace std;

int num, queue;
bool *mat;
vector<int> v;
void print() {
	for (int i = 0; i < queue; i++)
		cout << v[i] << " ";

	cout << '\n';
}

void dfs(int b) {
	if (b == queue) {
		print();
	}
	else {
		for (int i = 0; i < num; i++) {
			if (mat[i] == 1) continue;
			mat[i] = 1;
			v.push_back(i + 1);
			dfs(b + 1);
			v.pop_back();
			mat[i] = 0;
		}
	}
}

int main(void) {
	cin >> num >> queue;
	mat = new bool[num];
	for (int i = 0; i < 2; i++)
		mat[i] = false;
	dfs(0);
	delete[] mat;
	return 0;
}