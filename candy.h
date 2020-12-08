/*
 Austin Sickels
*/

#ifndef candy_h
#define candy_h

#include <string>
#include <vector>

using namespace std;


class Candy {
private:
  string name; // Name of the candy
  string type; // Type of the candy
  string priceType; // Price type of the candy
  float price; // Price of each unit of candy
  int color; // Color of the candy
  float amount; // Amount of this candy
  float calories; // Calories per unit of this candy

public:
  Candy() { //Default constructor - init each value to empty or -1
    name = "";
    type = "";
    priceType = "";
    price = -1;
    color = -1;
    amount = -1;
    calories = -1;
  }

  Candy(string givenName, string givenType, string givenPriceType, float givenPrice, int givenColor, float givenAmount, float givenCalories);

  Candy(const Candy& origCandy);

  Candy& operator=(const Candy& candyToCopy);

  bool operator<(const Candy& rhs);

  ~Candy();

  string GetName();

  float GetAmount();

  string GetPriceType();

  float GetTotalPrice();

  string GetType();
};

#endif
