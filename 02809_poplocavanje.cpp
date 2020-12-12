#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        map<char, int> childNodes;
        int failure{-1};
        int length{};
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
            nodes[node].length = i;

            return;
        }

        if (!nodes[node].childNodes.count(s[i])) nodes[node].childNodes[s[i]] = newNode();

        add(nodes[node].childNodes[s[i]], s, i + 1);
    }

    void add(string &s) {
        add(rootNode, s, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    int m;
    Trie trie;
    queue<int> bfsNodes;
    vector<pair<int, bool>> matches;  // .first = <index>, .second = <if match is opening>
    int matchOpenIndex = 0;
    int matchOpenStack = 0;
    int foundCharCount = 0;

    cin >> n >> s >> m;

    while (m--) {
        string p;

        cin >> p;

        trie.add(p);
    }

    trie.nodes[trie.rootNode].failure = trie.rootNode;

    bfsNodes.push(trie.rootNode);

    while (!bfsNodes.empty()) {
        int currentNode = bfsNodes.front();

        bfsNodes.pop();

        for (int i = 0; i < 26; i++) {
            char child = (char) ('a' + i);

            if (!trie.nodes[currentNode].childNodes.count(child)) continue;

            int childNode = trie.nodes[currentNode].childNodes[child];

            if (currentNode == trie.rootNode) trie.nodes[childNode].failure = trie.rootNode;
            else {
                int prefixNode = trie.nodes[currentNode].failure;

                while (prefixNode != trie.rootNode && !trie.nodes[prefixNode].childNodes.count(child)) {
                    prefixNode = trie.nodes[prefixNode].failure;
                }

                if (trie.nodes[prefixNode].childNodes.count(child)) {
                    prefixNode = trie.nodes[prefixNode].childNodes[child];
                }

                trie.nodes[childNode].failure = prefixNode;
            }

            trie.nodes[childNode].length = max(trie.nodes[childNode].length,
                                               trie.nodes[trie.nodes[childNode].failure].length);

            bfsNodes.push(childNode);
        }
    }

    int prefixNode = trie.rootNode;

    for (int i = 0; i < n; i++) {
        while (prefixNode != trie.rootNode && !trie.nodes[prefixNode].childNodes.count(s[i])) {
            prefixNode = trie.nodes[prefixNode].failure;
        }

        if (trie.nodes[prefixNode].childNodes.count(s[i])) prefixNode = trie.nodes[prefixNode].childNodes[s[i]];

        if (trie.nodes[prefixNode].length) {
            matches.emplace_back(i - trie.nodes[prefixNode].length + 1, false);
            matches.emplace_back(i, true);
        }
    }

    sort(matches.begin(), matches.end());

    for (auto &match : matches) {
        if (!match.second) {
            if (!matchOpenStack) matchOpenIndex = match.first;

            matchOpenStack++;
        } else {
            matchOpenStack--;

            if (!matchOpenStack) foundCharCount += match.first - matchOpenIndex + 1;
        }
    }

    cout << n - foundCharCount << '\n';

    return 0;
}
