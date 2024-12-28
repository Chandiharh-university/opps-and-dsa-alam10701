#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int wordLadderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    if (beginWord == endWord) return 1;

    queue<pair<string, int>> toVisit;
    toVisit.push({beginWord, 1});

    while (!toVisit.empty()) {
        auto current = toVisit.front();
        toVisit.pop();

        string word = current.first;
        int length = current.second;

        for (int i = 0; i < word.length(); ++i) {
            char originalChar = word[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == originalChar) continue;

                word[i] = c;
                if (word == endWord) return length + 1;

                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push({word, length + 1});
                    wordDict.erase(word);
                }
            }
            word[i] = originalChar;
        }
    }

    return 0;
}

int main() {
    string beginWord, endWord;
    int n;
    cout << "Enter the begin word: ";
    cin >> beginWord;
    cout << "Enter the end word: ";
    cin >> endWord;
    cout << "Enter the number of words in the dictionary: ";
    cin >> n;

    unordered_set<string> wordDict;
    cout << "Enter the words in the dictionary:\n";
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        wordDict.insert(word);
    }

    int result = wordLadderLength(beginWord, endWord, wordDict);

    if (result == 0) {
        cout << "No transformation sequence exists." << endl;
    } else {
        cout << "The length of the shortest transformation sequence is: " << result << endl;
    }

    return 0;
}
