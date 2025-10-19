#include <bits/stdc++.h>
#include <stack>
// #include "d:\Testing_running\code.cpp"
#include "jackquees.h"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

// int main()
// {
//     jackquees t;
//     Solution c;
//     vector<int> a = {1, 2, 3, 1};
//     int b = 5;
//     int d = 4;
//     cout << t.printhello(b, d);
//     // vector<vector<int>> d = c.generate(b);
//     // for(int i = 0 ;i<b;i++){
//     //     for(int j = 0 ;j<i;j++){
//     //         cout << d[i][j]<< " ";
//     //     }
//     // }
//     return 0;
// }

// class Solution
// {
// public:
//     void reverseTreeNode(TreeNode *node, vector<int> &ans)
//     {
//         if (node == NULL)
//         {
//             return;
//         }
//         reverseTreeNode(node->left, ans);
//         reverseTreeNode(node->right, ans);
//         ans.push_back(node->val);
//     }
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         vector<int> ans;
//         reverseTreeNode(root, ans);
//         return ans;
//     }
// };

// int main()
// {
//     TreeNode *a = new TreeNode(1);
//     a->right = new TreeNode(2);
//     a->right->left = new TreeNode(3);
//     Solution s;
//     vector<int> ans = s.postorderTraversal(a);
//     for (int i = 0 ;i<ans.size();i++){
//         cout << ans[i] << " ";
//     }
//     return 0;
// }

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = a[j];
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void selectionSortwithNum(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        swap(a[min], a[i]);
    }
}

void selectionSortwithChar(string s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((s[min][0] - 'A') < (s[j][0] - 'A'))
            {
                min = j;
            }
        }
        swap(s[min], s[i]);
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int flag = a[i];
        int j = i - 1;
        while (j >= 0 && flag < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = flag;
    }
}

int binarySearch(int a[], int n, int key)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int linearSearch(int a[], int n, int key)
{
    int i = 0;
    while (i < n && key != a[i])
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int linearSearchAdvanced(int a[], int n, int k)
{
    int i = 0;
    int lastElement = a[n];
    a[n] = k;
    while (a[i] != k)
    {
        i++;
    }
    a[n] = lastElement;
    if (i < n)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void quickSortforInt(int a[], int left, int right)
{
    if (left > right)
        return;
    int i = left, j = right, p = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] < p)
            i++;
        while (a[j] > p)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSortforInt(a, left, j);
    if (right > i)
        quickSortforInt(a, i, right);
}

void quickSortforStr(string s[], int left, int right)
{
    if (left > right)
        return;
    int i = left, j = right;
    string p = s[(left + right) / 2];
    while (i <= j)
    {
        while (s[i][0] - 'A' < p[0] - 'A')
            i++;
        while (s[j][0] - 'A' > p[0] - 'A')
            j--;
        if (i <= j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSortforStr(s, left, j);
    if (right > i)
        quickSortforStr(s, i, right);
}

void heapify(int a[], int n, int i)
{
    // as least, we known how actually the tree look like
    //      0
    //   1    2
    // 3  4  5
    // so start from the first node, the left position will be
    //  1 and right will be 2,and then i realized 1/2=0+1 and 2/2=0+2
    //  inference => left = 2*i+1 and right = 2*i+2
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // we compare if the left or right element < n and a[left] > a[i] with another 2 leaf
    //  if its true, assignment the real largest element and swap with the parent left
    //(which is smaller than the first one)
    //  finally,call the function again until it gets to the last node
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    // why did we start at n/2-1 position?
    // that because the n/2-1 is the one leaf dont have a child
    // we need heapify to sort the array from largest to smallest
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    //
    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void mergeSort(int a[], int m, int b[], int n, int c[]){
	int k = 0, i = 0, j = 0;
	while(i<m && j < n){
		if(a[i] < b[j]){
			c[k] = a[i]; i++;k++;
		} 
		else{
			c[k] = b[j]; k++;j++;
		}
	}
	while(i<m) c[k] = a[i]; i++;k++;
	while(j<n) c[k] = b[j]; j++;k++;
}

void merge(int a[], int l, int m, int r)
{
    vector<int> x(a + l, a + l + m + 1);
    vector<int> y(a + m + 1, a + r + 1);

    int i = 0, j = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] < y[j])
        {
            a[l] = x[i];
            ++i;
            ++l;
        }
        else
        {
            a[l] = y[j];
            ++j;
            ++l;
        }
    }
    while (i < x.size())
        a[l] = x[i];
    ++i;
    ++l;
    while (j < y.size())
        a[l] = y[j];
    ++j;
    ++l;
}

void mergeSort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << linearSearchAdvanced(a, n, k);
    return 0;
}
