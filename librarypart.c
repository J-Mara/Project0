#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listfile.h"
#include "librarypart.h"

void addSong(struct song_node* n){
  if(isalpha(n -> artist[0]) != 0){
    addAlpha(n, *libr['a' - n->artist[0]]);
  }
  else{
    addAlpha(n, *libr[26]);
  }
}

void printLib(){
  int i;
  for(i = 0; i < 27; i++){
    printList(*libr[i]);
  }
}

int main(){
  struct song_node* head = NULL;
  struct song_node* second = NULL;
  struct song_node* third = NULL;
  struct song_node* first = NULL;

  head = (struct song_node*)malloc(sizeof(struct song_node));
  second = (struct song_node*)malloc(sizeof(struct song_node));
  third = (struct song_node*)malloc(sizeof(struct song_node));
  first = (struct song_node*)malloc(sizeof(struct song_node));

  strcpy(head->name, "test1");
  strcpy(second->name, "test3");
  strcpy(third->name, "test2");
  strcpy(first->name, "test add at the begining");

  strcpy(head->artist, "a");
  strcpy(second->artist, "b");
  strcpy(third->artist, "b");
  strcpy(first->artist, "e");

  addSong(head);
  addSong(first);
  addSong(second);
  addSong(third);

  printLib();
}
