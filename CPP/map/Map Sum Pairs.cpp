class MapSum {
public:
    unordered_map<string, int> mp;
    MapSum() {}

    void insert(string key, int val) { mp[key] = val; }

    int sum(string prefix) {
        int total = 0;
        // auto it=mp.lower_bound(prefix);
        // while(it!=mp.end() && it->first.substr(0,prefix.size())==prefix){
        //     total+=it->second;
        //     it++;
        // }
    // Using Iterators : Use it->first and it->second to access elements pointed to by iterators.
            // for(auto it:mp){
            //     if(it.first.substr(0,prefix.size())==prefix){
            //         total+=it.second;
            //     }
            // }
    
    //Using Range-Based For Loops: Use entry.first and entry.second to access elements directly since entry is a reference to the std::pair object.
            for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->first.substr(0, prefix.size()) == prefix) {
                total += it->second;
            }
        }
        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
