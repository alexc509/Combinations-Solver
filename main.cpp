#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void bruteForceSearch(std::string *letters, std::vector<std::string> vec) {
    std::string combination;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            combination = letters[i] + letters[j];
            if (std::find(vec.begin(), vec.end(), combination) != vec.end()) {
                std::cout << combination << std::endl;
            }
            for (int k = 0; k < 12; k++) {
                combination = letters[i] + letters[j] + letters[k];
                if (std::find(vec.begin(), vec.end(), combination) != vec.end()) {
                    std::cout << combination << std::endl;
                }
            }
        }
    }
}

int main() {
    
    const int arrSize = 12;
    std::string letters[arrSize];
    std::vector<std::string> dictionaryWords = {};
    std::string dictionaryWord;
    
    std::cout << "Enter all the blocks one by one\n";
    for (int i = 0; i < arrSize; i++) {
        std::cin >> letters[i];
    }
    std::ifstream inputFile("engmix.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening dictionary file." << std::endl;
        return 1;
    }

    while (inputFile >> dictionaryWord)
    {
        dictionaryWords.push_back(dictionaryWord);
    }
    std::cout << "\nSuccesfully initialized data\n\n";

    inputFile.close(); // Close the file after reading
    
    bruteForceSearch(letters, dictionaryWords);

}