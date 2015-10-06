# Python 2.7 and up

def solution(A):
    # write your code in Python 2.7
    S = [A[0]]
    C = [A[0]]
    # Since this is the DP solution, we define the subproblem as follows:
    # 0 <= i < n
    # S[i] = current optimum subarray ending at A[i]
    # C[i] = global optimum subarray ending at A[i]
    # Base cases:
    #   C[0] = A[0]
    #   S[0] = A[0]
    # Recursive formula:
    #   S[i] = max(S[i-1] + A[i], A[i])
    #   C[i] = max(C[i-1], max(A[i], C[i] + A[i]))
    for x in range(1, len(A)):
        S.append(max(A[x], S[x-1] + A[x]))
        C.append(max(C[x-1], S[x]))
    print(C)
    return C[len(C)-1]
    
    
print(solution([3, 2, 1, -5, 4]))
print(solution([-1, 1]))
