#include <cstdint>
#include <iostream>
#include <random>

struct Node {
    Node* left;
    Node* right;
    uint32_t data;
    Node(uint32_t m_data) : data(m_data) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    Node* add(Node* parent, uint32_t data) {
        if (parent == nullptr) {
            std::cout << "Alloc " << sizeof(Node) << " bytes\n";
            return new Node(data);
        }
        if (data < parent->data) {
            parent->left = add(parent->left, data);
        }else {
            parent->right = add(parent->right, data);
        }
        return parent;
    }

    void add(uint32_t data) {
        if (root == nullptr) {
            root = add(root, data);
        }else {
            add(root, data);
        }
    }

    void inOrder(Node* node) {
        if (node == nullptr)
            return;
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }

    void inOrder() {
        inOrder(root);
    }

    void preOrder(Node* node) {
        if (node == nullptr)
            return;
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void preOrder() {
        preOrder(root);
    }

    void postOrder(Node* node) {
        if (node == nullptr)
            return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }

    void postOrder() {
        postOrder(root);
    }
};

int main() {
    BinaryTree tree = BinaryTree();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 200); // random number between 1 and 100

    for (int i = 0; i < 10; i++) {
        int randomNumber = distrib(gen);
        tree.add(randomNumber);
    }

    tree.inOrder();
    std::cout << "\n";
    tree.preOrder();
    std::cout << "\n";
    tree.postOrder();
    std::cout << "\n";

    std::cout << "Binary Tree size: " << sizeof(tree) << "\n";
}
