#include <stdio.h>
#include <math.h>
int IsPointInBoundingBox(int x1, int y1, int x2, int y2, int px, int py)

{

    int left, top, right, bottom; // Bounding Box For Line Segment

    // For Bounding Box

    if(x1 < x2)

    {

        left = x1;

        right = x2;

    }

    else

    {

        left = x2;

        right = x1;

    }

    if(y1 < y2)

    {

        top = y1;

        bottom = y2;

    }

    else

    {

        top = y1;

        bottom = y2;

    }

 

    if( (px+0.01) >= left && (px-0.01) <= right && 

            (py+0.01) >= top && (py-0.01) <= bottom )

    {

        return 1;

    }

    else

        return 0;

}

 

int LineIntersection(int l1x1, int l1y1, int l1x2, int l1y2,

                            int l2x1, int l2y1, int l2x2, int l2y2,

                            int *m1, int *c1, int *m2, int *c2,

                            int* intersection_X, int* intersection_Y)

{

    int dx, dy;

 

    dx = l1x2 - l1x1;

    dy = l1y2 - l1y1;

 

    *m1 = dy / dx;

    // y = mx + c

    // intercept c = y - mx

    *c1 = l1y1 - *m1 * l1x1; // which is same as y2 - slope * x2

 

    dx = l2x2 - l2x1;

    dy = l2y2 - l2y1;

 

    *m2 = dy / dx;

    // y = mx + c

    // intercept c = y - mx

    *c2 = l2y1 - *m2 * l2x1; // which is same as y2 - slope * x2

 

    if( (*m1 - *m2) == 0)

        return 0;

    else

    {

        *intersection_X = (*c2 - *c1) / (*m1 - *m2);

        *intersection_Y = *m1 * *intersection_X + *c1;

    }

}

 

int LineSegmentIntersection(int l1x1, int l1y1, int l1x2, int l1y2,

                            int l2x1, int l2y1, int l2x2, int l2y2,

                            int *m1, int *c1, int *m2, int *c2,

                            int* intersection_X, int* intersection_Y)

{

    int dx, dy;

 

    dx = l1x2 - l1x1;

    dy = l1y2 - l1y1;

 

    *m1 = dy / dx;

    // y = mx + c

    // intercept c = y - mx

    *c1 = l1y1 - *m1 * l1x1; // which is same as y2 - slope * x2

 

    dx = l2x2 - l2x1;

    dy = l2y2 - l2y1;

 

    *m2 = dy / dx;

    // y = mx + c

    // intercept c = y - mx

    *c2 = l2y1 - *m2 * l2x1; // which is same as y2 - slope * x2

 

    if( (*m1 - *m2) == 0)

        return 0;

    else

    {

        *intersection_X = (*c2 - *c1) / (*m1 - *m2);

        *intersection_Y = *m1 * *intersection_X + *c1;

    }

    if(IsPointInBoundingBox(l1x1, l1y1, l1x2, l1y2, *intersection_X, *intersection_Y) == 1 &&

        IsPointInBoundingBox(l2x1, l2y1, l2x2, l2y2, *intersection_X, *intersection_Y) == 1)

        return 1;

    else

        return 0;

}

 

int main()

{

    int m1, c1, m2, c2;

    int l1x1, l1y1, l1x2, l1y2;

    int l2x1, l2y1, l2x2, l2y2;

    int intersection_X, intersection_Y;

    int nRet;

 

    

    scanf("%f %f", &l1x1, &l1y1);

    scanf("%f %f", &l1x2,&l1y2);

    scanf("%f %f", &l2x1,&l2y1);
 
    scanf("%f %f", &l2x2, &l2y2);

 

 

    nRet = LineSegmentIntersection(l1x1, l1y1, l1x2, l1y2,

                            l2x1, l2y1, l2x2, l2y2,

                            &m1, &c1, &m2, &c2, &intersection_X, &intersection_Y);

 

    if(nRet == 0)

        printf("Line segments do not intersect");

    else

        printf("Line segments intersect");

    return 0;

 

}