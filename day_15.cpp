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
    Node *insert(Node *head, int data) {
        Node *link = new Node(data);
        if (head == nullptr) return link;

        Node *ptr = head;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = link;
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
    my_list.display(head);
    my_list.clear(head);
}
