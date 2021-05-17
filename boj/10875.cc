#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct dd {
	int sx, sy, ex, ey, shape;
};

int num, row;
vector <struct dd> v;
pair <int, int> que;
int di = 0;
int dir[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
struct dd g;
long long int ans = 0;

int check() {
	int minus = -1;
	struct dd &k = v.back();
	for (int i = 0; i < v.size() - 1; ++i) {
		struct dd &q = v[i];
		if (di == 0) {
			if (q.shape == 1 || q.shape == 3) {
				if (k.ey >= q.sy && k.sy <= q.sy && q.sx <= k.sx && q.ex >= k.sx) {
					if (minus < (k.ey - q.sy)) minus = k.ey - q.sy;
				}
			}
			else {
				if (k.ey >= q.sy && k.sy <= q.sy && q.ex == k.ex) {
					if (minus < (k.ey - q.sy)) minus = k.ey - q.sy;
				}
			}
		}
		else if (di == 1) {
			if (q.shape == 0 || q.shape == 2) {
				if (k.sx <= q.sx && k.ex >= q.sx && k.ey <= q.ey && k.ey >= q.sy) {
					if (minus < q.sx - k.sx) minus = q.sx - k.sx;
				}
			}
			else {
				if (k.sx <= q.ex && k.ex >= q.ex && k.ey == q.ey) {
					if (minus < q.ex - k.sx) minus = q.ex - k.sx;
				}
			}
		}
		else if (di == 2) {
			if (q.shape == 1 || q.shape == 3) {
				if (k.sy <= q.sy && k.ey >= q.sy && k.ex >= q.sx && k.ex <= q.ex) {
					if (minus < (q.sy - k.sy)) minus = q.sy - k.sy;
				}
			}
			else {
				if (k.sy <= q.ey && k.ey >= q.ey && k.ex == q.ex) {
					if (minus < (q.ex - k.sy)) minus = q.ex - k.sy;
				}
			}
		}
		else {
			if (q.shape == 2 || q.shape == 0) {
				if (k.sx <= q.sx && k.ex >= q.sx && k.ey >= q.sy && k.ey <= q.ey)
					if (minus < k.ex - q.sx) minus = k.ex - q.sx;
			}
			else {
				if (q.sx <= k.sx && q.sx >= k.ex && k.ey == q.ey) {
					if (minus < k.ex - q.sx) minus = k.ex - q.sx;
				}
			}
		}
	}
	if (minus >= 0) {
		ans -= minus;
		return 0;
	}
	else {
		if (k.sx < -1 * row || k.ex > row || k.sy < -1 * row || k.ey > row) {
			if (k.shape == 0) {
				ans -= (k.ey - row);
			}
			else if (k.shape == 1) {
				ans -= (-1 * row - k.sx);
			}
			else if (k.shape == 2) {
				ans -= (-1 * row - k.sy);
			}
			else {
				ans -= (k.ex - row);
			}
			ans++;
			return 0;
		}

	}
	return 1;
}

void inpu(int a, char b) {
	int x, y;
	x = que.first + a * dir[di][0];
	y = que.second + a * dir[di][1];
	if (di == 0 || di == 3) {
		g.sx = que.first + dir[di][0];
		g.sy = que.second + dir[di][1];
		g.ex = x;
		g.ey = y;
		g.shape = di;
		if (v.empty()) {
			g.sx -= dir[di][0];
			g.sy -= dir[di][1];
		}
		v.push_back(g);
	}
	else {
		g.sx = x;
		g.sy = y;
		g.ex = que.first + dir[di][0];
		g.ey = que.second + dir[di][1];
		g.shape = di;
		v.push_back(g);
	}
	que.first = x;
	que.second = y;
	ans += a;
}

int main(void) {
	int a;
	char b;

	que = { 0,0 };
	scanf("%d %d", &row, &num);
	for (int i = 0; i < num; ++i) {
		scanf("%d%c", &a, &b);
		scanf("%c", &b);
		inpu(a, b);
		if (check());
		else {
			printf("%lld", ans);
			return 0;
		}
		if (b == 'L') {
			di = (di + 1) % 4;
		}
		else di = (di + 3) % 4;
	}
	inpu(200000002, 'L');
	check();
	printf("%lld", ans);
}