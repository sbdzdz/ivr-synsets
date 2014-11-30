#ifndef WORDNET_READER_H
#define WORDNET_READER_H

#include <string>
#include <vector>

namespace Wordnet
{
  const char* MODULE_NAME = "wdnet";

  class Reader
  {
  private:
    PyObject * moduleName;
    PyObject* moduleObject;
    PyObject* isKnown;
  public:
    Reader();
    bool isKnown(std::string word);
    bool areSynonyms(std::string word, std::string otherWord);
    std::vector<std::string> getSynonymsOf(std::string word);
    std::vector<std::string> getHyponymsOf(std::string word, int level);
  };
}
#endif
