#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define BOARD_SIZE 4

struct Trie {
    struct Node {
        int childNodes[26]{};
        bool isTerminal{};

        Node() {
            for (int &childNode : childNodes) {
                childNode = -1;
            }
        }
    };

    vector<Node> nodes;
    int backNode{};
    int rootNode{newNode()};

    int newNode() {
        Node node;

        nodes.push_back(node);

        return backNode++;
    }

    void add(int node, string &s, int i) {
        if (i == s.size()) {
            nodes[node].isTerminal = true;

            return;
        }

        int child = s[i] - 'A';

        if (nodes[node].childNodes[child] == -1) nodes[node].childNodes[child] = newNode();

        add(nodes[node].childNodes[child], s, i + 1);
    }

    void add(string &s) {
        add(rootNode, s, 0);
    }

    bool find(int node, string &s, int i) {
        if (node == -1) return false;

        if (i == s.size()) return nodes[node].isTerminal = true;

        return find(nodes[node].childNodes[s[i] - 'A'], s, i + 1);
    }

    bool find(string &s) {
        return find(rootNode, s, 0);
    }
};

char board[BOARD_SIZE][BOARD_SIZE];
bool isUsed[BOARD_SIZE][BOARD_SIZE];

void backtrackWord(Trie &trie, string word, int y, int x) {
    trie.add(word);

    if (word.size() == 8) return;

    for (int i = 0; i < 8; i++) {
        int ny = y + "00011222"[i] - '1';
        int nx = x + "01202012"[i] - '1';

        if (ny >= 0 && ny < BOARD_SIZE && nx >= 0 && nx < BOARD_SIZE && !isUsed[ny][nx]) {
            isUsed[ny][nx] = true;

            backtrackWord(trie, word + board[ny][nx], ny, nx);

            isUsed[ny][nx] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    int b;

    cin >> w;

    vector<string> words(w);

    for (auto &word : words) {
        cin >> word;
    }

    sort(words.begin(), words.end());

    cin >> b;

    while (b--) {
        Trie trie;
        set<string> foundWords;
        int totalScore = 0;
        int maxFoundWordSize = 0;
        string longestFoundWord;

        for (auto &boardRow : board) {
            string boardRowString;

            cin >> boardRowString;

            for (int j = 0; j < BOARD_SIZE; j++) {
                boardRow[j] = boardRowString[j];
            }
        }

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                isUsed[i][j] = true;

                backtrackWord(trie, string(1, board[i][j]), i, j);

                isUsed[i][j] = false;
            }
        }

        for (auto &word : words) {
            if (trie.find(word)) foundWords.insert(word);
        }

        for (auto &foundWord : foundWords) {
            int foundWordSize = foundWord.size();

            totalScore += "00011235;"[foundWordSize] - '0';  // ';' = '0' + 11

            if (foundWordSize > maxFoundWordSize) {
                maxFoundWordSize = foundWordSize;
                longestFoundWord = foundWord;
            }
        }

        cout << totalScore << ' ' << longestFoundWord << ' ' << foundWords.size() << '\n';

        memset(isUsed, 0, sizeof(isUsed));
    }

    return 0;
}
