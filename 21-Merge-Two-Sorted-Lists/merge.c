/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* CreateNode(int val){
    struct ListNode * newNode = calloc(1,sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode * result = CreateNode(0); 
    struct ListNode * backup = result;
    
    if (list1 == NULL && list2 == NULL){
        return list1;
    } else if (list1 || list2){
        while (list1 || list2){
            if (list1 == NULL){
                result->val = list2->val;
                if (list2->next != NULL){
                    result->next = CreateNode(0);
                    result = result->next;
                } else {
                    break;
                }
                list2 = list2->next;
            } else if (list2 == NULL){
                result->val = list1->val;
                if (list1->next != NULL){
                    result->next = CreateNode(0);
                    result = result->next;
                } else {
                    break;
                }
                list1 = list1->next;
            } else if (list1->val > list2->val){
                result->val = list2->val;
                result->next = CreateNode(0);
                result = result->next;
                list2 = list2->next;
            } else {
                result->val = list1->val;
                result->next = CreateNode(0);
                result = result->next;
                list1 = list1->next;
            }
        }
    } 
    return backup;
}
