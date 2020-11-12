//
//  main.cpp
//  23. Merge k Sorted Lists
//
//  Created by 强文杰 on 2020/11/12.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <set>
#include <stack>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        if (lists.size() == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }
        
        vector<ListNode*> l;
        vector<ListNode*> r;
        for (int i = 0; i < (int)(lists.size()/2); i++) {
            l.push_back(lists[i]);
        }
        for (int i = (int)(lists.size()/2); i < lists.size(); i++) {
            r.push_back(lists[i]);
        }

        return mergeTwoLists(mergeKLists(l),mergeKLists(r));
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Remember this initialization method
        ListNode* l3 = new ListNode(0);
        ListNode*p = l3;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                l3->next = l2;
                l2 = l2->next;
            }else{
                l3->next = l1;
                l1 = l1->next;
            }
            l3 = l3->next;
        }
        
        if (l1) {
            l3->next = l1;
        }
        if (l2) {
            l3->next = l2;
        }
        return p->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
