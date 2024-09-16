# include "Processor.h"
# include "FileConfig.h"
# include <string>
# include <iostream>
# include <chrono>
# include <ctime>

using namespace std;

int main() {
    auto start = chrono::system_clock::now();
    FileConfig* config = new FileConfig("config.json");
    Processor* processor = new Processor();
    processor->addKeywordsFromFile(config->keywordFilePath);
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "BUILD TIME (s): " << elapsed_seconds.count() << endl;
    
    auto start2 = chrono::system_clock::now();
    processor->searchMultipleFiles(config->listOfTextFilePath);
    processor->writeResults(config->outputFilePath);
    auto end2 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2;
    cout << "SEARCH TIME (s): " << elapsed_seconds2.count() << endl;
    cout << "MATCHES: " << processor->countMatches() << endl;
    return 0;

}
