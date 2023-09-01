// Angelina Toste

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool prefersZoverX( unsigned char Y[4][4], int y, int x, int z)
{
    // determines if the woman prefers her current partner Z over X (the man proposing)
    for (int i = 0; i < 4; i++)
    {
        if (Y[y-1][i] == z)
        {
            return true;
        }

        if (Y[y-1][i] == x + 65)
        {
            return false;
        }

    }
    return false;
}

bool manIsFree( int engagements[][4], int x)
{
    // determines if the man listed in engagements is free
    // returns true if he is free and false if not free
    x = x + 65;

    for(int j = 0; j < 4; j++)
    {
        if(engagements[j][1] == x)
        {
            return false;
        }
    }
    return true;
}

bool womanIsFree( int engagements[][4], int y)
{
    // determines if the woman listed in engagements is free
    // returns true if she is free and false if not free
    for (int i = 0; i < 4; i++)
    {
        if (engagements[i][0] == y )
        {
            if (engagements[i][1] == -1)
            {
                return true;
            }
            else
            {
                return false;
            }

        }

    }
    return false;
}

void outputPrinter (int engagements[][4])
{
    // Printing the output for the function in alphabetical order
    int printCounter = 0;
    while (printCounter < 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (engagements[i][1] == 65 + printCounter)
            {
                printf("%c%i\n", engagements[i][1], engagements[i][0]);
                printCounter++;
            }
        }
    }
}


void StableMarraige(int X[][4], unsigned char Y[][4])
{
    // Record of who is free and who is engaged
    // -1 denotes that a woman is free
    int engagements[][4] =
        {
            {1, -1},
            {2, -1},
            {3, -1},
            {4, -1},
        };

    // this will keep track of how many men are still free
    int freeCounter = 4;

    // while there exist free men
    while (freeCounter > 0)
    {
        //pick the first free man in the list
        int x = 0;
        while (x < 4)
        {
            if (manIsFree(engagements, x))
            {
                // this person is free
                break;
            }
            x++;
        }

        // go to each of the women in the man's preference list, one at a time
        int i = 0;
        while (i < 4 && manIsFree(engagements, x))
        {
            //y is x's highest ranked woman
            int y = X[x][i];

           // if the woman is free, make a match and record it
           if (womanIsFree(engagements, y))
           {
               engagements[y-1][1] = x + 65;
               freeCounter--;
           }
           else
           {
               // if the woman is not free, find out who her partner is and compare

                int z = engagements[y-1][1];

                // if the woman prefers the man proposing over her current partner
                if (!prefersZoverX(Y, y, x, z))
                {
                    // make a new match and swap the men the woman is paired with (making her old partner now free)
                    engagements[y-1][1] = x + 65;
                }
           }

           i++;

        }
    }
    outputPrinter(engagements);
}

int main()
{

    int X[4][4] = {};

    unsigned char Y[4][4] = {};




    FILE *stream;
    if ((stream = fopen("hw9.in","r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    for(int n = 0; n < 8; n++)
    {
    	if (n < 4)
    	{
            char P;
            int C1, C2, C3, C4;
            fscanf(stream, "%c %i %i %i %i\n", &P, &C1, &C2, &C3, &C4);

            X[P - 65][0] = C1;
            X[P - 65][1] = C2;
            X[P - 65][2] = C3;
            X[P - 65][3] = C4;

    	}
    	else if (n >= 4)
        {
            int P;
            char C1, C2, C3, C4;
            fscanf(stream, "%i %c %c %c %c\n", &P, &C1, &C2, &C3, &C4);

            Y[P-1][0] = C1;
            Y[P-1][1] = C2;
            Y[P-1][2] = C3;
            Y[P-1][3] = C4;
        }
    }
    fclose(stream);

    StableMarraige(X, Y);

    return 0;
}
