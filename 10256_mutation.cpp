#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define CHILDREN_SIZE 4

using namespace std;

int childNoOf(char c) {
    if (c == 'A') return 0;
    else if (c == 'C') return 1;
    else if (c == 'G') return 2;
    else return 3;
}

struct Trie {
    struct Node {
        int children[CHILDREN_SIZE]{-1, -1, -1, -1};
        int failure{-1};
        int hitCount{};
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
            nodes[depth].hitCount = 1;

            return;
        }

        int iChildNo = childNoOf(s[i]);

        if (nodes[depth].children[iChildNo] == -1) nodes[depth].children[iChildNo] = newNode();

        add(nodes[depth].children[iChildNo], s, i + 1);
    }

    void add(string &s) {
        add(root, s, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcases;

    cin >> testcases;

    while (testcases--) {
        int n;
        int m;
        string dna;
        string marker;
        set<string> mutations;
        Trie trie;
        queue<int> bfsDepths;
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

                trie.nodes[child].hitCount += trie.nodes[trie.nodes[child].failure].hitCount;

                bfsDepths.push(child);
            }
        }

        int prefixIndex = trie.root;

        for (int i = 0; i < n; i++) {
            int childNo = childNoOf(dna[i]);

            while (prefixIndex != trie.root && trie.nodes[prefixIndex].children[childNo] == -1) {
                prefixIndex = trie.nodes[prefixIndex].failure;
            }

            if (trie.nodes[prefixIndex].children[childNo] != -1) {
                prefixIndex = trie.nodes[prefixIndex].children[childNo];
            }

            totalHitCount += trie.nodes[prefixIndex].hitCount;
        }

        cout << totalHitCount << '\n';
    }

    return 0;
}
