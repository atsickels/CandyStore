/*
 Austin Sickels
*/

#include <string>
#include <vector>
#include "candy.h"
#include <iostream>

// Constructor for the candy class, takes 7 parameters that describe a candy
Candy::Candy(string givenName, string givenType, string givenPriceType, float givenPrice, int givenColor, float givenAmount, float givenCalories) {
  // Candy parameters
  name = givenName;
  type = givenType;
  priceType = givenPriceType;
  price = givenPrice;
  color = givenColor;
  amount = givenAmount;
  calories = givenCalories;
}

// Copy constructor for the candy class
Candy::Candy(const Candy& candyToCopy) {
  // Assign this candies variables to the candy we want to copy
  name = candyToCopy.name;
  type = candyToCopy.type;
  priceType = candyToCopy.priceType;
  price = candyToCopy.price;
  color = candyToCopy.color;
  amount = candyToCopy.amount;
  calories = candyToCopy.calories;
}

// overloaded = operator for candy class
Candy& Candy::operator=(const Candy& candyToCopy) {
  // Same as above but return the reference, as specified in prototype
  name = candyToCopy.name;
  type = candyToCopy.type;
  priceType = candyToCopy.priceType;
  price = candyToCopy.price;
  color = candyToCopy.color;
  amount = candyToCopy.amount;
  calories = candyToCopy.calories;
  return *this;
}

// Destructor for the candy class
Candy::~Candy() {} // There are no special objects that need to be deleted so let the default destructor work

// Overloaded < operator for candy class, used in selection sort
bool Candy::operator<(const Candy& rhs) {
  return (price * amount) < (rhs.price * rhs.amount); // Return true if the total cost of the left candy is less than the total cost of the right candy
}

// Returns the name of this candy
string Candy::GetName() {
  return this->name;
}

// Returns the amount of this candy
float Candy::GetAmount() {
  return this->amount;
}

// Returns the price type of this candy
string Candy::GetPriceType() {
  return this->priceType;
}

// Returns the price * the amount of this candy to calculate the current price of this candy in the store
float Candy::GetTotalPrice() {
  return this->price * this->amount;
}

// Returns the type of this candy
string Candy::GetType() {
  return this->type;
}
