Synsets
===========

Requires Python 3.4, NLTK 3.0 and plWordNet 2.1.
###Installation
To install NLTK (assuming Python 3.4 is installed):
```
sudo apt-get install python3-pip
sudo easy_install3 pip
sudo pip3.4 install nltk
```
Polish Wordnet 2.1. is available [here](http://www.nlp.pwr.wroc.pl/plwordnet/download/plwordnet_2_1_0.zip). After downloading and unzipping, copy the files from `*.pwn_format` folder into `/usr/share/nltk_data/corpora/wordnet`.

###Functions
- To check whether a word exists in the Wordnet, use `is_known(word)`:
```Python
if is_known("spam"):
  print("Spam is a word!")
```
Note: this function actually returns a list of synsets for a given lemma. In Python, an empty list evaluates to `False`.
- To list all synonyms (in form of lemmas) for a certain word, use `get_synonyms(word)`:
```Python
if is_known("spam"):
  print(get_synonyms("spam"))
```
- To check whether two words appear together in any synset, use `are_synonyms(word1, word2)`:
```Python
are_synonyms("spam", "eggs")
```
- To list hyponyms, hypernyms etc. of a word, use `get_closure(word, relation, level)`:
```Python
rel = lambda s:s.hyponyms()
get_closure("spam", rel, 3)
```
Note: the function uses a breadth-first approach, maximum depth is set with the third argument. For a list of Synset methods, see NLTK [source](http://www.nltk.org/_modules/nltk/corpus/reader/wordnet.html) and [documentation.](http://www.nltk.org/api/nltk.corpus.reader.html#module-nltk.corpus.reader.wordnet)
Concraft
===========
Concraft-pl is a morphosyntactic tagger for Polish based on constrained conditional random fields. It combines the following components into a pipeline:

- Maca, a morphosyntactic segmentation and analysis tool
- Concraft, a morphosyntactic disambiguation library 

For more information, see [the project website](http://zil.ipipan.waw.pl/Concraft).
###Installing Maca
First, install necessary utils and libraries:
```
sudo apt-get install build-essential cmake bison flex python-dev swig git subversion
sudo apt-get install libicu-dev libboost-dev libloki-dev libxml++-dev libedit-dev libreadline-dev
```
Next, install Morfeusz SGJP. The package is available [here](https://launchpad.net/~bartosz-zaborowski/+archive/ubuntu/nlp/+files/morfeusz-sgjp_0.81-1_amd64.deb). Alternatively run:
```
sudo add-apt-repository ppa:bartosz-zaborowski/nlp
sudo apt-get update
sudo apt-get install morfeusz-sgjp
```
Install Stuttgart Finite State Tools:
```
sudo apt-get install sfst
```
Next, use git to clone Corpus2, Toki, and Maca repositories (this make take a few tries):
```
cd ~
git clone http://nlp.pwr.wroc.pl/corpus2.git
git clone http://nlp.pwr.wroc.pl/toki.git
git clone http://nlp.pwr.wroc.pl/maca.git
```
Install Corpus2:
```
mkdir corpus2/bin
cd corpus2/bin
cmake ..
make
sudo make install
```
Use the above procedure to install Maca and Toki.
Finally run:
```
sudo ldconfig
```
###Installing Concraft
First, obtain Haskell Platform:
```
sudo apt-get install haskell-platform
```
Next, use Cabal to install Concraft-pl:
```
cabal update 
cabal install concraft-pl
```
Finally, download a [pre-trained model](http://zil.ipipan.waw.pl/Concraft?action=AttachFile&do=get&target=nkjp-model-0.2.gz), rename it to `model.gz` (do not unzip it) and put into Concraft directory (default is `~/.cabal/bin`). You can now test the installation by running:
```
concraft-pl tag model.gz < input.txt > output.plain
```
For more information, see the [Github repo.](https://github.com/kawu/concraft-pl#concraft-pl)