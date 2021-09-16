#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool delim_character(char c);
bool non_delim_character(char c);
char *word_start(char* str);
char *end_word(char* str);
int count_tokens(char* str);

void print_all_tokens(char** tokens);
char *copy_str(char *inStr, short len);
char** tokenize(char* str);

short count_chars(char *wordStart);

/* Return true (non-zero) if c is a whitespace character
  ('\t' or ' ').
  Zero terminators are not printable (therfore false) */
bool delim_character(char c)
{
  if(c==' ' || c == '\t' || c=='\n') return true;
  return false;
}

/*Return true (non-zero) if c is a non-whitespace
  character (not tab or space).
  Zero terminators are not printable (therefore false)*/
bool non_delim_character(char c)
{
  if(delim_character(c) || c=='\0') return false;
  return true;
}

/*Returns a pointer to the first character of the next
  space-separated word*/
char *word_start(char* str)
{
  while (*str != '\0') {
    char curr_char = str[0];
    if(delim_character(curr_char) && non_delim_character(str[1])) {
      *str++;
      break;
    }
    *str++;
  }
  return str;
}

/*Returns a pointer to the first space character of the zero
  terminated string*/
char *end_word(char* str)
{
  while(delim_character(*str)) str++;
  return str;
}

// counts the number of words or tokens
int count_tokens(char* str)
{
  int count = 0;
  while(*str != '\0') {
    str = word_start(str);
    count++;
  }
  return count;
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
  char *new_word = (char*)malloc((len)*sizeof(char));
  if (new_word == NULL) printf("Memory not allocated.\n");

  for (int i = 0; i < len; i++) {
    *(new_word+i) = *(inStr+i);
  }
  *(new_word+len) ='\0';
  return new_word;
}


char** tokenize(char* str)
{
  int numWords = count_tokens(str);
  char **tokens=(char**)malloc((numWords+1)*sizeof(char*));
  if (tokens == NULL) printf("Memory not allocated.\n");

  if (delim_character(*str)) str = word_start(str);
  for(int i = 0; i < numWords; i++) {
    char *wordHead = str;
    char *wordTail = end_word(wordHead);
    short wordLen = count_chars(wordHead);
    char *wordToken = copy_str(wordHead, wordLen);

    *(tokens+i) = wordToken;
    str=word_start(str);
    }
  char *wordTerminator = copy_str('\0', 0);
  *(tokens+numWords) = wordTerminator;
  return tokens;
}


void print_all_tokens(char** tokens)
{
  int count = 0;
  while (**tokens != '\0') {
    char *currWord = *tokens;
    printf("tokens[%i] = \"%s\"\n", count,currWord);
    tokens++;
    count++;
  }
}


//counts the number of chars (spaces and words) in the inputted string
short count_chars(char *wordStart)
{
  int count = 0;
  while (!delim_character(*wordStart)){
    wordStart++;
    count++;
  }
  return count;
}

int main()
{
  char word[50];
  printf("Enter a string to be counted:\n");
  fgets(word, sizeof(word), stdin);
  int num_tokens = count_tokens(word);
  printf("Number of words = %i\n",num_tokens);

  char** tokens = tokenize(word);
  print_all_tokens(tokens);
  //char* new_word = copy_str(word, num_chars);
  //printf("Newly copied string: %s\n", new_word);
  return 0;
}
