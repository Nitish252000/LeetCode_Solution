class MyCalendarTwo:

    def __init__(self): 
        self.events=[]
        self.overlaps=[]

    def book(self, start: int, end: int) -> bool:
        for ov in self.overlaps:
            overlapStart = ov[0]
            overlapEnd=ov[1]
            if overlapStart<end and start<overlapEnd:
                return False
        ## check for overlaps with all existing events     
        for ev in self.events:
            eventStart = ev[0]
            eventEnd = ev[1]
            if start<eventEnd and eventStart<end:
                overlapStart = max(start, eventStart)
                overlapEnd= min(end,eventEnd)
                self.overlaps.append((overlapStart, overlapEnd))
        self.events.append((start,end))
        return True

# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
