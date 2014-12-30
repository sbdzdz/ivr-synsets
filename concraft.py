import re
import operator

def parse(path):
    for paragraph in readfile(path):
        sentence = []
        forms = {}
        for line in paragraph.splitlines():
            line = line.split()
            if new_word(line):
                sentence.append(disambiguate(forms))
                forms = {}
            if disambiguation(line):
                forms[line[0]] = float(line[2])
        else:
            sentence.append(disambiguate(forms))
        yield join(sentence)

def join(sentence):
    return ' '.join(filter(None, sentence))

def readfile(path):
    with open(path, 'r') as file:
        content = re.split('(\n){2,}', file.read())
    return content

def disambiguate(forms):
    return max(forms.keys(), key=(lambda key: forms[key])) if forms else None

def new_word(line):
    return len(line) == 2
    
def disambiguation(line):
    return len(line) == 3

for sentence in parse('out'):
    print (sentence)


