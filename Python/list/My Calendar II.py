class MyCalendarTwo:

    def __init__(self): 
        self.events=[]
        self.overlaps=[]

    def book(self, start: int, end: int) -> bool:
        # Step 1: Check if the new event overlaps with any of the previously double-booked intervals
        for ov in self.overlaps:
            overlapStart = ov[0]
            overlapEnd=ov[1]
            if overlapStart<end and start<overlapEnd:
                return False
        # Step 2: Check for new overlaps with existing events and update 'overlaps' list     
        for ev in self.events:
            eventStart = ev[0]
            eventEnd = ev[1]
            if start<eventEnd and eventStart<end:
                overlapStart = max(start, eventStart)
                overlapEnd= min(end,eventEnd)
                self.overlaps.append((overlapStart, overlapEnd))
        # Step 3: No triple booking found, so add the new event to 'events' list
        self.events.append((start,end))
        return True

# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
