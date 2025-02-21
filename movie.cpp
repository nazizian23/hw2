#include "movie.h"
#include <sstream>

using namespace std;

//Constructor for movie calls the product base class constructor with movie as the category and initializes the genre and rating from input

Movie::Movie(const string name, double price, int qty, const string genre, const string rating) : Product("movie",name,price,qty), genre_(genre), rating_(rating){

}
//Destructor
Movie::~Movie(){

}
//Generates keywords for searching the movie
set<string> Movie::keywords()const{
  set<string> keywords= parseStringToWords(name_);//Extracts keywords from movie name 
  keywords.insert(convToLower(genre_));//adds genre as a keyword 
  return keywords;

}

string Movie::displayString() const{//Returns a formatted string that describes movie

  stringstream ss;
  ss<<name_<<"\nGenre: "<<genre_<<" Rating: "<< rating_<<"\n"<<price_<<" "<< qty_<<" left."; 
  return ss.str();
}

void Movie::dump(ostream& os) const{//Dumps movie data in the correct format for the database storage

  os<<"movie\n"<<name_<<"\n"<< price_<< "\n"<< qty_<<"\n"<<genre_<<"\n"<<rating_<<endl;
}





