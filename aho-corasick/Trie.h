#ifndef TRIE_H
#define TRIE_H

# include "TrieNode.h"
# include <unordered_set>
# include <string>
# include <vector>

using namespace std;

class Trie {
    private:
        static TrieNode* root;
        unordered_set<string> wordSet;
        void build();
        void buildWordSetTrie();
        void addAllEdges();
        void addEdges(TrieNode* node);
    public:
        Trie(const unordered_set<string> words)
         : wordSet(words) {
            build();
        }
        vector<string*> searchString(string text);
};

#endif
