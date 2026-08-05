#include<iostream>
#include<stdio.h>
using namespace std;

 struct node 
{
    int data;
    struct node*next;
		
};

 int main()
{
	node *newnode = (node*)malloc(sizeof(node)); 
	newnode -> data =10;
	newnode -> next =NULL;
	
	cout << newnode->data << endl;
	cout << newnode->next << endl;

}