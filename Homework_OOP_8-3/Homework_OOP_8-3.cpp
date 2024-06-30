// Homework_OOP_8-3.cpp

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

map<std::string, int> countFrequency(const std::string& file_path) {
    map<std::string, int> frequency;
    ifstream file(file_path);
    string word;
    
    if (file.is_open()) {
        while (file >> word) {
            word.erase(remove_if(word.begin(), word.end(), [](char c) {return ispunct(c)|| isdigit(c); }), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            frequency[word]++;
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
    }

    return frequency;
}

void writeResultsToFile(const std::map<std::string, int>& result, const std::string& output_file) {
    std::ofstream outfile(output_file, std::ios::out);
    if (outfile.is_open()) {
        for (const auto& pair : result) {
            outfile << pair.first << ": " << pair.second << std::endl;
        }
     auto max_element = std::max_element(result.begin(), result.end(),
     [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                return a.second < b.second;
            });
     
     outfile << "Most frequent word: " << max_element->first << " (Frequency: " << max_element->second << ")" << std::endl;
     outfile.close();
     cout << "Results have been written to '" << output_file << "'" << std::endl;
    }
    else {
        cerr << "Unable to open output file" << std::endl;
    }
}


void main()
{
    setlocale(LC_ALL, "");
    std::string file_path = "war_and_peace.ru.txt";
    std::map<std::string, int> result = countFrequency(file_path);

    writeResultsToFile(result, "output_results.txt");




    
}

