#https://gist.github.com/mikesea/8158912ba07cba930329

import time

class KVstore(object):
    
    
    def __init__(self):
        self.kvdict = {}
        
    
    def set(self, k, v):
        timestamp = int(time.time())
        
        if not k in self.kvdict:
            self.kvdict[k] = [[v, timestamp]]
        else:
            self.kvdict[k].append([v, timestamp])
        
    def get(self, k, t=None):
        vals = self.kvdict[k]
        
        if not t:
            return vals[-1]
        else:
            t = int(t)
            for elm in vals:
                if elm[1] == t:
                    return elm[0]
                else:
                    return None
                


myDict = KVstore()
myDict.set('foo', 'bar')
now = time.time()
time.sleep(1)
myDict.set('foo', 'baz')
myDict.set('yo', 'hi')
myDict.set('yo', 'hi')
myDict.set('what', 'is this')
print myDict.get('yo')
print myDict.get('foo', now)
print myDict.get("whoops")