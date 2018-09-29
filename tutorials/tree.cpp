#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *head = NULL;

void inorder(struct node * temp)
{
  if(!temp)
  return;

  inorder(temp->left);
  cout<<temp->data<<" ";
  inorder(temp->right);
}

void postorder(struct node * temp)
{
  if(!temp)
  return;

  inorder(temp->left);
  inorder(temp->right);
  cout<<temp->data<<" ";
}

void preorder(struct node * temp)
{
  if(!temp)
  return;

  cout<<temp->data<<" ";
  inorder(temp->left);
  inorder(temp->right);
}

void show()
{
  queue<struct node*> q;
  struct node *pp = head;
  q.push(pp);

  struct node * f;

  while(!q.empty())
  {
    struct node * f = q.front();
    q.pop();

    cout<<f->data<<" ";
    if(f->left != NULL)
    {
      q.push(f->left);
    }

    if(f->right != NULL)
    {
      q.push(f->right);
    }
  }
}

void insert(int a)
{
  queue<struct node*> q;

  struct node *p = head;
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  temp->data = a;
  temp->left = NULL;
  temp->right = NULL;

  if(head == NULL)
  {
    head = temp;
  }
  else
  {
    struct node *pp = head;
    q.push(pp);

    while(!q.empty())
    {
      struct node * f = q.front();
      q.pop();

      if(f->left == NULL)
      {
        f->left = temp;
        break;
      } else
        q.push(f->left);

      if(f->right == NULL)
      {
        f->right = temp;
        break;
      } else
        q.push(f->right);
    }
  }
}

int main()
{
  int n,i,a;
  cin>>n;

  for(i=0;i<n;i++)
  {
    cin>>a;
    insert(a);
  }

  cout<<"Preorder => ";
  preorder(head);
  cout<<endl;
  cout<<"Inorder => ";
  inorder(head);
  cout<<endl;
  cout<<"Postorder => ";
  postorder(head);

  return 0;
}
