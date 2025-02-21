#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> results;// Store all the elements in common
  //Declare iterators for both sets so we can traverse in loop later
  typename std::set<T>::iterator it1=s1.begin();
  typename std::set<T>::iterator it2=s2.begin();
  //Go through the sets at the same time
  while(it1!=s1.end()&&it2!=s2.end()){
    if(*it1<*it2){
      ++it1;//If the element in s1 is smaller than in s2 then move it1 up
    }
    else if(*it2<*it1){
      ++it2;//If the element in s2 is smaller than in s1 then move it2 up
    }
    else{
      //if they are equal add to the result set and move both up
      results.insert(*it1);
      ++it1;
      ++it2;
    }
  }
  return results;

}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> results=s1;//Initialize with all the elements of s1
  results.insert(s2.begin(),s2.end());//insert all the elements of s2 into results
  return results;//return the combined set


}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
