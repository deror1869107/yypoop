#include <iostream>
#include <string>
/*add the header if you need*/
#include <list>
#include <iomanip>
#include <sstream>
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
public:
    /* Write about IceCream Constructor
       IceCream(string name, double cost):DessertItem(name),cost(cost)
    */
    IceCream(string name, double cost):DessertItem(name), cost(cost)
    {

    }
    /* Write about IceCream other member functions*/
    string getDetails()
    {
        return "";
    }

    double getCost()
    {
        return cost;
    }
private:
    double cost;
};

class Topping : public IceCream
{
public:
    /* Write about Topping Constructor
       Topping(string iceCreamName, double iceCreamCost,
	string toppingName, double toppingCost)
    */
    Topping(string iceCreamName, double iceCreamCost, string toppingName, double toppingCost)
    :IceCream(toppingName + " Sundae with " + iceCreamName, iceCreamCost), toppingName(toppingName), toppingCost(toppingCost)
    {

    }
    /* Write about Topping other member functions*/
    string getDetails()
    {
        return "";
    }

    double getCost()
    {
        return toppingCost + IceCream::getCost();
    }
private:
    string toppingName;
    double toppingCost;
};

class Cookie : public DessertItem
{
public:
    /* Write about Cookie Constructor
       Cookie(string name, int number, double pricePerDozen)
    */
    Cookie(string name, int number, double pricePerDozen)
    :DessertItem(name), number(number), pricePerDozen(pricePerDozen)
    {

    }
    /* Write about Cookie other member functions*/
    string getDetails()
    {
        return "(" + to_string(number) + " dozen(s) * " + (stringstream() << pricePerDozen).str() + "/dozen)\n";
    }

    double getCost()
    {
        return number * pricePerDozen;
    }
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
    Candy(string name, double weight, double pricePerGram)
    :DessertItem(name), weight(weight), pricePerGram(pricePerGram)
    {

    }
    /* Write about Candy other member functions*/
    string getDetails()
    {
        return "(" + (stringstream() << weight).str() + " gram(s) * " + (stringstream() << pricePerGram).str() + "/gram)\n";
    }

    double getCost()
    {
        return weight * pricePerGram;
    }
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
public:
    void enterItem(DessertItem *ptr)
    {
        itemList.push_back(ptr);
    }

    void removeItem(DessertItem *ptr)
    {
        itemList.remove(ptr);
    }

    int numberOfItems() const
    {
        return itemList.size();
    }

    void clear()
    {
        itemList.clear();
    }
private:
    list<DessertItem*> itemList;
};


ostream &operator<<(ostream &output, Checkout &checkout){

/*Overloaded operator that output a receipt for the current list of items*/
    output.setf(ios::fixed, ios::floatfield);
    output << setprecision(0);
    output << "Welcome to OOP's shop" << endl;
    output << "------------------------------" << endl;
    output << endl;
    output << "Number of items: " << checkout.numberOfItems() << endl;
    output << endl;
    double cost = 0;
    for(auto dessert:checkout.itemList){
        cost += dessert->getCost();
        cout << setw(40) << left << dessert->getName() << setw(10) << right << dessert->getCost() << endl;
        cout << dessert->getDetails();
    }
    output << endl;
    output << "------------------------------" << endl;
    double tax = cost * 0.05;
    output << setw(40) << left << "Cost" << setw(10) << right << cost << endl;
    output << setw(40) << left << "Tax" << setw(10) << right << tax << endl;
    output << endl;
    output << setw(40) << left << "Total cost" << setw(10) << right << cost + tax;
    return output;
}
