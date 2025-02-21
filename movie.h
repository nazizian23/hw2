#ifndef MOVIE_H
#define MOVIE_H
//Include the product base class and util functions
#include "product.h"
#include "util.h"
#include <set>
#include <string>

class Movie: public Product{
  public:
    //Constructor for movie inherits the product constructor and takes on genre and rating as well
    Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating);
    ~Movie();//Destructor
    std:: set<std::string> keywords() const;//Creates set of keywords for movie
    std::string displayString() const;//returns string formatted correctly for movie
    void dump(std::ostream& os) const;//Dumps the movie data into ostream in correct database format


  private:
    //Unique movie variables are genre and rating
    std::string genre_;
    std::string rating_;
};

#endif
