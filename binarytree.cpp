#include <iostream>

using namespace std;


class tree{
    struct node{
        int value;
        node* left;
        node* right;

        node(int Value) : value(Value), left(nullptr), right(nullptr) {}
    };
    node* root;

public:
    tree() : root(nullptr) {}

    void append(int);
    void insert(node*& , node*& );
    string search(int);
    void display();
    void printTree(node*);
};


int main(){
    tree numbers;

    numbers.append(10);
    numbers.append(20);
    numbers.append(5);

    numbers.display();

    cout << numbers.search(20);

    return 0;
}

void tree::append(int Value){
    node* newNode = new node(Value);
    if (!root){root = newNode;}
    else{
        node* temp = root;
        insert(temp, newNode);
    }
}

void tree::insert(node*& temp, node*& newNode) {
    if (temp == nullptr){temp = newNode;}                 
    else if (newNode->value < temp->value) {insert(temp->left, newNode);}    
    else {insert(temp->right, newNode);}
}

string tree::search(int value) {
    node* temp = root;
    while (temp != nullptr) {
        if (value == temp->value) {return "Found";} 
        else if (value < temp->value) {temp = temp->left;} 
        else {temp = temp->right;}
    }
    return "Not Found";
}
void tree::display(){
    if (!root) {cout << "Tree is empty." << endl;}
    else{
        printTree(root);
        cout << endl;
    }
}    
void tree::printTree(node* temp){
    if (temp){
        cout << temp->value << " ";
        printTree(temp->left);       
        printTree(temp->right);
    }
}
