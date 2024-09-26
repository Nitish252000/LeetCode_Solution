class MyCalendar {
public:
    MyCalendar() {
        
    }
    unordered_map<int,int>mp;
    bool book(int start, int end) {
        if(mp.size()==0){
            mp[start]=end;
            return true;
        }
     // Check for conflicts with existing events
        for(auto it:mp){
            int s = it.first;
            int e = it.second;
         // If the new event overlaps with an existing one, return false
            if(start<e && s<end){
                return false;
            }
        }
      // If no conflict, add the new event
        mp[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
