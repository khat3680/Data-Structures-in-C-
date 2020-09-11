/*
 * ---------------------------------
 * Student Name:Anshul Khatri
 * Student ID:193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* encrypt(char *plaintext, int key) {
	int shift=0,i=0;
	int size = strlen(plaintext);

	char *ciphertext = (char*)malloc(sizeof(char)*(size+1));
	strcpy(ciphertext,plaintext);

	for(i=0;i<size;i++)
	{
		shift = key;
	if(islower(ciphertext[i]) && (ciphertext[i] + key >122)) {
		shift = key -26;
	}
	else if (isupper(ciphertext[i]) && (ciphertext[i] + key > 90))
	{
		shift = key - 26;
	}
	else if(isspace(ciphertext[i])){
		shift = 0;
	}

	ciphertext[i] += shift;
	}
	return ciphertext;
}

char* decrypt(char *ciphertext, int key) {
	char *temp = (char*)malloc(sizeof(ciphertext) +1);
	key %=26;
	for(int i =0; ciphertext[i]!='\0';i++)
	{
		int ascii = (int)ciphertext[i];
		if(ascii>=65 && ascii < 90)
		{
			//upper
			ascii -=key;

		if(ascii <65)
		{	//order
			ascii = 90 - (65 -ascii -1);
		}
		temp[i] = (char)ascii;	}
		else if(ascii >=97 && ascii <=122) {
			//lower
			ascii -= key;

		if(ascii < 97)
		{
			ascii = 122 -( 97- ascii -1);
		}
		temp[i] = (char)ascii; }
		else{

			temp[i] = (char) ascii;
		}



	}
	return temp;
}
