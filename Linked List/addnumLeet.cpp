#include<bits/stdc++.h>
#include<math.h>
 class ListNode
  {
    public:
     int val;
     ListNode *next;
     ListNode(){
          val = 0; 
          next = nullptr;
          }
     ListNode(int x){
         val = x; 
         next = nullptr;
     }
     ListNode(int x, ListNode *next){
         val = x; 
         next = next;
     }
 };
    
    int getNum(ListNode *num){
        ListNode *itr = num;
        int n = 0;
        int multipler = 1;
        while(itr)
        {
            n += itr->val * multipler;
            multipler *= 10;
            itr= itr->next;
        }

        return n;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1,num2;
        ListNode *itr,*res,*temp;

        num1 = getNum(l1);
        
        return res;
    }

    ListNode* num3dig(int ones,int tens,int hunds) {
        ListNode *l = new ListNode(ones);
        l->next = new ListNode(tens);
        l->next->next = new ListNode(hunds);

        return l;
    }

    int main()
    {
        ListNode *l1 = num3dig(2,4,3),
                 *l2 = num3dig(5,6,4); 
        
        ListNode *l3 = addTwoNumbers(l1,l2);

        std::cout<<getNum(l1)<<' '<<getNum(l2);

        for (ListNode *itr = l3; itr != nullptr; itr = itr->next)
        {   
            std::cout<<itr->val;
        }
        

        return 0;
    }
    