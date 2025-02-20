#include "movie.h"
#include <sstream>

using namespace std;

Movie::Movie(const string name, double price, int qty, const string genre, const string rating) : Product("movie",name,price,qty), genre_(genre), rating_(rating){

}

Movie::~Movie(){

}

set<string> Movie::keywords()const{
  set<string> keywords= parseStringToWords(name_);
  keywords.insert(convToLower(genre_));
  return keywords;

}

string Movie::displayString() const{
  stringstream ss;
  ss<<name_<<"\nGenre: "<<genre_<<" Rating: "<< rating_<<"\n"<<price_<<" "<< qty_<<" left."; 
  return ss.str();
}

void Movie::dump(ostream& os) const{
  os<<"movie\n"<<name_<<"\n"<< price_<< "\n"<< qty_<<"\n"<<genre_<<"\n"<<rating_<<endl;
}





