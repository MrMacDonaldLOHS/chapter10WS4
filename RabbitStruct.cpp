#include <iostream>
#include <fstream>
#include "ReadUtils.h"
using namespace std;
// Rabbit struct, holds information about a single rabbit.
struct Rabbit{
    enum {MAX_CHAR_LEN=100};
    char name[MAX_CHAR_LEN];
    double maxWeight;
    int yearRecognized;
    bool isRare;
    bool isValid;
    Rabbit();
    
};
// Default constructor, clear all the information.
Rabbit::Rabbit() {
    for (int index = 0; index < MAX_CHAR_LEN; index++) {
        name[index] = '\0';
    }
    maxWeight = 0;
    yearRecognized = 0;
    isRare = false;
    isValid = false;
}


// Rabbit function
// Print out the information about a rabbit to the stream passed in
// out can be cout or a file ofstream.
void printRabbit(ostream &out, Rabbit b) {
    out << b.name << ";" << b.maxWeight << ";" << b.yearRecognized << ";" << b.isRare << endl;
}

// Rabbit function
// Fill in the values about a rabbit by asking the user questions
Rabbit makeRabbit() {
    Rabbit b;
    cout << "Enter a rabbit name: ";
    if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
    }
    cin.get(b.name, Rabbit::MAX_CHAR_LEN);
    b.maxWeight = readDouble("Enter max rabbit weight: ");
    b.yearRecognized = readInt("Enter year recognized: ");
    b.isRare = readBool("Is this rabbit rare (y/n)? ");
    b.isValid = true;
    return b; 
}

// Rabbit function
// Read one entry in the file into a Rabbit and create it.
Rabbit readRabbit(ifstream &inFile){
    Rabbit rabbit; 
    inFile.get(rabbit.name, Rabbit::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> rabbit.maxWeight;
    inFile.ignore(100,';');
    inFile >> rabbit.yearRecognized;
    inFile.ignore(100,';');
    inFile >> rabbit.isRare;
    inFile.ignore(100,'\n');
    // If we reached the end of the file while reading, then the entry is not valid
    rabbit.isValid = !inFile.eof();
    return rabbit;
}

// Database constant, maximum number of rabbits we can have in our array.
const int MAX_RABBITS=500;
// Database function
// Read the rabbits in from a file by looping and calling readRabbit.
int readRabbits(Rabbit rabbits[]) {
    ifstream rabbitFile("rabbits.txt");
    int numRabbits = 0;
    while(rabbitFile.peek() != EOF && numRabbits < MAX_RABBITS) {
        rabbits[numRabbits] = readRabbit(rabbitFile);
        numRabbits++;
    }
    return numRabbits;
}

// Database function.
// Print out the rabbits to the stream out - this could be a file
// or the screen. When it is the screen, printIndex should be true
// When it is a file, printIndex should be false.
// Only prints the valid rabbits.
void printRabbits(ostream &out, Rabbit rabbits[], bool printIndex) {
    for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbits[index].isValid) {
            if (printIndex) {
                out << "Index " << index << ": ";
            }
            printRabbit(out, rabbits[index]);
        } 
    }
}

// Database function.
// Save the list of valid rabbits back to the text file.
void saveRabbits(Rabbit rabbits[]) {
    ofstream out("rabbits.txt");
    printRabbits(out, rabbits, false);
}

// Database function.
// Get an index to remove, set the valid flag false in that location.
void removeRabbit(Rabbit rabbits[]) {
    int index = 0;
    do {
        index = readInt("Enter an index to remove between 0 and 500: ");
    }while (index < 0 || index >= MAX_RABBITS);
    rabbits[index].isValid = false;
}

// Database function.
// Find an index in the rabbit list where the Rabbit is not valid
// add the rabbit in that location.
void addRabbit(Rabbit rabbits[]) {
    for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbits[index].isValid == false) {
            rabbits[index] = makeRabbit();
            return;
        }
    }
    cout << "Too many rabbits! No room for more!" << endl;
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
    Rabbit rabbits[MAX_RABBITS]; 
    int option = 0;
    char menuOptions[][MAX_MENU_LEN]={  "Print rabbit list",
                                        "Save list to file",
                                        "Remove rabbit",
                                        "Add rabbit",
                                        "Quit"};
    readRabbits(rabbits);
    do {
        printMenu(menuOptions,5);
        option = readInt("Please select an option: ");
        switch(option) {
            case 1:
                printRabbits(cout, rabbits, true);
                break;
            case 2:
                saveRabbits(rabbits);
                break;
            case 3:
                removeRabbit(rabbits);
                break;
            case 4:
                addRabbit(rabbits);
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
