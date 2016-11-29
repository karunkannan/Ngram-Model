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
using  std::cout;
using  std::map;
using  std::pair;
using  std::list;

int main(int argc, char* argv[]){
  if(argc > 5 || argc < 4){
    cout << "Error: Invalid Inputs";
    return 0;
  }
  string fileName = argv[1];
  std::ifstream file (fileName);
  if(!file){
    cout << "Error: invalid file\n";
    return 0;
  }
  unsigned num = atoi(argv[2]);
  if(num < 2){
    cout << "Error: number too low to build model\n";
    return 0;
  }
  char order = (argv[3][0]);
  int numOut;
  LanguageModel model(num);
  model.buildModel(fileName);
  cout << model.print(order);
  if(order == 'g'){
    numOut = atoi(argv[4]);
    if(numOut < 1){
      cout << "Error: invlaid input\n";
      return 0;
    }
    for(int i = 0; i<numOut; i++){
      cout << model.output();
    }
  }
  return 0;
}
