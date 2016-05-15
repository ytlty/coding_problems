w, n = tuple(map(int, input().split()))
coinValues = list(map(int, input().split()))
'''
define subproblem:
i = 0, ..., n
j = 0, ..., w
C[n, w] is min required
Base cases:
C[i, 0] = {0}
C[0, j] = INF
Recursive formula:
C[i, j] = 
    {
        case 1: we use C_i -> C[i, j-C_i]
        case 2: we don't use C_i -> C[i-1, j]
        if j >= C_i: min(C[i-1, j], C[i, j-Ci])
        if j < C_i: C[i-1, j]
    }
'''
# build the result array
pi = list([[float('inf')]*(w+1)])
for x in range(n):
    pi.append(list([0]+ [float('inf')]*(w)))

for i in range(1, n+1):
    for j in range(1, w+1):
        if j < coinValues[i-1]:
            pi[i][j] = pi[i-1][j]
        else:
            pi[i][j] = min(float(pi[i-1][j]), float(pi[i][j-coinValues[i-1]] + 1) )
print(int(pi[n][w]))
