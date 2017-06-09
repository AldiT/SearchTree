

#include "SearchTree.hpp"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

SearchTree::SearchTree() {
    root = NULL;
    //srand(time(0));
}

SearchTree::~SearchTree() {
    Clear(root);
}

void SearchTree::Clear(Node *T) {
    if(T==NULL) return;
    if(T->left != NULL)
        Clear(T->left);
    
    if(T->right != NULL)
        Clear(T->right);
    
    delete T;
    return;
}

bool SearchTree::isEmpty()
{
    return(root==NULL);
}

Node *SearchTree::CopyNode(Node * T) {
    Node *kopje;
    kopje = new Node();
    *kopje = *T;    // kopjon strukturen
    kopje->left = NULL;
    kopje->right = NULL;
    return kopje;
}

Node *SearchTree::Search(int Key) {
    
    Node *temp;
    
    temp = root;
    
    while((temp != NULL) && (temp->Key != Key)) {
        if(Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    
    if(temp == NULL)
        return temp;
    else
        return(CopyNode(temp));
}

bool SearchTree::Insert(Node *newNode) {
    Node *temp;
    Node *p;
    temp = root;
    p = NULL;
    
    while(temp != NULL)
    {
        p = temp;
        if(newNode->Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    
    if(p == NULL)
        root = newNode;//i bie qe sesht futur fare tek while pema ishte bosh
    else {
        if(newNode->Key < p->Key)
            p->left = newNode;
        else
            p->right = newNode;
    }
    return true ;
}
bool SearchTree::Insert(int Key) {
    Node *nyje;
    nyje = new Node();
    nyje->Key = Key;
    nyje->left = nyje->right = NULL;
    return(Insert(nyje));
}

bool SearchTree::Delete(int Key) {
    Node *back;
    Node *temp;
    Node *delPrind;
    Node *delNyje;
    temp = root;
    back = NULL;
    
    while((temp != NULL) && (Key != temp->Key)) {
        back = temp;
        if(Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    
    if(temp == NULL){
        return false;//do te thote se elementi nuk u gjet
    }else{
        if(temp == root){
            delNyje = root;
            delPrind = NULL;
        }else{
            delNyje = temp;
            delPrind = back;
        }
    }
    // Rasti 1: fshin nyje me 1 ose 0 femije
    if(delNyje->right == NULL)
    {
        if(delPrind == NULL){ // nqs po fshijme rrenjen
            root = delNyje->left;
        delete delNyje;
        return true;
            
        }else{
            if(delPrind->left == delNyje)
                delPrind->left = delNyje->left;
            else
                delPrind->right = delNyje->left;
        delete delNyje;
        return true;
        }
    }
    else{ // ka te pakten nje femije
        if(delNyje->left == NULL){
            if(delPrind == NULL){
                //ka vetem nje femije dhe eshte i djathte // nqs po fshihet rrenja
                root = delNyje->right;
                delete delNyje;
                return true;
            }else{
                if(delPrind->left == delNyje)
                    delPrind->left = delNyje->right;
                else
                    delPrind->right = delNyje->right;
                delete delNyje;
                return true;
            }
        }
    else{ //Rasti dy po fshime nyje me dy femije
    
        temp = delNyje->left;
        back = delNyje;
        while(temp->right != NULL)
        {
            back = temp;
            temp = temp->right;
        }
        delNyje->Key = temp->Key;
        if(back == delNyje)
            back->left = temp->left;
        else
            back->right = temp->left;
            delete temp;
        return true;
        }
    }
}

void SearchTree::PrintNode(Node *T) {
    
    
    if(T == root)
        cout << "Root: " << T->Key <<"\n";
    else
        cout << T->Key <<"\n";

}



//Nder Rendore
void SearchTree::PrintTree(Node *T) {
    if(T != NULL)
    {
        PrintTree(T->left);
        PrintNode(T);
        PrintTree(T->right);
    }
    
}

//Para Rendore
void SearchTree::PrintTreeP(Node *T) {
    if(T != NULL)
    {
        PrintNode(T);
        PrintTree(T->left);
        
        PrintTree(T->right);
    }
    
}


void SearchTree::Print()
{
    PrintTree(root);
}



/*
Node* SearchTree::generate(int k, int l, int n){
    Node *temp = NULL;
    
    
    if(l <= n && n > 0 && k > 0 && k <= n){
        temp = new Node(k,
                            generate(k-1, l, k-1), generate(k+1, k+1, n));
    }
    
    return temp;
    
}*/

//generate functions just fill the tree with random numbers from a given range.

Node* SearchTree::generateD(int l, int u){
    
    Node* temp = new Node();
    
    
    if(l <= u && u > 0){
        srand((unsigned)time(0));
        temp->Key = randNumF(l, u);
        temp->left = generateD(l, temp->Key-1);
        temp->right = generateD(temp->Key+1, u);
        return temp;
    }
    
    return NULL;
}

























