//
//  main.cpp
//  48. Rotate Image
//
//  Created by 强文杰 on 2020/11/17.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <set>
#include <stack>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int len = 0;
    void rotate(vector<vector<int>>& matrix) {
        len = matrix[0].size();
        if (len == 1) {
            return;
        }
        int bias = 0;
        r(matrix, bias);
    }
    
    void r(vector<vector<int>>& matrix, int bias){
        if (bias == len/2) {
            return;
        }
        for (int i = 0; i < matrix[0].size() - 2*bias - 1; i++) {
            swap(matrix[i+bias][bias], matrix[len-1-bias][i+bias]);
            swap(matrix[i+bias][bias], matrix[len-1-bias-i][len-1-bias]);
            swap(matrix[i+bias][bias], matrix[bias][len-1-bias-i]);
        }
        r(matrix, bias+1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
