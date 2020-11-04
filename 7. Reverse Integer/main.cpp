//
//  main.cpp
//  7. Reverse Integer
//
//  Created by 强文杰 on 2020/11/4.
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
    int reverse(int x) {
        int ans = 0;
        
        if (x == 0) {
            return 0;
        }
        while (x % 10 == 0) {
            x = x/10;
        }
        while (x != 0) {
            if(ans > INT_MAX/10 || ans < INT_MIN /10)
                return 0;
            ans *= 10;
            ans += x%10;
            x /= 10;
        }
        
        
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
