// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        int i=0,j=0;
        int sum=0,maxi=INT_MIN;
        while(i<n){
            if(i<k){
                sum+=arr[i];
            }
            else{
                sum-=arr[j];
                sum+=arr[i];
                j++;
            }
            i++;
            maxi=max(maxi,sum);
        }
        
        return maxi;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends