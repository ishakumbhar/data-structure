#include <iostream>
#include <stdlib.h>   
using namespace std;

struct node
{
    int data;
    node *next;
};


void insert(node *&head, int value)
{
    node *newnode = (node *)malloc(sizeof(node));

    newnode->data = value;
    newnode->next = head;
    head = newnode;
}


void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    display(head);

   
    
}
