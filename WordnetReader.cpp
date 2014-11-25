#include "WordnetReader.h"
#include <string>
#include <vector>

WordnetReader::Synset::Synset(std:: string word) {
  lemma = word;
}

std::string WordnetReader::Synset::getLemma() {
  return lemma;
}

bool WordnetReader::Synset::isSynonymOf(WordnetReader::Synset word) {
  //TODO
}

std::vector<std::string> WordnetReader::Synset::getSynonyms() {
  //TODO
}

std::vector<std::string> WordnetReader::Synset::getClosure(std::string relation, int level) {
  //TODO
}
