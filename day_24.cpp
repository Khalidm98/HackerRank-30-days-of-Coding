#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Solution {
public:
    Node *removeDuplicates(Node *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node *curr = head;
        Node *prev = head;
        Node *ptr = head->next;
        while (curr->next != nullptr) {
            while (ptr != nullptr) {
                if (curr->data == ptr->data) {
                    Node *del = ptr;
                    ptr = ptr->next;
                    prev->next = ptr;
                    del->next = nullptr;
                    delete del;
                } else {
                    prev = ptr;
                    ptr = ptr->next;
                }
            }
            if (curr->next == nullptr)
                return head;
            curr = curr->next;
            prev = curr;
            ptr = curr->next;
        }
        return head;
    }

    // Another working solution
//    Node *removeDuplicates(Node *head) {
//        if (head == nullptr)
//            return head;
//
//        Node *ptr = head;
//        unsigned short size = 0;
//        while (ptr != nullptr) {
//            ++size;
//            ptr = ptr->next;
//        }
//
//        for (int i = 0; i < size - 1; ++i) {
//            Node *current = head;
//            for (int j = 0; j < i; ++j)
//                current = current->next;
//            Node *del = current->next;
//            ptr = current;
//
//            while (del != nullptr) {
//                if (del->data == current->data) {
//                    ptr->next = del->next;
//                    delete del;
//                    del = ptr->next;
//                    --size;
//                } else {
//                    ptr = del;
//                    del = del->next;
//                }
//            }
//        }
//        return head;
//    }

    Node *insert(Node *head, int data) {
        Node *p = new Node(data);
        if (head == nullptr)
            head = p;

        else {
            Node *start = head;
            while (start->next != nullptr) {
                start = start->next;
            }
            start->next = p;
        }
        return head;
    }

    void display(Node *head) {
        Node *start = head;
        while (start) {
            cout << start->data << " ";
            start = start->next;
        }
    }

    void clear(Node *head) {
        while (head != nullptr) {
            Node *ptr = head;
            head = head->next;
            delete ptr;
        }
    }
};

int main() {
    Node *head = nullptr;
    Solution my_list;
    int T, data;
    cin >> T;
    while (T--) {
        cin >> data;
        head = my_list.insert(head, data);
    }
    head = my_list.removeDuplicates(head);
    my_list.display(head);
    my_list.clear(head);
}
