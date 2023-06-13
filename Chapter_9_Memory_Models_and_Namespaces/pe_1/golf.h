#ifndef GOLF_H
#define GOLF_H
#include <iostream>
#include <cstring>

const int Len{40};
extern int num_of_s_pl;

struct golf{
    char fullname[Len];
    int handicap;
};

void setgolf(golf & g, const char * name, int i);
int setgolf(golf & g);
void handicap(golf & g, int hc);
void showgolf(const golf & g);


#endif