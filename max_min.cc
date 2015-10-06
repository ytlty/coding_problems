/*
Problem Statement

Given a list of N integers, your task is to select K integers from the list such that its unfairness is minimized.

if (x1,x2,x3,…,xk) are K numbers selected from the list N, the unfairness is defined as

max(x1,x2,…,xk)−min(x1,x2,…,xk)
where max denotes the largest integer among the elements of K, and min denotes the smallest integer among the elements of K.

Input Format 
The first line contains an integer N. 
The second line contains an integer K. 
N lines follow. Each line contains an integer that belongs to the list N.

Note: Integers in the list N may not be unique.

Output Format 
An integer that denotes the minimum possible value of unfairness.

Constraints 
2≤N≤105 
2≤K≤N 
0≤integer in N ≤109
Sample Input #00
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// It is NOT mandatory to use the provided template. You can handle the IO section differently.

int main() {
    /* The code required to enter n,k, candies is provided*/

    int N, K, unfairness;
    int tmp;
    cin >> N >> K;
    vector<int> candies;
    for (int i=0; i<N; i++) {
        cin >> tmp; 
        candies.push_back(tmp);
    }
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    sort(candies.begin(), candies.end());
    unfairness = candies[N-1] - candies[0];
    for (int i = 0; i < N - K; i++) {
        int j  = K + i - 1;
        int tryUnfair = candies[j] - candies[i];
        if (tryUnfair < unfairness) {
            unfairness = tryUnfair;
        }
    }
    
    cout << unfairness << "\n";
    return 0;
}
