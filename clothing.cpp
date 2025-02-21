#include "clothing.h"
#include <sstream>

using namespace std;

//Constructor calls the product base class with clothing as the category and initializes size and brand from the input

Clothing::Clothing(const string name, double price, int qty, const string size, const string brand) : Product("clothing",name,price,qty), size_(size), brand_(brand){

}

//Destructor

Clothing::~Clothing(){

}
//Generates the keywords associated with clothing
set<string> Clothing::keywords()const{
  set<string> keywords= parseStringToWords(name_);//Extracts the keywords from the clothing name using parseStringToWords

  set<string> brandWords= parseStringToWords(brand_);//Extracts the keywords from the brand name 
  keywords.insert(brandWords.begin(),brandWords.end());// merges the keywords all together
  return keywords;

}
//Returns formatted string that represents the clothing item
string Clothing::displayString() const{
  stringstream ss;
  ss<<name_<<"\nSize: "<<size_<<" Brand: "<< brand_<<"\n"<<price_<<" "<< qty_<<" left."; 
  return ss.str();

}
//Dumps the clothing data in the correct format for the database
void Clothing::dump(ostream& os) const{
  os<<"clothing\n"<<name_<<"\n"<< price_<< "\n"<< qty_<<"\n"<<size_<<"\n"<<brand_<<endl;
}


