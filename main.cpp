#include <Python.h>
#include <iostream>
#include <string>

#include "wordnet_reader.h"
#include "wordnet_reader.cpp"

int main() {
  Py_Initialize();
  PyObject* sysPath = PySys_GetObject((char*)"path");
  PyObject* curDir = PyUnicode_FromString(".");
  PyList_Append(sysPath, curDir);
  Py_DECREF(curDir);
  
  std::string word;
  std::string anotherWord;
  Wordnet::Reader wordnet = Wordnet::Reader();
  std:: cout << "Podaj pierwsze słowo: \n";
  std::getline(std::cin, word);
  if (!wordnet.isKnown(word))
    std::cout<<"The word is not in the dictionary!"<<std::endl;
  std::cout << "Podaj drugie słowo: \n";
  std::getline(std::cin, anotherWord);
  if (!wordnet.isKnown(anotherWord))
    std::cout<<"The word is not in the dictionary!"<<std::endl;
  if (wordnet.areSynonyms(anotherWord))
    std::cout<<"These words are synonyms."<<std::endl;https://www.youtube.com/watch?v=rCRP-5om_3Y
  Py_Finalize();
  return 0;
}
