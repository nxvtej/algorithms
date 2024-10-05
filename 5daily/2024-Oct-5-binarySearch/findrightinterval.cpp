class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        /*

        ese to muskil sa hai

         vector<pair<int, int>> temp;
         for(int i=0;i<intervals.size();i++){
             temp.push_back(make_pair(intervals[i][0], i));
         }

 // sort
         auto cmp = [&](auto a, auto b){
             return a.first<b.first;
         };
         sort(temp.begin(), temp.end(), cmp);

 // print
         for(auto it: temp){
             cout<<it.first<<" "<<it.first<<" "<<it.second<<"\n";
         }



         int left = 0;
         int right = intervals.size();
         while(left < right){
             int mid = (left + right)/2;

             if(temp[mid][0] > intervals[i][])
         }


         return {};
         */
        vector<int> ans;
        map<int, int> m{{INT_MAX, -1}};

        for (int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;

        for (int i = 0; i < intervals.size(); i++)
        {
            int endOfCurrentInterval = intervals[i][1];
            auto it = m.lower_bound(endOfCurrentInterval);
            ans.push_back(it->second);
        }
        return ans;
    }
};