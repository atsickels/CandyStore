/*
 Austin Sickels
*/

#ifndef inventory_h
#define inventory_h

#include <string>
#include <vector>
#include "candy.h"

using namespace std;


class Inventory {
private:
  vector<Candy> candyList; // Vector to store candies in the inventory

public:
  Inventory() {} // Default constructor

  Inventory(const Inventory& origInventory);

  Inventory& operator=(const Inventory& inventoryToCopy);

  ~Inventory();

  void SelectionSort();

  void add(Candy c);

  void PrintTotalValue();

  void ListAllCandies();

  void PrintTypeAmount();

};

#endif
