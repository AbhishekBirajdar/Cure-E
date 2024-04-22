#include "EVStationTree.h"

void EVStationTree::deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

EVStationTree::EVStationTree() : root(nullptr) {}

EVStationTree::~EVStationTree() {
    deleteTree(root);
}

void EVStationTree::insert(const Station& data) {
    TreeNode** cur = &root;
    while (*cur) {
        TreeNode*& node = *cur;
        if (data < node->data) {
            cur = &node->left;
        } else if (node->data < data) {
            cur = &node->right;
        } else {
            return; // Ignore duplicates or handle updates
        }
    }
    *cur = new TreeNode(data);
}

void EVStationTree::inOrderDisplay() const {
    inOrderDisplay(root);
}

void EVStationTree::inOrderDisplay(TreeNode* node) const {
    if (node) {
        inOrderDisplay(node->left);
        std::cout << "Station: " << node->data.name << ", Address: " << node->data.address
                  << ", City: " << node->data.city << ", State: " << node->data.state
                  << ", ZIP: " << node->data.zip << ", Fuel Type: " << node->data.fuelType << std::endl;
        inOrderDisplay(node->right);
    }
}
