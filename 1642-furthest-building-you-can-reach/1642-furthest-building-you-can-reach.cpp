class Solution {
public:
    //min heap
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i=0;i<heights.size()-1;i++)
        {
            int climb=heights[i+1]-heights[i]; 
            if(climb<=0) continue; //jumping down
            minH.push(climb); //add ladder to min heap
            if(minH.size()<=ladders) continue; //all ladders are not used
            bricks-=minH.top(); //otherwise use bricks
            minH.pop();
            if(bricks<0) //no bricks left cnt move forward
                return i;
        }
        return heights.size()-1; //reached end 
    }
};