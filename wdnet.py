#coding: utf-8
from nltk.corpus import wordnet as wn

def is_known(word):
  return wn.synsets(word)

def get_synonyms(word):
  synsets = wn.synsets(word)
  synonyms = [l for s in synsets for l in s.lemma_names()]
  return list(synonyms)

def are_synonyms(word1, word2):
  return word2 in get_synonyms(word1)

def get_hyponyms(word, level):
  synsets = wn.synsets(word)
  closure = [synset.closure(lambda s:s.hyponyms(), level) for synset in synsets]
  hyponyms = set([lemma for lemma in synset.lemma_names() for synset in closure])
  return list(hyponyms)
