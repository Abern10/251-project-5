// mymap.h
// Program 5: mymap
// Course: CS 251, Fall 2022. Thursday 12pm lab
//
// Author: Alex Bernatowicz
//
// The mymap.h file is a class consisting of member functions that is used to 
// create our own version of map. The mymap is created using a threaded binary 
// search tree. A threaded binary search tree means that our right child of
// each node will point to the next in order node, therefore saving memory
// because it is not pointing a nullptr if it were to be empty.
// 
#pragma once

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template<typename keyType, typename valueType>
class mymap {
 private:
    struct NODE {
        keyType key;  // used to build BST
        valueType value;  // stored data for the map
        NODE* left;  // links to left child
        NODE* right;  // links to right child
        int nL;  // number of nodes in left subtree
        int nR;  // number of nodes in right subtree
        bool isThreaded;
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of key/value pairs in the mymap

    //
    // iterator:
    // This iterator is used so that mymap will work with a foreach loop.
    //
    struct iterator {
     private:
        NODE* curr;  // points to current in-order node for begin/end

     public:
        iterator(NODE* node) {
            curr = node;
        }

        keyType operator *() {
            return curr -> key;
        }

        bool operator ==(const iterator& rhs) {
            return curr == rhs.curr;
        }

        bool operator !=(const iterator& rhs) {
            return curr != rhs.curr;
        }

        bool isDefault() {
            return !curr;
        }

        //
        // operator++:
        //
        // This function should advance curr to the next in-order node.
        // O(logN)
        //
        iterator operator++() {
            if(curr->isThreaded == true) { // if curr is threaded go right
                curr = curr->right;
            }
            else { // if not go right then go as far left as you can
                curr = curr->right;
                while(curr->left != nullptr) {
                    curr = curr->left;
                }
            }
            return iterator(curr);
        }
    };

    // to string recursive helper function using in-order traversal
    void _toString(NODE* node, ostream& output) {
        if(node == nullptr) { // base case to check is tree is empty
            return;
        }
        if(node->left != nullptr){ // checks to see if node is at the farthest left(1st in order)
            if (node->left->key < node->key) { // if left child key is less than current key go call recursive function to go left
                _toString(node->left, output);
            } 
        }
        output << "key: " << node->key << " value: " << node->value << "\n";
        if(node->isThreaded) { // checks to see if node is threaded, if so set to nullptr
            node = nullptr;
        } 
        else { // if not threaded call recursive function to go right
            _toString(node->right, output);
        }       
    }

    // clear recursive helper function using post order traversal
    void _clear(NODE* current) {
        if(current == nullptr) { // base case to check if tree is empty
            return;
        }
        else { // post-order traveral to clear
            _clear(current->left);
            if(current->isThreaded) { // if current is threaded
                current = nullptr;
            }
            else { // if not threadead recursive function call to go right
            _clear(current->right);
            }
        }
        delete current;
    }

    // copy recursive helper function for equal operator and copy contructor using pre-order traversal
    void _copy(NODE* current) {
        if(current == nullptr) { // base case to check if tree is empty
            return;
        }
        this->put(current->key, current->value); // calls put function to insert node into new tree
        _copy(current->left); // recursive call to go left
        if(current->isThreaded) { // checks to see current node is threaded or not, if it is sets to nullptr
            current = nullptr;
        }
        else { // if not threaded then proceed right
            _copy(current->right);
        }
    }

    // to Vector recursive helper function
    void _toVector(NODE* node, vector<pair<keyType, valueType> > &vector) {
        if(node == nullptr) { // base case to check is tree is empty
            return;
        }
        _toVector(node->left, vector);
        vector.push_back(make_pair(node->key, node->value)); // creates pair and adds to vector
        if(node->isThreaded) { // checks to see if node is threaded if is set to nullptr
            node = nullptr;
        }
        else { // if not continue right
            _toVector(node->right, vector);
        }
    }

    // check balance recursive helper function using pre-order
    void _CheckBalance(NODE *node, ostream& output) {
        if(node == nullptr) { // base case to check if tree is empty
            return;
        }
        // output statement
        output << "key: " << node->key << ", nL: " << node->nL << ", nR: " << node->nR << endl;
        _CheckBalance(node->left, output);
        if(node->isThreaded) { // checks if node is threaded, if it is set to nullptr
            node = nullptr;
        }
        else { // if not then proceed right recursively
            _CheckBalance(node->right, output);
        }
    }

 public:
    //
    // default constructor:
    //
    // Creates an empty mymap.
    // Time complexity: O(1)
    //
    mymap() {
        root = nullptr;
        size = 0;
    }

    //
    // copy constructor:
    //
    // Constructs a new mymap which is a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(nlogn), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap(const mymap& other) {
       root = nullptr;
       size = 0;
       _copy(other.root); 
    }

    //
    // operator=:
    //
    // Clears "this" mymap and then makes a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(nlogn), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap& operator=(const mymap& other) {
        this->clear(); // clears the inputted BST
        _copy(other.root); // calls the copy recursive helper function
        return *this;
    }

    // clear:
    //
    // Frees the memory associated with the mymap; can be used for testing.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    void clear() {
        _clear(root); // calls recursive helper function
        root = nullptr; // set back root and size to default values
        size = 0;
    }

    //
    // destructor:
    //
    // Frees the memory associated with the mymap.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    ~mymap() {
        clear();
    }

    //
    // put:
    //
    // Inserts the key/value into the threaded, self-balancing BST based on
    // the key.
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-tree that needs to be re-balanced.
    // Space complexity: O(1)
    //
    void put(keyType key, valueType value) {
        NODE* previous = nullptr;
        NODE* current = root;

        while(current != nullptr) {
            if(key == current->key) { // if keys are equal update value
                current->value = value;
                return;
            }
            if(key < current->key) { // if input key is less than current key, go left
                current->nL++;
                previous = current;
                current = current->left;
            }
            else if(key > current->key) { // if input key is greater than current key, go right
                current->nR++;
                previous = current;
                current = (current->isThreaded) ? nullptr : current->right;
            }
        }
        // Creates new node to be inserted, member variables set to default values
        NODE* newNode = new NODE;
        newNode->key = key;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->nL = 0;
        newNode->nR = 0;
        newNode->isThreaded = false;

        // inserts new node and takes into account threading
        if(previous == nullptr) { // insert into empty BST
            root = newNode;
            // root->isThreaded = true;
        }
        else if(key < previous->key) { // insert left
            previous->left = newNode;
            newNode->isThreaded = true;
            newNode->right = previous;
        }
        else if(key > previous->key) { // insert right
            newNode->right = previous->right;
            previous->isThreaded = false;
            newNode->isThreaded = true;
            previous->right = newNode;
        }
        size++;
    }

    //
    // contains:
    // Returns true if the key is in mymap, return false if not.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    bool contains(keyType key) {
        NODE* current = root;

        while(current != nullptr) { 
            if(key == current->key) { // if key found return true
                return true;
            }
            if(key < current->key) { // search left child if less than
                current = current->left;
            }
            else { // search right child if greater than
                current = (current->isThreaded) ? nullptr : current->right;
            }
        }
        return false;  // if key not found return false
    }

    //
    // get:
    //
    // Returns the value for the given key; if the key is not found, the
    // default value, valueType(), is returned (but not added to mymap).
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    valueType get(keyType key) {
        NODE* current = root;

        while(current != nullptr) {
            if(key == current->key) { // if key found return value associated with it
                return current->value;
            }
            if(key < current->key) { // search left child if less than
                current = current->left;
            }
            else { // search right child if greater than
                // current = current->right;
                current = (current->isThreaded) ? nullptr : current->right;
            }
        }
        return valueType();  // if key not found returns default value
    }

    //
    // operator[]:
    //
    // Returns the value for the given key; if the key is not found,
    // the default value, valueType(), is returned (and the resulting new
    // key/value pair is inserted into the map).
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-trees that need to be re-balanced.
    // Space complexity: O(1)
    //
    valueType operator[](keyType key) {
        NODE* current = root;

        while(current != nullptr) {
            if(key == current->key) { // if key found return value associated
                return current->value;
            }
            if(key < current->key) { // search left child if less than
                current = current->left;
            }
            else { // search right child if greater than
                // current = current->right;
                current = (current->isThreaded) ? nullptr : current->right;
            }
        }
        // if key is not found call put function to insert key with default value and return default value
        put(key, valueType());
        return valueType();
    }

    //
    // Size:
    //
    // Returns the # of key/value pairs in the mymap, 0 if empty.
    // O(1)
    //
    int Size() {
        return size;
    }

    //
    // begin:
    //
    // returns an iterator to the first in order NODE.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    iterator begin() {
        NODE* current = root;

        while(current->left != nullptr) { // goes as far left as possible
            current = current->left;
        }
        return iterator(current);
    }

    //
    // end:
    //
    // returns an iterator to the last in order NODE.
    // this function is given to you.
    // 
    // Time Complexity: O(1)
    //
    iterator end() {
        return iterator(nullptr);
    }

    //
    // toString:
    //
    // Returns a string of the entire mymap, in order.
    // Format for 8/80, 15/150, 20/200:
    // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string toString() {
        stringstream ss;
        NODE* current = root;

        _toString(current, ss); // to string recursive function call using in-order

        return ss.str();
    }

    //
    // toVector:
    //
    // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
    // {{8, 80}, {15, 150}, {20, 200}}
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    vector<pair<keyType, valueType> > toVector() {
        vector<pair<keyType, valueType> > vector;
        NODE* current = root;
        _toVector(current, vector); // calls to vector recursive helper function
        return vector;
    }

    //
    // checkBalance:
    //
    // Returns a string of mymap that verifies that the tree is properly
    // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
    // function should return a string in this format (in pre-order):
    // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string checkBalance() {
        stringstream ss;
        NODE *current = root;
        _CheckBalance(current, ss); // check balance recursive function call using pre-order
       return ss.str();
    }
};