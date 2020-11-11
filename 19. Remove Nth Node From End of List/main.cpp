//
//  main.cpp
//  19. Remove Nth Node From End of List
//
//  Created by 强文杰 on 2020/11/11.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 1;
        ListNode *p = head;
        while (p->next != nullptr) {
            len ++;
            p = p->next;
        }
            
        int pos = len - n + 1;
        
        if (pos == 1) {
            return head->next;
        }
        ListNode *pre = head;

        while (pos > 2) {
            pre = pre->next;
            pos --;
        }
        if (pre->next->next == nullptr) {
            pre->next = nullptr;
            return head;
        }else{
            ListNode *post =pre->next->next;
            pre->next = post;
            return head;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
