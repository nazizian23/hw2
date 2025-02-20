#include "mydatastore.h"
#include <iostream>

using namespace std;

MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){
  for(set<Product*>::iterator it=products_.begin();it!=products_.end();++it){
    delete *it;
  }
  for(map<string, User*>::iterator it=users_.begin();it!=users_.end();++it){
    delete it->second;
  }

}


void MyDataStore::addProduct(Product* p){
  products_.insert(p);
  set<string> keywords=p->keywords();

  for(set<string>::iterator it=keywords.begin();it!=keywords.end();++it){
    keywordMap_[*it].insert(p);
  }

}

void MyDataStore::addUser(User* u){
  users_[convToLower(u->getName())]=u;
}

vector<Product*> MyDataStore::search(vector<string>& terms,int type){
  vector<Product*> results;
  if(terms.empty()){
    return results;

  }
  set<Product*> resultSet;
  for(size_t i=0; i<terms.size();i++){
    string key= convToLower(terms[i]);
    if(keywordMap_.find(key)!=keywordMap_.end()){
      if(i==0){
        resultSet=keywordMap_[key];

      }
      else{
        if(type==0){
          resultSet= setIntersection(resultSet,keywordMap_[key]);
        }
        else{
          resultSet=setUnion(resultSet,keywordMap_[key]);
        }
      }
    }
    else if(type==0){
      return{};
    }
  }
  results.assign(resultSet.begin(),resultSet.end());
  return results;
}


void MyDataStore::addToCart(string username, Product* p){
  username=convToLower(username);
  if(users_.find(username)==users_.end()){
    cout<<"Invalid request"<< endl;
    return;
  }
  carts_[username].push_back(p);
}

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

    if(p->getQty()>0&&user->getBalance()>=p->getPrice()){
      p->subtractQty(1);
      user->deductAmount(p->getPrice());

    }
    else{
      remItems.push_back(p);

    }
  }

  cart.clear();
  cart.insert(cart.end(),remItems.begin(),remItems.end());

}


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











