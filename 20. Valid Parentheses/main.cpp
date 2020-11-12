//
//  main.cpp
//  20. Valid Parentheses
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
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> lr = {{'}','{'},{']','['},{')','('}};
        for (int i = 0; i < s.length(); i++) {
            auto it = lr.find(s[i]);
            if (it != lr.end()) {
                if (!st.empty() && lr[s[i]] == st.top()) {
                    st.pop();
                }else{
                    return false;
                }
            }else{
                st.push(s[i]);
            }
        }
        
        if (st.empty()) {
            return true;
        }else{
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
