#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono> 

void bruteForceSearch(std::string *letters, std::vector<std::string> vec) {
    std::string combination;
    int  wordsFound = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (letters[i] != letters[j]) {
                combination = letters[i] + letters[j];
                if (std::find(vec.begin(), vec.end(), combination) != vec.end()) {
                    wordsFound++;
                    std::cout << combination << std::endl;
                }
            }

            for (int k = 0; k < 12; k++) {
                if (letters[i] != letters[j] && letters[i] != letters[k] && letters[j] != letters[k]) {
                    combination = letters[i] + letters[j] + letters[k];
                    if (std::find(vec.begin(), vec.end(), combination) != vec.end()) {
                        wordsFound++;
                        std::cout << combination << std::endl;
                    }
                }
            }
        }
    }
    std::cout << "Words found: " << wordsFound << std::endl;
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
    std::ifstream inputFile("twl06.txt");

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

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();
    
    bruteForceSearch(letters, dictionaryWords);

    // Record end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    std::chrono::duration<double> duration = end - start;

    std::cout << "Task complete in " << duration.count() << " seconds" << std::endl;
}