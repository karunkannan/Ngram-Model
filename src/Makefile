Ngram: driver.o NgramCollection.o LanguageModel.o
	g++ -std=c++11 -pedantic -Wall -Wextra -g -o Ngram driver.o NgramCollection.o LanguageModel.o
driver.o:driver.cpp 
	g++ -std=c++11 -pedantic -Wall -Wextra -g -c driver.cpp 
NgramCollection.o: NgramCollection.cpp 
	g++ -std=c++11 -pedantic -Wall -Wextra -g -c  NgramCollection.cpp 
LanguageModel.o: LanguageModel.cpp
	g++ -std=c++11 -pedantic -Wall -Wextra -g -c  LanguageModel.cpp
clean:
	rm -f *.o Ngram
