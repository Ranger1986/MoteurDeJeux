#include <string>
#include <vector>

#include <fstream> 
#include <iostream>

using namespace std;

vector<vector<int>> readmap(const std::string &path){
    vector<vector<int>> result = vector<vector<int>>();

    ifstream inputFile(path); 
  
    if (!inputFile.is_open()) { 
        cerr << "Error opening the file!" << endl; 
        return result; 
    } 
  
    string line; 
  
    vector<vector<int>> temp = vector<vector<int>>();
    while (getline(inputFile, line)) { 
        vector<int> ligne = vector<int>();
        for (size_t i = 0; i < line.size(); i+=2)
        {
            ligne.push_back((int)line[i]-'0');
        }
        result.push_back(ligne);
    } 
  
    inputFile.close(); 

    return result;
}