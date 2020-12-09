#include <iostream>
#include <queue>
#include <vector>

#define CHILDREN_SIZE 26

using namespace std;

struct Trie {
    struct Node {
        int children[CHILDREN_SIZE]{};
        int failure{-1};
        bool isTerminal{};

        Node() {
            for (int &child : children) {
                child = -1;
            }
        }
    };

    vector<Node> nodes;
    int maxDepth{};
    int root{newNode()};

    int newNode() {
        Node node;

        nodes.push_back(node);

        return maxDepth++;
    }

    void add(int depth, string &s, int i) {
        if (i == s.size()) {
            nodes[depth].isTerminal = true;

            return;
        }

        int childNo = s[i] - 'a';

        if (nodes[depth].children[childNo] == -1) nodes[depth].children[childNo] = newNode();

        add(nodes[depth].children[childNo], s, i + 1);
    }

    void add(string &s) {
        add(root, s, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int q;
    Trie trie;
    queue<int> bfsDepths;

    cin >> n;

    while (n--) {
        string s;

        cin >> s;

        trie.add(s);
    }

    trie.nodes[trie.root].failure = trie.root;

    bfsDepths.push(trie.root);

    while (!bfsDepths.empty()) {
        int currentDepth = bfsDepths.front();

        bfsDepths.pop();

        for (int i = 0; i < CHILDREN_SIZE; i++) {
            int child = trie.nodes[currentDepth].children[i];

            if (child == -1) continue;

            if (currentDepth == trie.root) trie.nodes[child].failure = trie.root;
            else {
                int prefixIndex = trie.nodes[currentDepth].failure;

                while (prefixIndex != trie.root && trie.nodes[prefixIndex].children[i] == -1) {
                    prefixIndex = trie.nodes[prefixIndex].failure;
                }

                if (trie.nodes[prefixIndex].children[i] != -1) prefixIndex = trie.nodes[prefixIndex].children[i];

                trie.nodes[child].failure = prefixIndex;
            }

            trie.nodes[child].isTerminal |= trie.nodes[trie.nodes[child].failure].isTerminal;

            bfsDepths.push(child);
        }
    }

    cin >> q;

    while (q--) {
        string s;
        int sSize;
        int prefixIndex = trie.root;
        bool isHit = false;

        cin >> s;

        sSize = s.size();

        for (int i = 0; i < sSize; i++) {
            int childNo = s[i] - 'a';

            while (prefixIndex != trie.root && trie.nodes[prefixIndex].children[childNo] == -1) {
                prefixIndex = trie.nodes[prefixIndex].failure;
            }

            if (trie.nodes[prefixIndex].children[childNo] != -1) {
                prefixIndex = trie.nodes[prefixIndex].children[childNo];
            }

            if (trie.nodes[prefixIndex].isTerminal) isHit = true;
        }

        cout << (isHit ? "YES\n" : "NO\n");
    }

    return 0;
}
