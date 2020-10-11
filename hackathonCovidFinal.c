//Joshua Taggart
//covid symtpom tracker program
//my extremely basic program that took longer than it should have to make

#include <stdio.h>

int main() {
    int menu_num, flag1 = 0, flag2 = 0, flag3 = 0, i, j, k, num_days, num_sym;
    char file_name[100];
    int sym_array[84], counter = 0;
    //84 is the max number of symptoms for a 2 week period

    //Scrapped Idea 1: Having symptom results printed in .txt file. Receipt-like format.
    /*
    printf("Where do you want to export your Covid Information?");
    scanf("%s", &file_name);

    FILE * ofp;
    ofp = fopen(file_name, "w");
    */


    //initialize array
    for (k = 0; k < 84; k++) {
        sym_array[k] = 0;
    }


    //menu
    printf("Menu Phrase:\n");
    printf("\t1 - 2 Week Symptom Day Tracker\n");
    printf("\t2 - Covid Safety Measures\n");
    printf("\t3 - Quit\n");
    scanf("%d", &menu_num);

    //manages user menu options
    while (menu_num != 3) {
        switch (menu_num) {
            case 1:
                printf("You selected the Symptom Tracker.\n");
                printf("How many days did you experience symptoms?: ");
                scanf("%d", &num_days);

                for (i = 0; i < num_days; i++) {
                    printf("How many symptoms did you experience on day %d?: ", i+1);
                    scanf("%d", &num_sym);

                    for (j = 0; j < num_sym; j++) {
                        printf("--------------------------------------------------\n");
                        printf("\t1 - Sore Throat / Cough\n");
                        printf("\t2 - Fever or chills\n");
                        printf("\t3 - Shortness of breath or difficulty breathing\n");
                        printf("\t4 - Fatigue\n");
                        printf("\t5 - Muscle or body aches\n");
                        printf("\t6 - Headache\n");
                        printf("--------------------------------------------------\n");

                        printf("\nWhich symptom(s) did you experience on day %d?: ", i+1);
                        scanf("%d", &sym_array[counter]);
                        counter = counter + 1;
                        //counter makes sure each symptom # is going in array in order starting at sym_array[0]
                    }
                }

                //deletes all preset 0's from array
                //does not actually remove 0's from array, just learns to ignore them
                //j becomes new length of array, ignoring all 0's that appear after it
                for (i = 0, j = 0; i < 84; i++) {
                    if (sym_array[i] != 0) {
                        sym_array[j++] = sym_array[i];
                    }
                }

                /*
                //prints new array (test purpose)
                for (i = 0; i < j; i++) {
                    printf("Index %d: %d\n", i, sym_array[i]);
                }
                */

                //finds first most occurring symptom
                int first_occ = 0;
                int count = 0;
                for (i = 0; i < j; i++) {
                    int tempMax1 = sym_array[i];
                    int tempCount1 = 0;

                    for (k = 0; k < j; k++) {
                        if (sym_array[k] == tempMax1) {
                        tempCount1++;
                        }
                    }
                    if (tempCount1 > count) {
                        first_occ = tempMax1;
                        count = tempCount1;
                    }
                }

                //did not solve problem of 2 different symptoms occurring for the same amount of time

                printf("Your most occurring symptom is %d which occurs %d times throughout %d days\n", first_occ, count, num_days);
                break;
            case 2:
                printf("Covid Safety Measures:\n");
                printf("Wash your hands often.\n");
                printf("\t- If soap and water are not readily available, use a hand sanitizer that contains at least 60 percent alcohol.\n");
                printf("\t- Avoid touching your eyes, nose, and mouth with unwashed hands.\n");
                printf("Avoid close contact.\n");
                printf("\t- Inside your home: Avoid close contact with people who are sick.\n");
                printf("\t- Outside your home: Put 6 feet of distance between yourself and people who don't live in your household.\n");
                printf("Cover your mouth and nose with a mask when around others.\n");
                printf("Cover coughs and sneezes.\n");
                printf("Clean and disinfect.\n");
                printf("\t- Clean AND disinfect frequently touched surfaces daily.\n");
                printf("Monitor your health daily.\n");
                printf("\t- Be alert for symptoms.\n");
                printf("\t- Take your temperature if symptoms develop.\n");
                printf("(All guidance taken from the CDC)\n");
                break;
            case 3:
                printf("Goodbye\n");
                break;
            default:
                printf("Not a valid option.\n");
                break;
        } //end of switch statement

        //reprint main menu
        printf("Menu Phrase:\n");
        printf("\t1 - 2 Week Symptom Day Tracker\n");
        printf("\t2 - Covid Safety Measures\n");
        printf("\t3 - Quit\n");
        scanf("%d", &menu_num);

    } //end of while loop

    return 0;
} //end of main



    //Scrapped Idea 2: finding second and third highest occurring num in array
    /*
    //removes second highest occurring number
    //k will become new length of array
    for (i = 0; k = 0; i < j) {
        if (sym_array[i] != first_occ) {
            sym_array[k++] = sym_array[i];
        }
    }

    //prints new array (test purpose)
    for (i = 0; i < k; i++) {
        printf("Index %d: %d\n", i, sym_array[i]);
    }

    int sec_occ = 0;
    int count2 = 0;
    for (i = 0; i < k; i++) {
        int tempMax2 = sym_array[i];
        int tempCount2 = 0;

        for (j = 0; j < k; j++) {
            if (sym_array[k] == tempMax2) {
                tempCount2++;
            }
        }
        if (tempCount2 > count2) {
            sec_occ = tempMax2;
            count2 = tempCount2;
        }
    }

    printf("Your second most occurring symptom is %d which appears %d times\n", sec_occ, count2);
    */


