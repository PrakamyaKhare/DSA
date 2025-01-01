#include <iostream>
#include <vector>
using namespace std;


string slice_up(string s, int y) {
    string v = "";
    for (int i = y; i < s.length(); i++) {
        v = v + s[i];
    }
    return v;
}

int cmp(string s, int k,char c) {
    if (k + 1 <= s.length() - 1) {
        if (s[k + 1] == c) {
            return true;
        }
    }
    return false;
}

string slice_asterick(string s, int k) {
    string v = "";
    for (int i = k; i < s.length(); i++) {
        if (i + 1 <= s.length() - 1) {
            if (s[i] == '.' && s[i + 1] == '*') {
                break;
            }
        }
        if (s[i] == '*') {
            break;
        }
        v = v + s[i];
    }
    return v;
}
int one(int n) {
    if (n > 0) {
        return 1;
    }
    return 0;
}
int abs(int k) {
    if (k < 0) {
        return -k;
    }
    return k;
}

vector<int> match_str(string s, string p,char c,int j,int k) {
    int l = 0;
    bool has_dot = 0;
    vector<int> v;
    bool is_empty = false;
    if (c == '.') {
        has_dot = 1;
        int h = (p.length() - 1 - j);
        if (h == 0) {
            is_empty = true;
        }
    }

    l = (s.length() - k);
 
    if (c == '.' && is_empty) {
        k = s.length() - 1;
        v.push_back(k);
        v.push_back(l);
        return v;
    }
    if (has_dot == 0) {
        l = 0;
        for (int i = k; i < s.length(); i++) {
            if (s[i] == c) {
                l = l + 1;
                k = i;
                continue;
            }
            break;
       }
        v.push_back(k);
        v.push_back(l);
        return v;
    }
    l = 0;
    int l1 = 0;
    int prev = -1;
    int d = s.length() - 1;
    int y = k;
    string p1 = slice_asterick(p, j+1);
    int of = p1.length() - 1;
    while (d >= k+1 && of >=0) {
        if (l1 == p1.length()-1) {
            k = d + l1 ;
            break;
        }
        if (s[d] == p1[of] || p1[of] == '.') {
            if (prev == -1) {
                prev = d;
                l1 = l1 + 1;
                of = of - 1;
                d = d - 1;
                continue;
            }
            if (d == prev-1) {
                prev = d;
                l1 = l1 + 1;
                of = of - 1;
                d = d - 1;
                continue;
            }
            // reseting the iterative variable if window doesn't matches!
            prev = -1;
            l1 = 0;
            of = p1.length()-1;
            d = d - 1;
        }
        d = d - 1;
    }
    if (has_dot) {
        l1 = l1 + (d - y) + one(abs(d - y));
    }
    v.push_back(k);
    v.push_back(l1);
    return v;
}

bool pattern_matching(string s, string p) {
    // abchhgjkl, ab.*gj.*.kl
    // * :- zero or more appearence of the preceding element
    // . :- any single character 
    string chars[2] = { ".","*" };
    int sign_dot = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '*') {
            sign_dot = 1;
            break;
        }
    }
    if (sign_dot == 0) {
        
        if (s.length() != p.length()) {
            return 0;
        }
        // matching each characters in pattern p string with real string s
        for (int k = 0; k < s.length(); k++) {
            if (p[k] == '.') {
                continue;
            }
            if (p[k] != s[k]) {
                return 0;
            }
        }
        return 1;
    }
    
    int k = 0;
    int L = 0;
    int i = 0;
    vector<int> return_;
    int N = p.length();
    char c;
    while(i < s.length()) {
        if (p[k] == '.' ) {
            L = L + 1;
            k = k + 1;
            i = i + 1;
            continue;
        }
        if (p[k] == '*') {
            if (k == 0) {
                k = k + 1;
            }
            c = p[k-1];
            if (c == '*') {
                return 0;
            }
            if (c == '.') {
                L = L - 1;
                i = i - 1;
            }
            return_ = match_str(s,p, c, k,i);
            if (return_[1] == 0) {
                // if length == 0 then it means it didn't matches so we will just return false!
                
                return 0;
            }
            i = return_[0] +1;
            L = L + return_[1];
            k = k + return_[1] + 1;
            //cout << i << " " << k << endl;
            //cout << L << endl;
            continue;
        }
        if (p[k] != s[i]) {
            break;
        }
        L = L + 1;
        i = i + 1;
        k = k + 1;
    }

    if (L == s.length()) {
        return 1;
    }
    return 0;

}

int main()
{
    string s[2] = {"Hello","abcfghabc"};
    string p[2] = {".*", "a.cf.*gh.*" };
    string si;
    string pi;
    
    for (int i = 0; i < 2; i++) {
        si = s[i];
        pi = p[i];
        cout << pattern_matching(si, pi) << endl;

 }
 
    cout << pattern_matching("abcfkkgh", "a.cf.*gh") << endl;
    
    
    cout << pattern_matching("aa", "a*");
    return 0;
}