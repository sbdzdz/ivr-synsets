nimport concraft
import wdnet

def analyse(sentence, concraftClient):
    for word in concraftClient.lemmatize(sentence).split():
        print(word)
        hyponyms = wdnet.get_hyponyms(word, 2)
        for hyponym in set(hyponyms):
            print ("\t{0}".format(hyponym))

server = concraft.Server()
port = server.get_port()
client = concraft.Client(port)

sentence = input("Please wait for the server to load and then enter a sentence\n")
analyse(sentence, client)
while (True):
    sentence = input("Please enter another sentence or leave a blank line to exit:\n")
    if not sentence:
        break
    analyse(sentence, client)
