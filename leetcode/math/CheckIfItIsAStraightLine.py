class Solution:
    def checkStraightLine(self, c: List[List[int]]) -> bool:
        if len(c) == 2:
            return True

        print(c)
        p0 = c[0]
        p1 = c[1]

        slope = 0
        if p1[0]-p0[0] == 0:
            #if diff is zero -> one vertical line -> all x are the same
            for i in c:
                if p0[0] != i[0]:
                    return False
            return True
        else:
            slope = (p1[1] - p0[1]) / (p1[0]- p0[0])
        #y = mx+n <=> y - mx = n
        n = p0[1] - slope*p0[0]

        print(slope)
        counter = 0
        for i in c:
            x,y = i
            py = slope*x + n
            if py != y:
                return False

        return True
