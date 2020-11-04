//
//  main.cpp
//  6. ZigZag Conversion
//
//  Created by 强文杰 on 2020/10/29.
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
    string convert(string s, int numRows) {
        const int len = (int)s.length();
        string *str = new string[numRows];
        
        int row = 0,step = 1;
        for (int i =0 ; i<len; i++) {
            str[row].push_back(s[i]);
            
            if (row == 0) {
                // 往下
                step = 1;
            }else if(row == numRows -1){
                // 往上
                step = -1;
            }
            row += step;
        }
        string a = "";
        for (int i = 0; i <numRows; i++) {
            a.append(str[i]);
        }
        return  a;   
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
