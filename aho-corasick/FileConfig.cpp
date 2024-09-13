# include "FileConfig.h"
# include <fstream>
# include <string>

void FileConfig::build() {
    ifstream configFile(configFilePath);
    string line;
    int lineNumber = 0;
    while(getline(configFile, line)) {
        if (lineNumber == 0 || lineNumber > 4) {
            lineNumber ++ ;
            continue;
        }
        int start = line.find(":\"") + 2;
        int end = line.find("\"", start);
        string targetText = line.substr(start, end-start);
        switch (lineNumber) {
            case 1:
                keywordFilePath = targetText;
                break;
            case 2:
                textFilePath = targetText;
                break;
            case 3:
                listOfTextFilePath = targetText;
            case 4:
                outputFilePath = targetText;
                break;
            default:
                break;
        }
        lineNumber ++;
    }
    configFile.close();
}