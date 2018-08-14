#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node *next;
};

int main()
{
  int n,i,a;
  cin>>n;

  struct node *head = NULL;

  for(i=0;i<n;i++)
  {
    struct node *p = head;
    cin>>a;

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;

    if(head==NULL)
    {
      head = temp;
    }
    else
    {
      while(p->next != NULL)
      p = p->next;
      p->next = temp;
    }

  }

  struct node *t = head;
  while(t->next != NULL)
  {
    cout<<t->data<<"->";
    t = t->next;
  }

  return 0;
}
