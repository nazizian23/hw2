#include "clothing.h"
#include <sstream>

using namespace std;

Clothing::Clothing(const string name, double price, int qty, const string size, const string brand) : Product("clothing",name,price,qty), size_(size), brand_(brand){

}

Clothing::~Clothing(){

}

set<string> Clothing::keywords()const{
  set<string> keywords= parseStringToWords(name_);
  set<string> brandWords= parseStringToWords(brand_);
  keywords.insert(brandWords.begin(),brandWords.end());
  return keywords;

}

string Clothing::displayString() const{
  stringstream ss;
  ss<<name_<<"\nSize: "<<size_<<" Brand: "<< brand_<<"\n"<<price_<<" "<< qty_<<" left."; 
  return ss.str();

}

void Clothing::dump(ostream& os) const{
  os<<"clothing\n"<<name_<<"\n"<< price_<< "\n"<< qty_<<"\n"<<size_<<"\n"<<brand_<<endl;
}


