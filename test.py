from wdnet import *

word = "lekarz"
level = 3

synsets = wn.synsets(word)
for synset in synsets:
  print ("-" * 10)
  print ("Name:", synset.name())
  print ("Lexical Type:", synset.lexname())
  print ("Lemmas:", ", ".join(synset.lemma_names()))
  print ("Attributes:", synset.attributes())
  print ("Definition:", synset.definition())
  for example in synset.examples():
    print ("Example:", example)
print ("-" * 10)
print("Synonyms: ", ", ".join(get_synonyms(word)))
print ("-" * 10)
print ("Hyponyms: ", ", ".join(get_closure(word, lambda s:s.hyponyms(), level)))
print ("-" * 10)
print ("Hypernyms: ", ", ".join(get_closure(word, lambda s:s.hypernyms(), level)))