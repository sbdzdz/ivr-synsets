#coding: utf-8
from nltk.corpus import wordnet as wn

def is_known(word):
  return bool(wn.synsets(word))

def get_synonyms(word):
  synsets = wn.synsets(word)
  return list([l for s in synsets for l in s.lemma_names()])

def are_synonyms(word1, word2):
  return word2 in get_synonyms(word1)

def get_closure(word, relation, level):
  synsets = wn.synsets(word)
  return set([l for synset in synsets for s in synset.closure(relation, level) for l in s.lemma_names()])  
