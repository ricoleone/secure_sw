/* ***************************************************************************
* Name:         rot13.c
* Description:  encrypts user input to a text file using Ceasar rot 13. If no
*               input is provided, it looks for the file input.txt, The file contains
*               numbers separated by dashes and spaces. The numbers translate 1 to A 
*               and 26 to Z. Then those letters have been encrypted by ROT13. Spaces 
*               are breaks in words and dashes are separators for letters in the same 
*               word file and writes the decrypted message to the file output.txt
* Usage:        rot13 <enter>, rot13 "some plaintext here" <enter>
* Example:      7-21-22-6 22-6 18-1-16-2-17-18-17 10-22-7-21 14 16-14-18-6-14-5 16-22-3-21-18-5
*               decrypts to THIS IS ENCODED WITH A CAESAR CIPHER
* Author:       Rico Leone
* Date:         April 8, 2023
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decrypt(char*);
char* encrypt(char*);
void  writefile(char*, char*);
void  readfile(char*, char*);

#define MAX 2048
int main(int argc, char** argv, char** envp){
    char buff[MAX];
    memset(buff, 0, MAX);
    char* infile = "input.txt";
    char* outfile = "output.txt";

    if(argc == 2){
        printf("input string = %s\n", argv[1]);
        
        char* ct = encrypt(argv[1]);
        writefile(ct, infile);
        
        printf("ciphertext: %s\n", ct );
        printf("ciphertext written to file: %s\n", infile);
    } 
    else if(argc == 1){
        readfile(buff, infile);
        
        printf("ciphertext: %s\n", buff );
        printf("ciphertext read from file: %s\n", infile);
        
        char* pt = decrypt(buff);
        writefile(pt, outfile);
    
        printf("plaintext = %s\n", pt );
        printf("plaintext written to file: %s\n", outfile);
    }
    else {
        printf("Error! no input provided\n");
        exit(1);
    }

}

/* ***************************************************************************
* Name:         decrypt
* Description:  decrypts a null termnated string using Ceasar rot 13 that is in
*               the format described at the top of this file.
* Usage:        rot13 <enter>, rot13 <message> <enter>
* Author:       Rico Leone
* Date:         April 8, 2023
*******************************************************************************/
char* decrypt(char* s){
    int len = strlen(s);
    char* msg = (char*)malloc(MAX);
    char* pmsg = msg; 
    // a 2 char place holder, zero terminated (so we can use atoi to convert char digits to an int)
    char ph[] = {'\0','\0', '\0'};
    char* pph = ph;
    while(*s != 0){
        // if a char store in ph[0] and ph[1] for a two digit number
        if((*s != '-') && (*s != ' ')){
            *(pph++) = *s;
        }
        // decrypt a letter of a word (one or two digits), where each digit is a char in NULL terminated string
        else if((*s == '-') || (*s == ' ')){
            *(pmsg++) = (int)'@' + (atoi(ph) + 13)  % 26;
            ph[1] = '\0';
            pph = ph;
        }
        // consume the white space and append it to the plaintext
        if(*s == ' '){
            *(pmsg++) = *s;
        }
        s++;
        // decrypt the last letter, which is not followed by an "-" or " ".
        if(*s == '\0'){
            *(pmsg++) = (int)'@' + (atoi(ph) + 13)  % 26;
            *pmsg = '\0';
            ph[1] = '\0';
            pph = ph;
        }
    }
    return msg;

}
/* ***************************************************************************
* Name:         encrypt
* Description:  encrypts a null termnated string using Ceasar rot 13 that is in
*               the format described at the top of this file. Returns a char* of 
*               encrypted message from the heap.
* Usage:        char* cipherttxt = encrypt(char* plaintext);
* Author:       Rico Leone
* Date:         April 8, 2023
*******************************************************************************/
char* encrypt(char* pt){
        char * token = strtok(pt, " ");
        char* ct = (char*)malloc(MAX);
        // loop through the string to extract all other tokens
        char* pct = ct;
        char  buff[10];
        char* pbuff = buff;
        int   num   = 0;
        int   len   = 0;
        char  c     ='\0';
        while( token != NULL ) {
            // printf( " %s\n", token ); //printing each token
            for(int i =0; i < strlen(token); i++){
                c = toupper(*(token + i));
                //printf("token = %c ", *(token + i));
                num = ( (int)c - (int)'@' + 13) % 26;
                len = sprintf(buff, "%d", num);
                // printf("num = %d ", num);
                // printf("buff = %s \n", buff);
                for(int k=0; k<len; k++){
                    *(pct++) = buff[k];
                }
                if(i < (strlen(token) -1)){
                    *(pct++) = '-';
                }
                else{
                    *(pct++) = ' ';
                }
            }
            token = strtok(NULL, " ");
        }
        //remove last blank space and null terminate string
        *(--pct) = '\0';
        return ct;
    }
/* ***************************************************************************
* Name:         writefile
* Description:  writes the contents of a buffer to a file in text mode
* Usage:        char* cipherttxt = encrypt(char* plaintext);
* Author:       Rico Leone
* Date:         April 8, 2023
*******************************************************************************/
void writefile(char* buff, char* filename){
        FILE* fp;
        if((fp = fopen(filename,"w")) == NULL){
            printf("Error! opening file %s\n", filename);
            exit(1);
        }    
        if(fputs (buff, fp) == 0 ){
            printf("Error! writing to file: %s\n", filename);
            exit(1);
        }
        fclose(fp);
    } 
/* ***************************************************************************
* Name:         readfile
* Description:  writes the contents of a file to a buffer in text mode
* Usage:        char* cipherttxt = encrypt(char* plaintext);
* Author:       Rico Leone
* Date:         April 8, 2023
*******************************************************************************/
void readfile(char* buff, char* filename){
        FILE* fp;
        if((fp = fopen(filename,"r")) == NULL){
            printf("Error! opening file %s\n", filename);
            exit(1);
        }    
        if(fgets (buff, MAX, fp) == NULL ){
            printf("Error! reading from file: %s\n", filename);
            exit(1);
        }
        fclose(fp) ;
    }   