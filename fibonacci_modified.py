'''
A series is defined in the following manner:

Given the nth and (n+1)th terms, the (n+2)th can be computed by the following relation 
Tn+2 = (Tn+1)2 + Tn

So, if the first two terms of the series are 0 and 1: 
the third term = 12 + 0 = 1 
fourth term = 12 + 1 = 2 
fifth term = 22 + 1 = 5 
... And so on.

Given three integers A, B and N, such that the first two terms of the series (1st and 2nd terms) are A and B respectively, compute the Nth term of the series.

Input Format

You are given three space separated integers A, B and N on one line.

Input Constraints 
0 <= A,B <= 2 
3 <= N <= 20

Output Format

One integer. 
This integer is the Nth term of the given series when the first two terms are A and B respectively.

Note

Some output may even exceed the range of 64 bit integer.
'''

import sys
from math import pow

a,b,n = tuple(map(int, input().split()))

#print(a,b,n)

nums = []
nums.append(a)
nums.append(b)
n_2 = a
n_1 = b
res = 0
for x in range(2, n):
    res = n_1*n_1 + n_2
    n_2 = n_1
    n_1 = res
    
    
print(res)
