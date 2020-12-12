#include <iostream>
#include <queue>
#include <vector>

#define CHILDREN_SIZE 26

using namespace std;

struct Trie {
    struct Node {
        int childNodes[CHILDREN_SIZE]{};
        int failure{-1};
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

        int child = s[i] - 'a';

        if (nodes[node].childNodes[child] == -1) nodes[node].childNodes[child] = newNode();

        add(nodes[node].childNodes[child], s, i + 1);
    }

    void add(string &s) {
        add(rootNode, s, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int q;
    Trie trie;
    queue<int> bfsNodes;

    cin >> n;

    while (n--) {
        string p;

        cin >> p;

        trie.add(p);
    }

    trie.nodes[trie.rootNode].failure = trie.rootNode;

    bfsNodes.push(trie.rootNode);

    while (!bfsNodes.empty()) {
        int currentNode = bfsNodes.front();

        bfsNodes.pop();

        for (int i = 0; i < CHILDREN_SIZE; i++) {
            int childNode = trie.nodes[currentNode].childNodes[i];

            if (childNode == -1) continue;

            if (currentNode == trie.rootNode) trie.nodes[childNode].failure = trie.rootNode;
            else {
                int prefixNode = trie.nodes[currentNode].failure;

                while (prefixNode != trie.rootNode && trie.nodes[prefixNode].childNodes[i] == -1) {
                    prefixNode = trie.nodes[prefixNode].failure;
                }

                if (trie.nodes[prefixNode].childNodes[i] != -1) prefixNode = trie.nodes[prefixNode].childNodes[i];

                trie.nodes[childNode].failure = prefixNode;
            }

            trie.nodes[childNode].isTerminal |= trie.nodes[trie.nodes[childNode].failure].isTerminal;

            bfsNodes.push(childNode);
        }
    }

    cin >> q;

    while (q--) {
        string s;
        int sSize;
        int prefixNode = trie.rootNode;
        bool isHit = false;

        cin >> s;

        sSize = s.size();

        for (int i = 0; i < sSize; i++) {
            int child = s[i] - 'a';

            while (prefixNode != trie.rootNode && trie.nodes[prefixNode].childNodes[child] == -1) {
                prefixNode = trie.nodes[prefixNode].failure;
            }

            if (trie.nodes[prefixNode].childNodes[child] != -1) prefixNode = trie.nodes[prefixNode].childNodes[child];

            isHit |= trie.nodes[prefixNode].isTerminal;
        }

        cout << (isHit ? "YES\n" : "NO\n");
    }

    return 0;
}
