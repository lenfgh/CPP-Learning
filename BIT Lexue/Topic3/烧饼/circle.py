import math

def circle_area(x, y, r):
    return math.pi * r * r

def is_overlap(x1, y1, r1, x2, y2, r2):
    distance = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
    return distance < r1 + r2

def union_area(circles):
    total_area = 0
    for i in range(len(circles)):
        x1, y1, r1 = circles[i]
        overlap_area = 0
        for j in range(i):
            x2, y2, r2 = circles[j]
            if is_overlap(x1, y1, r1, x2, y2, r2):
                overlap_area += circle_area(x2, y2, r2)
        total_area += circle_area(x1, y1, r1) - overlap_area
    return total_area

def main():
    n = int(input())
    circles = []
    for _ in range(n):
        x, y, r = map(int, input().split())
        circles.append((x, y, r))
    
    total_area = union_area(circles)
    print("%.3f" % total_area)

if __name__ == "__main__":
    main()