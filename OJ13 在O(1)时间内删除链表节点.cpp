//
// Created by ProMoriarty on 2017/8/18.
//
//O(1)时间删除链表节点


class Solution {
public:
    void DeleteNode(ListNode** pListNode,ListNode* pToBeDeleted){
        if(!pListNode || !pToBeDeleted){
            return;
        }
        if(pToBeDeleted->next!=NULL){
            ListNode* pNext = pToBeDeleted->next;
            pToBeDeleted->val = pNext->val;
            pToBeDeleted->next = pNext->next;
            delete pNext;
            pNext = NULL;
        }else if(*pListNode==pToBeDeleted){
            delete pToBeDeleted;
            pToBeDeleted = NULL;
            *pListNode=NULL;
        }else{
            ListNode* pNode = *pListNode;
            while(pNode->next!=pToBeDeleted){
                pNode = pNode->next;
            }
            pNode->next = NULL;
            delete pToBeDeleted;
            pToBeDeleted = NULL;
        }
    }
};