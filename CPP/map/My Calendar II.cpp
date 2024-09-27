/*
Approach
1./ Booking a New Event:
When a new event [start, end) is added, it is first checked against the list of previously overlapped intervals (overlaps). These intervals represent ranges where two events are already overlapping.

2./ Checking for Triple Booking:
If the new event overlaps with any of the stored intervals in overlaps, that means there will be a triple booking in that time range, so we return false.

3./ Updating Overlap List:
If no triple booking is found, we then check the new event against the list of existing events to see if it overlaps with any of them. If it does, the intersection (overlap) of these two events is calculated and stored in the overlaps list for future checks.

4./ Adding the Event:
Finally, if no triple booking is detected, the new event is added to the list of events.
*/
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
