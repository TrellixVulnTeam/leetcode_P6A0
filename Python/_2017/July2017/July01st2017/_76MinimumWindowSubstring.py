import collections
class Solution(object):
        
    def minWindow(self, s, t):
        collection = collections.Counter(t)
        need = len(t)
        tmp = 0
        start = 0
        end = 0
        for i in range(len(s)):
            if collection[s[i]] > 0:
                need -=1
            collection[s[i]] -=1
            if not need:
                while tmp <=i and collection[s[tmp]] < 0:
                    collection[s[tmp]]+=1
                    tmp+=1
                if not end or end - start > i+1 - tmp:
                    end = i+1
                    start = tmp
                
        return s[start:end]