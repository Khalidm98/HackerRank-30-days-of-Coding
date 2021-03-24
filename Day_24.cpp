#include <iostream>
using namespace std;	

class Node {
public:
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class Solution {
public:
    Node* removeDuplicates(Node *head){
        if (head == NULL)
        	return head;

        Node *ptr = head;
        unsigned short size = 0;
        while (ptr != NULL){
        	++size;
        	ptr = ptr->next;
        }

        for (int i = 0; i < size - 1; ++i){
        	Node *current = head;
        	for (int j = 0; j < i; ++j)
        		current = current->next;
        	Node *del = current->next;
        	ptr = current;

        	while (del != NULL){
        		if (del->data == current->data){
        			ptr->next = del->next;
        			delete del;
        			del = ptr->next;
        			--size;
        		}
        		else {
        			ptr = del;
        			del = del->next;
        		}
        	}
        }
        return head;
    }

    Node* insert(Node *head, int data){
        Node* p = new Node(data);
        if (head == NULL)
            head = p;
        
        else {
            Node *start = head;
            while (start->next != NULL){
                start = start->next;
            }
            start->next = p;
        }
        return head;
    }

    void display(Node *head){
        Node *start = head;
        while (start){
            cout << start->data << " ";
            start = start->next;
        }
    }

    void clear(Node *head){
		while (head != NULL){
			Node *ptr = head;
			head = head->next;
			delete ptr;
		}
	}
};
			
int main(){
	Node* head = NULL;
  	Solution mylist;
    int T,data;
    cin >> T;
    while(T--){
        cin >> data;
        head = mylist.insert(head,data);
    }	
    head = mylist.removeDuplicates(head);
	mylist.display(head);
	mylist.clear(head);
}
