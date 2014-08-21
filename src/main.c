//
//  main.c
//
// Entry point for m compiler!
// M is a low level language (Assembly like)
//


#include <stdio.h>
#include <string.h>

// Command switch option enum.
typedef enum {
    NONE,      // No option
    SOURCE,    // Source file
    OUT,       // Output file
} Option;

char *g_src_file = NULL;
char *g_out_file = NULL;

// Function protoypes
void parse_arguments(int argc, const char *argv[]);
void compile(const char *src_file, const char *out_file);

int main(int argc, const char * argv[]) {
    parse_arguments(argc, argv);
    if (g_src_file != NULL) {
        compile(g_src_file, NULL);
    } else {
        printf("Error, no source file specified!\n");
    }
    return 0;
}

void parse_arguments(int argc, const char *argv[]) {
    if(argc == 1) {
        printf("No arguments.  Exiting...");
        return;
    }
    
    Option opt = NONE;
    int current_arg = 1;
    while (current_arg < argc) {
        
        if (opt == NONE) {
            if ( strcmp(argv[current_arg], "-s") == 0 ) {
                opt = SOURCE;
                current_arg++;
                continue;
            } else if ( strcmp(argv[current_arg], "-o")) {
                opt = OUT;
                current_arg++;
                continue;
            } else {
                printf("Invalid parameters\n");
                return;
            }
        } else {
            switch (opt) {
                case SOURCE:
                    ;
                    break;
                case OUT:
                    ;
                    break;
                default:
                    break;
            }
        }
        
        
        g_src_file = (char*) argv[current_arg];
        printf ("Source file == %s\n", g_src_file);
        current_arg++;
    }
    
    printf("Parsing args\n");
}

void compile(const char *src_file, const char *out_file) {
    FILE *fp = fopen(src_file, "rt"); // "rt" is for reading text.
    if (fp == NULL) {
        printf("Error opening %s\n", src_file);
        return;
    }
    while(!feof(fp)) {
        int ch = fgetc(fp);
        printf("%c", ch);
        
        //char *str = mallac();
        //fscanf(stdin, "%s", &str);
        //printf("%s", str);
    }
    printf("\nEnd of file.");
    fclose(fp);
}