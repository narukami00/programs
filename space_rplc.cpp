#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void processFile(const string &inputFile, const string &outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    
    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return;
    }
    
    if (!outFile) {
        cerr << "Error opening output file." << endl;
        return;
    }
    
    string line, word;
    bool firstWord = true;
    
    while (getline(inFile, line)) {
        stringstream ss(line);
        
        while (ss >> word) {
            if (firstWord) {
                outFile << word;
                firstWord = false;
            } else {
                outFile << " " << word;
            }
        }
        
        outFile << "\n";
        firstWord = true;
    }
    
    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "input_t.txt";
    string outputFile = "output_t.txt";
    
    processFile(inputFile, outputFile);
    
    cout << "File processing complete. Check " << outputFile << endl;
    return 0;
}
