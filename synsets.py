#coding: utf-8
from nltk.corpus import wordnet as wn

def is_known(word):
  return wn.synsets(word)

def get_synonyms(word):
  synsets = wn.synsets(word)
  return set([l for s in synsets for l in s.lemma_names()])

def are_synonyms(word1, word2):
  return word2 in get_synonyms(word1)

def get_closure(word, relation, level):
  synsets = wn.synsets(word)
  return set([l for synset in synsets for s in synset.closure(relation, level) for l in s.lemma_names()])


word = "termin"
level = 3

print("Synonyms: ", ", ".join(get_synonyms(word)))
print ("Hyponyms: ", ", ".join(get_closure(word, lambda s:s.hyponyms(), level)))
print ("Hypernyms: ", ", ".join(get_closure(word, lambda s:s.hypernyms(), level)))

# synsets = wn.synsets("człowiek")
# for synset in synsets:
#   print ("-" * 10)
#   print ("Name:", synset.name())
#   print ("Lexical Type:", synset.lexname())
#   print ("Lemmas:", ", ".join(synset.lemma_names()))
#   print ("Attributes:", synset.attributes())
#   for example in synset.examples():
#     print ("Example:", example)