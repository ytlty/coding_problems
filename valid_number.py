'''
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
'''
class Solution(object):
    def isnumeric(self, n):
        return n.isdigit()
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # deal with spaces
        i = 0
        for x in xrange(0, len(s)):
            if s[x] != " ":
                i = x
                break;
        s = s[i:len(s)]
        i = 0
        for x in xrange(len(s), 0, -1):
            if s[x-1] != " ":
                i = x
                break;
        s = s[0:i]
        if len(s) == 0:
            return False
        if s[0] == "-" or s[0] == "+":
            s = s[1:len(s)]
        if "e" in s:
            index = s.find("e")
            s2 = s[index+1:len(s)]
            print(s2)
            s = s[0:index]
            print(s)
            if len(s2) == 0 or len(s) == 0:
                return False
            if len(s2) > 1 and (s2[0] == "+" or s2[0] == "-"):
                s2 = s2[1:len(s2)]
            if "e" in s or not self.isnumeric(s2):
                return False
        # deal with floats
        if "." in s:
            index = s.find(".")
            left = s[0:index]
            right = s[index+1:len(s)]
            #print(left)
            #print(right)
            if "." in left or "." in right:
                return False
            if len(left) == 0 and len(right) == 0:
                return False

            if len(left) == 0 :
                return self.isnumeric(right)
            if len(right) == 0:
                return self.isnumeric(left)
            return (self.isnumeric(left) and self.isnumeric(right))
        else:
            return self.isnumeric(s)
            
                    
        
