#coding: utf-8
from nltk.corpus import wordnet as wn

def is_known(word):
  return wn.synsets(word)

def get_synonyms(word):
  synsets = wn.synsets(word)
  synonyms = set([lemma for synset in synsets for lemma in synset.lemma_names()])
  return list(synonyms)

def are_synonyms(word, otherWord):
  return word in get_synonyms(otherWord)

def get_hyponyms(word, level):
  synsets = wn.synsets(word)
  relation = lambda s:s.hyponyms()
  hyponyms = set([lemma for synset in synsets for s in synset.closure(relation, level) for lemma in s.lemma_names()]) 
  return list(hyponyms)
