#include "mydatastore.h"
#include <iostream>

using namespace std;

MyDataStore::MyDataStore(){//Constructor initializes empty product and user store

}

MyDataStore::~MyDataStore(){//Destructor frees up all the dynamically allocated memoryy from product and user objects
  for(set<Product*>::iterator it=products_.begin();it!=products_.end();++it){//Deletes products
    delete *it;
  }
  for(map<string, User*>::iterator it=users_.begin();it!=users_.end();++it){//Deletes users
    delete it->second;
  }

}

//Adds product to data store
void MyDataStore::addProduct(Product* p){
  products_.insert(p);//Stores product in the global set
  set<string> keywords=p->keywords();//extracts the keywords
  //Maps each of the keywords to the product
  for(set<string>::iterator it=keywords.begin();it!=keywords.end();++it){
    keywordMap_[*it].insert(p);
  }

}
//adds a user to the data store
void MyDataStore::addUser(User* u){
  users_[convToLower(u->getName())]=u;
}

//Searches for products that match the given search terms
vector<Product*> MyDataStore::search(vector<string>& terms,int type){
  vector<Product*> results;
  if(terms.empty()){//Returns empty results if no search terms
    return results;

  }
  set<Product*> resultSet;

  //iterates through the search terms
  for(size_t i=0; i<terms.size();i++){
    string key= convToLower(terms[i]);//makes the term lowercase

    if(keywordMap_.find(key)!=keywordMap_.end()){
      if(i==0){
        resultSet=keywordMap_[key];//initializes with first terms results
      }
      else{
        if(type==0){//Checks if it is an AND search
          resultSet= setIntersection(resultSet,keywordMap_[key]);
        }
        else{//Checks if OR search
          resultSet=setUnion(resultSet,keywordMap_[key]);
        }
      }
    }
    else if(type==0){//If AND search no match means empty result

      return{};
    }
  }
  results.assign(resultSet.begin(),resultSet.end());
  return results;
}

//Add a product to user cart and gives error if user doesnt exist
void MyDataStore::addToCart(string username, Product* p){
  username=convToLower(username);
  if(users_.find(username)==users_.end()){
    cout<<"Invalid request"<< endl;
    return;
  }
  carts_[username].push_back(p);
}

//Displays the users cart and if the user doesnt exist gives error. Prints separate message if cart empty
void MyDataStore::viewCart(string username){
  username=convToLower(username);
  if(users_.find(username)==users_.end()){
    cout<<"Invalid username"<< endl;
    return;
  }

  deque<Product*>& cart= carts_[username];
  if(cart.empty()){
    cout<<"Cart is empty!"<<endl;
    return;
  }

  int ind=1;
  for(deque<Product*>::iterator it=cart.begin();it!=cart.end();++it){
    cout<<"Item "<< ind << ":\n"<< (*it)->displayString() <<"\n";
    ind++;
  }

}

//Purchases the items of the cart if user can afford them, takes the items out when done and leaves the unnafordable items in the cart
void MyDataStore::buyCart(string username){
  username=convToLower(username);
  if(users_.find(username)==users_.end()){
    cout<<"Invalid username"<< endl;
    return;
  }

  User* user=users_[username];
  deque<Product*>& cart =carts_[username];
  deque<Product*> remItems;

  while(!cart.empty()){
    Product* p=cart.front();
    cart.pop_front();
    //Checks if the user can afford the iterm and if it is in stock
    if(p->getQty()>0&&user->getBalance()>=p->getPrice()){
      p->subtractQty(1);
      user->deductAmount(p->getPrice());

    }
    else{
      remItems.push_back(p);

    }
  }

  cart.clear();
  cart.insert(cart.end(),remItems.begin(),remItems.end());// restores the unpurchased items


}

//Saves the current state of the data store to a file and outputs all the products and users in database format
void MyDataStore::dump(ostream& ofile){
  ofile<<"<products>"<<endl;

  for(set<Product*>::iterator it=products_.begin();it!=products_.end();++it){
    (*it)->dump(ofile);
    
  }

  ofile<<"</products>"<<endl;
  ofile<<"<users>"<<endl;


  for(map<string, User*>::iterator it=users_.begin();it!=users_.end();++it){
    it->second->dump(ofile);
  }

  ofile<<"</users>"<<endl;


}











