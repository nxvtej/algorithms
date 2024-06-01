class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_index=0, max_diagonal=0,i=0;
        
        for(auto it: dimensions){
            if(sqrt((it[0]*it[0])+(it[1]*it[1]))>=max_diagonal){
                max_diagonal = sqrt((it[0]*it[0])+(it[1]*it[1]));
                max_index = i;
            }
            i++;
        }
        
//         step2: calculate area of rectangle 
        int area=0;
        auto it=dimensions[max_index];
        return it[0]*it[1];        
    }
};