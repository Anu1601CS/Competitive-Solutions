#include <bits/stdc++.h>
#include <string>
using namespace std;
#define SYNC                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'

typedef long long int lli;
typedef unsigned long long int ulli;

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node* insert(int data, struct node **head)
{
    struct node *p= *head;
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(*head == NULL) {
         *head = temp;
    } else {

        queue<struct node*> q;
        q.push(p);

        while (!q.empty()) {
           struct node *val = q.front();
           q.pop();

           if(val->left == NULL) {
                val->left = temp;
                break;
           } else {
                q.push(val->left);
           }

           if(val->right == NULL) {
               val->right = temp;
               break;
           } else {
                q.push(val->right);
           }
        }
    }
    
    return *head;
}

void inorder(struct node *p){

    if(p == NULL)
        return;

    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);    
}

int main()
{
    struct node *head = NULL;

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        insert(a, &head);
    }

    std::vector<int> v1;

    inorder(head);

    return 0;
}