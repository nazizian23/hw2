#include "book.h"
#include <sstream>

using namespace std;

//Constructor calls product base class with book as the category and initializes isbn and author from input
Book::Book(const string name, double price, int qty, const string isbn, const string author) : Product("book",name,price,qty), isbn_(isbn), author_(author){

}

Book::~Book(){//Destructor

}

set<string> Book::keywords()const{//Generates the keywords for searching book
  set<string> keywords= parseStringToWords(name_);//takes the keywords from the book name using parseStringToWords
  set<string> authWords= parseStringToWords(author_);//takes the keywords from the author name using parseStringToWords
  keywords.insert(authWords.begin(),authWords.end());//Merges the keywords from author into book keywords
  keywords.insert(isbn_);//Adds the isbn as a keyword
  return keywords;

}

string Book::displayString() const{//Returns a string in the correct format of the book. Displays the name author isbn and the quantity left
  stringstream ss;
  ss<<name_<<"\nAuthor: "<<author_<<" ISBN: "<< isbn_<<"\n"<<price_<<" "<< qty_<<" left."; 
  return ss.str();
}

void Book::dump(ostream& os) const{// Dumps book data for the database storage in correct format outputting name price quantity isbn and author
  os<<"book\n"<<name_<<"\n"<< price_<< "\n"<< qty_<<"\n"<<isbn_<<"\n"<<author_<<endl;
}





