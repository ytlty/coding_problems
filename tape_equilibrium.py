# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(A):
    sumsofar = sum(A[1:])
    cursum = A[0]
    min = abs(sumsofar - cursum)
    for item in A[1:len(A)-1]:
        cursum = cursum + item
        sumsofar = sumsofar - item
        diff = abs(sumsofar - cursum)
        if diff < min:
            min = diff
    return min
