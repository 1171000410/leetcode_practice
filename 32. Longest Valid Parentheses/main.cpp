//
//  main.cpp
//  32. Longest Valid Parentheses
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
    int longestValidParentheses(string s) {
        // cleverly convert the character stack into a number stack
        // when calculating the length
        stack<int> st;
        st.push(-1);
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }else{
                st.pop();
                if (st.empty()) {
                    st.push(i);
                }else{
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }
        
        return maxlen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
