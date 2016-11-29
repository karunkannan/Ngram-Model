#include "../include/catch.hpp" // simple unit-testing framework
#include "../include/NgramCollection.hpp"
#include "../include/LanguageModel.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

TEST_CASE("readFileList", "[readFileList]"){
  vector<string> expectedOutput;
  expectedOutput.push_back("file1.txt");
  expectedOutput.push_back("file2.txt");
  LanguageModel model(3);
  REQUIRE(model.readFileList("file_list.txt") == expectedOutput);
}
