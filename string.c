#include<stdio.h>
#include<stdlib.h>

#define ARRAY_LEN 10

typedef struct string_tab {
    char tokens[10];
    int len;
}string_tab;

string_tab insert(string_tab *tab , char token){
    tab->tokens[tab->len] = token;
    tab->len = tab->len +1;
}


void get_len(string_tab tab ){
    printf("%d\n" , (tab).len);
}

void main(){
    string_tab tab;
    tab.len = 0;
    char c = 'c';
    insert(&tab , c);
    get_len(tab);
    printf("%d\n" , (tab).len);

    

}