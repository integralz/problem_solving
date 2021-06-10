#include <iostream>
using namespace std;

int num, queue;
bool *mat;

void print() {
	for (int i = 0; i < num; i++)
		if (mat[i] == 1)
			cout << i + 1 << " ";

	cout << endl;
}

void dfs(int a, int b) {
	if (b == queue) {
		print();
	}
	else {
		for (int i = a; i < num; i++) {
			if (mat[i] == 1) continue;
			mat[i] = 1;
			dfs(i + 1, b + 1);
			mat[i] = 0;
		}
	}
}

int main(void) {
	cin >> num >> queue;
	mat = new bool[num];
	for (int i = 0; i < 2; i++)
		mat[i] = false;
	dfs(0, 0);
	delete[] mat;
	return 0;
}