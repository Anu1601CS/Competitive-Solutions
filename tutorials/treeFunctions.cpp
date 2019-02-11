#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *head = NULL;

void inorder(struct node *temp)
{
    if (!temp)
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

void postorder(struct node *temp)
{
    if (!temp)
        return;

    inorder(temp->left);
    inorder(temp->right);
    cout << temp->data << " ";
}

void preorder(struct node *temp)
{
    if (!temp)
        return;

    cout << temp->data << " ";
    inorder(temp->left);
    inorder(temp->right);
}

bool checkContinuous(struct node *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->left == NULL)
        return true;

    if (root->left == NULL)
        return ((abs(root->data - root->right->data) == 1) && checkContinuous(root->right));

    if (root->right == NULL)
        return ((abs(root->data - root->left->data) == 1) && checkContinuous(root->left));

    return (abs(root->data - root->left->data) == 1) && (abs(root->data - root->right->data) == 1) && checkContinuous(root->left) &&
           checkContinuous(root->right);
}

int calculate(struct node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->value;

    int leftVal = calculate(root->left);
    int rightVal = calculate(root->right);

    if (!isdigit(root->value))
    {
        if (root->value == '+')
        {
            cout << leftVal << root->value << rightVal << endl;
            return leftVal + rightVal;
        }
        else if (root->value == '*')
        {
            cout << leftVal << root->value << rightVal << endl;
            return leftVal * rightVal;
        }
    }
}

bool isSametree(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return true;

    return isSametree(a->left, b->left) && isSametree(a->right, b->right);
}

void show()
{
    queue<struct node *> q;
    struct node *pp = head;
    q.push(pp);

    struct node *f;

    while (!q.empty())
    {
        struct node *f = q.front();
        q.pop();

        cout << f->data << " ";
        if (f->left != NULL)
        {
            q.push(f->left);
        }

        if (f->right != NULL)
        {
            q.push(f->right);
        }
    }
}

bool checkSum(struct node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == val)
            return true;
        else
            return false;
    }

    return checkSum(root->left, val - root->data) || checkSum(root->right, val - root->data);
}

void insert(int a)
{
    struct node *p = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;

    if (head == NULL)
    {
        head = temp;
        temp->left = NULL;
        temp->right = NULL;
    }
    else
    {
        struct node *parent, *current = head;

        while (current != NULL)
        {
            parent = current;
            if (current->data <= temp->data)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }

        if (parent->data <= temp->data)
        {
            parent->right = temp;
        }
        else
        {
            parent->left = temp;
        }
    }
}

int main()
{
    int n, i, a;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> a;
        insert(a);
    }

    cout << "Preorder => ";
    preorder(head);
    cout << endl;
    cout << "Inorder => ";
    inorder(head);
    cout << endl;
    cout << "Postorder => ";
    postorder(head);
    cout << endl;
    cout << "Level to level => ";
    show();

    if (checkSum(head, 12))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
