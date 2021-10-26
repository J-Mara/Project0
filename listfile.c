#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

void printList(struct song_node* n){
  while (n != NULL){
    printf(" %s ", n->name);
    printf(" %s ", n->artist);
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

char* getArtSong(char a[], struct song_node* s){
  while (s != NULL){
    if(strcmp(s->artist, a) == 0){
      return s->name;
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
  struct song_node* tmp;
  while(n != NULL){
    tmp = n;
    n = n->next;
    free(tmp);
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

  //head->next = second;
  //second->next = third;
  //third->next = NULL;

  addAlpha(first, head);
  addAlpha(second, head);
  addAlpha(third, head);
  
  printList(head);
  printf("pointer to head: %p\n", getPoint("test1", "a", head));
  printf("head name: %s\n", getPoint("test1", "a", head)->name);
  printf("head artist: %s\n", getPoint("test1", "a", head)->artist);

  remSong("b", "test2", head);
  printList(head);
  
  freeList(head);
  //printList(head);
}
