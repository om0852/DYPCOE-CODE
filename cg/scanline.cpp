#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void scanFill(int x[], int y[], int edges)
{
    int i, j, temp;
    int xmin = getmaxx(), xmax = 0;

    // Find the minimum and maximum x-coordinates of the polygon
    for (i = 0; i < edges; i++)
    {
        if (x[i] < xmin)
            xmin = x[i];
        if (x[i] > xmax)
            xmax = x[i];
    }

    // Scan each scan-line within the polygon's vertical extent
    for (i = xmin; i <= xmax; i++)
    {
        // Initialize an array to store the intersection points
        int interPoints[edges], count = 0;

        for (j = 0; j < edges; j++)
        {
            int next = (j + 1) % edges;

            // Check if the current edge intersects with the scan line
            if ((y[j] > i && y[next] <= i) || (y[next] > i && y[j] <= i))
            {
                interPoints[count++] = x[j] + (i - y[j]) * (x[next] - x[j]) / (y[next] - y[j]);
            }
        }

        // Sort the intersection points in ascending order
        for (j = 0; j < count - 1; j++)
        {
            for (int k = 0; k < count - j - 1; k++)
            {
                if (interPoints[k] > interPoints[k + 1])
                {
                    temp = interPoints[k];
                    interPoints[k] = interPoints[k + 1];
                    interPoints[k + 1] = temp;
                }
            }
        }

        // Fill the pixels between pairs of intersection points
        for (j = 0; j < count; j += 2)
        {
            line(interPoints[j], i, interPoints[j + 1], i);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x[] = {100, 200, 300};
    int y[] = {100, 300, 200};
    int edges = 3;

    scanFill(x, y, edges);

    delay(5000);
    closegraph();
    return 0;
}
