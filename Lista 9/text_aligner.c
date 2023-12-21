#include "text_aligner.h"

int text_align(FILE* input, FILE* output, int width, Direction direction){
    char line[MAX_BUFFER];

    while(fgets(line, MAX_BUFFER, input)){
        fprintf(output, "%s", line);
    }
    return 0;
}