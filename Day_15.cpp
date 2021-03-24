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
	Node* insert(Node *head, int data){
		Node *link = new Node(data);
		if (head == NULL){
			head = link;
			return head;
		}
		
		Node *ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = link;
		return head;
	}

	void display(Node *head){
		Node *start = head;
		while(start){
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
	Node *head = NULL;
  	Solution mylist;
    int T, data;
    cin >> T;
    while(T--){
        cin >> data;
        head = mylist.insert(head,data);
    }	
	mylist.display(head);
	mylist.clear(head);
}
