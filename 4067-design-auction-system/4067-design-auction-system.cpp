class AuctionSystem {
public:
    // addBid/updateBid: O(log k) where k is the number of users bidding on this item (set insertion/deletion)
    // removeBid: O(log k) for set removal
    // getHighestBidder: O(1) - just access the last element of the set
    // Space: O(n) where n is the total number of active bids
    
    unordered_map<int,unordered_map<int,int>>mp;        // stores mapping of 'item' and their corresponding {userId, bidAmount}
    unordered_map<int,set<pair<int,int>>>q;             // stores mapping of 'item' and their corresponding {bidAmount, userId}
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(mp[itemId].count(userId)) q[itemId].erase({mp[itemId][userId], userId});

        mp[itemId][userId]=bidAmount;
        q[itemId].insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        q[itemId].erase({mp[itemId][userId], userId});
        mp[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if(q[itemId].empty()) return -1;

        return q[itemId].rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */