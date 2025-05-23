class Solution {
public:
    // Consider array 
    // [x, y, z, a, b, c]
    // Let k be 3. 
    // [x, y, z, a, b, c]
    // |     |         - Let this Sum be A (x + y + z)
    // Now slide window
    // [x, y, z, a, b, c]
    //     |     |      - Let this Sum be B (A - x + a)
    // Here Sum of this subarray B can be equal to A only if a is equal to x.

    // There is one caveat yet to make the argument complete: In this problem arr is not only a regular array but also a circular array.
    // Suppose n = 6 and k = 4, we need to have every gcd(n, k) = gcd(6, 4) = 2-th element of arr to be equal after all operations.

    // linear congruences: ax ≡ b (mod n) has solution if and only if gcd(a, n) divides b.
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans=0;
        int n=arr.size();
        k=__gcd(n,k);
        
        for(int i=0;i<k;++i)
        {
            vector<int>temp;
            
            for(int j=i;arr[j]!=0;j=(j+k)%n)  // Now check for each of the index in the 'k'
            {
                temp.push_back(arr[j]);
                arr[j]=0;
            }
        // e.g., for arr=[1,3,7,5,2,9] and let k==2.Then for i=0, temp==[1,7,2]Now for this temp, It's always wiser to make values equal to median.
            sort(temp.begin(),temp.end());
            int val=temp[temp.size()/2]; // It's always wiser to make the values equal to median value. so, that It'll cost us minimum.
            
            for(int j=0;j<temp.size();++j) ans+=abs(temp[j]-val);
        }
        return ans;
    }
};