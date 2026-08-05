#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = 10;
    newnode->next = newnode;   

    head = newnode;

    cout << "Data = " << head->data << endl;
    cout << "Next Data = " << head->next->data << endl;

    
    
}