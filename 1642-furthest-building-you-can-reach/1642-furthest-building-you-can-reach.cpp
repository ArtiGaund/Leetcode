class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxH;
        for(int i=0;i<heights.size()-1;i++)
        {
            int climb=heights[i+1]-heights[i];
            if(climb<=0) continue;
            maxH.push(climb);
            bricks-=climb;
            if(bricks<0 and ladders==0) return i;
            if(bricks<0)
            {
                bricks+=maxH.top();
                maxH.pop();
                ladders--;
            }
            
        }
        return heights.size()-1;
    }
};