import os
import re
import subprocess
import time

def tag(sentence):
    with open('input', 'w') as input:
        input.write(sentence)
    call = "~/.cabal/bin/concraft-pl client < input"
    serverRunning = False
    while (not serverRunning):
        try:
            subprocess.check_call(call, shell=True)
            serverRunning = True
        except subprocess.CalledProcessError:
            time.sleep(5)
    os.remove('input')

def parse(concraftOutput):
    sentence = [line.split()[0] for line in concraftOutput if disambiguation(line)]
    return ''.join(sentence)

def disambiguation(line):
    return line.split()[-1] == 'disamb'

def start_concraft_server():
    call = "~/.cabal/bin/concraft-pl server ~/.cabal/bin/model.gz"
    server = subprocess.Popen(call, shell = True)
    return server
