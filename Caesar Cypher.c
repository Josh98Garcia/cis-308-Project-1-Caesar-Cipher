// cis 803B
// Created by josh98 on 2/20/2019.
// A simple Caesar Cipher, using a key between 0 and 26
// to rotate the English alphabet to encrypt given text.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void decryptString(char *cipherText, int key);
void encryptString(char *plainText, int key);
char encryptChar(char ch, int key);
char decryptChar(char ch, int key);
int isInt(char *input);
char* getMes();
int choice();
int getKey();
int again();

int main ()
{
	char message[100];
	int key, rep = 1;
	key = getKey();
	while(rep)
	{
		switch(choice()){
			case 1:
				printf("Before Encrypt");
				message = getMes();
				printf("After getMes, before encryptString");
				encryptString(message, key);
				printf("After Encrypt");
				break;
			case 2:
				decryptString(getMes(), key);
				break;
			default:
				printf("Error, please try again.\n\n");
		}
		
		rep = again();
	}

	return 1;
}

int isInt(char *input)
{
    if(*input != '\0' || *input != '\n')
	    return 0;
    while(*input != '\0' && *input != '\n')
	{   if(!isdigit(*input))
	    {
	        printf("\nInter state %d\n",10);
    		return 0;
	    }
	    input++;
	}
	return 1;
}

int getKey()
{
	char keyTemp[3];
	int key;
	while(1)
	{
		printf("\nEnter the key being used: ");
		fgets(keyTemp, 3, stdin);
		printf("%d\n",1);
		if(1)//isInt(keyTemp))
		{
		    printf("%d\n", 2);
			key = atoi(keyTemp);
			printf("%d\n", 3);
			if(key<=26&&key>=0)
			{
			    printf("%d\n", 4);
				return key;
			}
		}
		printf("Invalid input.");
	}
	return key;
}

char* getMes()
{
	char message[100];
	printf("\nEnter a message: ");
	fgets(message, 100, stdin);
	printf("%s\n", message);
	return message;
}

int choice()
{
	char cho[3];
	while(1)
	{
		printf("\nWould you like to (e)ncode or (d)ecode? ");
		fgets(cho, 3, stdin);
		printf("\n%s", cho);
		if(*cho=='e')
			return 1;
		else if(*cho=='d')
			return 2;
		printf("\nPlease select only (e) for encode or (d) for decode.");
	}
	return 0;
}

void encryptString(char *plainText, int key)
{
	int i;
	for(i = 0; plainText[i] != '\0'; i = i+1)
		plainText[i] = encryptChar(plainText[i], key);
}

void decryptString(char *cipherText, int key)
{
	int i;
	for(i = 0; cipherText[i] != '\0'; i = i+1)
		cipherText[i] = decryptChar(cipherText[i], key);
}

int again()
{
	char again[3];
	int rep = 1;
	printf("Would you like to go again? (y)es (n)o: ");
	while(rep)
	{
		fgets(again, 3, stdin);
		if(again=="n")
			return 0;
		else if(again=="y")
		{
			printf("\n");
			return 1;
		}
		else
			printf("\nPlease only input (y) for yes or (n) for no: ");
	}
}

char encryptChar(char ch, int key)
{
	if(ch >= 'a' && ch <= 'z')
	{
		ch = ch + key;
		
		if(ch > 'z')
			ch = ch - 'z' + 'a' - 1;
	}
	else if(ch >= 'A' && ch <= 'Z')
	{
		ch = ch + key;
		
		if(ch > 'Z')
			ch = ch - 'Z' + 'A' - 1;
	}
	return ch;
}

char decryptChar(char ch, int key)
{
	if(ch >= 'a' && ch <= 'z')
	{
		ch = ch - key;
		
		if(ch < 'a')
			ch = ch + 'z' - 'a' + 1;
	}
	else if(ch >= 'A' && ch <= 'Z')
	{
		ch = ch - key;
		
		if(ch < 'A')
			ch = ch + 'Z' - 'A' + 1;
	}
	return ch;
}

