#include <iostream>
template <typename type> class AVL {
private:
    struct node {
        type key;
        int32_t height;
        node *left = nullptr, *right = nullptr;
    };
    node *root = nullptr;
    void clearTree(node* x) {
        if (x == nullptr)
            return;
        clearTree(x -> left);
        clearTree(x -> right);
        delete x;
    }
    uint32_t getHeight(node *x) {
        if (x == nullptr)
            return 0;
        return x -> height;
    }
    node *newNode(type key) {
        node *x = new node;
        x -> key = key;
        x -> left = nullptr;
        x -> right = nullptr;
        x -> height = 1;
        return x;
    }
    node *rotateRight(node *x) {
        node *y = x -> left;
        node *z = y -> right;
        y -> right = x;
        x -> left = z;
        x -> height = std :: max(getHeight(x -> left), getHeight(x -> right)) + 1;
        y -> height = std :: max(getHeight(y -> left), getHeight(y -> right)) + 1;
        return y;
    }
    node *rotateLeft(node *x) {
        node *y = x -> right;
        node *z = y -> left;
        y -> left = x;
        x -> right = z;
        x -> height = std :: max(getHeight(x -> left), getHeight(x -> right)) + 1;
        y -> height = std :: max(getHeight(y -> left), getHeight(y -> right)) + 1;
        return y;
    }
    int32_t getBalance(node *x) {
        if (x == nullptr)
            return 0;
        return getHeight(x -> left) - getHeight(x -> right);
    }
    node *insertNode(node *x, type key) {
        if (x == nullptr)
            return newNode(key);
        if (key < x -> key)
            x -> left = insertNode(x -> left, key);
        else
            if (key > x -> key)
                x -> right = insertNode(x -> right, key);
            else
                return x;
        x -> height = std :: max(getHeight(x -> left), getHeight(x -> right)) + 1;
        int32_t balanceFactor = getBalance(x);
        if (balanceFactor > 1) {
            if (key > x -> left -> key)
                x -> left = rotateLeft(x -> left);
            return rotateRight(x);
        }
        if (balanceFactor < -1) {
            if (key < x -> right -> key)
                x -> right = rotateRight(x -> right);
            return rotateLeft(x);
        }
        return x;
    }
    node *getMin(node *x) {
        node *crr = x;
        while (crr -> left != nullptr)
            crr = crr -> left;
        return crr;
    }
    node *getMax(node *x) {
        node *crr = x;
        while (crr -> right != nullptr)
            crr = crr -> right;
        return crr;
    }
    node *eraseNode(node *root, type key) {
        if (root == nullptr)
            return root;
        if (key < root -> key)
            root -> left = eraseNode(root -> left, key);
        else
            if (key > root -> key)
                root -> right = eraseNode(root -> right, key);
            else
                if (root -> left == nullptr or root -> right == nullptr) {
                    node *aux = (root -> left != nullptr) ? (root -> left) : (root -> right);
                    if (aux == nullptr) {
                        aux = root;
                        root = nullptr;
                    }
                    else
                        root = aux;
                    free(aux);
                }
                else {
                    node *aux = getMin(root -> right);
                    root -> key = aux -> key;
                    root -> right = eraseNode(root -> right, aux -> key);
                }
        if (root == nullptr)
            return root;
        root -> height = std :: max(getHeight(root -> left), getHeight(root -> right)) + 1;
        int32_t balanceFactor = getBalance(root);
        if (balanceFactor > 1) {
            if (getBalance(root -> left) < 0)
                root -> left = rotateLeft(root -> left);
            return rotateRight(root);
        }
        if (balanceFactor < -1) {
            if (getBalance(root -> right) < 0)
                root -> right = rotateRight(root -> right);
            return rotateLeft(root);
        }
        return root;
    }
    void printTree(node *root, std :: string indent, bool last) {
        if (root != nullptr) {
            std :: cout << indent;
            if (last == true) {
                std :: cout << "R----";
                indent += "    ";
            }
            else {
                std :: cout << "L----";
                indent += "|   ";
            }
            std :: cout << root -> key << '\n';
            printTree(root -> left, indent, false);
            printTree(root -> right, indent, true);
        }
    }
public:
    void print() {
        printTree(root, "", true);
    }
    bool isEmpty() {
        return root != nullptr;
    }
    bool findKey(type key) {
        node *crr = root;
        while (crr != nullptr) {
            if (crr -> key == key)
                return true;
            if (crr -> key < key)
                crr = crr -> left;
            else
                crr = crr -> right;
        }
        return false;
    }
    void eraseKey(type key) {
        root = eraseNode(root, key);
    }
    void insertKey(type key) {
        root = insertNode(root, key);
    }
    void clearAVL() {
        clearTree(root);
    }
};
