
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions 


char* remove_front(char* source, char* desination)
{
    int i = 0;

    for (i = 1; *(source + i) != '\0'; i++)
    {
        *(desination + i - 1) = *(source + i);
    }

    *(desination + i - 1) = '\0';

    return desination;
}





int longest_poorSleep_range(int* start_index, int* end_index, FitbitData record[])
{
    int length = 1;              //The length of the consecutive range of poor sleep
    int maxLength = 0;           //The max length
    int start = -1, end = -1;    //The starting and ending indexes of the poor sleep ranges

    int i = 0;   //The index used to traverse the array of sleep levels


    while (end < SIZE)
    {
        i = end + 1;

        //We find the next starting index of the poor sleep range
        while (record[i].sleepLevel < 2 && i < SIZE)
        {
            i++;
        }

        if (i == SIZE)
        {
            break;    //We finished traversing the array and no next poor sleep range found, so break the loop  
        }

        start = i;   //The next starting index is found as the result of the above while loop
        i = 1;       //Reset i = 1 to traverse the next loop
        length = 1;  //Reset the length to compute the length for the next range

        //Next, we find the ending index of the range and its length
        while (record[start + i].sleepLevel > 1 && start + i < SIZE)
        {
            length++;    //Increment the range length
            i++;
        }

        end = start + i - 1;   //The ending index is found as the result of the above while loop

        //Compare the lengths and update the max length, starting and ending indexes of the longest range
        if (length >= maxLength)
        {
            maxLength = length;
            *start_index = start;
            *end_index = end;
        }
    }

    return maxLength;    //Return the maximum length
}




void display(FitbitData record[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d) %s,%s,", i + 1, record[i].patient, record[i].minute);

        if (record[i].calories == D_INVALID)
        {
            printf("INVALID VALUE,");
        }
        else
        {
            printf("%lf,", record[i].calories);
        }


        if (record[i].distance == D_INVALID)
        {
            printf("INVALID VALUE,");
        }
        else
        {
            printf("%lf,", record[i].distance);
        }


        if (record[i].floors == I_INVALID)
        {
            printf("INVALID VALUE,");
        }
        else
        {
            printf("%d,", record[i].floors);
        }

        if (record[i].heartRate == I_INVALID)
        {
            printf("INVALID VALUE,");
        }
        else
        {
            printf("%d,", record[i].heartRate);
        }

        if (record[i].steps == I_INVALID)
        {
            printf("INVALID VALUE,");
        }
        else
        {
            printf("%d,", record[i].steps);
        }

        if (record[i].sleepLevel == NONE)
        {
            printf("NONE\n");
        }
        else
        {
            printf("%d\n", record[i].sleepLevel);
        }
    }
}



void report_to_file(FILE* outfile, FitbitData record[])
{
    for (int i = 0; i < SIZE; i++)
    {
        fprintf(outfile, "%s,%s,", record[i].patient, record[i].minute);

        if (record[i].calories == D_INVALID)
        {
            fprintf(outfile, "INVALID VALUE,");
        }
        else
        {
            fprintf(outfile, "%lf,", record[i].calories);
        }


        if (record[i].distance == D_INVALID)
        {
            fprintf(outfile, "INVALID VALUE,");
        }
        else
        {
            fprintf(outfile, "%lf,", record[i].distance);
        }


        if (record[i].floors == I_INVALID)
        {
            fprintf(outfile, "INVALID VALUE,");
        }
        else
        {
            fprintf(outfile, "%d,", record[i].floors);
        }

        if (record[i].heartRate == I_INVALID)
        {
            fprintf(outfile, "INVALID VALUE,");
        }
        else
        {
            fprintf(outfile, "%d,", record[i].heartRate);
        }

        if (record[i].steps == I_INVALID)
        {
            fprintf(outfile, "INVALID VALUE,");
        }
        else
        {
            fprintf(outfile, "%d,", record[i].steps);
        }

        if (record[i].sleepLevel == NONE)
        {
            fprintf(outfile, "NONE\n");
        }
        else
        {
            fprintf(outfile, "%d\n", record[i].sleepLevel);
        }
    }
}