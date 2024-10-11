#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define NUM_PARTS 6
int flag_parts[NUM_PARTS][20] = {
    {70, 76, 65, 71, 45, 82, 65, 73, 68, 123},
    {71, 51},                               
    {84, 45, 65, 45},                      
    {76, 49},
    {70, 51},
    {45, 66, 85, 68, 125}
};
char questions[NUM_PARTS][100] = {
    "Question 1: What is 2 + 2?",
    "Question 2: What is the capital of France?",
    "Question 3: Who wrote 'Romeo and Juliet'?",
    "Question 4: What is the chemical symbol for water?",
    "Question 5: What planet is known as the Red Planet?",
    "Question 6: What is the largest mammal on Earth?"
};
char correct_answers[NUM_PARTS][20] = {
    "4", "Paris", "Shakespeare", "H2O", "Mars", "Blue Whale"
};
int wait_times[NUM_PARTS] = {5, 10, 20, 40, 80, 160};
void clear_screen() {
    printf("\033[2J\033[H");
}
void get_flag_part(int ascii_values[], char *output) {
    int i = 0;
    while (ascii_values[i] != 0 && i < 20) {
        output[i] = (char)ascii_values[i];
        i++;
    }
    output[i] = '\0';
}
int main() {
    char answer[100];
    char revealed_flag[100] = "";    
    char part[20];
    
    for (int i = 0; i < NUM_PARTS; i++) {
        clear_screen();
        printf("Current flag: %s\n\n", revealed_flag);
        printf("%s\n", questions[i]);
        printf("Enter your answer: ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0;
        printf("\nWaiting for %d seconds...\n", wait_times[i]);
        for (int j = wait_times[i]; j > 0; j--) {
            printf("\rTime remaining: %d seconds", j);
            fflush(stdout);
            sleep(1);
        }
        printf("\n\n");
        if (strcmp(answer, correct_answers[i]) == 0) {
            get_flag_part(flag_parts[i], part);
            strcat(revealed_flag, part);
            printf("Correct! Flag part revealed.\n");
        } else {
            printf("Incorrect. Try again from the beginning.\n");
            sleep(2);
            return 1;
        }
        sleep(2);
    }    
    clear_screen();
    printf("Congratulations! You've revealed the entire flag:\n%s\n", revealed_flag);    
    return 0;
}

