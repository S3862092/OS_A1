#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

void TaskFilter(std::string fileName);
std::string* getWordsFromFile(std::string fileName, int numberOfLines);
int countLines(std::string fileName);

int main(){
    std::string fileName = "data/clean_data/fullList.txt";
    TaskFilter(fileName);

    return EXIT_SUCCESS;
}

void TaskFilter(std::string fileName){
    std::ifstream file(fileName);
    std::ofstream output;
    int numberOfLines = countLines(fileName);
    
    //sort file
    std::string* wordsArr = getWordsFromFile(fileName, numberOfLines);
    for(int i = 0; i < 1; i++){
        cout << wordsArr[i] << endl;
    }
    file.close();
}

std::string* getWordsFromFile(std::string fileName, int numberOfLines){
    std::ifstream file(fileName);
    std::string* wordsArr = new std::string[numberOfLines];
    if(file.is_open()){
        int index = 0;
        std::string line;
        while(getline(file, line)){
            wordsArr[index] = line;
            index++;
        }
    }
    return wordsArr;
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