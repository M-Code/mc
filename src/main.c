//
//  main.c
//
// Entry point for m compiler!
// M is a low level language (Assembly like)
//


#include <stdio.h>
#include <string.h>

static const char DEFAULT_OUT[] = "a.bin";

// Command switch option enum.
typedef enum {
    NONE,      // No option
    SOURCE,    // Source file
    OUT,       // Output file
} Option;

char *g_src_file = NULL;
char *g_out_file = (char*)DEFAULT_OUT;


// Function protoypes
/* returns -1 if failed, 0 if succeed */
int parse_arguments(int argc, const char *argv[]);

/* Compiles source code and creates a binary output file */
void compile(const char *src_file, const char *out_file);

int main(int argc, const char * argv[]) {
    int res = parse_arguments(argc, argv);
    if (res == -1) {
        printf("Exiting..\n");
        return 0;
    }
    if (g_src_file != NULL) {
        compile(g_src_file, g_out_file);
    } else {
        printf("Error, no source file specified!\n");
    }
    return 0;
}

int parse_arguments(int argc, const char *argv[]) {
    if(argc == 1) {
        printf("No arguments.\n");
        return -1;
    }
    
    Option opt = NONE;
    int current_arg = 1;
    while (current_arg < argc) {
        
        if (opt == NONE) {
            if ( strcmp(argv[current_arg], "-s") == 0 ) {
                opt = SOURCE;
                current_arg++;
                continue;
            } else if ( strcmp(argv[current_arg], "-o") == 0) {
                opt = OUT;
                current_arg++;
                continue;
            } else {
                printf("Invalid parameters\n");
                return -1;
            }
        } else {
            switch (opt) {
                case SOURCE:
                    g_src_file = (char*) argv[current_arg];
                    break;
                case OUT:
                    g_out_file = (char*) argv[current_arg];
                    break;
                default:
                    break;
            }
            current_arg++;
        }
    }
    
    return 0;
}

void compile(const char *src_file, const char *out_file) {
    FILE *in_fp = fopen(src_file, "rt"); // "rt" is for reading text.
    FILE *out_fp = fopen(out_file, "wb"); // "wb" is for writing binary.
    
    if (in_fp == NULL) {
        printf("Error opening source file %s!\n", src_file);
        return;
    }
    
    if (out_fp == NULL) {
        printf("Error creating binary file %s!\n", out_file);
    }
    
    while(!feof(in_fp)) {
        int ch = fgetc(in_fp);
        printf("%ch", ch);
        
        //char *str = mallac();
        //fscanf(stdin, "%s", &str);
        //printf("%s", str);
    }
    printf("\nEnd of file.");
    fclose(in_fp);
    fclose(out_fp);
}