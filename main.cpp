#include <Python.h>
#include <iostream>
#include <string>
#include "WordnetReader.h"
#include "WordnetReader.cpp"

int main() {
  Py_Initialize();
  PyObject* sysPath = PySys_GetObject((char*)"path");
  PyObject* curDir = PyUnicode_FromString(".");
  PyList_Append(sysPath, curDir);
  Py_DECREF(curDir);
  std::string word;
  std::string anotherWord;
  std:: cout << "Podaj pierwsze słowo: \n";
  std::getline(std::cin, word);
  WordnetReader::Synset synset = WordnetReader::Synset(word);
  std::cout << synset.getLemma() << std::endl;
  std::cout << "Podaj drugie słowo: \n";
  std::getline(std::cin, anotherWord);
  std::cout << synset.isSynonymOf(anotherWord);
  Py_Finalize();
  return 0;
}
