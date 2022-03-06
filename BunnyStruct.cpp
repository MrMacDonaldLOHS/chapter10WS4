#include <iostream>
#include <fstream>
#include "FileUtils.h"
using namespace std;
// Bunny struct, holds information about a single bunny.
struct Bunny{
    enum {MAX_CHAR_LEN=100};
    char name[MAX_CHAR_LEN];
    double maxWeight;
    int yearRecognized;
    bool isRare;
    bool isValid;
    Bunny();
    
};
// Default constructor, clear all the information.
Bunny::Bunny() {
    for (int index = 0; index < MAX_CHAR_LEN; index++) {
        name[index] = '\0';
    }
    maxWeight = 0;
    yearRecognized = 0;
    isRare = false;
    isValid = false;
}


// Bunny function
// Print out the information about a bunny to the stream passed in
// out can be cout or a file ofstream.
void printBunny(ostream &out, Bunny b) {
    out << b.name << ";" << b.maxWeight << ";" << b.yearRecognized << ";" << b.isRare << endl;
}

// Bunny function
// Fill in the values about a bunny by asking the user questions
Bunny makeBunny() {
    Bunny b;
    cout << "Enter a bunny name: ";
    if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
    }
    cin.get(b.name, Bunny::MAX_CHAR_LEN);
    b.maxWeight = readDouble("Enter max bunny weight: ");
    b.yearRecognized = readInt("Enter year recognized: ");
    b.isRare = readBool("Is this bunny rare (y/n)? ");
    b.isValid = true;
    return b; 
}

// Bunny function
// Read one entry in the file into a Bunny and create it.
Bunny readBunny(ifstream &inFile){
    Bunny bunny; 
    inFile.get(bunny.name, Bunny::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> bunny.maxWeight;
    inFile.ignore(100,';');
    inFile >> bunny.yearRecognized;
    inFile.ignore(100,';');
    inFile >> bunny.isRare;
    inFile.ignore(100,'\n');
    // If we reached the end of the file while reading, then the entry is not valid
    bunny.isValid = !inFile.eof();
    return bunny;
}

// Database constant, maximum number of bunnies we can have in our array.
const int MAX_BUNNIES=500;
// Database function
// Read the bunnies in from a file by looping and calling readBunny.
int readBunnies(Bunny bunnies[]) {
    ifstream bunnyFile("bunnies.txt");
    int numBunnies = 0;
    while(bunnyFile.peek() != EOF && numBunnies < MAX_BUNNIES) {
        bunnies[numBunnies] = readBunny(bunnyFile);
        numBunnies++;
    }
    return numBunnies;
}

// Database function.
// Print out the bunnies to the stream out - this could be a file
// or the screen. When it is the screen, printIndex should be true
// When it is a file, printIndex should be false.
// Only prints the valid bunnies.
void printBunnies(ostream &out, Bunny bunnies[], bool printIndex) {
    for (int index = 0; index < MAX_BUNNIES; index++) {
        if (bunnies[index].isValid) {
            if (printIndex) {
                out << "Index " << index << ": ";
            }
            printBunny(out, bunnies[index]);
        } 
    }
}

// Database function.
// Save the list of valid bunnies back to the text file.
void saveBunnies(Bunny bunnies[]) {
    ofstream out("bunnies.txt");
    printBunnies(out, bunnies, false);
}

// Database function.
// Get an index to remove, set the valid flag false in that location.
void removeBunny(Bunny bunnies[]) {
    int index = 0;
    do {
        index = readInt("Enter an index to remove between 0 and 500: ");
    }while (index < 0 || index >= MAX_BUNNIES);
    bunnies[index].isValid = false;
}

// Database function.
// Find an index in the bunny list where the Bunny is not valid
// add the bunny in that location.
void addBunny(Bunny bunnies[]) {
    for (int index = 0; index < MAX_BUNNIES; index++) {
        if (bunnies[index].isValid == false) {
            bunnies[index] = makeBunny();
            return;
        }
    }
    cout << "Too many bunnies! No room for more!" << endl;
}

// Not a database function.
// Used by main to print out the current menu.
const int MAX_MENU_LEN = 70;
void printMenu(char options[][MAX_MENU_LEN], int numEntries) {
    for (int index = 0; index < numEntries; index++) {
        cout << (index + 1) << ") " << options[index] << endl;
    }
}

// Interact with the database functions using a menu to choose what to do
int main() {
    Bunny bunnies[MAX_BUNNIES]; 
    int option = 0;
    char menuOptions[][MAX_MENU_LEN]={  "Print bunny list",
                                        "Save list to file",
                                        "Remove bunny",
                                        "Add bunny",
                                        "Quit"};
    readBunnies(bunnies);
    do {
        printMenu(menuOptions,5);
        option = readInt("Please select an option: ");
        switch(option) {
            case 1:
                printBunnies(cout, bunnies, true);
                break;
            case 2:
                saveBunnies(bunnies);
                break;
            case 3:
                removeBunny(bunnies);
                break;
            case 4:
                addBunny(bunnies);
                break;
            case 5:
                break;
            default:
                cout << "Invalid option, try again" << endl;
                break;
        }
    }while(option != 5);
    
    return 0;
}
