#include <bits/stdc++.h>
using namespace std;
#define SYNC                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007s
#define all(c) c.begin(), c.end()
#define endl '\n'

typedef long long int lli;

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

int nextPowerOfTwo(int n)
{
    int val = 1;

    while (val <= n)
        val = val << 1;

    return val;
}

int prevPowerOfTwo(int n)
{
    int c = 0;
    while (pow(2, c) < n)
        c++;

    if (pow(2, c) == n)
        return pow(2, c - 1);
    else
        return pow(2, c);
}

void constructTree(int input[], int segmentTree[], int low, int high, int pos)
{
    if (low == high)
    {
        segmentTree[pos] = input[high];
        return;
    }

    int mid = (low + high) /2 ;

    constructTree(input,  segmentTree, low, mid, 2*pos + 1);
    constructTree(input,  segmentTree, mid + 1, high, 2*pos + 2);

    segmentTree[pos] = min(segmentTree[2*pos + 1], segmentTree[2*pos + 2]);

}


int minRangeQuery(int segmentTree[], int low, int high, int qLow, int qHigh, int pos)
{

   if(qLow <= low  && qHigh >= high )
    return segmentTree[pos]; 
    else if(qLow > high ||  qHigh < low)
        return 999999;

    int mid = (low+high ) /2;

    return min(minRangeQuery(segmentTree, 0, mid, qLow, qHigh, 2*pos + 1),minRangeQuery(segmentTree, mid+1, high, qLow, qHigh, 2*pos + 2));

}

int main()
{
    SYNC

        int n;
    cin >> n;

    int input[n];
    for (int i = 0; i < n; i++)
        cin >> input[i];

    int size;
    if (isPowerOfTwo(n))
        size = n * 2 - 1;
    else
        size = nextPowerOfTwo(n) * 2 - 1;

    int segmentTree[size];

    constructTree(input, segmentTree, 0, n - 1, 0);

    for(int i=0;i<size; i++)
        cout<<segmentTree[i]<<" ";


        cout<<endl;

        cout<<minRangeQuery(segmentTree, 0, n-1, 1, 2, 0);

    return 0;
}