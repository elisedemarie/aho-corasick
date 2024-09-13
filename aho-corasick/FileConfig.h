# ifndef FILECONFIG_H
# define FILECONFIG_H
# include <string>

using namespace std;

class FileConfig {
    private:
        void build();
        string configFilePath;
    public:
        FileConfig(string filePath) : configFilePath(filePath) {
            build();
        }
        string keywordFilePath;
        string textFilePath;
        string listOfTextFilePath;
        string outputFilePath;
};

#endif