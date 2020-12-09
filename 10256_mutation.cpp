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
        int childDepths[CHILDREN_SIZE]{-1, -1, -1, -1};
        int failure{-1};
        int hitCount{};
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
            nodes[depth].hitCount = 1;

            return;
        }

        int childNo = childNoOf(s[i]);

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

                    if (trie.nodes[prefixDepth].childDepths[i] != -1) {
                        prefixDepth = trie.nodes[prefixDepth].childDepths[i];
                    }

                    trie.nodes[childDepth].failure = prefixDepth;
                }

                trie.nodes[childDepth].hitCount += trie.nodes[trie.nodes[childDepth].failure].hitCount;

                bfsDepths.push(childDepth);
            }
        }

        int prefixDepth = trie.rootDepth;

        for (int i = 0; i < n; i++) {
            int childNo = childNoOf(dna[i]);

            while (prefixDepth != trie.rootDepth && trie.nodes[prefixDepth].childDepths[childNo] == -1) {
                prefixDepth = trie.nodes[prefixDepth].failure;
            }

            if (trie.nodes[prefixDepth].childDepths[childNo] != -1) {
                prefixDepth = trie.nodes[prefixDepth].childDepths[childNo];
            }

            totalHitCount += trie.nodes[prefixDepth].hitCount;
        }

        cout << totalHitCount << '\n';
    }

    return 0;
}
