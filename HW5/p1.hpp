#include <iostream>
#include <string>
/*add the header if you need*/
using namespace std;

//Abstract base class for Dessert Item hierarchy
class DessertItem
{
private:
//Name of the DessertItem object
    string name;

public:
    DessertItem(){}
    DessertItem(string name):name(name){}
//Empty virtual destructor for DessertItem class
    virtual ~DessertItem(){}     
//returns Name of DessertItem  
    string getName(){ return name;}
    virtual string getDetails() = 0;
    virtual double getCost() = 0;
};

class IceCream : public DessertItem 
{
 
    /* Write about IceCream Constructor
       IceCream(string name, double cost):DessertItem(name),cost(cost)
    */

    /* Write about IceCream other member functions*/
private:
    double cost;
};

class Topping : public IceCream 
{

    /* Write about Topping Constructor
       Topping(string iceCreamName, double iceCreamCost,
	string toppingName, double toppingCost)
    */

    /* Write about Topping other member functions*/
private:
    string toppingName;
    double toppingCost;
};

class Cookie : public DessertItem 
{
    /* Write about Cookie Constructor
       Cookie(string name, int number, double pricePerDozen)
    */

    /* Write about Cookie other member functions*/

private:
//Number of dozens of Cookie
    int number;
    double pricePerDozen;
};

class Candy : public DessertItem 
{
public:
    /* Write here about Candy Constructor
       Candy(string name, double weight, double pricePerGram)
    */
    /* Write about Candy other member functions*/	
private:
//Weight of Candy
    double weight;
    double pricePerGram;
};



class Checkout {
    
    friend ostream &operator<<(std::ostream &, Checkout &);

    
    /* Write about Checkout member functions
    1. "enterItem" function to add the element into the list
    2. "removeItem" function to remove the elemtent from the list
    3. calculate the total cost and tax in the list
    4. "numberOfItems" for number of Item in the list
    5. "clear" clear all Items from list
    */
private:
    list<DessertItem*> itemList;
};


ostream &operator<<(ostream &output, Checkout &checkout){
  
/*Overloaded operator that output a receipt for the current list of items*/

}
