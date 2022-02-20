#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define LEN 1000
#define STR 512

struct questions
{
    char ques[LEN][LEN];
    char options[LEN][LEN];
    char answers[LEN];
};

int lives = 3;

int main(void)
{
    struct questions questions;

    // category computer trivia
    static const char filename[] = "ques.txt";
    static const char filename1[] = "options.txt";
    static const char filename2[] = "crctans.txt";
    FILE *file = fopen(filename, "r");
    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");

    int i, j = 0, k = 0, m, n = 0, _randno, scrptr = 0;
    int x, f;
    char choice, ch;
    int temp, scorefinal, run = 1, answered = 0, consent;

    // importing computer trivia questions

    if (file != NULL)
    {
        while (fgets(questions.ques[k], STR, file) != NULL)
        {
            questions.ques[k][strlen(questions.ques[k]) - 1] = '\0';
            k++;
        }
        i = k;
        fclose(file);
    }
    else
    {
        perror(filename);
    }

    if (file1 != NULL)
    {
        while (fgets(questions.options[j], STR, file1) != NULL)
        {
            questions.options[j][strlen(questions.options[j]) - 1] = '\0';
            j++;
        }
        m = j;
        fclose(file1);
    }
    else
    {
        perror(filename1);
    }

    if (file2 != NULL)
    {
        while ((ch = fgetc(file2)) != EOF)
        {
            questions.answers[n] = ch;
            n++;
        }
        questions.answers[n] = '\0';
        fclose(file2);
    }
    else
    {
        perror(filename2);
    }

    // segfault for more declarations of the struct type

    printf("--------------------------QUIZ--------------------------\n");
    printf("=>This quiz contains the trivial questions based on Computer Science\n");
    printf("=>Rules for the game are as given below.\n");
    printf("=>Make sure you read them before you start\n");
    printf("----------------------------------------------------------");
    printf("\n->You have to answer 10 random questions\n");
    printf("->They Questions are mostly of the MCQ type\n");
    printf("->You can choose the correct answer and then input it in the console\n");
    printf("->For every right answer you will be awarded points\n");
    printf("->And you get only 3 chances, each time you answer incorrectly reduce by 1\n");
    printf("->Your score will be displayed at the end of the game\n");
    printf("----------------------------------------------------------\n\n");
    printf("Choose (y) to start playing the game or (n) to exit from the console\n");
    scanf("%c", &choice);

    if (choice == 'y')
    {

        while (run == 1)
        {
            x = 0;
            scorefinal = 0;
            answered = 0;
            while (x < 10 && lives != 0)
            {
                f = rand() % strlen(questions.answers);
                printf("=>%s\n", questions.ques[f]);
                printf("%s\n\n", questions.options[f]);
                scanf("%d", &temp);

                if (questions.answers[f] - temp == 96)
                {
                    printf("Great! you answered correctly\n");
                    printf("You are awarded 5 points\n\n");
                    scorefinal += 5;
                    answered += 1;
                }
                else
                {
                    printf("Oh! your answer is incorrect, unfortunately you lose a life\n\n");
                    lives--;
                }
                x++;
            }
            if (lives == 0)
            {
                printf("-------------------------------------------------------------");
                printf("'\nOh no you lost all the lives.\n");
                printf("Your final score is: \n");
                printf("%d\n", scorefinal);
                printf("You got %d out of %d correct\n\n", answered, 10);
                printf("-------------------------------------------------------------");
            }
            if (x == 10)
            {
                printf("-------------------------------------------------------------");
                printf("\nYou have finished all the 10 questions\n");
                printf("Your Final score is: \n");
                printf("%d\n", scorefinal);
                printf("You got %d out of %d correct\n\n", answered, 10);
                printf("-------------------------------------------------------------");
            }
            printf("\nDo you wanna continue playing\n");
            printf("(1/0)\n");
            scanf("%d", &consent);
            if (consent == 1)
            {
                lives = 3;
                run = 1;
            }
            else
            {
                printf("Hope you come back and enjoy.");
                run = 0;
            }
        }
    }
    else
    {
        exit(1);
    }

    return 0;
}