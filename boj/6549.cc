#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int num;
long long ans = 0;
int make_seg(int node, int start, int end, vector <int>& mat, vector <int> &v) {
	int q1, q2;
	if (start == end) return v[node] = start;
	int mid = (start + end) / 2;
	q1 = make_seg(node * 2, start, mid, mat, v);
	q2 = make_seg(node * 2 + 1, mid + 1, end, mat, v);
	if (mat[q1] <= mat[q2]) return v[node] = q1;
	return v[node] = q2;

}

int find_seg(int node, int start, int end, int left, int right, vector <int> &mat, vector <int> &v) {
	int q1, q2;
	if (right < start || end < left) return num;
	if (left <= start && end <= right) return v[node];
	int mid = (start + end) / 2;
	q1 = find_seg(node * 2, start, mid, left, right, mat, v);
	q2 = find_seg(node * 2 + 1, mid + 1, end, left, right, mat, v);
	if (mat[q1] <= mat[q2]) return q1;
	return q2;
}

void find(int left, int right, vector <int> &mat, vector <int> &v){
	long long che;
	int que = find_seg(1, 0, num - 1, left, right, mat, v);
	che = (long long)mat[que] * (right - left + 1);
	if (ans < che) ans = che;
	if (left < que) {
		find(left, que - 1, mat, v);
	}
	if (que < right) {
		find(que + 1, right, mat, v);
	}
}

int main(void) {
	int a;
	int siz;
	while (1){
		scanf("%d", &num);
		if (num == 0) return 0;
		vector <int> v;
		vector <int> mat;
		for (int i = 0; i < num; ++i) {
			scanf("%d", &a);
			mat.push_back(a);
		}
		mat.push_back(1987654321);
		siz = ceil(log2(num) + 1);
		siz = 1 << siz;
		v.resize(siz);
		make_seg(1, 0, num - 1, mat, v);
		ans = 0;
		find(0, num - 1, mat, v);
		printf("%lld\n", ans);
	}
	return 0;
}