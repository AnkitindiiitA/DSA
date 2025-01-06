#include<bits/stdc++.h>
using namespace std;

class SGTree
{
public:
	vector<int> segtree;

	SGTree(int n)
	{
		segtree.resize(4 * n + 1);
	}

	void build(vector<int> &a, int n)
	{
		// assign values to leaves of the segment tree
		for (int i = 0; i < n; i++)
			segtree[n + i] = a[i];

		/* assign values to internal nodes
		  to compute minimum in a given range */
		for (int i = n - 1; i >= 1; i--)
			segtree[i] = (segtree[2 * i] + segtree[2 * i + 1]);
	}

	int query(int left, int right, int n)
	{
		/*  Basically the left and right indices will move
			towards right and left respectively and with
			every each next higher level and compute the
			minimum at each height. */
		// change the index to leaf node first
		left += n;
		right += n;

		// initialize minimum to a very high value
		int mi = 0;

		while (left < right)
		{

			// if left index is odd
            //cout<<left<<' '<<right<<'\n';
			if (left & 1)
			{
				mi += (segtree[left]);

				// make left index even
				left++;
			}

			// if right index is odd
			if (right & 1)
			{

				// make right index even
				right--;

				mi += (segtree[right]);
			}

			// move to the next higher level
			left /= 2;
			right /= 2;
		}
		return mi;
	}

	void update(int pos, int value, int n)
	{
		// change the index to leaf node first
		pos += n;

		// update the value at the leaf node
		// at the exact index
		segtree[pos] = value;

		while (pos > 1)
		{

			// move up one level at a time in the tree
			pos >>= 1;

			// update the values in the nodes in
			// the next higher level
			segtree[pos] = (segtree[2 * pos]+segtree[2 * pos + 1]);
		}
	}
};

int main() {
    vector<int> arr = {2,4,3,3,1};
    int n=5;
    SGTree sg(n);
    sg.build(arr,n);
    // for(int i=0;i<2*n;i++)cout<<sg.segtree[i]<<' ';
    // cout<<'\n';
    cout<<sg.query(0,n-1+1,n)<<'\n';
    sg.update(0,4,n);
    cout<<sg.query(0,n-1+1,n)<<'\n';
}
