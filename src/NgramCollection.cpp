/*NgramCollection.cpp
 *Karun Kannan
 *11/12/16
 *Purpose: Defines methods from .hpp file
 */
#include <vector>
#include <algorithm>
#include <list> 
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <iostream>
#include "../include/NgramCollection.hpp"
//using declarations
using std::get;
using  std::tuple;
using  std::vector;
using  std::string;
using  std::cout;
using  std::map;
using  std::pair;
//using  std::lsit;
//used to build the map counts by referencing values from the file which are stored in the vector
void NgramCollection::increment(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end){
  vector<string> key;
  string input;
  
  for(vector<string>::const_iterator it = begin; it != end-1; ++it){
    key.push_back((*it));
  }
  input = (*(end-1));
  counts[key][input]++;
    
}

//puts it to string
string NgramCollection::toString(char order) const {
  string output;
  if (order == 'c'){
    output = toStringCount();
  }else if(order == 'r'){
    output = toStringReverseAlpha();
  }else if(order == 'a'){
    output = toStringAlpha();
  }else if(order == 'g'){
    output = "";
  }else{
    cout << "Error: Invalid input";
  }
  return output;
}

string NgramCollection::toStringAlpha() const{
  string output; 
  //already sorted 
  for(map<vector<string>, map<string,unsigned>>::const_iterator it1 = counts.begin(); it1 != counts.end(); ++it1){
    string temp;
    for(vector<string>::const_iterator it = it1->first.begin();it!=it1->first.end();++it){
      temp = temp + (*it) + " ";
    }
    for(map<string,unsigned>::const_iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2){
      output = output +temp+  it2->first + " " + std::to_string(it2->second) + "\n";
    }
  }
    return output;
    
} 


string NgramCollection::toStringReverseAlpha() const{
  string output;
  for(map<vector<string>, map<string,unsigned>>::const_reverse_iterator it1 = counts.rbegin(); it1 != counts.rend(); ++it1){
    string temp;
    for(vector<string>::const_iterator it = (it1->first).begin();it!=(it1->first).end();++it){
      temp = temp + (*it) +" ";
    }
    for(map<string,unsigned>::const_reverse_iterator it2 = (it1->second).rbegin(); it2 != (it1->second).rend(); ++it2){
      output = output+temp + it2->first + " " + std::to_string(it2->second) + "\n";
    }
  }
  return output; 
}

string NgramCollection::toStringCount() const {
  string output;
  //put it into tuple to order
  vector<tuple<unsigned,vector<string>,string>> recs;
  for(map<vector<string>, map<string,unsigned>>::const_iterator it1 = counts.begin(); it1 != counts.end(); ++it1){
    for(map<string,unsigned>::const_iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2){
      recs.push_back(make_tuple(it2->second,it1->first, it2->first));
    }
  }
  //sort said tuple
  sort(recs.begin(),recs.end());
  //output ordered tuple
  for(vector<tuple<unsigned,vector<string>,string>>::iterator it1 = recs.begin();it1!=recs.end();++it1){
    string temp;
    for(vector<string>::iterator it = (get<1>(*it1)).begin();it!=(get<1>(*it1)).end();++it){
      temp = temp + (*it) +" ";
    }
    
    output= output +temp+ get<2>(*it1) + " " + std::to_string(get<0>(*it1)) + "\n";
  }

  return output;
}

//Picks word for random generation
string NgramCollection::pickWord(std::list<std::string>::const_iterator begin,std::list<std::string>::const_iterator end) const {
  string output;
  vector<string> key1;
  //builds the key 
  for(std::list<std::string>::const_iterator it = begin; it!=end; ++it){
    key1.push_back((*it));
    //std::cout << (*it);
  }
  //stores options for the next word
  vector<string> options;
  //use key to cycle through the nested map to build the options vector 
  for(std::map<std::string, unsigned>::const_iterator it = (counts.at(key1)).cbegin();it!=(counts.at(key1)).cend();++it){
    //std::cout << " Inside the second loop";
    for(int i = 0; i < (int)(it->second);i++){
      options.push_back(it->first);
    }
  }
  //pick the word 
  int i = (rand() % options.size());
  output = options.at(i);
  return output; 
}

