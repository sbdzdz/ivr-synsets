#include <Python.h>
#include <iostream>
#include <string>

#include "wordnet_reader.h"
#include "wordnet_reader.cpp"

int main() 
{
  Py_Initialize();
  PyObject* sysPath = PySys_GetObject((char*)"path");
  PyObject* curDir = PyUnicode_FromString(".");
  // PyObject* curDir = PyString_FromString(".");
  PyList_Append(sysPath, curDir);
  Py_DECREF(curDir);

  std::string word;
  std::string otherWord;
  Wordnet::Reader wordnet = Wordnet::Reader();

  while (true) {
    std::cout<<"Podaj pierwsze słowo: \n";
    std::getline(std::cin, word);
    if (!wordnet.isKnown(word)) {
      std::cout<<word<<" is not in the dictionary!"<<std::endl;
      continue;
    }
    wordnet.getSynonymsOf(word);
    std::cout<<"Podaj drugie słowo: \n";
    std::getline(std::cin, otherWord);
    if (!wordnet.isKnown(otherWord)) {
      std::cout<<otherWord<<" is not in the dictionary!"<<std::endl;
      continue;
    }
    if (wordnet.areSynonyms(word, otherWord))
      std::cout<<"These words are synonyms."<<std::endl;
    else
      std::cout<<"These words are not synonymous"<<std::endl;
  }
  Py_Finalize();
  return 0;
}
