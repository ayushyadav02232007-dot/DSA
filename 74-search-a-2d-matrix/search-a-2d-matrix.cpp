class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int lower=0,upper=m-1,mid;

        while(lower<=upper){
            mid=(lower+upper)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][n-1]){
                int idx=mid;
                lower=0;
                upper=n-1;

                while(lower<=upper){
                    mid=(lower+upper)/2;

                    if(matrix[idx][mid]==target) return true;
                    else if(target<matrix[idx][mid]) upper=mid-1;
                    else lower=mid+1;
                }
            }else if(target<matrix[mid][0]){
                upper=mid-1;
            }else{
                lower=mid+1;
            }
        }
        return false;
    }
};