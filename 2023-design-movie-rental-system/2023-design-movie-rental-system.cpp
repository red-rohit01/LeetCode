class MovieRentingSystem {
public:
    vector<set<pair<int,int>>>available = vector<set<pair<int,int>>>(10001);  // List of available movies which are not rented
    vector<set<pair<int,int>>>getPrice = vector<set<pair<int,int>>>(10001);
    set<pair<int,pair<int,int>>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &v:entries)
        {
            available[v[1]].insert({v[2],v[0]});   // {movie_name-->{price,shop_no}}
            getPrice[v[1]].insert({v[0],v[2]});      // {movie_name-->{shop_no, price}}
        }
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
        int cnt=0;
        for(auto &x:available[movie])
        {
            ans.push_back(x.second);
            cnt++;
            if(cnt==5) break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        auto it=getPrice[movie].lower_bound({shop,INT_MIN});
        int price= (*it).second;

        available[movie].erase({price,shop});
        rented.insert({price,{shop,movie}});
    }
    
    void drop(int shop, int movie) {
        auto it=getPrice[movie].lower_bound({shop,INT_MIN});
        int price= (*it).second;

        available[movie].insert({price,shop});
        rented.erase({price,{shop,movie}});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        int cnt=0;
        for(auto &x:rented)
        {
            ans.push_back({x.second.first,x.second.second});
            cnt++;
            if(cnt==5) break;
        }
        return ans;
    }
};
/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

//fast i/o
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);