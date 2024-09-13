#ifndef TRIENODE_H
#define TRIENODE_H
#include <map>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
    private:
        char character;
        string nodeString;
        TrieNode* suffix;
        TrieNode* output = NULL;
        TrieNode* parent;
        map<char, TrieNode*> children;
        vector<TrieNode*> childVector;
    public:
        TrieNode(const char letter) : character(letter) {};
        TrieNode* getChild (char character);
        bool checkChild (char character);
        vector<TrieNode*>* getAllChildren ();
        TrieNode* getOrAddChild (char character);
        void setString (TrieNode* parentNode);
        void setSuffix (TrieNode* suffixNode);
        void setParent (TrieNode* parentNode);
        void setOutput (TrieNode* outputNode);
        TrieNode* getSuffix ();
        TrieNode* getParent ();
        TrieNode* getOutput ();
        char getCharacter ();
        string* getString ();
};

#endif
