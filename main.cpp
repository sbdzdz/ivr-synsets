#include <iostream>
#include <string>
#include "WordnetReader.h"
#include "WordnetReader.cpp"

int main() {
  std::string name;
  std::getline(std::cin, name);
  WordnetReader::Synset synset = WordnetReader::Synset(name);
  std::cout << synset.getLemma() << std::endl;
  return 0;
}
