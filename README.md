Synsets
===========

Requires Python 3.4, NLTK 3.0 and plWordNet 2.1.

To install NLTK (assuming Python 3.4 is installed):
```
sudo apt-get install python3-pip
sudo easy_install3 pip
sudo pip3.4 install nltk
```
Polish Wordnet 2.1. is available [here](http://www.nlp.pwr.wroc.pl/plwordnet/download/plwordnet_2_1_0.zip). After downloading and unzipping, copy the files from `*.pwn_format` folder into `/usr/share/nltk_data/corpora/wordnet`.

###Functions
- To check whether a word exists in the Wordnet, use `is_known(word)`:
```
if is_known("spam"):
  print("Spam is a word!")
```
Note: this function actually returns a list of synsets for a given lemma. In Python, an empty list evaluates to `False`.
- To list all synonyms (in form of lemmas) for a certain word, use `get_synonyms(word)`:
```
if is_known("spam"):
  print(get_synonyms("spam"))
```
- To check whether two words appear together in any synset, use `are_synonyms(word1, word2)`:
```
are_synonyms("spam", "eggs")
```