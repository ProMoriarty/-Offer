//
// Created by ProMoriarty on 2017/9/8.
//
/**
 *  删除链表中的重复节点
 *  题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 */
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;

        ListNode* pPreNode = NULL;
        ListNode* pNode = pHead;
        while(pNode!=NULL){
            ListNode *pNext = pNode->next;
            bool needelete = false;
            if(pNext!=NULL && pNext->val==pNode->val){
                needelete = true;
            }
            if(!needelete){
                pPreNode = pNode;
                pNode = pNode->next;
            }else{
                int value = pNode->val;
                ListNode* pToBedelete = pNode;
                while(pToBedelete!=NULL && pToBedelete->val==value){
                    pNext = pToBedelete->next;
                    delete pToBedelete;
                    pToBedelete = NULL;
                    pToBedelete = pNext;
                }
                if(pPreNode==NULL){
                    pHead=pNext;
                }
                else{
                    pPreNode->next = pNext;
                }
                pNode = pNext;
            }
        }
        return pHead;
    }
};