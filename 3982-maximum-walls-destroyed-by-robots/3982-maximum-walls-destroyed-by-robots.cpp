class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,vector<int>& walls) {
        int n=robots.size();
        // left[i]==maximum number of walls destroyed by i'th robot if fired on left side in the range (robot[i-1], robot[i]]. Excluding if any 'robot[i-1]'th position wall to avoid duplicates computing and similarly for right[i]
        // right[i]==maximum number of walls destroyed if fired on the right side. range is [robot[i], robot[i+1])
        // num[i]==number of walls lying between i'th robot and (i-1)'th robot including the walls at both robot position.

        // Why do we need num[i]?
        // Because if:

        // robot i-1 shoots right and robot i shoots left

        // their destruction regions may overlap as both may destroy some of the same walls.
        // Since walls are counted uniquely, we must avoid double counting.

        vector<int> left(n), right(n), num(n);
        unordered_map<int, int>robotsToDistance;    // All values in robots are unique so can use this
        for(int i=0;i<n;++i) robotsToDistance[robots[i]]=distance[i];
        
        sort(robots.begin(),robots.end());
        sort(walls.begin(),walls.end());

        int pos1, pos2, pos3, leftPos, rightPos;
        for(int i=0;i<n;++i) 
        {
            pos1=upper_bound(walls.begin(), walls.end(), robots[i])-walls.begin();
            if(i>=1) 
            {
                leftPos=lower_bound(walls.begin(), walls.end(),max(robots[i]-robotsToDistance[robots[i]],robots[i-1]+1)) - walls.begin();
            } 
            else leftPos=lower_bound(walls.begin(), walls.end(),robots[i] - robotsToDistance[robots[i]]) - walls.begin();
            
            left[i]=pos1-leftPos;

            pos2=lower_bound(walls.begin(), walls.end(), robots[i]) - walls.begin();
            if(i<n-1) 
            {
                rightPos=upper_bound(walls.begin(), walls.end(),min(robots[i]+robotsToDistance[robots[i]],robots[i+1]-1)) - walls.begin();
            } 
            else rightPos=upper_bound(walls.begin(), walls.end(),robots[i] + robotsToDistance[robots[i]]) - walls.begin();

            right[i]=rightPos-pos2;

            if(i==0) continue;

            pos3=lower_bound(walls.begin(),walls.end(),robots[i-1]) - walls.begin();
            num[i]=pos1-pos3;
        }
        int subLeft, subRight, currLeft, currRight;
        subLeft=left[0];   // Maximum unique walls destroyed by robots 0...i-1, with robot i-1 shooting LEFT.
        subRight=right[0]; // Maximum unique walls destroyed by robots 0...i-1, with robot i-1 shooting RIGHT.
        for(int i=1;i<n;++i) 
        {
            // currLeft --> If i'th robot is firing on left side
            // currRight --> If i'th robot is firing on right side

            // currLeft is bit tricky, It has two cases:
            // Case 1: Previous robot also shoots left
            // Ri-1 <----      ---- Ri              === contribution :   subLeft+left[i]

            // Case 2: Previous robot shoots right
            // Ri-1 ---->     <---- Ri              === contribution : subRight - right[i-1] (subtracted because subRight already has the contribution of right firing) + min(left[i]+right[i-1], num[i]) --> num[i] contains total unique number of walls Robot[i-1, i]
            
            currLeft=max(subLeft + left[i], subRight - right[i-1] + min(left[i]+right[i-1], num[i]));
            currRight=max(subLeft + right[i], subRight + right[i]);
            subLeft=currLeft;
            subRight=currRight;
        }
        return max(subLeft, subRight);
    }
};