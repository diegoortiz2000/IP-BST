//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460, Luis Armando Salazar A01114901
// November 01 2020
//

#include "MyBST.h"
#include <iostream>
#include <queue>

using namespace std;

MyBST::MyBST() {
    this->size = 0;
    this->root = nullptr;
}

bool MyBST::search(int data, MyNodeBST *current) {
    if (current == nullptr) {
        return false;
    } else if (current->data == data) {
        return true;
    }
    if (data < current->data) {
        return search(data, current->left);
    } else {
        return search(data, current->right);
    }
}

bool MyBST::insert(int key, const string &ip) {
    if (this->root == nullptr) {
        this->root = new MyNodeBST(key, ip);
        size++;
        return true;
    } else {
        MyNodeBST *current = this->root, *prev = nullptr;
        while (current != nullptr) {
            prev = current;
            if (key == current->data) {
                return false;
            } else {
                current = key < current->data ? current->left : current->right;
            }
        }
        if (key < prev->data) {
            prev->left = new MyNodeBST(key, ip);
        } else {
            prev->right = new MyNodeBST(key, ip);
        }
        this->size++;
        return true;
    }
}

MyNodeBST *MyBST::minValueNode(MyNodeBST *node) {
    MyNodeBST *current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

MyNodeBST *MyBST::remove(MyNodeBST *node, int data, bool &success) {
    if (node == nullptr) {
        success = false;
        return node;
    }
    if (data < node->data) {
        node->left = remove(node->left, data, success);
    } else if (data > node->data) {
        node->right = remove(node->right, data, success);
    } else {
        if (node->left == nullptr) {
            MyNodeBST *temp = node->right;
            delete node;
            success = true;
            return temp;
        } else if (node->right == nullptr) {
            MyNodeBST *temp = node->left;
            delete node;
            success = true;
            return temp;
        }
        MyNodeBST *temp = minValueNode(node->right);
        node->data = temp->data;
        root->right = remove(node->right, temp->data, success);
    }
    return node;
}

void MyBST::postorder(MyNodeBST *current) {

    if (current != nullptr) {
        postorder(current->left);
        postorder(current->right);
        cout << current->data << ",";
    }
}

void MyBST::preorder(MyNodeBST *current) {
    if (current != nullptr) {
        cout << current->data << ",";
        this->preorder(current->left);
        this->preorder(current->right);
    }
}

void MyBST::reverseInorder(MyNodeBST *current, int &count) {
    if (count > 0 || count == -1) {
        if (count != -1) {
            count--;
        }
        if (current != nullptr) {
            reverseInorder(current->right, count);
            cout << "Repetitions: " << current->data << " IP: " << current->ip << endl;
            reverseInorder(current->left, count);
        }
    }
}

void MyBST::reverseInorder() {
    int count = -1;
    reverseInorder(this->root, count);
}

int MyBST::height(MyNodeBST *node) {
    if (node == nullptr) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->left);
        if (leftHeight < rightHeight) {
            return (rightHeight + 1);
        } else {
            return (leftHeight + 1);
        }
    }
}

bool MyBST::ancestors(MyNodeBST *node, int data, string &output) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == data) {
        return true;
    }
    if (ancestors(node->left, data, output) || ancestors(node->right, data, output)) {
        output.insert(0, to_string(node->data) + ",");
        return true;
    } else {
        return false;
    }
}

int MyBST::whatLevelAmI(MyNodeBST *node, int data, int level) {
    if (node == nullptr) {
        return -1;
    }
    if (node->data == data) {
        return level;
    }

    int nextLevel = whatLevelAmI(node->left, data, level + 1);
    if (nextLevel != 0) {
        return nextLevel;
    }
    nextLevel = whatLevelAmI(node->right, data, level + 1);
    return nextLevel;
}

void MyBST::topFive() {
    int count = 5;
    reverseInorder(this->root, count);
}
