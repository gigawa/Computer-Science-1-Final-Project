/*Authors: Grant Hooks, Sohail Ahmed, Gary Situ*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int diffNum;
int wordNumber = 10;

//determines difficulty
int difficulty()
{
	printf("Chooses difficulty: Easy(1) Normal(2) Hard(3)\n");
	scanf("%d", &diffNum);
	if(diffNum == 1)
	{
		wordNumber = 5;
	}else
	if(diffNum == 2)
	{
		wordNumber = 10;
	}else
	if(diffNum == 3)
	{
		wordNumber = 20;
	}else
	{
		return difficulty();
	}
	return 0;
}

int main()
{
	#define INPUT_LEN 20
	#define WORDS 99154//number of total words
	FILE *fp;
	fp = fopen("american.txt", "r");//dictionary file

	srand(time(NULL));
	char userInput[20][INPUT_LEN + 1];
	char wordBank[WORDS][INPUT_LEN + 1];
	char targetWords[20][INPUT_LEN + 1];
	int j;
	char *pos;
	double diff = 0.0;
	time_t start;
	time_t stop;

	//determines difficulty
	difficulty();

	//assigns dictionary to wordBank
	for(int i = 0; i < WORDS; i++)
	{
		fgets(wordBank[i], INPUT_LEN, fp);
		//removes newline character
		if((pos = strchr(wordBank[i], '\n')) != NULL)
		{
			*pos = '\0';
		}
	}

	printf("Type the following words: \n");
	time(&start);//sets start time

	//sets and prints random words
	for(int i = 0; i < wordNumber; i++)
	{
		j = rand() % WORDS;
		strcpy(targetWords[i], wordBank[j]);
		printf("%s ", targetWords[i]);
	}
	printf("\n");
	
	//user input
	for(int i = 0; i < wordNumber; i++)
	{
		scanf("%s", userInput[i]);
	}

	time(&stop);//sets end time
	diff = difftime(stop, start);//calculates difference in time
	diff = ((wordNumber/diff)*60);//calculates wpm

	//compares user input to target words
	for(int i = 0; i < wordNumber; i++)
	{
		if(strcmp(userInput[i], targetWords[i]) != 0)
		{
			printf("Your input: %s, does not match the target input: %s", userInput[i], targetWords[i]);
			printf("\n");
		}
	}
	printf("You typed at a speed of %g words per minute\n", diff);//prints wpm

	return 0;
}
