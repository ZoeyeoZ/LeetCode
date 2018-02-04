// Add Two Numbers

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l = new ListNode(0), *h = l;
        int sum = 0;
        while (l1 || l2 || sum){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + sum;
            l1 = (l1 ? l1->next : l1);
            l2 = (l2 ? l2->next : l2);
            h->next = new ListNode(sum % 10);
            h = h->next;
            sum = sum / 10;
        }
        return l->next;
    }
    /*
    list<int> addTwoNumbers(list<int> l1, list<int> l2){
        list<int> ans;
        list<int>::iterator h1 = l1.begin();
        list<int>::iterator h2 = l2.begin(); 
        while ((h1 != l1.end()) && (h2 != l2.end()) ){
            ans.push_back((*h1+*h2)%10);
            ++ h1;
            ++ h2;
        }
        while (h1 != l1.end()){
            ans.push_back(*h1);
            ++ h1;
        }
        while (h2 != l2.end()){
            ans.push_back(*h2);
            ++ h2;
        }
        return ans;   
    }
    mei jin wei
    */
};

