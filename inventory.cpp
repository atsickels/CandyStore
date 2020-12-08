/*
 Austin Sickels
*/

#include <string>
#include <vector>
#include "candy.h"
#include "inventory.h"
#include <iostream>

// Copy constructor for the inventory class
Inventory::Inventory(const Inventory& origInventory) {
  for (int i = 0; i < origInventory.candyList.size(); i++) { // For every candy in our inventory
    candyList.push_back(origInventory.candyList.at(i)); // Add the candy at the corresponding location to our new inventory
  }
}

// = overload for inventory class, nearly the same as above
Inventory& Inventory::operator=(const Inventory& inventoryToCopy) {
  for (int i = 0; i < inventoryToCopy.candyList.size(); i++) { // For every candy in our inventory
    candyList.push_back(inventoryToCopy.candyList.at(i)); // Add the candy at the corresponding location to our new inventory
  }
  return *this; // Return the reference to this, as specified by the prototype
}

// Destructor for inventory class
Inventory::~Inventory() {
  candyList.clear(); // Removes all candies from inventory and sets size to 0
}

/*
* Code below is taken from 13.6 Selection Sort in zybooks
* Selection sort to sort the items in ascending order
*/
void Inventory::SelectionSort() {
  int indexSmallest = 0; // The index of the smallest item in the list
  for (int i = 0; i < candyList.size(); i++) { // for every candy in inventory
    indexSmallest = i; // call that location smallest until proven wrong
    for (int j = i + 1; j < candyList.size(); j++) { // for every candy beyond current smallest
      if (candyList.at(j) < candyList.at(indexSmallest)) { // if we find a smaller candy
        indexSmallest = j; // new smallest index
      }
    }
    // Swap
    Candy temp = candyList.at(i);
    candyList.at(i) = candyList.at(indexSmallest);
    candyList.at(indexSmallest) = temp;
  }
}

// Adds a candy to the candyList
void Inventory::add(Candy c) {
  candyList.push_back(c); // Add a candy to the inventory
}

// Prints the total value of the current inventory
void Inventory::PrintTotalValue() {
  float total = 0; // Init total to 0 in case we have no inventory
  cout << "Total value of all candy:" << endl; // title output string
  for (int i = 0; i < candyList.size(); i++) { // for every candy in inventory
    total += candyList.at(i).GetTotalPrice(); // get the price and add it to our total
  }
  cout << "$" << total << '\n' << endl; //output string
}

// Lists all the candies in descending order of the total value of that candies inventory
void Inventory::ListAllCandies() {
  cout << "All candy types, in descending order of value:" << endl; // title output string
  for (int i = candyList.size() - 1; i > -1; i--) { // Since our list is sorted in ascending order from selection sort, reverse the list here
    cout << candyList.at(i).GetName() << ": "; // print the name
    cout << candyList.at(i).GetAmount() << " " << candyList.at(i).GetPriceType() << "s, "; // then the amount and price type
    cout << "$" << candyList.at(i).GetTotalPrice() << endl; // finally the total price for this candy
  }
  cout << endl;
}

// Prints the number of candies of each type
void Inventory::PrintTypeAmount() {
  // Init all values to 0
  int caramelAmt = 0;
  int jellyAmt = 0;
  int chocolateAmt = 0;
  int hardAmt = 0;
  for (int i = 0; i < candyList.size(); i++) {
    if (candyList.at(i).GetType() == "caramel") { // If we find a caramel candy increment count
      caramelAmt++;
    } else if (candyList.at(i).GetType() == "jelly") { // If we find a jelly candy increment count
      jellyAmt++;
    } else if (candyList.at(i).GetType() == "chocolate") { // If we find a chocolate candy increment count
      chocolateAmt++;
    } else if (candyList.at(i).GetType() == "hard") { // If we find a hard candy increment count
      hardAmt++;
    }
  }
  // Output strings
  cout << "Total amounts of candy types:" << endl;
  cout << "There are " << caramelAmt << " caramel candies" << endl;
  cout << "There are " << jellyAmt << " jelly candies" << endl;
  cout << "There are " << chocolateAmt << " chocolate candies" << endl;
  cout << "There are " << hardAmt << " hard candies" << endl;
  cout << endl;
}
