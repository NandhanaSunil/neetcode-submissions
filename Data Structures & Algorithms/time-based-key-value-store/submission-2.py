class TimeMap:

    def __init__(self):
        self.diction = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.diction:
            p = self.diction[key]
            p.append([value, timestamp])
            self.diction[key] = p
        else:
            self.diction[key] = [[value, timestamp]]

    def get(self, key: str, timestamp: int) -> str:
        if key in self.diction:
            possible = self.diction[key]
            n = len(possible)
            r = n-1
            l = 0
            while(l<=r) :
                mid = l + int((r-l)/2)
                if (possible[mid][1] <= timestamp):
                    if mid == n-1:
                        return possible[mid][0]
                    if (possible[mid+1][1] > timestamp):
                        return possible[mid][0]
                    else:
                        l = mid + 1
                else:
                    r = mid - 1
        return ""
            
        
