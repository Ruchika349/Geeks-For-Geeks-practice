//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
         int n = arr.size();
        vector<int> result(n, 0);
        vector<pair<int, int>> enumArr;
        
        for (int i = 0; i < n; ++i) {
            enumArr.push_back({arr[i], i});
        }
        
        mergeSort(enumArr, 0, n - 1, result);
        return result;
    }
    
    private:
    void mergeSort(vector<pair<int, int>>& enumArr, int left, int right, vector<int>& result) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(enumArr, left, mid, result);
        mergeSort(enumArr, mid + 1, right, result);
        merge(enumArr, left, mid, right, result);
    }
    
    void merge(vector<pair<int, int>>& enumArr, int left, int mid, int right, vector<int>& result) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int rightCounter = 0;
        
        while (i <= mid && j <= right) {
            if (enumArr[i].first <= enumArr[j].first) {
                result[enumArr[i].second] += rightCounter;
                temp[k++] = enumArr[i++];
            } else {
                ++rightCounter;
                temp[k++] = enumArr[j++];
            }
        }
        
        while (i <= mid) {
            result[enumArr[i].second] += rightCounter;
            temp[k++] = enumArr[i++];
        }
        
        while (j <= right) {
            temp[k++] = enumArr[j++];
        }
        
        for (int l = left; l <= right; ++l) {
            enumArr[l] = temp[l - left];
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends