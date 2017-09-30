#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)

struct {
    char type[2];
    unsigned int size;
    unsigned short int reserved1, reserved2;
    unsigned int offset;
}header;

struct {
    unsigned int size;
    int width, height;
    unsigned short int planes;
    unsigned short int bits;
    unsigned int compression;
    unsigned int imagesize;
    int xresolution, yresolution;
    unsigned int ncolours
    unsigned int importantcolours;
}info_header;

struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
}pixel;


int main(int argc, char **argv) {

    if (argc<3) {
        printf("Too few args.\n"); //check number of arguments
        return(1);
    }

    FILE *in_file; //initialize file
    int i, j;      //loop variables
    char *invert = "-invert", *grayscale = "-grayscale";

    in_file = fopen(argv[2], "r+b"); //read and write binary

    if(in_file == NULL)
    {
        printf("Could not open file\n"); //if file is null, reject
        exit(8);
    }

    fread(&header, sizeof(header), 1, in_file); //read file header

    if(header.type[0] != 'B' || header.type[1] != 'M') //make sure type is BM
    {
        printf("Sorry mate, we don't except that file format :(");
        exit(8);
    }

    fread(&info_header, sizeof(info_header), 1, in_file); //read in info header
    fseek(in_file, header.offset, SEEK_SET);

    if(info_header.size != 40)
    {
        printf("Sorry mate, we don't except that file format :(");
        exit(8);
    }

    //print to debug

    printf("Type: %c%c, Size: %d, R1: %u, R2: %u, offset: %u",
           header.type[0], header.type[1], header.size, header.reserved1, header.reserved2, header.offset);
    printf("\nSize: %d, height: %d, width: %d, bpp: %d, xres: %d, yres: %d",
           info_header.size, info_header.height, info_header.width, info_header.bits, info_header.xresolution, info_header.yresolution);

    //end print

    if(strcmp(argv[1], invert) == 0) {
        for (i = 0; i < info_header.height; i++) {
            for (j = 0; j < info_header.width; j++) {
                fread(&pixel, 3, 1, in_file);

                pixel.red = ~pixel.red;
                pixel.green = ~pixel.green;
                pixel.blue = ~pixel.blue;

                fseek(in_file, -3, SEEK_CUR);
                fwrite(&pixel, 3, 1, in_file);
            }

            if ((info_header.width * 3) % 4 != 0) {
                char buf[4 - ((info_header.width * 3) % 4)];
                setbuf(stdin, buf);
                fseek(in_file, sizeof(buf), SEEK_CUR);
            }
        }
    }


    else if(strcmp(argv[1], grayscale) == 0) {
        for (i = 0; i < info_header.height; i++) {
            for (j = 0; j < info_header.width; j++) {
                fread(&pixel, 3, 1, in_file);

                pixel.red = ~pixel.red;
                pixel.green = ~pixel.green;
                pixel.blue = ~pixel.blue;

                fseek(in_file, -3, SEEK_CUR);
                fwrite(&pixel, 3, 1, in_file);
            }

            if ((info_header.width * 3) % 4 != 0) {
                char buf[4 - ((info_header.width * 3) % 4)];
                setbuf(stdin, buf);
                fseek(in_file, sizeof(buf), SEEK_CUR);
            }
        }
    }

    fclose(in_file);
    return 0;
}



/*void invert(const char* file_name)
{

}

void grayscale(const char* file_name)
{

}*/