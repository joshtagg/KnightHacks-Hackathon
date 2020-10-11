//Joshua Taggart
//covid symtpom tracker, prints receipt as txt

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
    printf("\t1 - 2 Week Symptom Day Tracker\n"); //loop for each day that they had symptoms, then ask what symptom was for each day
    printf("\t1 - Menu 2\n");
    printf("\t1 - Menu 3\n");
    scanf("%d", &menu_num);

    //manages user menu options
    switch (menu_num) {
        case 1:
            printf("You selected menu 1.\n");
            flag1 = 1;
            break;
        case 2:
            printf("You selected menu 2.\n");
            flag2 = 1;
            break;
        case 3:
            printf("You selected menu 3.\n");
            flag3 = 1;
            break;
        default:
            printf("Not a valid option.\n");
            break;
    }

    //have if loop for each flag
    if (flag1) {
        printf("How many days did you experience symptoms?\n");
        scanf("%d", &num_days);

        for (i = 0; i < num_days; i++) {
            printf("How many symptoms did you experience on day %d?\n", i+1);
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

                printf("Which symptom(s) did you experience on day %d?: ", i+1);
                scanf("%d", &sym_array[counter]);
                counter = counter + 1;
                //counter makes sure each symptom # is going in array in order starting at sym_array[0]
            }
        }

    }

    //rank out of top 6, symptoms: first_occ, sec_occ, third_occ, four_occ, fif_occ, six_occ
    //fprintf(ofp, "Your most occurring symptoms were in this order:")

    /*
    //deletes all 0's from array
    for (i = 0, j = 0; i < 84; i++) {
        if (sym_array[i] == 0)
            sym_array[i] = sym_array[i + 1];
    }
    */

    //deletes all preset 0's from array
    //does not actually remove 0's from array, just learns to ignore them
    //j becomes new length of array, ignoring all 0's that appear after it
    for (i = 0, j = 0; i < 84; i++) {
        if (sym_array[i] != 0) {
            sym_array[j++] = sym_array[i];
        }
    }

    //prints new array (test purpose)
    for (i = 0; i < j; i++) {
        printf("Index %d: %d\n", i, sym_array[i]);
    }

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

    printf("Your most occurring symptom is %d which appears %d times\n", first_occ, count);

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



    //fclose(ofp);
    return 0;
}
