#include "terminal_user_input.h"
#include <stdio.h>
#include <string.h>






typedef struct Track{

my_string trackname;
my_string tracklocation;
}Track;


typedef struct Album{

my_string albumname;
char* genretype;
struct Track array_Tracks[15];

} Album;


void ReadAlbums();
void DisplayAlbums();
struct Album array_Albums[100];
struct Album ReadAlbum();
struct Track ReadTrack();
char* GetGenre(int y);
int counter;

int main()
{

ReadAlbums();
DisplayAlbums();
return 0;
}

void  DisplayAnAlbum(struct Album tmpAlbum)
{
    int i,t = 0;
    printf("Album Name is %s\n",tmpAlbum.albumname.str);
    printf("Album Genere is %s\n",tmpAlbum.genretype);

    do
    {
        printf("Track Name %d is %s\n",i+1,tmpAlbum.array_Tracks[i].trackname.str);
        i = i+1;
    }while(strcmp(tmpAlbum.array_Tracks[i].trackname.str,""));

t = read_integer_range("Select Track Number to Play tracks\n",1,i+1);

    printf("The Track you selected is %s from the Album %s is now playing from file location %s",tmpAlbum.array_Tracks[t-1].trackname.str,tmpAlbum.albumname.str,tmpAlbum.array_Tracks[t-1].tracklocation.str);


}

void DisplayAlbums()
{
 printf(">>>>>>>>>>>>>>>>>Album List are as Below<<<<<<<<<<<<<<<\n");
 int i,y;
 for (i = 0; i<counter; i = i+1)
{
    printf("Album Name %d is %s\n",i+1,array_Albums[i].albumname.str);

}

y = read_integer_range("Select Album Number to View tracks\n",1,counter);
 DisplayAnAlbum(array_Albums[y-1]);

}


struct Track ReadTrack()
{
 struct Track tmptrack;
 tmptrack.trackname = read_string("Enter track name\n");
tmptrack.tracklocation = read_string("Enter track location\n");
return tmptrack;
}

struct Album ReadAlbum()
{
 struct Album tmpalbum;
 int p,t,loopt;

enum genre {pop=1, jazz=2, hiphop=3, classical=4};
 tmpalbum.albumname = read_string("Enter album name\n");
 p = read_integer_range("Enter 1.pop 2.jazz 3.hiphop 4.classical\n",1,4);
 tmpalbum.genretype = GetGenre(p);
 t = read_integer_range("Enter no. of tarcks\n",1,15);
//struct Track temp_array_Tracks[t];
for (loopt = 0; loopt<t; loopt = loopt+1)
{
    tmpalbum.array_Tracks[loopt]= ReadTrack();
}
//tmpalbum.array_Tracks = temp_array_Tracks;

return tmpalbum;
}

char* GetGenre(int y)
{
    switch(y)
    {
        case 1:return "pop";
        case 2:return "jazz";
        case 3:return "hiphop";
        case 4:return "classical";
    }
}



void ReadAlbums()
{
    int i,t;

 i = read_integer("Enetr number of Albums\n");
 counter = i;
for (t = 0; t<i; t = t+1)
{
  array_Albums[t] = ReadAlbum();
}
}
