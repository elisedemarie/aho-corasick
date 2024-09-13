# include "Processor.h"
# include <string>
# include <iostream>
# include <chrono>
# include <ctime>
# include <fstream>

using namespace std;

struct Config {
    string keywordFilePath;
    string textFilePath;
    string outputFilePath;
};

Config readConfig(string configFilePath) {
    Config config;
    ifstream configFile(configFilePath);
    string line;
    int lineNumber = 0;
    while(getline(configFile, line)) {
        if (lineNumber == 0 || lineNumber == 4) {
            lineNumber ++ ;
            continue;
        }
        int start = line.find(":\"") + 2;
        int end = line.find("\"", start);
        string targetText = line.substr(start, end-start);
        switch (lineNumber) {
            case 1:
                config.keywordFilePath = targetText;
                break;
            case 2:
                config.textFilePath = targetText;
                break;
            case 3:
                config.outputFilePath = targetText;
                break;
            default:
                break;
        }
        lineNumber ++;
    }
    configFile.close();
    return config;
}

int main() {
    Config config = readConfig("config.json");
    auto start = chrono::system_clock::now();
    Processor* processor = new Processor();
    processor->addKeywordsFromFile(config.keywordFilePath);
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "BUILD TIME (s): " << elapsed_seconds.count() << endl;
    
    auto start2 = chrono::system_clock::now();
    vector<Match> matches = processor->searchMultipleFiles(config.textFilePath);
    processor->writeResults(matches, config.outputFilePath);
    auto end2 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2;
    cout << "SEARCH TIME (s): " << elapsed_seconds2.count() << endl;
    cout << "MATCHES: " << matches.size() << endl;
    return 0;

}