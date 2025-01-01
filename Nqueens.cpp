#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double Pow(int n, int r) {
	if (r == 0) {
		return 1;
	}
	if (r == 1) {
		return n;
	}
	if (r > 0) {
		double res = n;
		for (int i = 1; i < r; i++) {
			res = res * n;
		}
		return res;
	}
	if (r < 0) {
		return 1 / Pow(n, -r);
	}

}
double M(int x, int y) {
	return pow((Pow(x, 2) + Pow(y, 2)), 0.5);
}
class Vector {
public: 
	int x;
	int y;

	Vector(int x, int y) {
		this->x = x;
		this->y = y;
	}

	double M() {
		return pow((Pow(x, 2) + Pow(y, 2)), 0.5);
  }
};

void board(int n) {
	string border = "";
	for (int k = 1; k <= n*n; k++) {
		border = border + '-';
	}
	for (int i = 0; i < n*n+1; i++) {
		if (i % n == 0) {
			cout << border << endl;
			continue;
		}
		for (int j = 0; j <=n*n; j++) {
			if (j % n == 0) {
				cout << "| ";
				continue;
			}
			cout << " ";
		}
		cout << endl;
	}
}

void print_board(vector<vector<int>> pos, int n) {
	int x, y;
	string board = "";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i < pos.size()) {
					if ((pos[i][0] == i) && (pos[i][1] == j)) {
						board += "Q";
						continue;
					}
				}
				board += ".";
			}
			cout << board << endl;
			board = "";
		}
	}

void print_vector(vector<vector<int>> pos) {
	for (int i = 0; i < pos.size(); i++) {
		cout<<"[" << pos[i][0] << "," << pos[i][1] << "]" << endl;
	}
}


void n_queens(int n,int d=0) {
	vector<vector<string>> board;
	vector<string> row;
	int x, y;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			row.push_back(".");
		}
		board.push_back(row);
		row.clear();
	}
	board[0][d] = "Q";
	Vector pos_q(0+1, d+1);
	vector<vector<int>> pos;
	pos.push_back({ 1,d+1 });	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Vector pos_ij(i+1, j+1);
			for (int k = 0; k < pos.size(); k++) {
				x = abs(pos[k][0] - pos_ij.x);
				y = abs(pos[k][1] - pos_ij.y);
				
				if (M(x,y) >= M(2,1)){
					count = count + 1;
				}
			}
			if (count == pos.size()) {
				count = 0;
				pos.push_back({ i+1,j+1 });
			}
		}
	}
	if (pos.size() < n && d < n) {
		n_queens(n, d + 1);
		return;
	}
		print_board(pos,n);
	print_vector(pos);
	return;
}

void main() {
	n_queens(4);
	/*
	int r = 5;
	cout << "r = " << 4 << endl;
	for (int n = 1; n <= 10; n = n + 1) {
		cout << "n = " << n << " ";
		cout << (n-1)%r << endl;
	}
	cout << 3%4;
	board(5);
	*/
	cout << M(2, 1);
	return;

}