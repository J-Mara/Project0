#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listfile.h"

void printList(struct song_node* n){
  while (n != NULL){
    printf(" %s ", n->artist);
    printf(" %s \n", n->name);
    n = n->next;
  }
}

void addFront(struct song_node* n, struct song_node* front){
  n->next = front;
}

void addAlpha(struct song_node* n, struct song_node* f){
  int x = 0;
  while (f->next != NULL && x == 0){
    if(strcmp(n->artist, f->next->artist) < 0){
      n->next = f->next;
      f->next = n;
      x = 1;
    }else{
      if(strcmp(n->artist, f->next->artist) == 0){
	if(strcmp(n->name, f->next->name) <= 0){
	  n->next = f->next;
	  f->next = n;
	  x = 1;
	}
      }
      else{
        f = f->next;
      }
    }
  }
  f->next = n;
}

struct song_node* getPoint(char n[], char a[], struct song_node* s){
  while (s != NULL){
    if(strcmp(s->name, n) == 0 && strcmp(s->artist, a) == 0){
      return s;
    }
    s = s->next;
  }
  return NULL;
}

struct song_node* getArtSong(char a[], struct song_node* s){
  while (s != NULL){
    if(strcmp(s->artist, a) == 0){
      return s;
    }
    s = s->next;
  }
  return NULL;
}

void remSong(char a[], char n[], struct song_node* s){
  struct song_node* tmp;
  while(s->next != NULL){
    if(strcmp(s->next->name, n) == 0 && strcmp(s->next->artist, a) == 0){
      tmp = s->next;
      s->next = s->next->next;
      free(tmp);
    }
    s = s->next;
  }
}

void freeList(struct song_node* n){
  //struct song_node* tmp;
  if(n->next != NULL){
    freeList(n->next);
    // free(n->name);
    //free(n->artist);
    //free(n->next);
    
    //tmp = n;
    //n = n->next;
    //free(tmp);
  }
  printf("freeing node %s %s\n", n->artist, n->name);
  free(n);
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
  strcpy(first->name, "test4");

  strcpy(head->artist, "a");
  strcpy(second->artist, "b");
  strcpy(third->artist, "b");
  strcpy(first->artist, "e");

  //head->next = second;
  //second->next = third;
  //third->next = NULL;

  addAlpha(first, head);
  addAlpha(second, head);
  addAlpha(third, head);
  
  //printList(head);
  //printf("pointer to head: %p\n", getPoint("test1", "a", head));
  //printf("head name: %s\n", getPoint("test1", "a", head)->name);
  //printf("head artist: %s\n", getPoint("test1", "a", head)->artist);

  //remSong("b", "test2", head);
  //printList(head);
  
  //freeList(head);
  //printList(head);


  printf("TESTING LIST PART\n");
  printf("==============\n");
  printf("Testing print_list:\n");
  printList(head);
  printf("==============\n");
  printf("Testing find_node: \n");
  printf("looking for [b:test3]\n");
  printf("found: %s %s\n", getPoint("test3", "b", head)->artist, getPoint("test3", "b", head)->name);
  printf("==============\n");
  printf("Testing find_artist:\n");
  printf("looking for artist b, first song: [b:test2]\n");
  printf("found: %s %s\n", getArtSong("b", head)->artist, getArtSong("b", head)->name);
  printf("==============\n");
  printf("Testing remove:\n");
  printf("removing [b, test3]\n");
  remSong("b", "test3", head);
  printList(head);
  printf("removing [b, test2]\n");
  remSong("b", "test2", head);
  printList(head);
  printf("==============\n");
  printf("Testing add_alpha: \n");
  struct song_node* other = NULL;
  other = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(other->name, "test5");
  strcpy(other->artist, "c");
  addAlpha(other, head);
  printf("Adding [c:test5]\n");
  printList(head);
  printf("==============\n");
  printf("Testing freeList:\n");
  freeList(head);
  printf("memory freed\n");
}

