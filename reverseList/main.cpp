//
//  main.cpp
//  reverseList
//
//  Created by Cong on 13-3-5.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
};

void build(Node* &head, int n){
    
    head = new Node();
    n--;
    head->data = n;

    Node* p = head;
    while(n--){
        p->next = new Node();
        p = p->next;
        p->data = n;
    }
}

Node* reverseList(Node* head){
    if(head == NULL){
        cout<<"Invalid input"<<endl;
        return NULL;
    }
    if(head->next == NULL)
        return head;
    
    Node* p1 = head;
    Node* p2 = p1->next;
    Node* p3 = p2->next;
    
    p1->next = NULL;
    while(p3 != NULL){
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    
    p2->next = p1;
    return p2;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(int argc, const char * argv[])
{
    Node * head = NULL;
    build(head, 10);
    print(head);
    print(reverseList(head));

    return 0;
}

