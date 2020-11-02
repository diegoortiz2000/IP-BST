//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460, Luis Armando Salazar A01114901
// November 01 2020
//

#ifndef INC_1_3_MYBST_H
#define INC_1_3_MYBST_H

#include <iostream>
#include <utility>

using namespace std;

struct MyNodeBST {
    int data;
    string ip;
    MyNodeBST *left, *right;

    explicit MyNodeBST(int data, string ip) {
        this->data = data;
        this->ip = std::move(ip);
        this->left = this->right = nullptr;
    }
};

class MyBST {
private:
    // Number of elements in the BST
    int size;

    // Pointer to the root of BST
    MyNodeBST *root;

    /// @brief This method searches an integer inside a BST.
    /// @param data Integer to search in the BST.
    /// @param current Current node.
    /// @return True if data is found false if not.
    // Time complexity: O(n)
    bool search(int data, MyNodeBST *current);

    /// @brief This method removes a node with the specified value from a BST.
    /// @param node Start node.
    /// @param data Value to be deleted.
    /// @param data Reference to a boolean to determine it the values was deleted.
    /// @return The start node.
    // Time complexity: O(n)
    MyNodeBST *remove(MyNodeBST *node, int data, bool &success);

    /// @brief This method iterate postorder a BST.
    /// @param current Current node.
    // Time complexity: O(n)
    void postorder(MyNodeBST *current);

    /// @brief This method iterate in preorder a BST.
    /// @param current Current node.
    // Time complexity: O(n)
    void preorder(MyNodeBST *current);

    /// @brief This method iterate reverseInorder a BST.
    /// @param current Current node.
    // Time complexity: O(n)
    void reverseInorder(MyNodeBST *current, int &count);

    /// @brief This method iterate a BST to get the node with minimum value.
    /// @param node Start node.
    /// @return The node with the minimum value.
    // Time complexity: O(n)
    static MyNodeBST *minValueNode(MyNodeBST *node);

    /// @brief This method calculates the height of a BST.
    /// @param node Start node.
    /// @return The Height of the BST.
    // Time complexity: O(n)
    int height(MyNodeBST *node);

    /// @brief This method gets the ancestors of the node that matches the number.
    /// @param node Start node.
    /// @param data Value to calculate the ancestors of the node.
    /// @param output Reference to store the data of the ancestor nodes.
    /// @return True if the value is found False if its not.
    // Time complexity: O(n)
    bool ancestors(MyNodeBST *node, int data, string &output);

    /// @brief This method gets the level of the node that matches the data.
    /// @param node Start node.
    /// @param data Value to calculate the level of it's corresponding node.
    /// @param level Current level to iterate.
    /// @return -1 if the value was not found and the corresponding level if the value is found.
    // Time complexity: O(n)
    int whatLevelAmI(MyNodeBST *node, int data, int level);

public:
    /// @brief Default constructor.
    // Time complexity: O(1)
    MyBST();

    /// @brief This method inserts an integer inside a BST.
    /// @param key Integer to be inserted in the BST.
    /// @return True if the key was inserted false if not.
    // Time complexity: O(n)
    bool insert(int key, const string &ip);

    /// @brief This method prints reverseInorder a BST.
    // Time complexity: O(n)
    void reverseInorder();

    /// @brief This method prints the top five of a BST.
    // Time complexity: O(1)
    void topFive();

};

#endif //INC_1_3_MYBST_H
