class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        double n1;
        int n2;
        int cnt = (n+m)%2==0 ? (n+m)/2 : (n+m)/2+1;
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        // cout<<n<<" "<<m<<" "<<cnt<<endl;
        while(cnt--){
            n1=min(nums1[i],nums2[j]);
            if(nums1[i]<=nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        if((n+m)%2){
            return n1;
        }
        else{
            n2=min(nums1[i],nums2[j]);
        }
        return (n1+n2)/2.0;
    }
};