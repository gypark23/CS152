#include <stdio.h> 
#include <assert.h>

/*
Kyu Park
12198215
3_blackjack.c*/

//calculates the given character of the card to a face value
//A comes out as 11, JQKT comes out as 10
//if a character other than those above, print out error and immediately terminates the program
int cardValue(char card)
{
	//if cards are numbered, returns that number
	if (card >= '2' && card <= '9')
	{
		return card - '0';
	}
	//if cards are not numbered,
	else
	{
		//check if cards are lettered JQKAT
		//if not, prints out error and terminates the program
		switch (card)
		{
		case 'J':
		case 'Q':
		case 'K':
		case 'T':
			return 10;
			break;
		case 'A':
			return 11;
			break;
		default:
			printf("***Invalid, %c is not a valid card\n", card);
			exit(0);
			break;
		}
	}
	return -1;
}

//add two card values
//check if there are double aces, if so returns 12 instead of 22.
//only takes two characters as input, input of AQ will take A and Q, A Q will also take A and Q
//as long as two correct cards are given as above, the middle space or character doesn't matter
int sumOfCards(char card1, char card2)
{
	int first = cardValue(card1);
	int second = cardValue(card2);
	if (first == 11 && second == 11)
	{
		return 12;
	}
	else
	{
		return first + second;
	}
}

int main()
{
	assert(cardValue('2') == 2);
	assert(cardValue('9') == 9);
	assert(cardValue('A') == 11);
	assert(cardValue('T') == 10);
	assert(cardValue('J') == 10);
	assert(sumOfCards('2', '2') == 4);
	assert(sumOfCards('2', 'Q') == 12);
	assert(sumOfCards('6', 'A') == 17);
	assert(sumOfCards('A', 'A') == 12);

	char first, last;
	printf("Enter Cards: ");
	scanf("%c %c", &first, &last);
	printf("%d", sumOfCards(first, last));

	return 0;
}

