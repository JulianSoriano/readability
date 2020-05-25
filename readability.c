//include files from these libraries
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//main body of code

int main(void)
{
    //variables
    ///////////////////////////////////////////////////

    int letters = 0;
    int words = 1;
    int sentences = 0;

    ///////////////////////////////////////////////////

    //prompt user "Text: " using get_string
    string input = get_string("Text: ");

    //calculate length of string using strlen
    int stringlength = strlen(input);

    //"for loop" for input array. if input is smaller than stringlength, run loop
    for (int i = 0; i < stringlength; i++)
    {
        //if character value is between (a to z) or (A to Z)
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            //letters count +1
        {
            letters++;
        }
        
        //if character value is a space
        if (input[i] == ' ')
            //words count +1
        {
            words++;
        }
            
        //if character value is a period, exclamation mark, or question mark
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
            //sentences count +1
        {
            sentences++;
        }
    }

    ///////////////////////////////////////////////////

    //Coleman-Liau Index

    //L (avg number of letters per 100 words)
    float L = (float) letters / (float) words * 100;
    //S (avg number of sentences per 100 words)
    float S = (float) sentences / (float) words * 100;
    //Coleman-Liau index (index = 0.0588 * L - 0.296 * S - 15.8)
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //Grade = (Coleman-Liau formula round to nearest int)
    int grade = round(index);

    printf("Grade %i\n", grade);

    //If index number is less than 1, display "Before Grade 1"
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    //If index number is 16 or higher, display "Grade 16+"
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
}
