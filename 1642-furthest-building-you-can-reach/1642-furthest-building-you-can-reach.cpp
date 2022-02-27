class Solution {
public:
    //min heap
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxH;
        for(int i=0;i<heights.size()-1;i++)
        {
            int climb=heights[i+1]-heights[i]; 
            if(climb<=0) continue; //going down
            maxH.push(climb); // adding ladder
            bricks-=climb;
            if(bricks<0 and ladders==0) return i; // used all bricks and no ladders remaining
            if(bricks<0) // bricks used then replace largest brick allocation with ladder
            {
                bricks+=maxH.top();
                maxH.pop();
                ladders--;
            }
        }
        return heights.size()-1; //reached end 
    }
};