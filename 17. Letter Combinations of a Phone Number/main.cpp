//
//  main.cpp
//  17. Letter Combinations of a Phone Number
//
//  Created by 强文杰 on 2020/11/10.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> ret;
    unordered_map<string, string> digit2str = {{"2","abc"},{"3","def"},{"4","ghi"},{"5","jkl"},
        {"6","mno"}, {"7","pqrs"},{"8","tuv"},{"9","wxyz"}};
    
    vector<string> letterCombinations(string digits) {
        if (!digits.empty()) {
            backtrack("", digits);
        }
        return ret;
    }
    
    void backtrack(string temp, string digits){
        if (digits.empty()) {
            ret.push_back(temp);
        }else{
            string d = digits.substr(0,1);
            string d2str = digit2str[d];
            for (int i = 0; i < d2str.length(); i++) {
                backtrack(temp + d2str[i], digits.substr(1));
            }

        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string a = "23";
    s.letterCombinations(a);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
