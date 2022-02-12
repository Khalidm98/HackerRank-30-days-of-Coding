#include <iostream>
#include <queue>

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

    void levelOrder(Node *root) {
        if (root == nullptr)
            return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
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
    int T, data;
    cin >> T;
    while (T--) {
        cin >> data;
        root = myTree.insert(root, data);
    }
    myTree.levelOrder(root);
    myTree.clear(root);
    return 0;
}
