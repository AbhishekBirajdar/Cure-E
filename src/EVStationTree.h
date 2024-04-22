#ifndef EVSTATIONTREE_H
#define EVSTATIONTREE_H

#include "StationData.h"
#include <iostream>

struct TreeNode {
    Station data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const Station& newData) : data(newData), left(nullptr), right(nullptr) {}
};

class EVStationTree {
public:
    EVStationTree();
    ~EVStationTree();
    void insert(const Station& data);
    void inOrderDisplay() const;

private:
    TreeNode* root;
    void deleteTree(TreeNode* node);
    void inOrderDisplay(TreeNode* node) const;
};

#endif // EVSTATIONTREE_H
