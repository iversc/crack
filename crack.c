#include <stdio.h>
#include <string.h>

#define _XOPEN_SOURCE
#include <unistd.h>

char *crypt(const char *key, const char *salt);
char *dictionary(char *salt, char *encryption);

int main(int argc, char *argv[])
{
	// Check to make sure there's only one argument given
	if (argc != 2)
	{
		printf("**Error: Invalid number of arguments entered.\n");
		printf("\tPlease enter only one argument.\n");
		return 1;
	}

	// Point to the encrypted string, create the salt 
	char *encryption = argv[1];
	char salt[2];
	
	// Grab the salt from the encrypted string
	salt[0] = encryption[0];
	salt[1] = encryption[1];

	// Create length and decrypted string variable
	unsigned length = strlen(argv[1]);
	char decrypted[length];

	// Check dictionary words 
	printf("%s\n", dictionary(salt, argv[1]));
	
	// TEST: Check to see if anything matches at all
	// I passed in '12345' encrypted, and it does recognize it
	strcpy(decrypted, crypt("12345", salt));
	if (strcmp(decrypted, argv[1]) == 0)
	{
		printf("Hi");
	}
	
	return 0;
}

char *dictionary(char *salt, char *encryption)
{

	// Open the file, create the line and len variable
	FILE *dict;
	dict=fopen("/usr/share/dict/words", "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	
	// Check to my arguments were properly passed to my function
	printf("[%s]", salt);
	printf("[%s]\n", encryption);

	printf("Checking dictionary words...\n");

	/* Go through the dictionary word for word -- if the encrypted
		dictionary word and salt match, then return the 
		dictionary word that was passed to the crypt function */		while ((read = getline(&line, &len, dict)) != -1)
	{
		// Test to make sure each word is being encrypted (It is)
		//printf("%s: %s", crypt(line, salt), line);
		if (strcmp(encryption, crypt(line, salt)) == 0)
		{
			fclose(dict);
			return line;
		}
	} 
	
	fclose(dict);
	return "NONE";
}
