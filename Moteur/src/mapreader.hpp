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
        temp.push_back(ligne);
    } 
    result.resize(temp.size());
    for (int i = 0; i < temp[0].size(); i++)
    {
        result.push_back(vector<int>());
    }
    
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = temp[i].size()-1; j >= 0; j--)
        {
            result[i].push_back(temp[j][i]);
        }
    }

    inputFile.close(); 

    return result;
}