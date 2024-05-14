#include <string>
#include <vector>

#include <fstream>
#include <iostream>

using namespace std;

vector<vector<string>> readmap(const std::string &path)
{
    vector<vector<string>> result = vector<vector<string>>();

    ifstream inputFile(path);

    if (!inputFile.is_open())
    {
        cerr << "Error opening the file!" << endl;
        return result;
    }

    string line;
    string word;
    int height, width;
    vector<vector<string>> temp = vector<vector<string>>();
    inputFile >> height;
    inputFile >> width;
    for (int i = 0; i < height; i++)
    {
        vector<string> ligne = vector<string>();
        for (int j = 0; j < width; j++)
        {
            inputFile >> word;
            ligne.push_back(word);
            std::cout << word;
            word="";
        }
        std::cout << std::endl;
        temp.push_back(ligne);
    }
    inputFile.close();
    return temp;
}