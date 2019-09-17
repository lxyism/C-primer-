#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
     double median(vector<int>& nums)
    {
        int l =0;
        l = nums.size();
        double m;
        if(l %2 == 0)
            m = (nums[l/2]+nums[l/2-1])/2.0;
        if(l%2 != 0)
            m = nums[l/2];
        return m;  
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        int l1=nums1.size();
        int l2=nums2.size();
        int x1=0,x2=0;
        double m;
        vector<int> nums;
        if(l1 == 0)
            m=median(nums2);
        if(l2 == 0)
            m=median(nums1);
        else
        {
            for(int i=0,j=0; i<l1 && j<l2;)
            {
                if(nums1[i] <=nums2[j])
                {
                    nums.push_back(nums1[i]);
                    i++;
                    x1++;
                }
                if(nums1[i] > nums2[j])
                {
                    nums.push_back(nums2[j]);
                    j++;
                    x2++;
                }
            }
            while(x1<l1) nums.push_back(nums1[x1++]);
            while(x2<l2) nums.push_back(nums2[x2++]);
            m=median(nums);
            for(int i=0;i<nums.size();i++){
                cout<<nums[i]<<endl;
            }
        }
        return m;
    }
};
int main(){
    Solution s;
    vector<int> arr={2,4};
    vector<int> brr={3,5};
    cout<<s.findMedianSortedArrays(arr,brr)<<endl;
    return 0;
}