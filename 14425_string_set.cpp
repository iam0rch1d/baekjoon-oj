#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        int children[26]{};
        bool isTerminal{false};

        Node() {
            for (int &child : children) {
                child = -1;
            }
        }
    };

    vector<Node> trie;
    int root{newNode()};

    int newNode() {
        Node node;

        trie.push_back(node);

        return (int) trie.size() - 1;
    }

    void add(int depth, string &s, int sIndex) {
        if (sIndex == s.size()) {
            trie[depth].isTerminal = true;

            return;
        }

        int sIndexChar = s[sIndex] - 'a';

        if (trie[depth].children[sIndexChar] == -1) trie[depth].children[sIndexChar] = newNode();

        add(trie[depth].children[sIndexChar], s, sIndex + 1);
    }

    void add(string &s) {
        add(root, s, 0);
    }

    bool find(int depth, string &s, int sIndex) {
        if (depth == -1) return false;

        if (sIndex == s.size()) return trie[depth].isTerminal;

        return find(trie[depth].children[s[sIndex] - 'a'], s, sIndex + 1);
    }

    bool find(string &s) {
        return find(root, s, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;
    Trie trie;
    int findCount = 0;

    cin >> n >> m;

    while (n--) {
        string s;

        cin >> s;

        trie.add(s);
    }

    while (m--) {
        string s;

        cin >> s;

        findCount += trie.find(s);
    }

    cout << findCount << '\n';

    return 0;
}
