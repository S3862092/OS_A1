#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

void TaskFilter(std::string fileName);
bool checkASCII(std::string word);
bool checkTripleConsecutives(std::string word);
bool containsWithPunctuation(std::string word);
bool checkLength(std::string word);
bool containsNumbers(std::string word);
std::vector<std::string> removeDuplicates(std::vector<std::string>*wordArr);
std::vector<std::string> removeDuplicates2(std::vector<std::string>*wordsArr, int*size);

/*
TASK TO DO: Performance, must be less than 10 seconds
*/


int main(){
    std::string fileName = "data//fullList.txt";
    TaskFilter(fileName);
    return EXIT_SUCCESS;
}

void TaskFilter(std::string fileName){
    std::ifstream file(fileName);
    std::ofstream output;
    std::ofstream output2;  //TESTING DELETE THIS LINE LATER
    output2.open("test2.txt"); //TESTING DELETE THIS LINE LATER

    int numberOfLines = 0;
    std::vector<std::string>wordsArr;
    std::string line;

    // STEP 1: 
    // As words are being added to the Vector, filter all non ASCII characters, filter all 
    // words with three consecutive letters, and remove all words that contains punctuations.
    // Also remove all words that are shorted than 3 characters and longer than 15 characters.
    // NOTES: When the algorithm was modified to read and add words to the vector instead,
    //        of constantly running multiple for loops to check each rule, the run time
    //        improved from an estimate of 33s to 6s. 
    if(file.is_open()){
        while(getline(file, line)){
            if(checkASCII(line) == true && checkTripleConsecutives(line) == false && 
                containsWithPunctuation(line) == false && checkLength(line) != false &&
                containsNumbers(line) != true){
                wordsArr.push_back(line);
                numberOfLines += 1;
            }
        }
    }else{
        cout << "ERROR, FILE IS CLOSED!" << endl;
    }

    // STEP 2: Sort
    // Sort filtered list to remove duplicates
    std::sort(wordsArr.begin(), std::end(wordsArr));

    // STEP 3: Remove Duplicate
    std::vector<std::string>*wordsArrPtr = &wordsArr;
    int newSize = 0;
    int*newSizePtr = &newSize;
    std::vector<std::string> newWordVector = removeDuplicates(wordsArrPtr);

    for(std::string word : newWordVector){
        output2 << word << endl;
    }

    /*
    std::vector<std::string> newWordVector = removeDuplicates2(wordsArrPtr, newSizePtr);
    cout << newSize << endl;
    for(int i = 0; i < newSize; i++){
        output2 << newWordVector[i] << endl;
    }
    */
    
    // 1. Sort file

    // 2. Remove non-printable characters such as the diamond question mark object
    
    // 3. Filter out all words with three consecutive of the same letters e.g. aaa,bbb...etc

    // 4. Remove all words starting with punctuation

    // 5. Remove all words that has numerical integers
    // 1. Sort file
    // 6. Remove all duplicated words

    // 7. JOIN WITH 4. IGNORE !!Remove all words ending with apostrophes s

    // 8. JOIN WITH 4. IGNORE !!Remove all words with random punctuation or symbols in between them (doesn't matter if the pattern is at the end or the start)

    // 9. Remove all words that are less than 3 and more than 15 characters long
    
    file.close();
    output.close();
}

bool checkASCII(std::string word){
    bool result = true;
    int ascii = 0;
    for(char& c : word) {
        ascii = c;
        if (ascii < 0 || ascii > 127){
            result = false;
        }
    }
    return result;
}

bool checkTripleConsecutives(std::string word){
    int run = 1;
    int equivalentCount = 0;
    char prevChar;
    char currChar;

    for(char& c : word) {
       if(run == 1){
          prevChar = c;
          equivalentCount++;
       }else if(run > 1){
          currChar = c;
          
          if(currChar == prevChar){
            equivalentCount++;
            if(equivalentCount == 3){
                return true;
            }
          }else{
            prevChar = currChar;
            equivalentCount = 1;
          }
       }
       run++;
    }

    return false;
}

bool containsWithPunctuation(std::string word){
    bool result = false;
    int ascii = 0;
    for(char& c : word) {
        ascii = c;
        if ((ascii >= 33 && ascii <= 47) || (ascii >= 58 && ascii <= 64) || (ascii >= 91 && ascii <= 96) || (ascii >=  123 && ascii <= 126)){
            result = true;
        }
    }
    return result;
}

bool checkLength(std::string word){
    bool result = true;

    int count = 0;
    int ascii;
    for(char& c : word) {
        count ++;
    }

    if(count < 3 || count > 15){
        result = false;
    }

    return result;
}

std::vector<std::string> removeDuplicates(std::vector<std::string>*wordsArr){
    std::string prevStr;
    std::string currStr;
    std::vector<std::string>newWordVector;
    int run = 1;
    for(std::string word : *wordsArr){
        if(run == 1){
            prevStr = word;
            newWordVector.push_back(prevStr);
            run++;
        }else{
            currStr = word;
            if(currStr != prevStr){
                newWordVector.push_back(currStr);
                prevStr = currStr;
            }
        }
    }
    return newWordVector;
}

std::vector<std::string> removeDuplicates2(std::vector<std::string>*wordsArr, int*size){
    std::string prevStr;
    std::string currStr;
    std::vector<std::string>newWordVector;
    newWordVector.reserve(wordsArr->size());
    int *newSize = size;
    int run = 1;
    for(std::string word : *wordsArr){
        if(run == 1){
            prevStr = word;
            newWordVector[run-1] = prevStr;
            run++;
            *newSize += 1;
        }else{
            currStr = word;
            if(currStr != prevStr){
                newWordVector[run-1] = prevStr;
                prevStr = currStr;
                *newSize += 1;
            }
        }
    }
    return newWordVector;
}

bool containsNumbers(std::string word){
    bool result = false;
    int ascii = 0;
    for(char& c : word) {
        ascii = c;
        if (ascii >= 48 && ascii <= 57){
            result = true;
        }
    }
    return result;
}
