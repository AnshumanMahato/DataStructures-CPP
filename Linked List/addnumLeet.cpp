#include<bits/stdc++.h>
#include<stdarg.h>
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
        long long n = 0;
        long long multipler = 1;
        while(itr)
        {
            n += itr->val * multipler;
            multipler *= 10;
            itr= itr->next;
        }

        return n;
    }

    ListNode* addTwoNumbers(ListNode* n1, ListNode* n2) {
        long long num;
        ListNode *itr,*res,*temp;

        num = getNum(n1) + getNum(n2);

        res = new ListNode(num%10);
        itr = res;
        num /= 10;

        while (num)
        {
            temp = new ListNode(num%10);
            itr->next = temp;
            itr = temp;
            num /= 10;
        }
        
        
        return res;
    }

    ListNode* numToList(int digits, ...) {

        va_list args;
        va_start(args,digits);

        int i = 1;
        ListNode *list = new ListNode(va_arg(args,int));
        ListNode *itr =  list;

        while (i < digits)
        {
            ListNode *temp = new ListNode(va_arg(args,int));
            itr->next = temp;
            itr = temp;
            i++;
        }

        va_end(args);
        return list;
    }

    // Test for this input 
    // [9]
    // [1,9,9,9,9,9,9,9,9,9]

    int main()
    {
        ListNode *l1 = numToList(1,9),
                 *l2 = numToList(10,1,9,9,9,9,9,9,9,9,9); 
        
        ListNode *l3 = addTwoNumbers(l1,l2);

        std::cout<<getNum(l1)<<' '<<getNum(l2)<<' '<<getNum(l3);
        

        return 0;
    }
    