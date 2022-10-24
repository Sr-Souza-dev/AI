from itertools import count
import re

from numpy import append

class Tokenizer:

    def __init__(self, idx, tab, file):
        self.items = tab
        self.back = tab
        self.arq = file
        self.idx = idx
        self.valu = 0
    
    def equal(self, item):
        while(len(self.items[item.lower()]) < self.idx - 1):
            self.items[item.lower()].append(0);

    def _separate(self,word):
        for item in re.findall(r'([0-9]+.[0-9]|\w*|\W)',word):
            item = str(item)
            item = item.strip()     
            if(item != "" and len(item) >= 3) and len(item) <= 20:
                if self.items.get(item.lower()) != None and len(self.items.get(item.lower())) == self.idx:
                    self.equal(item)
                    self.items[item.lower()][self.idx - 1] = 1 + self.items[item.lower()][self.idx - 1]
                else:
                    if self.items.get(item.lower()) == None : 
                        self.items[item.lower()] = []
                    self.equal(item)
                    self.items[item.lower()].append(1)
    
    def tokenizer(self):
        try:
            for t in self.arq:
                self._separate(t)
            return self.items
        except:
            self.valu = 1
            return self.back