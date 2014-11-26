#include <Python.h>
#include <string>
#include <vector>
#include "WordnetReader.h"

WordnetReader::Synset::Synset(std:: string word) {
  lemma = word;
  moduleName = PyUnicode_FromString(WordnetReader::MODULE_NAME);
  wordnetModule = PyImport_Import(moduleName);
  Py_DECREF(moduleName);
  if (!wordnetModule)
  {
    PyErr_Print();
  }
}

std::string WordnetReader::Synset::getLemma() {
  return lemma;
}

bool WordnetReader::Synset::isSynonymOf(WordnetReader::Synset otherWord) {
  std::string otherLemma = otherWord.getLemma();
  PyObject* isSynonymOf = PyObject_GetAttrString(wordnetModule, "are_synonyms");
  Py_DECREF(wordnetModule);
  PyObject* args = Py_BuildValue("ss", lemma.c_str(), otherLemma.c_str());
  PyObject* resultObj = PyObject_CallObject(isSynonymOf, args);
  Py_DECREF(isSynonymOf);
  Py_DECREF(args);
  const bool result = PyObject_IsTrue(resultObj);
  Py_DECREF(resultObj);
  return result;
}

std::vector<std::string> WordnetReader::Synset::getSynonyms() {
  //TODO
}

std::vector<std::string> WordnetReader::Synset::getClosure(std::string relation, int level) {
  //TODO
}
