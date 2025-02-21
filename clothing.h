#ifndef CLOTHING_H
#define CLOTHING_H
//Include product base class and util functions
#include "product.h"
#include "util.h"
#include <set>
#include <string>

class Clothing: public Product{
  public:
    //Constructor for clothing inherits the basic product information and takes size and brand as well

    Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand);
    ~Clothing();//Destructor
    std:: set<std::string> keywords() const;// creates a set of keywords for clothing

    std::string displayString() const;// returns a string that represents clothing in correct format

    void dump(std::ostream& os) const;// Dumps the clothing data into ostream in correct format


  private:
    //Variables unique to clothing are size and brand
    std::string size_;
    std::string brand_;
};

#endif
