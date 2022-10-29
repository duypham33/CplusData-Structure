
/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section 01; Lab Section 06

      * Programming Assignment:     PA 1: Analyzing Fitbit Data

      * Date: September 1, 2021

      * Description: This program analyzes data that was generated from Fitbit devices:
                     - Read all the records of the target patient from the file.
                     - It filters any data that is not related to the target patient, parses each record into the corresponding fields,
                       and store into the FitbitData array. If some of the fields are “empty” or null, then perform data cleansing 
                       and insert values to construct a record that is consistent with the others; the data inserted should not represent valid values.
                     - Next, compute the total calories burned, distance walked in miles, floors walked, steps taken,
                       average heartrate over the 24 hour period, and  report the max steps taken in one minute over the 24 hour period
                       and the starting and ending minutes of the longest consecutive range of poor sleep.
                     - Open “Results.csv” for mode write to report the data and display to the screen as well.
                     
*/




#include "header.h"


int main(void)
{
    //Open the input .csv file
	FILE* infile = NULL;

    //Input file opened with read permisions “r”
	infile = fopen("FitbitData.csv", "r");

	if (infile == NULL)    //Check whether the input file was opened successfully or not
	{
		printf("Not Successfully Open The File!\n");
	}

    else
    {
        printf("Opened file successfully!\n");    //Opened the file successfully

        //Declare an array of size 1440 for fitbitdata
        FitbitData record[SIZE] = { {"", "", 0.0, 0.0, 0, 0, 0, NONE}};
        
        char line[100] = "";       //The string used to read the record line by line
        char* token_ptr = NULL;    //The char pointer used to split the string line read for the first line to get the patient ID
        int index = 0;             //The index for the record array 


        double totalCalor = 0.0;        //Total calories burned
        double totalDistance = 0.0;     //Total distance walked in miles
        int totalFloors = 0;            //Total floors walked
        int totalSteps = 0;             //Total steps taken

        int totalHeartRate = 0;         //Total heart rate during 24 hour period
        double averageHeartRate = 0.0;  //The average heartrate over the 24 hour period (Times/minute)

        int maxStep = 0;                //The max steps taken in one minute over the 24 hour period



        //First, read the target patient from the first line
        fgets(line, 100, infile);
        token_ptr = strtok(line, ",");

        char target[10] = "";    //The target ID
        strcpy(target, strtok(NULL, ","));    //Get the target patient

        fgets(line, 100, infile);     //Read in the header line - discard


        //Read all the filtered, deduped, and cleansed  record in the file 
        while (fgets(line, 100, infile) != NULL)
        {
            //Get the patient ID
            char id[10] = "";
            strcpy(id, strtok(line, ","));


            //If the record belongs to the target patient, continue filtering the next data in the record, otherwise it should be discarded
            if (strcmp(id, target) == 0)
            {
                strcpy(record[index].patient, id);   //Get the patient ID for the record[index]

                strcpy(record[index].minute, strtok(NULL, ","));    //Get the minute

                //We compare the minute with the previous minute to check whether this record is duplicated or not
                if (index > 0 && strcmp(record[index].minute, record[index - 1].minute) == 0)
                {
                    continue;   //This is duplicated record, so move on the next record
                }


                //The record is not duplicated, then analyze the next data in this record
                char* pToken = strtok(NULL, "");    //The char pointer used to split the string

                //Get the calories
                if (pToken[0] == ',')      //It means the calories is empty
                {
                    record[index].calories = D_INVALID;    //Insert the double invalid value 
                    remove_front(pToken, pToken);          //Remove the first character (',') out of the pToken
                }

                else    //Calories is not empty
                {
                    record[index].calories = atof(strtok(pToken, ","));       //Get the calories for the record[index]
                    totalCalor += record[index].calories;                 //Increment the total calories burned

                    pToken = strtok(NULL, "");
                }



                //Get the distance
                if (pToken[0] == ',')     //It means the distance is empty
                {
                    record[index].distance = D_INVALID;     //Insert the double invalid value 
                    remove_front(pToken, pToken);           //Remove the first character (',') out of the pToken
                }

                else       //Distance is not empty
                {
                    record[index].distance = atof(strtok(pToken, ","));     //Get the distance for the record[index]
                    totalDistance += record[index].distance;            //Increment the total distance walked

                    pToken = strtok(NULL, "");
                }



                //Get the floors
                if (pToken[0] == ',')     //It means the floors is empty
                {
                    record[index].floors = I_INVALID;      //Insert the integer invalid value 
                    remove_front(pToken, pToken);          //Remove the first character (',') out of the pToken
                }

                else      //The floors data is not empty
                {
                    record[index].floors = atoi(strtok(pToken, ","));     //Get the floors for the record[index]
                    totalFloors += record[index].floors;          //Increment the total floors walked

                    pToken = strtok(NULL, "");
                }



                //Get the heartRate
                if (pToken[0] == ',')    //It means the heartRate is empty
                {
                    record[index].heartRate = I_INVALID;     //Insert the integer invalid value 
                    remove_front(pToken, pToken);            //Remove the first character (',') out of the pToken
                }

                else     //The heartRate is not empty
                {
                    record[index].heartRate = atoi(strtok(pToken, ","));     //Get the heartRate for the record[index]
                    totalHeartRate += record[index].heartRate;           //Increment the total heartRate

                    pToken = strtok(NULL, "");
                }


                int check = 0;    //The flag to check whether the final data(sleep level) is empty or not
                int l = strlen(pToken);    //The length of the pToken string

                //Get the step data
                if (pToken[0] == ',')     //It means the step data is empty
                {
                    record[index].steps = I_INVALID;    //Insert the integer invalid value 
                    if (pToken[l - 1] == ',')     //It means the final data (sleep level) is empty
                        check = 1;    //It is empty, so check = 1 (true). Now, both the two final data(step and sleepLevel) are empty

                    else   //The final data is not empty
                        remove_front(pToken, pToken);   //Remove the first character (',') out of the pToken, then find the valid value of the final data

                }

                else   //The step data is not empty
                {
                    if (pToken[l - 1] == ',')   //It means the final data (sleep level) is empty
                    {
                        check = 1;   //It is empty, so check = 1 (true)

                        record[index].steps = atoi(pToken);   //Get the step data for the record[index]
                    }
                    

                    else  //The final data is not empty
                    {
                        record[index].steps = atoi(strtok(pToken, ","));   //Get the step data for the record[index]
                        
                        pToken = strtok(NULL, "");
                    }

                    totalSteps += record[index].steps;     //Increment the total steps taken

                    //Update the maximum steps of the latest minute
                    if (maxStep <= record[index].steps)     
                    {
                        maxStep = record[index].steps;
                    }
                }


                if (check == 1)     //It means the sleepLevel is empty
                {
                    record[index].sleepLevel = NONE;    //NONE type
                }

                else   //check == 0
                {
                    //If check == 1, then the sleepLevel is empty. But it does mean check == 0, then the sleepLevel must be empty. So we should check it
                    if (pToken[0] == ',')   //It means the sleepLevel is empty
                    {
                        record[index].sleepLevel = NONE;    //NONE type
                    }

                    else
                    {
                        record[index].sleepLevel = atoi(pToken);    //Get the sleepLevel for the record[index]
                    }
                }

                index++;    //Increment the index of the record array
            }
        }

        //Compute the average heartrate over the 24 hour period
        averageHeartRate = (double)totalHeartRate / 1440;    //Times per minute

        int start_index = 0, end_index = 0;   //The starting and ending record index of the longest consecutive range of poor sleep 
        int maxLength = longest_poorSleep_range(&start_index, &end_index, record);

        //Display the report to the screen
        printf("\n\n\t\t\tREPORT\n");
        printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
        printf("%lf,%lf,%d,%d,%.2lf,%d,%s:%s\n", totalCalor, totalDistance, totalFloors, totalSteps, averageHeartRate,
            maxStep, record[start_index].minute, record[end_index].minute);

        display(record);


        //Open the output file
        FILE* outfile = NULL;

        //Output file opened with read permisions “w”
        outfile = fopen("Results.csv", "w");


        //Write report to the out file
        fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
        fprintf(outfile, "%lf,%lf,%d,%d,%.2lf,%d,%s:%s\n", totalCalor, totalDistance, totalFloors, totalSteps, averageHeartRate,
            maxStep, record[start_index].minute, record[end_index].minute);

        report_to_file(outfile, record);
        


        fclose(outfile);   //Close the output file
    }


    fclose(infile);    //Close the input file

    
	return 0;    //The program was successful
}
