#include <iostream>
#include <vector>
using namespace std;




/*

string short_str(string str, int k) {
	string new_ = "";
	for (int i = k; i < str.length(); i++) {
		new_ += str[i];
	}
	return new_;
}

int recur(string str, int l=0,int d = 0) {
	if (str.length() == 0) {
		return 0;
	}
	if (d > 0) {
		if (str[0] == ')') {
			return l+1;
		}
	 }
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			l = recur(short_str(str,i+1),l, d = d + 1);
		}
	}
	return 2*l;
}

int count_parantheises(string str) {
	const int N = str.length();
	vector<int> count;
	vector<char> open;

	for (int i = 0; i < N; i++) {
		if (str[i] == '(') {
			open.push_back('(');
		}
		else {
			if (!(open.empty())) {
				open.pop_back();
				count.push_back(1);
			}
		}
		
	}
	return 1;
}

int count_parantheses(string str) {
	vector<char> open;
	int count = 0;
	const int N = str.length();
	for (int i = 0; i < N; i++) {
		if (str[i] == '(') {
			if (i + 1 == N) {
				if (!(open.empty())) {
					count = 0;
				}
				break;
			}
			open.push_back(str[i]);
		}
		else if (str[i] == ')') {
			if (i + 1 == N) {
				if (open.empty()) {
					count = 0;
				}
			}
			if (!(open.empty())) {
				open.pop_back();
				count = count + 1;
			}
			
		}

	}
	return count*2;
}
*/
void main() {
	//(()(
	cout << f(")()())") << endl;
	cout << count_parantheses("(()") << endl;
	cout << recur("()(()((())") << endl;
}