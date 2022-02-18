#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define LEN 1000
#define STR 128
struct questions
{
    int questionId;
    char ques[LEN][LEN];
    char options[LEN][LEN];
    char answers[LEN];

};

int main(void)
{
    struct questions questions;
    static const char filename[] = "ques.txt";
    static const char filename1[] = "options.txt"; 
    static const char filename2[] = "crctans.txt";
    FILE *file = fopen(filename, "r");
    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");
    int i, j = 0, k = 0, m, n = 0, f;
    int x;
    char choice, ch;


    //file in the array done
    //now randomizing the o
    if(file != NULL)
    {
        while(fgets(questions.ques[k], STR, file) != NULL)
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

    if(file1 != NULL)
    {
        while(fgets(questions.options[j], STR, file1) != NULL)
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
    
    if(file2 != NULL)
    {
        while((ch = fgetc(file2)) != EOF)
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
    
    

    // this is for the access of the elements 

    
    for(k = 0, j = 0; k < i || j < m; k++, j++)
    {
        printf("%s\n", questions.ques[k]);
        printf("%s\n", questions.options[j]);
        printf("\n");
    }

    for(f = 0; f < strlen(questions.answers); f++)
    {
        printf("%c\t", questions.answers[f]);
    }


    return 0;
}