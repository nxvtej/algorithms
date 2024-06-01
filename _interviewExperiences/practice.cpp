#include <bits/stdc++.h>
using namespace std;

bool check(char it) {
    if (it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U' || 
        it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') return true;
    return false;
}

bool checkifVowel(string _s) {
    for (auto it : _s) {
        if (!check(it)) return false;
    }
    return true;
}

bool solve(string s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 2; j < s.size(); j++) {
            if (checkifVowel(s.substr(i, j - i + 1))) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        if (solve(s)) cout << "happy\n";
        else cout << "sad\n";
    }

    return 0;
}