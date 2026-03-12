#include <iostream>
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    int carry = 0;
    ListNode *head = new ListNode(0);
    ListNode *curr = head;

    while (l1 != NULL || l2 != NULL || carry)
    {
      int num = carry;

      if (l1)
      {
        num += l1->val;
        l1 = l1->next;
      }
      if (l2)
      {
        num += l2->val;
        l2 = l2->next;
      }

      carry = num / 10;
      num = num % 10;

      curr->next = new ListNode(num);
      curr = curr->next;
    }

    return head->next;
  }
};

int main()
{
  Solution s;
  ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  ListNode *result = s.addTwoNumbers(l1, l2);

  std::cout << "Result: ";
  while (result != NULL)
  {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << std::endl;

  return 0;
}