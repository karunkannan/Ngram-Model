#ifndef _CS120_LANGUAGE_MODEL_HPP
#define _CS120_LANGUAGE_MODEL_HPP
#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstdlib> // for srand
#include <ctime>// for time() (for srand)
#include "NgramCollection.hpp"
class LanguageModel{
public:
  LanguageModel (unsigned n) : Ngram(n){};
  void buildModel(std::string fileName);
  void readFile(std::string fileName);
  std::string print(char order);
  std::string output();
  std::vector<std::string> readFileList(std::string fileName);
private:
  NgramCollection Ngram;
};

#endif
