/*
 Austin Sickels
*/

#include <stdexcept>
#include "candy.h"
#include "inventory.h"
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, const char * argv[]) {
  if (argc != 2) { // If we are given an inappropriate amount of arguments, throw an error
    throw invalid_argument("Invalid number of arguments from command line \nCorrect format is: ./main <filename>");
  }
  ifstream fileIn; // file to read
  fileIn.open(argv[1]); // second parameter is the filename
  if (!fileIn.is_open()) { // if the file isnt open (23.5.1 in zybooks)
    cout << "Could not open file " << argv[1] << endl; // print error
    return 1; // return error code
  }
  string input; // current line of input
  // Next values match candy parameters
  string name;
  string type;
  string priceType;
  float price;
  int color;
  float amount;
  float calories;
  // End candy parameters
  Inventory *inv = new Inventory(); // Init the new inventory object to store candies
  // NOTE: I based the file input on Zybooks 23.5 File Input
  fileIn >> input; // Read the first line
  while (!fileIn.eof()) { // While there is still more file to read
    if (input == "START") { // if we find a candy definition read it in
      getline(fileIn, input); // Clear the newline character after START
      getline(fileIn, name); // Read the entire line, could have spaces in the name
      fileIn >> type;
      if (type != "jelly" && type != "caramel" && type != "chocolate" && type != "hard") { // If the type isnt valid
        throw runtime_error("Invalid type in candy: " + name + "\njelly, caramel, chocolate, or hard expected"); // Throw error and tell the user which candy caused the problem
      }
      fileIn >> priceType;
      if (priceType != "piece" && priceType != "pound") { // If the price type is not valid
        throw runtime_error("Invalid price type in candy: " + name + "\npiece or pound expected"); // Throw error and tell the user which candy caused the problem
      }
      fileIn >> price;
      if (price < 0) {
        throw runtime_error("Negative price in candy: " + name); // Throw error and tell the user which candy caused the problem
      }
      fileIn >> color;
      if (color < 0 || color > 9) { // If the color is invalid
        throw runtime_error("Invalid color in candy: " + name + "\nEnter a value between 0-9"); // Throw error and tell the user which candy caused the problem
      }
      fileIn >> amount;
      if (amount < 0) {
        throw runtime_error("Negative amount in candy: " + name); // Throw error and tell the user which candy caused the problem
      }
      fileIn >> calories;
      if (calories < 0) {
        throw runtime_error("Negative calories in candy: " + name); // Throw error and tell the user which candy caused the problem
      }
      Candy *candy = new Candy(name, type, priceType, price, color, amount, calories); // Create a new candy with those parameters
      inv->add(*candy); // Add the candy to our inventory
      fileIn >> input; // Clear END
    }
    fileIn >> input; // Scan the next item in the file
  }
  inv->SelectionSort(); // Run a selection sort to output the candies in the proper order
  inv->ListAllCandies(); // Call list all candies to print out all candies and information
  inv->PrintTotalValue(); // Call print total value to print the value of the inventory
  inv->PrintTypeAmount(); // Call print type amount to print the number of the types of candies we have

  fileIn.close(); // Close the file
}
