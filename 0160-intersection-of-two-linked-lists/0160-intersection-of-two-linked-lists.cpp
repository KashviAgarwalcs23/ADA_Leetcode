#include <iostream>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Calculate the lengths of both linked lists
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        // Align the starting points
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }
        
        // Traverse both lists together to find the intersection
        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) {
                return headA; // Intersection point
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr; // No intersection
    }
    
private:
    int getLength(ListNode *head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }
};
