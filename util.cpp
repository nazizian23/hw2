#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  set<string> keywords;//Make a set to store the unique keywords
  string currWord="";
  //Loops through all the char in rawWords
  for(size_t i=0; i<rawWords.size();i++){
    if(isalnum(rawWords[i])){//Checks if the character is a letter or number and adds it to the current word
      currWord+= rawWords[i];
    }
    else{
      //If it isnt a letter or number checks if current word is at least 2 characters long
      if(currWord.length()>=2){
        keywords.insert(convToLower(currWord)); //Converts the currWord to lowercase and adds to set

      }
      currWord="";// resets the temporary word so it can loop and do again
    }
  }

  if(currWord.length()>=2){//Checks if the last word is longer than 2 char and inserts it if it is
    keywords.insert(convToLower(currWord));
  }

  return keywords;



}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
