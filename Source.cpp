
/* Justin Swinney
* CS - 210
* Project 7
* 6 / 17 / 2023
*/

#include <iostream>
#include <fstream>
#include <map>
#include <limits>

using namespace std;

class FoodTracker {

private:
    map<string, int> quantityMap; // map that will store the frequencies of each item.

public:
    FoodTracker() {}


    //Function ReadInputFile:  for reading input file and setting count of items in list.

    void ReadInputFile(string fileName) {
        ifstream inFile(fileName);
        string food; //Variable for items or in this case a food item.
        while (inFile >> food) {
            quantityMap[food]++;
        }
        inFile.close();
    }

    // Function PrintItemFrequency: Menu Option 1 output via foods searched.

    void PrintItemFrequency(string food) {
        if (quantityMap.count(food) > 0) {
            cout << food << " was purchased " << quantityMap[food] << " times." << endl;
        }

        else {
            cout << food << " was not purchased. Please try again." << endl;
        }
        cout << endl;
    }

    // Function PrintAllFrequency: Menu Option 2 output all foods and frequencies.

    void PrintAllFrequencies() {
        for (auto iterator = quantityMap.begin(); iterator != quantityMap.end(); iterator++) {
            cout << iterator->first << " has been pruchased " << iterator->second << " times." << endl;
        }
        cout << endl;
    }

    // Function PrintHistogram: Menu Option 3 output all foods and frequencies replacing numerical values with *'s.

    void PrintAllHistogram() {
        for (auto iterator = quantityMap.begin(); iterator != quantityMap.end(); iterator++) {
            cout << iterator->first << " ";
            for (int i = 0; i < iterator->second; i++) {
                cout << "*";
            }
            cout << endl;
        }
        cout << endl;
    }

    //Function WriteFrequencyBackup Creates a backup file named frequency.dat, for data backup.

    void WriteFrequencyBackup(string frequency) {
        ofstream frequencyFileBackup("frequency.dat");
        for (auto iterator = quantityMap.begin(); iterator != quantityMap.end(); iterator++) {
            frequencyFileBackup << iterator->first << " " << iterator->second << endl;
        }
        frequencyFileBackup.close();
    }

};


int main() {

    FoodTracker tracker;
    tracker.ReadInputFile("CS210_Project_Three_Input_File.txt");
    tracker.WriteFrequencyBackup("frequency.dat"); //Calling function and creating backup at the start of the program without user interaction.


    int inputSelection;

    do { //Do loop for endless menu until input selection is 4.
        cout << "***************" << " MENU " << "***************" << endl;
        cout << "1: " << "Search for a vegetable" << endl;
        cout << "2: " << "Print all veggies and frequencies" << endl;
        cout << "3: " << "Print histogram of all veggies" << endl;
        cout << "4: " << "Exit the program" << endl;
        cout << "Please enter a number 1-4" << endl;
        cout << "************************************" << endl;
        cout << endl;
        cin >> inputSelection;
        cout << endl;

        switch (inputSelection) {

            //Case 1: Searching for food item and output the frequencies in the list.
        case 1: {
            string food;
            cout << "Enter a food to search for: ";
            cin >> food;
            tracker.PrintItemFrequency(food);
            break;
        }

              //Case 2: Printing all food items and frequencies.
        case 2: {
            tracker.PrintAllFrequencies();
            break;
        }

              //Case 3: Printing all food items and quantities in histogram format (*).
        case 3: {
            tracker.PrintAllHistogram();
            break;
        }

              // Case 4: Exiting program.
        case 4: {
            cout << "Terminating the program..." << endl;
            break;
        }

              //Default case: To produce output based on invalid input from user.
        default: {
            cout << "Invalid selection... Please input a number between 1-4" << endl;
            cout << endl;

            /* Clearing input selection and removing junk to avoid endless loop.*/
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        }

    } while (inputSelection != 4);

    return 0;
}
