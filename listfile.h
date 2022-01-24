#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void printList(struct song_node* n);

void addFront(struct song_node* n, struct song_node* front);

void addAlpha(struct song_node* n, struct song_node* f);

struct song_node* getPoint(char n[], char a[], struct song_node* s);

struct song_node* getArtSong(char a[], struct song_node* s);

void remSong(char a[], char n[], struct song_node* s);

void freeList(struct song_node* n);

#endif
