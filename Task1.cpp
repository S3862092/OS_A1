#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

void TaskFilter(std::string fileName);
std::vector<std::string> getWordsFromFile(std::string fileName, int numberOfLines);
int countLines(std::string fileName);
void sortArr(std::string*wordsArr);

int main(){
    std::string fileName = "data/clean_data/fullList.txt";
    TaskFilter(fileName);

    return EXIT_SUCCESS;
}

void TaskFilter(std::string fileName){
    std::ifstream file(fileName);
    std::ofstream output;
    output.open("test.txt");
    int numberOfLines = countLines(fileName);
    
    // 1. Sort file
    std::vector<std::string> wordsArr = getWordsFromFile(fileName, numberOfLines);
    std::sort(wordsArr.begin(), std::end(wordsArr));
    /*
    for(std::string word : wordsArr){
        output << word << endl;
    }*/

    // 2. Remove non-printable characters such as the diamond question mark object

    // 3. Filter out all words with three consecutive of the same letters e.g. aaa,bbb...etc

    // 4. Remove all words starting with punctuation

    // 5. Remove all words that has numerical integers

    // 6. Remove all duplicated words

    // 7. Remove all words ending with apostrophes s

    // 8.  Remove all words with random punctuation in between them (doesn't matter if the pattern is at the end or the start)

    // 9. Remove all words that are less than 3 and more than 15 characters long
    
    file.close();
}

std::vector<std::string> getWordsFromFile(std::string fileName, int numberOfLines){
    std::ifstream file(fileName);
    std::vector<std::string> wordsArr;
    if(file.is_open()){
        std::string line;
        while(getline(file, line)){
            wordsArr.push_back(line);
        }
    }
    return wordsArr;
}

void sortArr(std::string* wordsArr){  
}

int countLines(std::string fileName){
    std::ifstream file(fileName);
    int lines = 0;
    std::string line;
    if(file.is_open()){
        while(getline(file, line)){
            lines++;
        }
    }else{
        cout << "ERROR, FILE IS CLOSED!" << endl;
    }
    return lines;
}

void deleteNonPrintable(){

}

void deleteThreeConsecutive(){

}