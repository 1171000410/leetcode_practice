//
//  main.cpp
//  4. Median of Two Sorted Arrays
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // when we find mid1, we also find mid2
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = len1*2;
        int mid1 = 0, mid2 = 0;
        int l1, l2, r1, r2 = 0;
        while(low <= high) {
            mid1 = (low + high) >> 1;
            mid2 = len1 + len2 - mid1;
            l1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            r1 = (mid1 == 2*len1) ? INT_MAX : nums1[mid1/2];
            l2 = (mid2 == 0)? INT_MIN : nums2[(mid2-1)/2];
            r2 = (mid2 == 2*len2) ? INT_MAX : nums2[mid2/2];
            if(l1 > r2)
                high = mid1 - 1;
            else if (l2 > r1)
                low = mid1 + 1;
            else
                break;
        }
        return (double) (max(l1,l2) + min(r1, r2)) / 2;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
