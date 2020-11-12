//
//  main.cpp
//  22. Generate Parentheses
//
//  Created by 强文杰 on 2020/11/12.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> ans;
    int N = 0;
    vector<string> generateParenthesis(int n) {
        N = n;
        backtrack("", 0, n);
        return ans;
    }
    
    void backtrack(string s, int l , int r){
        if (r == N) {
            ans.push_back(s);
        }
        if (l < N) { // add left
            backtrack(s+'(', l+1, r);
        }
        if (l > r){ // balance right
            backtrack(s+')', l, r+1);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
