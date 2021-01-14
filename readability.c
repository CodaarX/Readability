#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

// start program
int main(void)
{
    // counters
    int letters = 0;
    int words = 1;
    int sentences = 0;
    int hyphen = 0;
    
    // input
    string input = get_string("Text: ");
    
    int inputL = strlen(input);
    
    
    // check the value of letter, word and sentence and count them
    for (int i = 0; i < inputL; i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            letters++;
        }
        
        else if (input[i] == 32)
        {
            words++;
        }
        
        else if ((input[i] == 46) || (input[i] == 33) || (input[i] == 63))
        {
            sentences++;
        }
    }
    
    // calculate values of L and S
    float L = letters * 100 / (float) words;
    float S = sentences * 100 / (float) words;
   
    // print output
    float index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    
    else if (index)
    {
        printf("Grade %i\n", (int) index);
    }
    
//    printf("Letter(s): %i\nWord(s): %i\nSentence(s): %i\n", letters, words, sentences);

}
