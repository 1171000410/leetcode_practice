//
//  main.cpp
//  2. Add Two Numbers
//
//  Created by 强文杰 on 2020/10/14.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode p_head(0), *p = &p_head;
        int sum = 0;
        while(l1 != NULL || l2 != NULL || sum !=0){
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(sum %10);
            cout << sum << '\n';
            sum /= 10;
            p = p->next;
        }
        
        return p_head.next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
