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
    vector<string> result = processer->searchTextFromString(text);
    
    if (!(target == result)) {
        cout << "FAILED: " << caseName << endl;
        cout << "\tsearch for: " << endl;
        for (const string& res : target) {
                cout << "\t\t" << res << endl;
            }
        cout << "\tfound: " << endl;
        for (const string& res : result) {
                cout << "\t\t" << res << endl;
            }
    }
    else {
        cout << "PASSED: " << caseName << endl;
    }
}

int main() {

    ifstream jsonFile("test/test_cases.json");
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
        for (const string& keyword : testKeywords) {
            keywords.push_back(keyword);
        }
        for (const string& testTarget : testTarget) { 
            target.push_back(testTarget);
        }
        testCase(caseName, keywords, text, target);
    }
    return 0;
}