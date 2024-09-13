# include "Trie.h"
# include "TrieNode.h"
# include <iostream>
# include <deque>
# include <vector>
# include <chrono>
# include <ctime>

TrieNode* Trie::root = new TrieNode('\0');

void Trie::buildWordSetTrie() {
    for (const string& word : wordSet) {
        TrieNode* pointer = root;
        for (const char& c : word) {
            pointer = pointer->getOrAddChild(c);
        }
    }
}

void Trie::addEdges(TrieNode* node) {
    if (node==root) {
        node->setSuffix(root);
        node->setOutput(root->getOutput());
        return;
    }
    if (node->getParent() == root) {
        node->setSuffix(root);
    }
    else {
        TrieNode* suffixPointer = node->getParent()->getSuffix();
        while (true) {
            if (suffixPointer->checkChild(node->getCharacter())) {
                node->setSuffix(suffixPointer->getChild(node->getCharacter()));
                break;
            }
            else if (suffixPointer == root) {
                node->setSuffix(root);
                break;
            }
            else {
                suffixPointer = suffixPointer->getSuffix();
            }
        }
    }
    if (wordSet.count(*(node->getSuffix()->getString()))) {
        node->setOutput(node->getSuffix());
    }
    else {
        node->setOutput(node->getSuffix()->getOutput());
    }
};

void addChildrenToQueue(TrieNode* node, deque<TrieNode*>* queuePointer) {
    vector<TrieNode*>* childVector = node->getAllChildren();
    for (TrieNode* child : *childVector) {
        queuePointer->push_back(child);
    }
}

void Trie::addAllEdges() {
    deque<TrieNode*> nodeQueue;
    addChildrenToQueue(root, &nodeQueue);
    while (!nodeQueue.empty()) {
        TrieNode* node = nodeQueue.front();
        addChildrenToQueue(node, &nodeQueue);
        addEdges(node);
        nodeQueue.pop_front();
    }
}

void Trie::build() {
    buildWordSetTrie();
    addAllEdges();
}

vector<string> Trie::searchString(string text) {
    vector<string> matches;
    TrieNode* pointer = root;
    for (const char& c : text) {
        while ((pointer != root) && (!pointer->checkChild(c))) {
            pointer = pointer->getSuffix();
        }
        if (pointer->checkChild(c)) {
            pointer = pointer->getChild(c);
            if (wordSet.count(*(pointer->getString()))) {
                matches.push_back( *(pointer->getString()));
            }
            else if (pointer->getOutput()) {
                matches.push_back(*(pointer->getOutput()->getString()));
            }
        }
    }
    return matches;
}
