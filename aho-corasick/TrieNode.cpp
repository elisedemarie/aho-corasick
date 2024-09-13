# include "TrieNode.h"
# include <map>
# include <string>
# include <vector>
# include <iostream>

using namespace std;

TrieNode* TrieNode::getChild (char character) {
    return children[character];
}

TrieNode* TrieNode::getOrAddChild(char character) {
    TrieNode* childNode = children[character];
    if (childNode) {
        return childNode;
    }
    childNode = new TrieNode(character);
    childNode->setParent(this);
    childVector.push_back(childNode);
    childNode->setString(this);
    children[character] = childNode;
    return childNode;
}

bool TrieNode::checkChild(char character) {
    return children.count(character) > 0;
}

void TrieNode::setString(TrieNode* parentNode) {
    nodeString = *(parentNode->getString()) + this->character;
}

void TrieNode::setSuffix(TrieNode* suffixNode) {
    suffix = suffixNode;
}

void TrieNode::setParent(TrieNode* parentNode) {
    parent = parentNode;
}

void TrieNode::setOutput(TrieNode* outputNode) {
    output = outputNode;
}

TrieNode* TrieNode::getSuffix() {
    return suffix;
}

TrieNode* TrieNode::getParent() {
    return parent;
}

TrieNode* TrieNode::getOutput() {
    return output;
}

char TrieNode::getCharacter() {
    return character;
}

string* TrieNode:: getString() {
    return &nodeString;
}
vector<TrieNode*>* TrieNode::getAllChildren() {
    return &childVector;
}
