#include <stdio.h>

int count_chars(char *word);


//counts the number of chars (spaces and words) in the inputted string
//counts the zero terminator at the end of the string as well
int count_chars(char *word)
{
  int count = 0;
  while (*word != '\0'){
    word++;
    count++;
  }
  return count;
}

int main()
{
  char word[50];
  printf("Enter a string to be counted:\n");
  fgets(word, sizeof(word), stdin);
  printf("Number of chars = %i\n",count_chars(word));
  return 0;
}
