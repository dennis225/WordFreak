struct word {
  char* name;
  int frequency;
  struct word *next;
};

typedef struct word WORD;