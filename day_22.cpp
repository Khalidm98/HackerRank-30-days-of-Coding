#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    explicit Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

class Solution {
public:
    Node *insert(Node *root, int data) {
        if (root == nullptr)
            return new Node(data);

        Node *node;
        if (data <= root->data) {
            node = insert(root->left, data);
            root->left = node;
        } else {
            node = insert(root->right, data);
            root->right = node;
        }
        return root;
    }

    int getHeight(Node *root) {
        if (root == nullptr)
            return -1;

        int left_count = 0;
        int right_count = 0;
        if (root->left != nullptr)
            left_count += getHeight(root->left) + 1;
        if (root->right != nullptr)
            right_count += getHeight(root->right) + 1;
        return left_count > right_count ? left_count : right_count;
    }

    void clear(Node *root) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return;
        }

        if (root->left != nullptr)
            clear(root->left);
        if (root->right != nullptr)
            clear(root->right);
    }
};

int main() {
    Solution myTree;
    Node *root = nullptr;
    int t;
    int data;

    cin >> t;
    while (t--) {
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;
    myTree.clear(root);
    return 0;
}
