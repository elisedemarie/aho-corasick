# ifndef PROCESSOR_H
# define PROCESSOR_H

# include <unordered_set>
# include <string>
# include <vector>
# include "Trie.h"

using namespace std;

class Processor {
    private:
        Trie* trie;
    public:
        void addKeywordsFromSet(unordered_set<string> keywords);
        void addKeywordsFromFile(string filePath);
        vector<Match> searchTextFromString(string text, string textname="\0");
        vector<Match> searchTextFromFile(string filePath);
        vector<Match> searchMultipleFiles(string listFilePath);
        void writeResults(vector<Match> results, string fileName);
};


# endif