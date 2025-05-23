class Solution
{
public:
	long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
	{
		// In the first pass through the numbers we calculate the current total
		// and keep track of the deltas if the xor is applied to each node
		vector<int>negativeDeltas;
		vector<int>positiveDeltas;
		long long ans=0;
		for(auto& n:nums)
		{
			ans+=n;
			int after=n^k;
			if (after>n) positiveDeltas.push_back(after-n);

			else negativeDeltas.push_back(n-after);
		}
        // Nice explanation by Aryan.
		sort(negativeDeltas.begin(),negativeDeltas.end());
		sort(positiveDeltas.begin(),positiveDeltas.end());
        int n=positiveDeltas.size();
		bool evenNumPositives=(n%2==0);                        // If it is even then we can pair each of those values.
		// If there is a node which can be made greater, but can't be paired 
		// (because there are an odd number of positive nodes)
		// then we can either decide not pair the smallest one, or
		// pair it with the smallest negative if the positive delta
		// outwieghs the negative delta.
		if (!evenNumPositives && !negativeDeltas.empty())
		{
			if (positiveDeltas[0]>negativeDeltas[0]) ans+=(positiveDeltas[0]-negativeDeltas[0]);
		}

		// We always pair as many positives as we can, adding their deltas to the total
		for (int i=(evenNumPositives?0:1);i<n;++i) ans+=positiveDeltas[i];

		return ans;
	}
};