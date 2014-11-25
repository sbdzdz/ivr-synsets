#include <iostream>
#include <string>
#include "wordnetReader.h"

int main() {
  std::string name;
  std::getline(std::cin, name);
  wordnetReader::Synset* synset = new WordnetReader::Synset(name);
  std::cout << synset.getLemma() << std::endl;
  return 0;
}
