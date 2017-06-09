
#ifndef SearchTree_hpp
#define SearchTree_hpp

#include <stdio.h>
#include <iostream>

#include <cstdlib>
#include <time.h>

using namespace std;
struct Node
{
    int      Key;
    Node *left;
    Node *right;
    
    
    Node(){
        Key = 0;
        left = NULL;
        right = NULL;
    }
    /*
    Node(int &v, Node* l, Node *r){
        Key = v;
        left= l;
        right = r;
    }
    
    Node(int &&v, Node*l, Node*r){
        Key = std::move(v);
        left = l;
        right = r;
    }
     */
};

class SearchTree
{
private:
    Node *root;
    static int in;
    
public:
    
    /*
     
     Ndertoni nje pem binare kerkimi me n nyje me celesa nga 1 ne n(n parameter)
     
     Te njejtin funk rekursiv
     */
    
    SearchTree();
    ~SearchTree();
    bool isEmpty();
    
    Node *Search(int Key);
    
    bool Insert(Node *newNode); bool Insert(int Key);
    
    bool Delete(int Key);
    
    void PrintNode(Node *T);
    void Print();
    void PrintTree(Node*);
    void PrintTreeP(Node*);
    
    void PrintNode1(Node *T, std::string pre);
    
    void generate(int n){
        root = generateD(1, n);
    }
    
    
    Node* getRoot(){
        return root;
    }
    
    int randNumF(int l, int u){
        return l+(rand() % (u-l+1));
    }
    
    int randNum(int l, int u){
        
        int a = 0, b = 0;
        
        //srand((unsigned)time(0));
        
        a = rand();
        
        b = l + (a/ RAND_MAX) * (u - l);
        
        return b;
    }
    
private:
    void Clear(Node *T);
    Node *CopyNode(Node * T); void PrintAll(Node *T);
    
    //Node* generate(int k, int l, int h);
    Node* generateD(int l, int u);
};

#endif /* SearchTree_hpp */


































