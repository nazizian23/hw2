#ifndef MYDATASTORE_H
#define MYDATASTORE_H
//Include all necessary information
#include "datastore.h"
#include "user.h"
#include "product.h"
#include "util.h"
#include <map>
#include <set>
#include <vector>
#include <deque>


class MyDataStore: public DataStore{
  public:
    MyDataStore();//Constructor
    
    ~MyDataStore();//Destructor
    
    void addProduct(Product* p);//Adds a product to the store and indexes via the keywords
    
    void addUser(User* u);//adds a user to the store

    std::vector<Product*> search(std::vector<std::string>& terms, int type);//Searches for products that match the keywords uses a vector of search terms, the search type(and or or), and returns a vector of products that match the criteria

    void addToCart(std::string username, Product* p);// Adds a product to the users cart, takes the username and the product to add as arguments

    void viewCart(std::string username);//Displays the users cart, takes the username as arguments

    void buyCart(std::string username);// Processes the users cart and purchases the items if it can be afforded by the user, takes the username as arguments

    void dump(std::ostream& ofile);// Saves the current state of products and users to a file, takes the correct ostream to output to as an argument

  private:

    std::map<std::string, std::set<Product*>> keywordMap_;//Maps keywords to products
    std::map<std::string, User*> users_;//Stores users by their username
    std::map<std::string,std::deque<Product*>> carts_;//Stores the users carts
    std::set<Product*> products_;//Stores all unique products

};

#endif
















