#include <Python.h>
#include <string>
#include <vector>

#include "wordnet_reader.h"

Wordnet::Reader::Reader() {
  moduleName = PyUnicode_FromString(Wordnet::MODULE_NAME);
  moduleObject = PyImport_Import(moduleName);
  PyObject* isKnown = PyObject_GetAttrString(moduleObject, "is_known");
  Py_DECREF(moduleName);
  Py_DECREF(moduleName);
}

bool Wordnet::Reader::isKnown(std::string word) {

  PyObject* args = Py_BuildValue("(s)", word.c_str());
  if(!args)
  {
    PyErr_Print();
    std::cout<<"Error building args tuple";
    return false;
  }
  PyObject* resultObj = PyObject_CallObject(isKnown, args);
  Py_DECREF(isKnown);
  Py_DECREF(args);
  if(!resultObj)
  {
      PyErr_Print();
      return false;
  }
  const bool resultBool = PyObject_IsTrue(resultObj);
  if (!resultBool)
  {
      PyErr_Print();
      return false;
  }
  const bool result = PyObject_IsTrue(resultObj);
  Py_DECREF(resultObj);
  return result;
}

bool Wordnet::Reader::areSynonyms(std::string word, std::string otherWord) {
  PyObject* areSynonyms = PyObject_GetAttrString(moduleObject, "are_synonyms");
  Py_DECREF(moduleObject);
  PyObject* args = Py_BuildValue("ss", word.c_str(), otherWord.c_str());
  PyObject* resultObj = PyObject_CallObject(areSynonyms, args);
  Py_DECREF(areSynonyms);
  Py_DECREF(args);
  const bool result = PyObject_IsTrue(resultObj);
  Py_DECREF(resultObj);
  return result;
}

std::vector<std::string> Wordnet::Reader::getSynonymsOf(std::string word) {
  //TODO
}

std::vector<std::string> Wordnet::Reader::getHyponymsOf(std::string word, int level) {
  //TODO
}
