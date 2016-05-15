'''
Given an array  of  elements, find the maximum possible sum of a

Contiguous subarray
Non-contiguous (not necessarily contiguous) subarray.
Empty subarrays/subsequences should not be considered.

Input Format

First line of the input has an integer .  cases follow. 
Each test case begins with an integer . In the next line,  integers follow representing the elements of array .

Constraints:

The subarray and subsequences you consider should have at least one element.

Output Format

Two, space separated, integers denoting the maximum contiguous and non-contiguous subarray. At least one integer should be selected and put into the subarrays (this may be required in cases where all elements are negative).
'''

def findSum(l):
    ma = l[0]
    maxSoFar = l[0]
    for x in range(1, len(l)):
        maxSoFar = max(maxSoFar + l[x], l[x])
        ma = max(maxSoFar, ma)
    return ma

def findPosSum(l):
    pos = False
    su = 0
    for item in l:
        if item > 0:
            pos = True
            su += item
    if not pos:
        return max(l)
    return su

numOfArrays = int(input())
arrays = []
for x in range(numOfArrays):
    size = int(input())
    l = list(map(int, input().split()))
    maxSum = findSum(l)
    posSum = findPosSum(l)
    print(maxSum, posSum)
