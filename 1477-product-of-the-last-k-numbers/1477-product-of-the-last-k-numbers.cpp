class ProductOfNumbers {
public:
    int total=0;
    int highest_0=0;
    int curr=1;
    vector<int>prod;
    ProductOfNumbers() {
        total=0;
        highest_0=0;
        curr=1;
    }
    
    void add(int num) {
        total++;
        if(num==0)
        {
            highest_0=total;
            curr=1;
        }
        else curr*=num;

        prod.push_back(curr);
    }
    
    int getProduct(int k) {
        int ind=(total-highest_0);
        if(k>ind) return 0;

        int ans=prod[total-1];
        int last=total-k;

        if((last-1)>=0) ans/=prod[last-1];
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */