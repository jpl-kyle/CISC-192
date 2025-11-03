# Challenges faced

My biggest challenge was my initial approach to the problem. I first tried putting in the first number to the array, and I realized that would make my code much harder to read, so I had to change my approach to put all the numbers in the array in one go.

```cpp
cout << "Number #1: ";
    if (!(cin >> numInput)) {  // Check if the first number is a number.
        cerr << "Invalid input." << '\n'; // Return an error if it is not a number/* cout << "Number #1: ";
    if (!(cin >> numInput)) {  // Check if the first number is a number.
        cerr << "Invalid input." << '\n'; // Return an error if it is not a number
        return 1;
    }
    if (numInput < 0) {
        cerr << "Input cannot be negative." << '\n'; // Return an error if it is a negative number.
        return 1;
    

    numberArray[0] = numInput; // puts the first number in the array
    }

        return 1;
    }
    if (numInput < 0) {
        cerr << "Input cannot be negative." << '\n'; // Return an error if it is a negative number.
        return 1;
    

    numberArray[0] = numInput; // puts the first number in the array
    } 
```
I really liked how this assignment combined all the things I learned up until now, and I was able to put some stuff I learned in java programming here, like while loops. I think that it is slightly easier to implement the while loops in Java, but I might be misremembering. What do you think?

This was a very good refresher to using arrays in programming. Thank you! Should I include more comments next time?

# The Code
```cpp
// Name: John Pierre Lucas
// Course: CISC 192 - C++ Programming
// Date: 11/02/2025
// Assignment: Non-Duplicated Integer Array Operations

#include <iostream>
#include <array>
using namespace std;

int main() {
    int* numberArray = new int[5];
    int numInput = 0;
    enum class Menu { Ascending=1, Descending=2, Minimum=3, Maximum=4 };
    int choice{};

    cout << "Please enter 5 unique integers:" << '\n';

    for (int i = 0; i < 5; ++i) { // index = 0
        while (true) {
            cout << "Number #" << i + 1 << ": "; // counts from 1
            if (!(cin >> numInput)) {  // Check if the number is a number.
                 cin.clear();
                 cin.ignore(100, '\n');
                 cerr << "Invalid input." << '\n'; // Return an error if it is not a number
                 continue;
            }
            if (numInput < 0) { // Check if the number is a negative number.
                 cin.clear();
                 cin.ignore(100, '\n');
                 cerr << "Input cannot be negative." << '\n'; // Return an error if it is a negative number.
                 continue;
            }
            
            bool dupe = false;
            for (int j = 0; j < i; ++j) { // looks through the array based on how many numbers are in it.
                if (numberArray[j] == numInput) { // if the inputted number matches with a number in an array
                    cerr << "Duplicate Number!" << '\n'; //Return an error if it already exists.
                    dupe = true;
                    break;
                }
            } 
            
            if (dupe) continue;
            break;
        }
        numberArray[i] = numInput;
    }
    
    cout << '\n' 
    << "1. Ascending" << '\n'
    << "2. Descending" << '\n'
    << "3. Minimum" << '\n'
    << "4. Maximum" << '\n'
    << "Please make your choice: ";
    
    while (true) { // did this so that you can constantly put invalid inputs but still get a result from a valid input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cerr << "Invalid input." << '\n'; // Return an error if it is not an int
            continue;
            }
        if (choice < 1 || choice > 4) { // Check if the number is less than 1 OR greater than 4
                 cin.clear();
                 cin.ignore(100, '\n');
                 cerr << "Invalid input." << '\n'; // Return an error.
                 continue;
        }
        break;
    }

    switch (static_cast<Menu>(choice)) {
        case Menu::Ascending: {
            int* ascendingArray = new int[5];
            for (int i = 0; i < 4; ++i) { // copy array
                ascendingArray[i] = numberArray[i];
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4 - i; j++) {
                    if (ascendingArray[j] > ascendingArray[j + 1]) {
                        int temp = ascendingArray[j];
                        ascendingArray[j] = ascendingArray[j + 1];
                        ascendingArray[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < 5; ++i) {
                cout << ascendingArray[i] << " ";
            }
            delete[] ascendingArray;
            break; 
        }
        case Menu::Descending: {
            int* descendingArray = new int[5];
            for (int i = 0; i < 4; ++i) { // copy array
                descendingArray[i] = numberArray[i];
            }
            for (int i = 0; i < 4; i++) { // bubble sort
                for (int j = 0; j < 4 - i; j++) {
                    if (descendingArray[j] < descendingArray[j + 1]) {
                        int temp = descendingArray[j];
                        descendingArray[j] = descendingArray[j + 1];
                        descendingArray[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < 5; ++i) {
                cout << descendingArray[i] << " ";
            }
            delete[] descendingArray;
            break; 
        }
        case Menu::Minimum: {
            int minimum = numberArray[0];
            for (int i = 0; i < 5; ++i) {
                int temp = numberArray[i]; //puts the first number for the first element
                if (minimum > temp) { 
                    minimum = temp;
                }
            }
            cout << "Smallest number in the array: " << minimum;
            break;
        }
        case Menu::Maximum: {
            int maximum = numberArray[0];
            for (int i = 0; i < 5; ++i) {
                int temp = numberArray[i]; //puts the first number for the first element
                if (maximum < temp) { 
                    maximum = temp;
                }
            }
            cout << "Largest number in the array: " << maximum;
            break;
        }
        default: {
            // input checker ensures that the number is 1, 2, 3, 4 already
            return 1; 
        }
        
    }
    cout << endl;
    delete[] numberArray;
    return 0;
}

```
