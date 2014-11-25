#ifndef WORDNET_READER_H
#define WORDNET_READER_H
#include <string>
#include <vector>

namespace WordnetReader 
{
  const std::string MODULE_NAME = "wordnet"

  class Synset
  {
  private:
    string lemma;
  public:

    std::string getLemma(); 
    bool isSynonymOf(std::string word);
    std::vector<std::string> getSynonyms(std::string word);
    std::vector<std::string> getClosure(std::string word);
  }

}
#endif
