#include <stdio.h>
#include <stdlib.h>

struct videogame{
    int id; // 4 bytes (0 - 3)
    int year; // 4 bytes (4 - 7)
    int serialNumber; // 4 bytes (8 - b)
    char sign; // 1 byte (c)
};

int main() {
    void *wptr = malloc(sizeof(struct videogame)); // 13 without padding (with padding 16)
    struct videogame *wvptr = (struct videogame*) wptr;
    // Size of the struct
    // printf("Size of struct videogame: %lu\n",sizeof(struct videogame));
    
    wvptr->id = 0xff11aabb;
    wvptr->year = 0xaf808090;
    wvptr->serialNumber = 0x12faacda;
    wvptr->sign = 'J';

    // Write To Disk
    FILE *wfh = fopen("videogame.vg","wb");
    if(wfh != NULL){
        fwrite(wptr,sizeof(struct videogame),1,wfh);
        fclose(wfh);
    }

    free(wptr);

    // Read From Disk
    void *rptr = malloc(sizeof(struct videogame));
    struct videogame *rvptr = (struct videogame*) rptr;
    FILE *rfh = fopen("videogame.vg","rb");
    if (rfh != NULL) {
        fread(rptr,sizeof(struct videogame),1,rfh);
        fclose(rfh);
    }

    printf("ID: %x\nYEAR: %x\nSERIAL NUMBER: %x\nSIGN: %x\n",
            rvptr->id, rvptr->year, rvptr->serialNumber, rvptr->sign);

    return 0;
}