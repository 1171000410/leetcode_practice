//
//  main.cpp
//  5. Longest Palindromic Substring
//
//  Created by 强文杰 on 2020/10/15.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
        int max_len = 0;
        int start_idx = 0;
        int i = 0;
        while (i < s.size()) {
            int r_ptr = i;
            int l_ptr = i;
            while (r_ptr < s.size() -1 && s[r_ptr] == s[r_ptr+1]) { //skip duplicate character
                r_ptr ++;
            }
            i = r_ptr +1;
            
            while (r_ptr < s.size() -1 && l_ptr > 0 && s[r_ptr +1] == s[l_ptr -1]) {  //expand
                r_ptr ++;
                l_ptr --;
            }
            
            int new_len = r_ptr -l_ptr +1;
            if (new_len > max_len) {
                max_len = new_len;
                start_idx = l_ptr;
            }
            
        }
        
        return s.substr(start_idx,max_len);
                
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
