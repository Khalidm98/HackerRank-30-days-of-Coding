#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
	Node* insert(Node *root, int data){
        if (root == NULL)
            return new Node(data);
        
        Node *cur;
        if (data <= root->data){
            cur = insert(root->left, data);
            root->left = cur;
        }
        else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }

    int getHeight(Node* root){
        if (root->left == NULL && root->right == NULL)
            return 0;

        int left_count = 0;
        int right_count = 0;
        if (root->left != NULL)
            left_count += getHeight(root->left) + 1;
        if (root->right != NULL)
            right_count += getHeight(root->right) + 1;
        return (left_count > right_count ? left_count : right_count);
    }

    void clear(Node* root){
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL){
            delete root;
            return;
        }

        if (root->left != NULL)
            clear(root->left);
        if (root->right != NULL)
            clear(root->right);
    }
};

int main(){
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;
    while(t--){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;
    myTree.clear(root);
    return 0;
}
