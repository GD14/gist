class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        int n=a.size();
        if(n<3) return ans;
        sort(a.begin(),a.end());
      
        int target=0;
        for(int i=0;i<n-2;i++)
        {
          if(i>0&&a[i]==a[i-1])
            continue;
          
          int l=i+1;
          int r=n-1;  
          while(l<r){
            int sum=a[i]+a[l]+a[r];
            if(sum==target)
            {
              ans.push_back({a[i],a[l],a[r]});
              while(l<r&&a[l]==a[l+1])l++;
              while(l<r&&a[r]==a[r-1])r--;
              l++;
              r--;
            }else if(sum>target)
              r--;
            else 
              l++;
          } 
        } 
      return ans;
    }