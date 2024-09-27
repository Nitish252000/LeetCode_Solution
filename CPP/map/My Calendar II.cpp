class MyCalendarTwo {
public:
    vector<pair<int,int>>events;
    vector<pair<int,int>>overlaps;
    MyCalendarTwo() {
        
    }
    bool book(int start, int end) {
        //check for new events causes a triple booking
        for(auto ov:overlaps){
            int overlapStart = ov.first;
            int overlapEnd= ov.second;
            if(overlapStart <end && start <overlapEnd){
                // If the new event overlaps with any range in the 'overlaps', it would cause a triple booking
                return false; 
            }
        }
        //check for overlaps with all existing events
        for(auto ev:events){
            int startEvent = ev.first;
            int endEvent =ev.second;
            if(start<endEvent && startEvent<end){
                int overlapStart = max(start,startEvent);
                int overlapEnd = min(end,endEvent);
                overlaps.push_back({overlapStart,overlapEnd});
            }
        }
        // If no triple booking is detected, add the event to the list of events
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
