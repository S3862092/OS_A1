#include <iostream>
#include <vector>

void changeInt(int*x);

using std::cout;
using std::endl;

int main(){
    int x = 1;
    int*xptr = &x;
    changeInt(xptr);
    //cout << x << endl;

    std::vector<std::string>words;
    words.reserve(4);
    /*
    words.push_back("Hello");
    words.push_back("World");
    words.push_back("?");
    words.push_back("!");
    */
    
    /*
    std::vector<std::string>::iterator it;
    it = words.begin()+1;
    words.erase(it);
    */
    std::vector<std::string>words2;
    words2.push_back("Hello");
    words2.push_back("World");
    words2.push_back("?");
    words2.push_back("!");   

    for(int i = 0; i < words2.size(); i++){
        words[i] = words2[i];
    }

    cout << "size: " << words.size()<< endl;
    for(int i = 0; i < 4; i++){
        cout << words[i] << endl;
    }
}

void changeInt(int*x){
    int*y = x;
    *y = 200;
}