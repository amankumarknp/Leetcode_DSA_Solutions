class Solution {
public:
// T.C  : O(N LOG N) (SORTING) + o(2N) (visiting each element 2 times)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            //Skip all the merged intervals:
            if(!ans.empty() && end <= ans.back()[1]){
                continue;
            } 
            //check the rest of the intervals:
            for(int j=i+1; j<n; j++){
                if(intervals[j][0] <= end){
                    end = max(intervals[j][1], end); 
                }
                else{
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};
class Solution2 {
public:
// T.C  : O(N LOG N) (SORTING) + o(N) (visiting each element 1 times)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++){
            if(!ans.empty() && intervals[i][1] <= ans.back()[1]){
               ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
