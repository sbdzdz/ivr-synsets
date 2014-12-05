#include <Python.h>
#include <iostream>
#include <string>

#include "wordnet_reader.h"
#include "wordnet_reader.cpp"

void printVector(std::vector<std::string> vec) {
    for(std::vector<std::string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
	std::cout<<*i<<" ";
    std::cout<<"\n";
}

int main() 
{
  Py_Initialize();
  PyObject* sysPath = PySys_GetObject((char*)"path");
  PyObject* curDir = PyUnicode_FromString(".");
  PyList_Append(sysPath, curDir);
  Py_DECREF(curDir);

  std::string word;
  std::string otherWord;
  int level = 3;
  Wordnet::Reader wordnet = Wordnet::Reader();

  std::vector<std::string> synonyms;
  std::vector<std::string> hyponyms;

  while (true) {
    std::cout<<"Enter a word (or type \"exit\" to leave)\n";
    std::getline(std::cin, word);
    if (word == "exit") {
	break;
    }
    if (!wordnet.isKnown(word)) {
      std::cout<<"Oops, "<<word<<" is not in the dictionary!"<<std::endl;
      continue;
    }
    synonyms = wordnet.getSynonymsOf(word);
    std::cout<<"Synonyms: \n";
    printVector(synonyms);
    hyponyms = wordnet.getHyponymsOf(word, level);
    std::cout<<"Hyponyms: \n";
    printVector(hyponyms);
    std::cout<<"Enter another word: \n";
    std::getline(std::cin, otherWord);
    if (!wordnet.isKnown(otherWord)) {
      std::cout<<"Oops, "<<otherWord<<"  is not in the dictionary!"<<std::endl;
      continue;
    }
    if (wordnet.areSynonyms(word, otherWord))
	std::cout<<"Yes, "<<word<<" and "<<otherWord<<" are synonyms.\n";
    else
	std::cout<<"No, "<<word<<" and "<<otherWord<<" are not synonyms.\n";
  }
  Py_Finalize();
  return 0;
}
