//
//  ListNode.h
//  LeetCode
//
//  Created by 强文杰 on 2020/11/11.
//  Copyright © 2020 强文杰. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif /* ListNode_h */
