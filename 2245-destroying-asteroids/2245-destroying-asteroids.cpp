class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();

        for(int i=0;i<n;++i)
        {
            if(asteroids[i]>mass) return false;

            if(mass<1e8) mass+=asteroids[i];
        }
        return true;
    }
};