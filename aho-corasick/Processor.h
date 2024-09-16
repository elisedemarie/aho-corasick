# ifndef PROCESSOR_H
# define PROCESSOR_H

# include <unordered_set>
# include <string>
# include <vector>
# include "Trie.h"

using namespace std;

struct Match {
    const string* matchedText;
    string fileName;
};

class Processor {
    private:
        Trie* trie;
        vector<Match> matches;
    public:
        void addKeywordsFromSet(unordered_set<string> keywords);
        void addKeywordsFromFile(string filePath);
        void addKeywordsFromVector(vector<string> keywords);
        vector<string*> searchTextFromString(string text);
        void searchTextFromFile(string filePath);
        void searchMultipleFiles(string listFilePath);
        void writeResults(string fileName);
        int countMatches();
};


# endif
