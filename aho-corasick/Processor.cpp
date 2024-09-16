# include "Processor.h"
# include "Trie.h"
# include <unordered_set>
# include <string>
# include <fstream>
# include <sstream>
# include <vector>
# include <iostream>

using namespace std;

void Processor::addKeywordsFromSet(unordered_set<string> keywords){
    trie = new Trie(keywords);
}

void Processor::addKeywordsFromFile(string filePath) {
    unordered_set<string> keywords;
    ifstream kwdFile(filePath);
    string keyword;
    while(getline(kwdFile, keyword)) {
        keywords.insert(keyword);
    }
    kwdFile.close();
    addKeywordsFromSet(keywords);
}

void Processor::addKeywordsFromVector(vector<string> keywords) {
    unordered_set<string> keywordSet;
    for (const string& keyword : keywords) {
        keywordSet.insert(keyword);
    }
    addKeywordsFromSet(keywordSet);
}

vector<string*> Processor::searchTextFromString(string text) {
    return trie->searchString(text);
}

void Processor::searchTextFromFile(string fileName) {
    stringstream buffer;
    ifstream txtFile(fileName);
    buffer << txtFile.rdbuf();
    string text = buffer.str();
    txtFile.close();
    vector<string*> textMatches = searchTextFromString(text);
    for (const string* text : textMatches) {
        Match match;
        match.matchedText = text;
        match.fileName = fileName;
        matches.push_back(match);
    }
}

void Processor::searchMultipleFiles(string listFilePath) {
    ifstream allFiles(listFilePath);
    string filePath;
    while(getline(allFiles, filePath)) {
        searchTextFromFile(filePath);
    }
    allFiles.close();
}

void Processor::writeResults(string filePath) {
    ofstream resultsFile;
    resultsFile.open(filePath);
    resultsFile << "MATHCED_TEXT,FILE_NAME\n";
    for (const Match& match : matches) {
        resultsFile << *match.matchedText << ",";
        resultsFile << match.fileName;
        resultsFile << "\n";
    }
    resultsFile.close();
}

int Processor::countMatches() {
    return matches.size();
}
