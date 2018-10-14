#include<stdio.h>
#include<stdlib.h>
#include<sys/file.h>




char *readFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    char c;
    
    if (file == NULL)
        return NULL; //could not open file
    code = malloc(1000);
    
    while ((c = fgetc(file)) != EOF)
    {
        
        code[n++] = c;
    }
    // don't forget to terminate with the null character
    code[n] = '\0';        
    return code;
}

void tokenize(char *c , char last_c , int error){
    switch(*c){
        case 'a' || 'b' || 'c' :
            if (last_c == 'a' || last_c == 'b' || last_c == 'c'){
                last_c = c;
                free(c);
            }else if (last_c == '1' ||last_c ==  '2' ||last_c ==  '3'){
                error = 1;
                printf("lexically , wrong sentence");
            }
            break;
        
        // case '0' || '1' : 
        //     if (last_c == '1' ||last_c ==  '0' ||last_c ==  'a' ||last_c ==  'b' ||last_c == 'c'){
        //         last_c = c;
        //         c = NULL;
        //     }
        //     break;

        default:
            error = 1;
            printf("lexically , we can not understand what you are writing");
        }
}

void main(){
    char *characters;
    characters = readFile("file.txt");

    int i = 0;
    int error = 0;
    char last_c = NULL;
    char c;
    // do {
    //     c = characters[i];
    //     tokenize(c , last_c , error);
    //     i++;
    // } while( characters[i] != '$' || error == 1 );
}