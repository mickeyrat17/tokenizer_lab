#include <stdio.h>

int count_chars(char *word);

/* Return true (non-zero) if c is a whitespace character
  ('\t' or ' ').
  Zero terminators are not printable (therfore false) */
bool delim_character(char c)
{

}

/*Return true (non-zero) if c is a non-whitespace
  character (not tab or space).
  Zero terminators are not printable (therefore false)*/

bool non_delim_character(char c)
{

}

/*Returns a pointer to the first character of the next
  space-separated word*/
char *word_start(char* str)
{

}

/*Returns a pointer to the first space character of the zero
  terminated string*/
char *end_word(char* str)
{

}

// counts the number of words or tokens
int count_tokens(char* str)
{

}
/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
      tokens[0] = "hello"
      tokens[1] = "world"
      tokens[2] = "string"
      tokens[3] = 0
*/
char *copy_str(char *inStr, short len)
{

}

char** tokenize(char* str)
{

}

void print_all_tokens(char** tokens)
{

}

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
