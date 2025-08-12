// 2. Add_Two_Numbers
// ListNode solution
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){} //預設
    ListNode(int x):val(x),next(nullptr){} //單參數
    ListNode(int x, ListNode* next):val(x),next(next){} //雙參數
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            ListNode dummy; //假頭節點(方便處理)
            ListNode* cur = &dummy;
            int count = 0;

            while(l1 != nullptr || l2 != nullptr || count){ //進位判斷
                int x = (l1 != nullptr)? l1 -> val:0;
                int y = (l2 != nullptr)? l2 -> val:0;

                int sum = x + y + count;
                count = sum/10;
                cur -> next = new ListNode(sum%10);
                cur = cur -> next;

                if(l1 != nullptr) l1 = l1 -> next;
                if(l2 != nullptr) l2 = l2 -> next;
            }
            return dummy.next;
        }
};
// 2. Add_Two_Numbers
// vector solution
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> Add_Two_Nums (vector<int> & l1 , vector<int> & l2){
            vector<int> Ans;
            if(l1.size() > l2.size()){
                l2.insert(l2.end(), l1.size()-l2.size(), 0);
                Ans.resize(l1.size());
            }else if(l2.size() > l1.size()){
                l1.insert(l1.end(), l2.size()-l1.size(), 0);
                Ans.resize(l2.size());
            }else{
                Ans.resize(l1.size());
            }

            int count = 0;

            for(int i = 0; i<l1.size(); i++){
                Ans[i] = l1[i] + l2[i] + count;
                count = 0;
                if(Ans[i] >= 10){
                    Ans[i] = Ans[i]-10;
                    count++;
                } 
                
            }
            if(count == 1){
                Ans.push_back(1);
            }

            return Ans;
        }
};

int main() {
    Solution sol;

    // 測試案例 1
    vector<int> l1 = {2, 4, 3}; // 表示 342
    vector<int> l2 = {5, 6, 4}; // 表示 465
    vector<int> result = sol.Add_Two_Nums(l1, l2); // 預期 {7, 0, 8} → 807

    cout << "Test case 1: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    // 測試案例 2（有進位到新的位數）
    vector<int> l3 = {9, 9, 9}; // 表示 999
    vector<int> l4 = {1};       // 表示 1
    result = sol.Add_Two_Nums(l3, l4); // 預期 {0, 0, 0, 1} → 1000

    cout << "Test case 2: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}

*/