#include <string>
#include <vector>

#include <fstream>
#include <iostream>

using namespace std;

vector<vector<int>> readmap(const std::string &path)
{
    vector<vector<int>> result = vector<vector<int>>();

    ifstream inputFile(path);

    if (!inputFile.is_open())
    {
        cerr << "Error opening the file!" << endl;
        return result;
    }

    string line;
    int word;
    int height, width;
    vector<vector<int>> temp = vector<vector<int>>();
    inputFile >> height;
    inputFile >> width;
    std::cout << height << std::endl;
    std::cout << width << std::endl;
    for (int i = 0; i < width; i++)
    {
        vector<int> ligne = vector<int>();
        for (int j = 0; j < height; j++)
        {
            inputFile >> word;
            ligne.push_back(word);
            word=0;
        }
        temp.push_back(ligne);
    }

    for (int i = 0; i < temp[0].size(); i++)
    {
        result.push_back(vector<int>());
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