#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "word.h"

//It traverses the linked list and returns the frequencies of the word in buf

int find(WORD** head,char* buf){
  
   WORD* curr = *head;
   long int count=0;
   while(curr!=NULL){
    if(strcasecmp(buf,curr->name)==0){
      count++;
    }  
    curr = curr->next;
   }
   return count;

}

//It updates the frequency for each distinct word.

void changeFreq(WORD** head, char* buf, int freqs){
  
  WORD* curr = *head;
   while(curr!=NULL){
     if(strcasecmp(buf,curr->name)==0){
       curr->frequency+=1;
     } 
    curr = curr->next;
   }
   
}

//It forms a new linked list at the end of each word and returns that new word. 

WORD* addAtEnd(WORD** current, char* buf){  
  
  WORD* newWord = (WORD*)malloc(sizeof(WORD));
  newWord->name =(char *)malloc(sizeof(char)*(strlen(buf)));
  strcpy(newWord->name,buf);
  newWord->frequency = 1;
  newWord->next = NULL;
  (*current)->next = newWord;
  return newWord;
  
}

//It executes the program by making the linked list and adding only new elements each time by calling find(), changeFreq() and addAtEnd()

int main(int argc, char *argv[]) {
  char* filename = "newton.txt";
  WORD* head = (WORD*)malloc(sizeof(WORD));
  WORD* current = (WORD*)malloc(sizeof(WORD));
  int fdone = open(filename,O_RDWR);
  char* buf = (char *)malloc(sizeof(char)*(50));
  int count = 1;
  int start = 1;

  while (read(fdone,buf,1)>0){

     if(buf[0]==' '||buf[0]=='\n'){
       lseek(fdone,-count,SEEK_CUR);
       buf = (char *)malloc(sizeof(char)*(50));
       read(fdone,buf,count-1);
        if(start == 1){
         head->name = (char *)malloc(sizeof(char)*(50));
         strcpy(head->name,buf);
         head->frequency = 1;
         head->next = NULL;
         current = head;
         start = 0;
       }
       else{
         int freq = find(&head,buf);
         if(freq>=1){
          changeFreq(&head,buf,freq+1);
         }
         else{
         current = addAtEnd(&current,buf);
         }
       }
       lseek(fdone,1,SEEK_CUR);
       count=1;
     }
     else{
      count++;
     }

  }

  WORD* curr = head;
  while(curr!=NULL){
    char* buf=(char*)malloc(sizeof(char)*60);
    sprintf(buf,"%-50s %i\n ",curr->name,curr->frequency);
    write(1,buf,60);
    curr = curr->next;
  }
  return 0;
}


