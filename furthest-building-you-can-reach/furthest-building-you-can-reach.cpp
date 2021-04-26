class Solution {

public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if (heights.size() == 0)
            return 0;
        priority_queue<int> heap;
        for (int i=0; i < heights.size()-1; ++i) {
            if (heights[i] < heights[i+1])
            {
                heap.push(heights[i] - heights[i+1]);
                cout << heights[i] << " " << heights[i+1] << endl;
            }
            if (heap.size() > ladders){
                bricks += heap.top();
                heap.pop();
            }
            
            if (bricks < 0)
                return i;
        }
        
        return heights.size() - 1;
    }
};