/*
Problem Statement

You are given an integer, N. Write a program to determine if N is an element of the Fibonacci sequence.

The first few elements of the Fibonacci sequence are 0,1,1,2,3,5,8,13,⋯. A Fibonacci sequence is one where every element is a sum of the previous two elements in the sequence. The first two elements are 0 and 1.

Formally: 
fib0fib1⋮fibn=0=1=fibn−1+fibn−2∀n>1
Input Format 
The first line contains T, number of test cases. 
T lines follow. Each line contains an integer N.

Output Format 
Display IsFibo if N is a Fibonacci number and IsNotFibo if it is not. The output for each test case should be displayed in a new line.

Constraints 
1≤T≤105 
1≤N≤1010
Sample Input

3
5
7
8
Sample Output

IsFibo
IsNotFibo
IsFibo
Explanation 
5 is a Fibonacci number given by fib5=3+2 
7 is not a Fibonacci number 
8 is a Fibonacci number given by fib6=5+3
*/

// Main note is the unsigned long long read
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<unsigned long long int> FibList;

void genFib() {
    unsigned long long int one = 1;
    unsigned long long int two = 1;
    unsigned long long int fib = 0;
    FibList.push_back(0);
    FibList.push_back(1);
    FibList.push_back(1);
    int x = 0;
    while (x < 51) {
        fib = (unsigned long long int) one + two;
        one = (unsigned long long int) two;
        two = (unsigned long long int) fib;
        FibList.push_back(fib);
        x++;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long long int tmp;
    vector<unsigned long long int> list;
    int size = 0;
    cin >> size;
    if (size == 0) {
        return 0;
    }
    while (size > 0) {
        cin >> tmp;
        list.push_back(tmp);
        size--;
    }
    genFib();
    for (int i = 0; i < list.size(); i++) {
        if (binary_search(FibList.begin(), FibList.end(), list[i])) {
            cout << "IsFibo" << endl;
        } else {
            cout << "IsNotFibo" << endl;
        }
    }
    return 0;
}
