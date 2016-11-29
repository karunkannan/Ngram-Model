#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "../include/NgramCollection.hpp"
#include "../include/LanguageModel.hpp"
//using declarations
using  std::vector;
using  std::string;
//using  std::cout;
using  std::map;
using  std::pair;
//using  std::lsit;

//trains the model 
void LanguageModel::buildModel(string fileName){
  vector<string> files = readFileList(fileName);
  for(vector<string>::iterator it = files.begin();it!=files.end();++it){
    readFile((*it));
  }
  
}

//reads the file list and creates a vector of lists of other file names
vector<string> LanguageModel::readFileList(string fileName){
  vector<string> fileNames;
  std::ifstream inFile(fileName);
  if(!inFile){
    std::cout << "Error: Could not open file";
    return fileNames;
  }
 
  string input;
  while(inFile >> input){
    fileNames.push_back(input);
  }
  inFile.close();
  return fileNames;
}

//trains the model with the inputs from each of the files. 
void LanguageModel::readFile(string fileName){
  std::ifstream inFile(fileName);
  if(!inFile){
    std::cout << "Error: Could not open file";
    return;
  }
  vector<string> file;
  for(int i = 1;i<(int)Ngram.getN();i++){
    file.push_back("<START_"+std::to_string(i)+">");
  }
  string input;
  while(inFile >> input){
    file.push_back(input);
  }
  for(int i = 1;i<(int)Ngram.getN();i++){
    file.push_back("<END_"+ std::to_string(i)+">");
  }
  for(int i=0; i<(int)file.size()-(int)Ngram.getN()+1;i++){
    Ngram.NgramCollection::increment(file.begin()+i,file.begin() + Ngram.getN()  +i);
  }
  //turn to string
  
}

//accesses the toString funciton of NgramCollection
std::string LanguageModel::print(char order){
  return  Ngram.toString(order);
}

//Used to randomly generate outputs
std::string LanguageModel::output(){
  std::list<std::string> output;
  int n = (int)Ngram.getN();
  for(int i = 1;i<n;i++){
    output.push_back("<START_" + std::to_string(i) + ">");
  }
  string in;
  std::list<std::string>::const_iterator begin = output.cbegin(); 
  while(in != ("<END_" + std::to_string(n-1) + ">")){
    in = Ngram.pickWord(begin++,output.cend());
    //std::cout << in;
    output.push_back(in);   
  }
  string out;
  for(std::list<std::string>::const_iterator it = output.cbegin();
      it!=output.cend();++it){
    out = out +  (*it) + " ";
  }
  out = out + "\n";
  return out; 
}
