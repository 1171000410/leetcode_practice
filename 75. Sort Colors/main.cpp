//
//  main.cpp
//  75. Sort Colors
//
//  Created by 强文杰 on 2020/12/21.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // three pointers
        int low = 0, mid = 0, high = nums.size() -1;
        int temp = 0;
        while(mid <= high){
            if(nums[mid] == 1){
                mid ++;
            }else if (nums[mid] ==0){
                temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low ++;
                mid ++;
                
            }else{
                temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high --;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
