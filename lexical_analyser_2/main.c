#include<stdio.h>
#include<stdlib.h>
#include"DFA.c"

#define TOKEN_LEN 10


int isAB(char c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j') {
        return 1;
    }
    return 0;
}
int is01(char c){
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        return 1;
    }
    return 0;
}
int isAB01(char c){
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j') {
        return 1;
    }
    return 0;
}

int condition01(char c) {
    if (isAB(c) == 1) return 1;
    return 0;
}

int condition02(char c) {
    if(is01(c) == 1) return 1;
    return 0;
}

int condition11(char c) {
    if(isAB01(c) == 1 ) return 1;
    return 0;
}

int condition22(char c) {
    if(is01(c) == 1) return 1;
    return 0;
}

char *AnalyseFile(char *fileName , DFA* dfa , int *correct)
{
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    char c;
    
    if (file == NULL)
        return NULL; //could not open file
    code = malloc(1000);
    
    dfa->currentStateID = 0;
    Token *token;
    intializeToken(token);

    while ((c = fgetc(file)) != EOF && *correct == 1){
    {   
        
        if(c != ' '){
            addCharToken(token , c);
        }else {
            printf("\n");
            analyseToken(token , dfa , correct);
            intializeToken(token);
        }
    }
    }
    // don't forget to terminate with the null character
    code[n] = '\0';        
    return code;
}

void main() {
    DFA* dfa;

    dfa = dfa_createDFA();

    DFAState state0;
    DFAState state1;
    DFAState state2;
    
    dfa_addState(dfa , &state0);
    dfa_addState(dfa , &state1);
    dfa_addState(dfa , &state2);

    
    

    DFATransition transition0;
    DFATransition transition1;
    DFATransition transition2;
    DFATransition transition3;
    DFATransition transition4;
    DFATransition transition5;


    transition0.condition = condition01;
    transition0.toStateID = 1;
    
    transition1.condition = condition11;
    transition1.toStateID = 1;

    transition0.condition = condition02;
    transition0.toStateID = 2;

    transition0.condition = condition22;
    transition0.toStateID = 2;

    

    dfa_addTransition(dfa , 0 , condition01 ,1);
    
    dfa_addTransition(dfa , 0 , condition02 , 2);

    dfa_addTransition(dfa , 1 , condition11 , 1);

    dfa_addTransition(dfa , 2 , condition22 , 2);
    
    int correct = 1;
    //read file 
    // AnalyseFile("file.txt" , dfa ,&correct);
    // printf("\n");
    // printf("%d\n" , correct);

    char c = 'c';

    dfa_makeNextTransition(dfa , 'c');

    printf("%d", dfa->currentStateID);

    
    
}