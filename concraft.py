import os
import re
import socket
import subprocess
import time
import wdnet

PATH_TO_CONCRAFT = '~/.cabal/bin'

def analyse(sentence, client):
    out = []
    for word in client.lemmatize(sentence):
        hyponyms = list(set(wdnet.get_hyponyms(word, 1)))
        synonyms = list(set(wdnet.get_synonyms(word)))
        out.append((word, hyponyms))
    return out

class Server:
    def __init__(self):
        self.port = self.find_free_port()
        self.call = self.generate_call()
        self.server = self.start_server()

    def __del__(self):
        self.server.terminate()

    def find_free_port(self):
        sock = socket.socket()
        sock.bind(('', 0))
        port = sock.getsockname()[1]
        return port

    def generate_call(self):
        call = "{0}/concraft-pl server {0}/model.gz --port {1}".format(PATH_TO_CONCRAFT, self.port)
        return call

    def start_server(self):
        server = subprocess.Popen(self.call, shell=True)
        return server
        
    def get_port(self):
        return self.port

class Client:
    def __init__(self, port):
        self.port = port
        self.call = self.generate_call()

    def lemmatize(self, sentence):
        self.write_to_file(sentence)
        serverRunning = False
        while (not serverRunning):
            try:
                concraftOutput = subprocess.check_output(self.call, shell=True)
                serverRunning = True
            except subprocess.CalledProcessError:
                time.sleep(10)
        return self.parse(concraftOutput.decode('utf-8'))

    def generate_call(self):
        call = "{0}/concraft-pl client --port {1} < input".format(PATH_TO_CONCRAFT, self.port)
        return call

    def write_to_file(self, sentence):
        with open('input', 'w') as input:
            input.write(sentence)

    def parse(self, concraftOutput):
        sentence = [line.split()[0] for line in concraftOutput.split("\n") if self.disambiguation(line)]
        return sentence

    def disambiguation(self, line):
        return line and line.split()[-1] == 'disamb'


    


