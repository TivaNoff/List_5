#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        return;
    }

    ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;

    delete nextNode;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head1 = new ListNode(4);
    head1->next = new ListNode(5);
    head1->next->next = new ListNode(1);
    head1->next->next->next = new ListNode(9);

    ListNode* node1 = head1->next;
    std::cout << "Input 1: ";
    printList(head1);
    deleteNode(node1);
    std::cout << "Output 1: ";
    printList(head1);

    ListNode* head2 = new ListNode(4);
    head2->next = new ListNode(5);
    head2->next->next = new ListNode(1);
    head2->next->next->next = new ListNode(9);

    ListNode* node2 = head2->next->next;
    std::cout << "Input 2: ";
    printList(head2);
    deleteNode(node2);
    std::cout << "Output 2: ";
    printList(head2);

    return 0;
}
