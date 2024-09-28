class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        def calcArea(point1, point2, point3):
            first = point1[0] * (point2[1] - point3[1])
            second = point2[0] * (point3[1] - point1[1])
            third = point3[0] * (point1[1] - point2[1])
            return 0.5 * abs(first + second + third)
        res = 0
        for i in range(len(points)-2):
            for j in range(i+1, len(points)-1):
                for k in range(j+1, len(points)):
                    res = max(res, calcArea(points[i], points[j], points[k]))
        return res
