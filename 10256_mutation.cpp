#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define CHILDREN_SIZE 4

int childNoOf(char c) {
    if (c == 'A') return 0;
    else if (c == 'C') return 1;
    else if (c == 'G') return 2;
    else return 3;
}

struct Trie {
    struct Node {
        int childNodes[CHILDREN_SIZE]{-1, -1, -1, -1};
        int failure{-1};
        int hitCount{};
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
            nodes[node].hitCount = 1;

            return;
        }

        int child = childNoOf(s[i]);

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

    int t;

    cin >> t;

    while (t--) {
        int n;
        int m;
        string dna;
        string marker;
        set<string> mutations;
        Trie trie;
        queue<int> bfsNodes;
        int totalHitCount = 0;

        cin >> n >> m >> dna >> marker;

        mutations.insert(marker);

        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                string mutation{marker};

                reverse(mutation.begin() + i, mutation.begin() + j + 1);

                mutations.insert(mutation);
            }
        }

        for (auto mutation : mutations) {
            trie.add(mutation);
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

                trie.nodes[childNode].hitCount += trie.nodes[trie.nodes[childNode].failure].hitCount;

                bfsNodes.push(childNode);
            }
        }

        int prefixNode = trie.rootNode;

        for (int i = 0; i < n; i++) {
            int child = childNoOf(dna[i]);

            while (prefixNode != trie.rootNode && trie.nodes[prefixNode].childNodes[child] == -1) {
                prefixNode = trie.nodes[prefixNode].failure;
            }

            if (trie.nodes[prefixNode].childNodes[child] != -1) {
                prefixNode = trie.nodes[prefixNode].childNodes[child];
            }

            totalHitCount += trie.nodes[prefixNode].hitCount;
        }

        cout << totalHitCount << '\n';
    }

    return 0;
}
