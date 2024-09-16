# include "../aho-corasick/Processor.h"
# include <nlohmann/json.hpp>
# include <fstream>
# include <sstream>
# include <string>
# include <iostream>
# include <vector>

using json = nlohmann::json;

void testCase(string caseName, vector<string> keywords, string text, vector<string> target) {
    Processor* processer = new Processor();
    processer->addKeywordsFromVector(keywords);
    vector<string*> result = processer->searchTextFromString(text);
    vector<string> resultStrings;
    // convert pointers to objects for comparison
    for (const string* word : result) {
        resultStrings.push_back(*word);
    }
    if (!(target == resultStrings)) {
        cout << "FAILED: " << caseName << endl;
        cout << "\tsearch for: " << endl;
        for (const string res : target) {
                cout << "\t\t" << res << endl;
            }
        cout << "\tfound: " << endl;
        for (const string res : resultStrings) {
                cout << "\t\t" << res << endl;
            }
    }
    else {
        cout << "PASSED: " << caseName << endl;
    }
}

int main() {

    ifstream jsonFile("test_cases.json");
    json testCases;
    jsonFile >> testCases;
    jsonFile.close();
    for (const json& test : testCases) {
        string caseName = test["case"];
        string text = test["text"];
        auto testKeywords = test["keywords"];
        auto testTarget = test["target"];
        vector<string> keywords;
        vector<string> target;
        vector<string> targetStrings;
        for (const string& keyword : testKeywords) {
            keywords.push_back(keyword);
        }
        for (const string& word : testTarget) { 
            target.push_back(word);
        }
        testCase(caseName, keywords, text, target);
    }
    return 0;
}