//
// Created by tseyu on 1/13/23.
//
#include <iostream>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct{
    Node* root;
} Tree;

void insert(Tree* tree, int value){
    Node* node = new Node;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;

    if (tree ->root == nullptr){
        tree->root = node;
    }else{
        Node* temp = tree->root;
        while (temp != nullptr){
            if (temp->data > value ){
                if (temp->left == nullptr){
                    temp->left =node;
                    return ;
                }else{
                    temp = temp->left;
                }
            }else{
                if (temp->right == nullptr){
                    temp->right = node;
                    return;
                }else{
                    temp = temp->right;
                }
            }
        }
    }
}

void preorder(Node* node){
    if (node != nullptr){
        std::cout << node->data <<"\n";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node* node){
    if (node != nullptr){
        inorder(node->left);
        std::cout << node->data <<"\n";
        inorder(node->right);
    }
}

void postorder(Node* node){
    if (node != nullptr){
        postorder(node->left);
        std::cout << node->data <<"\n";
        postorder(node->right);
    }
}

int getHeight(Node* node){
    if (node == nullptr){
        return 0;
    }else{
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        int max = leftHeight;
        if (rightHeight > leftHeight){
            max = rightHeight;
        }
        return max+1;
    }
}

int getMaximum(Node* node){
    if (node == nullptr){
        return -1;
    }else{
        int m1 = getMaximum(node->left);
        int m2 = getMaximum(node->right);
        int m3 = node->data;
        int max = m1;
        if (m2 > max){
            max =m2;
        }
        if (m3 > max){
            max = m3;
        }
        return max;
    }

}

int main(){
    int arr[7] {6,3,8,2,5,1,7};
    Tree tree;
    tree.root = nullptr;
    for (int i{0}; i< 7;i++){
        insert(&tree,arr[i]);
    }
    // inorder(tree.root);

    int h = getHeight(tree.root);
    std::cout << h <<"\n";


    int m = getMaximum(tree.root);
    std::cout << m <<"\n";

    return 0;
}
