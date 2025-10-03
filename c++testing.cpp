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
    while (i > n && key != a[i])
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
    if(left<j)quickSortforInt(a, left, j);
    if(right > i)quickSortforInt(a, i, right);
}

void quickSortforStr(string s[], int left , int right){
    if(left >right)return;
    int i = left, j = right;
    string p = s[(left+right)/2];
    while(i<=j){
        while(s[i][0]-'A' < p[0]-'A') i++;
        while(s[j][0]-'A' > p[0]-'A') j--;
        if(i<=j){
            swap(s[i],s[j]);
            i++;j--;
        }
    }
    if(left < j)quickSortforStr(s,left,j);
    if(right > i) quickSortforStr(s,i,right);
}

int main()
{
    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSortforStr(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
