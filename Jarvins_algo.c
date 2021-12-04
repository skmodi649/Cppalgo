#include<stdio.h>
#include<stdlib.h>

struct Point
{
	int x, y;
};


int orientation(struct Point p, struct Point q, struct Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // collinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

// Prints convex hull of a set of n points.
void convexHull(struct Point points[], int n)
{
	// There must be at least 3 points
	if (n < 3) return;


	// Find the leftmost point
	int l = 0;
    struct Point hull[n];
    int len = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;

	
	int p = l, q;
	do
	{
		// Add current point to result
		hull[len] = points[p];
        len++;

		
		q = (p+1)%n;
		for (int i = 0; i < n; i++)
		{
		
		if (orientation(points[p], points[i], points[q]) == 2)
			q = i;
		}

	
		p = q;

	} while (p != l); // While we don't come to first point

	// Print Result
	for (int i = 0; i < len-1; i++){
		printf("%d %d",hull[i].x,hull[i].y);
		printf("\n");
	}
}

// Driver program to test above functions
int main()
{
	struct Point points[] = {{1, 2}, {1, 9}, {2, 2}, {2, 5},
					{2, 7}, {3, 5}, {4, 3}, {5, 4}, {5, 6}, {6, 4}};
	int n = sizeof(points)/sizeof(points[0]);
	convexHull(points, n);
	return 0;
}
