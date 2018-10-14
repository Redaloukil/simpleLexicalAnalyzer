#include<stdio.h>
#include<stdlib.h>
#include"DFA.c"

int isAB(char c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j') {
        printf("its a lettre\n");
        return 1;
    }
    return 0;
}
int is01(char c){
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        printf("its a chiffre\n");    
        return 1;
    }
    return 0;
}
int isAB01(char c){
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j') {
        printf("its a lettre or alphabet\n");
        return 1;
    }
    return 0;
}

int isWalou(char c){
    if(c == ' ') {
        printf("its a white space\n");
        return 1;
    }
    return 0;
}

int condition01(char c) {
    if (isAB(c) == 1) return 1;
    return 0;
}
int condition10(char c) {
    if(isWalou(c)== 1) return 1;
    return 0;
}
int condition02(char c) {
    if(is01(c) == 1) return 1;
    return 0;
}
int condition20(char c) {
    if(isWalou(c) == 1) return 1;
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


void main(){
    DFA* dfa;

    dfa = dfa_createDFA();

    DFAState state0;
    DFAState state1;
    DFAState state2;
    
    dfa_addState(dfa , &state0);
    dfa_addState(dfa , &state1);
    dfa_addState(dfa , &state2);

    int len = dfa->numberOfStates;
    printf("%d\n" , len);

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

    transition2.condition = condition10;
    transition2.toStateID = 0;

    transition0.condition = condition02;
    transition0.toStateID = 2;

    transition0.condition = condition22;
    transition0.toStateID = 2;

    transition0.condition = condition20;
    transition0.toStateID = 0;

    dfa_addTransition(dfa , 0 , condition01 ,1);
    
    dfa_addTransition(dfa , 1 , condition10 ,0);

    dfa_addTransition(dfa , 0 , condition02 , 2);

    dfa_addTransition(dfa , 2 , condition20 , 0);

    dfa_addTransition(dfa , 1 , condition11 , 1);

    dfa_addTransition(dfa , 2 , condition22 , 2);
    
    // dfa = dfa_createState(dfa , state0);
    // dfa = dfa_createState(dfa , state1);
    // dfa = dfa_createState(dfa , state2);

    int lena = dfa->currentStateID;
    lena = dfa->currentStateID = 0;
    printf("%d\n" , lena);
    dfa_makeNextTransition(dfa , 'c');
    printf("%d\n" ,dfa->currentStateID );


    
    
    
    

}