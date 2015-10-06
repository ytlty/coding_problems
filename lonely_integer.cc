#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int lonelyinteger(vector < int > a) {
    std::map<int, int> dict;
    for (int i = 0; i < a.size(); i++) {
        // if the value doesn't exist, we initialize it
        if (dict.find(a[i]) == dict.end()) {
            dict[a[i]] = 1;
        } else { // otherwise add 1 to its value
            dict.find(a[i])->second++;
        }
    }
    for (std::map<int,int>::iterator it=dict.begin(); it!=dict.end(); ++it) {
        if (it->second == 1) {
            return (it->first);
        }
    }
    return a.back(); // give up
}
int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}
