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
    for (int i = 0; i < width; i++)
    {
        vector<string> ligne = vector<string>();
        for (int j = 0; j < height; j++)
        {
            inputFile >> word;
            ligne.push_back(word);
            word="";
        }
        temp.push_back(ligne);
    }

    for (int i = 0; i < temp[0].size(); i++)
    {
        result.push_back(vector<string>());
    }

    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = temp[i].size() - 1; j >= 0; j--)
        {
            result[i].push_back(temp[j][i]);
        }
    }

    inputFile.close();

    return result;
}