//============================================================================
// Name        : Lab 1-3.cpp
// Author      : Zachary Meisner
// Course      : Data Structures and Algorithms
// Date        : 8/24/2021
// Project Number
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// FIXME (1): Define a data structure to hold bid information together as a single unit of storage.

struct bidData { // Declaring Struct bidData to define unit of storage
    string Title;
    string Fund;
    string Vehicle;
    int BidAmount;
};
// FIXME (4): Display the bid values passed in data structure
/**
 * Display the bid information
 *
 * @param ?type? data structure containing the bid info
 */

void displayBid(bidData userBid) { // Calls the structure and the variable for menu function
    cout << "Title: " << userBid.Title << endl;
    cout << "Fund: " << userBid.Fund << endl;
    cout << "Vehicle: " << userBid.Vehicle << endl;
    cout << "Bid Amount: " << userBid.BidAmount << endl;

    return;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end()); // Had to move above FIXME(3): or the program would not work.
    return atof(str.c_str());
}

// FIXME (3): Store input values in data structure
/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */

bidData getBid() { // Calls appropriate structure data and maps it with temporary value shown below in each question
    bidData notUserData;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, notUserData.Title); // Example of title information being mapped to notUserData

    cout << "Enter fund: ";
    cin >> notUserData.Fund;

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, notUserData.Vehicle);

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    notUserData.BidAmount = strToDouble(strAmount, '$'); // Calls the above strToDouble function while mapping Data

    return notUserData;
}

/**
 * The one and only main() method
 */
int main() {

    // FIXME (2): Declare instance of data structure to hold bid information

	bidData userBid; // Declaring struct name and variable to hold data

    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // FIXME (5): Complete the method calls then test the program

        switch (choice) { // Had to add the correct function to make them accessible in the main menu
            case 1:
            	userBid = getBid();
                break;
            case 2:
                displayBid(userBid); // Calls the variables back after taking them as input from case 1
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
