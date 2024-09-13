# aho-corasick
An implementation of the Aho-Corasick matching algorithm in C++

Currently this code has two implementations. Running `./file_match` reads the list of keywords pointed to by config.json and outputs all matches found in the file pointed to by config.json. Running `./dir_match` will also read keywords pointed to by config.json but will search all files listed in the listOfTextFilePaths file pointed to in config.json.

Both implementations will output a CSV listing all matches and their parent file.

Tests for variations of search types can be run in the test/ directory.
