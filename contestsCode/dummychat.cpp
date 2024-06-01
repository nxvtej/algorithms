#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e';
}

bool isSyllable(const string& word, int start) {
    if (word.length() - start < 2) {
        return false;  // Not enough letters for a syllable
    }

    if (!isVowel(word[start + 1])) {
        return false;  // Second letter must be a vowel
    }

    // Check for CV or CVC, allowing for consecutive syllables
    return (start == 0 || !isVowel(word[start - 1])) &&
           ((word.length() == start + 2 || !isVowel(word[start + 2])) ||
            (word.length() > start + 2 && !isVowel(word[start + 3])));
}

string splitIntoSyllables(const string& word) {
    string syllables = "";

    for (int i = 0; i < word.length(); i++) {
        syllables += word[i];
        if (isSyllable(word, i)) {
            syllables += '.';
        }
    }

    return syllables;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string word;
        cin >> word;

        string result = splitIntoSyllables(word);
        cout << result << endl;
    }

    return 0;
}
