#ifndef BOOK_H
#define BOOK_H
//Include the base product and util functions
#include "product.h"
#include "util.h"
#include <set>
#include <string>

class Book: public Product{
  public:
    //Constructor of book inherits the name price and quantity from Product class and takes the isbn and author as well
    Book(const std::string name, double price, int qty, const std::string isbn, const std::string author);
    ~Book();//Destructor
    std:: set<std::string> keywords() const; //generates the keywords for book
    std::string displayString() const;//returns string representing books details
    void dump(std::ostream& os) const;//puts books data into ostream in the correct format

  private:
    //Variables unique to book are isbn and author
    std::string isbn_;
    std::string author_;
};

#endif
