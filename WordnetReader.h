#ifndef WORDNET_READER_H
#define WORDNET_READER_H
#include <string>
#include <vector>

namespace WordnetReader 
{
  const char* MODULE_NAME = "wdnet";

  class Synset
  {
  private:
    std::string lemma;
    PyObject * moduleName;
    PyObject* wordnetModule;
  public:
    Synset(std::string word);
    std::string getLemma(); 
    bool isSynonymOf(WordnetReader::Synset word);
    std::vector<std::string> getSynonyms();
    std::vector<std::string> getClosure(std::string relation, int level);
  };

}
#endif
