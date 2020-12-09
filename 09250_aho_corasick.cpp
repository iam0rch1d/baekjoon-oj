#include <iostream>
#include <queue>
#include <vector>

#define CHILDREN_SIZE 26

using namespace std;

struct Trie {
    struct Node {
        int childDepths[CHILDREN_SIZE]{};
        int failure{-1};
        bool isTerminal{};

        Node() {
            for (int &childDepth : childDepths) {
                childDepth = -1;
            }
        }
    };

    vector<Node> nodes;
    int maxDepth{};
    int rootDepth{newNode()};

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

        if (nodes[depth].childDepths[childNo] == -1) nodes[depth].childDepths[childNo] = newNode();

        add(nodes[depth].childDepths[childNo], s, i + 1);
    }

    void add(string &s) {
        add(rootDepth, s, 0);
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

    trie.nodes[trie.rootDepth].failure = trie.rootDepth;

    bfsDepths.push(trie.rootDepth);

    while (!bfsDepths.empty()) {
        int currentDepth = bfsDepths.front();

        bfsDepths.pop();

        for (int i = 0; i < CHILDREN_SIZE; i++) {
            int childDepth = trie.nodes[currentDepth].childDepths[i];

            if (childDepth == -1) continue;

            if (currentDepth == trie.rootDepth) trie.nodes[childDepth].failure = trie.rootDepth;
            else {
                int prefixDepth = trie.nodes[currentDepth].failure;

                while (prefixDepth != trie.rootDepth && trie.nodes[prefixDepth].childDepths[i] == -1) {
                    prefixDepth = trie.nodes[prefixDepth].failure;
                }

                if (trie.nodes[prefixDepth].childDepths[i] != -1) prefixDepth = trie.nodes[prefixDepth].childDepths[i];

                trie.nodes[childDepth].failure = prefixDepth;
            }

            trie.nodes[childDepth].isTerminal |= trie.nodes[trie.nodes[childDepth].failure].isTerminal;

            bfsDepths.push(childDepth);
        }
    }

    cin >> q;

    while (q--) {
        string s;
        int sSize;
        int prefixIndex = trie.rootDepth;
        bool isHit = false;

        cin >> s;

        sSize = s.size();

        for (int i = 0; i < sSize; i++) {
            int childNo = s[i] - 'a';

            while (prefixIndex != trie.rootDepth && trie.nodes[prefixIndex].childDepths[childNo] == -1) {
                prefixIndex = trie.nodes[prefixIndex].failure;
            }

            if (trie.nodes[prefixIndex].childDepths[childNo] != -1) {
                prefixIndex = trie.nodes[prefixIndex].childDepths[childNo];
            }

            isHit |= trie.nodes[prefixIndex].isTerminal;
        }

        cout << (isHit ? "YES\n" : "NO\n");
    }

    return 0;
}
