#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int hp;
int wp;
int hm;
int wm;

struct Trie {
    struct Node {
        int childNodes[2]{-1, -1};
        int failure{-1};
        int terminalNode{-1};
    };

    vector<Node> nodes;
    int backNode{};
    int rootNode{newNode()};

    int newNode() {
        Node node;

        nodes.push_back(node);

        return backNode++;
    }

    int add(int node, string &s, int i) {
        if (i == wp) {
            nodes[node].terminalNode = node;

            return node;
        }

        int child = s[i] == 'o';

        if (nodes[node].childNodes[child] == -1) nodes[node].childNodes[child] = newNode();

        return add(nodes[node].childNodes[child], s, i + 1);
    }

    int add(string &s) {
        return add(rootNode, s, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;
    queue<int> bfsNodes;

    cin >> hp >> wp >> hm >> wm;

    vector<int> pNodes(hp);
    vector<int> pNodeFailures(hp);
    int pNodePrefixIndex = 0;
    vector<vector<int>> mNodes(hm, vector<int>(wm, -1));
    int pCount = 0;

    for (int &pNode : pNodes) {
        string p;

        cin >> p;

        pNode = trie.add(p);
    }

    pNodeFailures[0] = 0;

    for (int i = 1; i < hp; i++) {
        while (pNodePrefixIndex && pNodes[i] != pNodes[pNodePrefixIndex]) {
            pNodePrefixIndex = pNodes[pNodePrefixIndex - 1];
        }

        if (pNodes[i] == pNodes[pNodePrefixIndex]) pNodeFailures[i] = ++pNodePrefixIndex;
        else pNodePrefixIndex = 0;
    }

    trie.nodes[trie.rootNode].failure = trie.rootNode;

    bfsNodes.push(trie.rootNode);

    while (!bfsNodes.empty()) {
        int currentNode = bfsNodes.front();

        bfsNodes.pop();

        for (int i = 0; i < 2; i++) {
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

            bfsNodes.push(childNode);
        }
    }

    for (auto &mNode : mNodes) {
        string m;
        int prefixNode = trie.rootNode;

        cin >> m;

        for (int i = 0; i < wm; i++) {
            int child = m[i] == 'o';

            while (prefixNode != trie.rootNode && trie.nodes[prefixNode].childNodes[child] == -1) {
                prefixNode = trie.nodes[prefixNode].failure;
            }

            if (trie.nodes[prefixNode].childNodes[child] != -1) prefixNode = trie.nodes[prefixNode].childNodes[child];

            mNode[i] = trie.nodes[prefixNode].terminalNode;
        }
    }

    for (int j = 0; j < wm; j++) {
        int mNodePrefixIndex = 0;

        for (int i = 0; i < hm; i++) {
            while (mNodePrefixIndex && mNodes[i][j] != pNodes[mNodePrefixIndex]) {
                mNodePrefixIndex = pNodeFailures[mNodePrefixIndex - 1];
            }

            if (mNodes[i][j] == pNodes[mNodePrefixIndex]) {
                if (mNodePrefixIndex == hp - 1) {
                    pCount++;
                    mNodePrefixIndex = pNodeFailures[mNodePrefixIndex];
                } else ++mNodePrefixIndex;
            }
        }
    }

    cout << pCount << '\n';

    return 0;
}
