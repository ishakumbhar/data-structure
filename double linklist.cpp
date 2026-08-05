#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    node *newnode = (node*)malloc(sizeof(node));

    newnode->data = 10;
    newnode->prev = NULL;
    newnode->next = NULL;

    cout << "Data: " << newnode->data << endl;
    cout << "Previous: " << newnode->prev << endl;
    cout << "Next: " << newnode->next << endl;

                                                                                                
}