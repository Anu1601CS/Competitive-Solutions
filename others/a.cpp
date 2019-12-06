#include <bits/stdc++.h>
using namespace std;

void constructSegmentTree(int arr[], int segment[], int low, int high, int pos)
{
	if (low == high)
	{
		segment[pos] = arr[low];
		return;
	}

	int mid = (low + high) / 2;

	constructSegmentTree(arr, segment, low, mid, (2 * pos) + 1);
	constructSegmentTree(arr, segment, mid + 1, high, (2 * pos) + 2);

	segment[pos] = min(segment[(2 * pos) + 1], segment[(2 * pos) + 2]);
}

int minRangeQuery(int segment[], int fLow, int fHigh, int low, int high, int pos)
{

	if (high <= fHigh && low >= fLow)
		return segment[pos];

	if (high < fLow || low > fHigh)
		return 999999;

	int mid = (low + high) / 2;

	return min(minRangeQuery(segment, fLow, fHigh, low, mid, (2 * pos) + 1), minRangeQuery(segment, fLow, fHigh, mid + 1, high, (2 * pos) + 2));
}

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int segmentSize;
	if (n % 2 == 0)
		segmentSize = 2 * n - 1;
	else
		segmentSize = 2 * pow(2, ceil(log2(n))) - 1;

	int segment[segmentSize];
	for (int i = 0; i < segmentSize; i++)
		segment[i] = 99999;

	constructSegmentTree(arr, segment, 0, n - 1, 0);

	int l, h;
	cin >> l >> h;

	cout << minRangeQuery(segment, l, h, 0, segmentSize - 1, 0);

	return 0;
}
