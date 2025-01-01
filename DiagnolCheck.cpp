#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double magnitude(int x, int y) {
	return pow((pow(x, 2) + pow(y, 2)), 0.5);

}

bool Dig(vector<int> rc, vector<vector<int>> P,int N){
	int cb = 0;
	int ca = 0;
	int ra = 0;
	int rb = 0;
	int a = 0;
	int n1, m1;
	int xc = rc[0];
	int yc = rc[1];
	int xq = 0;
	int yq = 0;
	int n = 0;
	int m = 0;
	for (int k = 0; k < P.size(); k++) {
		ca = 0;
		cb = 0;
		ra = rb = 0;
		xq = P[k][0];
		yq = P[k][1];
		if (xq == xc || yq == yc) {
			return false;
		}
		n = min(abs(xq - 1), abs(yq - 1));
		for(int i = 1; i <=n; i++) {
			if ((xq - i == xc) && (yq - i) == yc) {
				continue;
			}
			cb = cb + 1;
		}
		m = min(abs(N - xq), abs(N - yq));
		for (int i = 1; i <= m; i++) {
			if ((xq + i == xc) && (yq + i == yc)) {
				continue;
			}
			ca = ca + 1;
		}
		n1 = min(abs(xq - 1), abs(N - yq));
		for (int i = 1; i <= n1; i++) {
			if (xq - i == xc && yq + i == yc) {
				continue;
			}
			rb = rb + 1;
		}
		m1 = min(abs(N - xq), abs(yq - 1));
		for (int i = 1; i <= m1; i++) {
			if (xq + i == xc && yq - i == yc) {
				continue;
			}
			ra = ra + 1;
		}
		if (cb == n && ca == m && rb == n1 && ra == m1) {
			a = a + 1;
		}
	}
	if (a == P.size()) {
		return 1;
	}
	return 0;
}

void main() {
	vector<vector<int>> P = { {1,1},{2,3} };
	vector<int> rc = {4,4};
	bool res = Dig(rc, P,4);
	cout << res << endl;
}