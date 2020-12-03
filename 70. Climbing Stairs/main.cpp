//
//  main.cpp
//  70. Climbing Stairs
//
//  Created by 强文杰 on 2020/12/3.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
     // dp
     vector<int> steps(n,0);
     steps[0]=1;
     steps[1]=2;
     for(int i=2;i<n;i++){
         steps[i]=steps[i-2]+steps[i-1];
     }
     return steps[n-1];
 }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
