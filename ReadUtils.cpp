#include <iostream>
#include "ReadUtils.h"
using namespace std;

void commonErrorCode(const char prompt[]) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
}

int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        commonErrorCode(prompt);
        cin >> temp;
    }
    return temp;
}
double readDouble(const char prompt[]){
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        commonErrorCode(prompt);
        cin >> temp;
    }
    return temp;
}
bool readBool(const char prompt[]){
    char temp;
    cout << prompt;
    cin >> temp;
    temp = toupper(temp); 
    while (temp != 'Y' && temp != 'N') {
        commonErrorCode(prompt);
        cin >> temp;
        temp = toupper(temp);
    }
    return temp == 'Y';
}

