/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }

        Node* curr = root;  // Current level pointer
        Node* dummy = new Node(0);  // Dummy node to start the next level
        Node* tail = dummy;  // Tail pointer for linking nodes at the next level

        while (curr) {
            // Process the current level
            if (curr->left) {
                tail->next = curr->left;
                tail = tail->next;
            }
            if (curr->right) {
                tail->next = curr->right;
                tail = tail->next;
            }

            // Move to the next node in the current level
            curr = curr->next;

            // If end of the current level, move to the next level
            if (!curr) {
                curr = dummy->next;
                dummy->next = nullptr;  // Reset dummy for the next level
                tail = dummy;  // Reset tail for the next level
            }
        }

        delete dummy;  // Clean up the dummy node
        return root;
    }
};
