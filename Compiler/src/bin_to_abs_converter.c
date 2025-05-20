#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *in;
    struct stat s;
    int start_address;
    int data_start_adress = 01000;
    int i;
    char checksum = 0;
    char ch;

    if (argc != 4) {
        fprintf(stderr,
                "Wrong number of arguments. Program need three parameters. "
                "Filename of input file and start address.\n");
        fprintf(stderr,
                "bin2abs <file name of binary file> <start address> <binary "
                "fil data>\n");
        fprintf(stderr, "Program will output to stdout.\n");
        exit(1);
    }
    in = fopen(argv[1], "r");
    start_address = strtol(argv[3], NULL, 0);

    fstat(fileno(in), &s);

    putchar(0x01);
    checksum += 0x01;
    putchar(0x00);
    putchar((s.st_size + 6) & 0xff);
    checksum += (s.st_size + 6) & 0xff;
    putchar(((s.st_size + 6) >> 8) & 0xff);
    checksum += ((s.st_size + 6) >> 8) & 0xff;
    putchar(start_address & 0xff);
    checksum += start_address & 0xff;
    putchar((start_address >> 8) & 0xff);
    checksum += (start_address >> 8) & 0xff;

    for (i = 0; i < s.st_size; i++) {
        ch = fgetc(in);
        putchar(ch);
        checksum += ch;
    }

    putchar(-checksum);

    in = fopen(argv[2], "r");

    fstat(fileno(in), &s);
    checksum = 0;
    putchar(0x01);
    checksum += 0x01;
    putchar(0x00);
    putchar((s.st_size + 6) & 0xff);
    checksum += (s.st_size + 6) & 0xff;
    putchar(((s.st_size + 6) >> 8) & 0xff);
    checksum += ((s.st_size + 6) >> 8) & 0xff;
    putchar(data_start_adress & 0xff);
    checksum += data_start_adress & 0xff;
    putchar((data_start_adress >> 8) & 0xff);
    checksum += (data_start_adress >> 8) & 0xff;

    for (i = 0; i < s.st_size; i++) {
        ch = fgetc(in);
        putchar(ch);
        checksum += ch;
    }

    putchar(-checksum);

    checksum = 0;
    putchar(0x01);
    putchar(0x00);
    putchar(0x06);
    putchar(0x00);
    putchar(start_address & 0xff);
    checksum += start_address & 0xff;
    putchar((start_address >> 8) & 0xff);
    checksum += (start_address >> 8) & 0xff;
    putchar(-checksum - 7);

    return 0;
}