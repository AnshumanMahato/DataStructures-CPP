#include<math.h>
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
        int num1,num2;
        ListNode *itr,*res,*temp;

        itr = l1;

        while(itr)
        {
            int i = 0;
            num1 = num1*pow(10,i++) + itr->val;
            itr = itr->next;
        }

        itr = l2;

         while(itr)
        {
            int i = 0;
            num2 = num2*pow(10,i++) + itr->val;
            itr = itr->next;
        }

        num1 += num2;

        while(num1)
        {
            temp = new ListNode(num1%10);
            if(!res)
            {
                 res=temp;
                 itr=res;
            }
            else
            {
                itr->next = temp;
                itr = temp;
            }

            num1 /= 10; 
        }
        
        return res;
    }
};