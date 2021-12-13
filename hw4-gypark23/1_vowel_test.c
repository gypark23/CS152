#include <stdio.h>
#include <assert.h>
#include "1_vowel.c"

/*
1_vowel.c
12198215
Kyu Park
*/

//unit test
void test();

int main(int argc, char* argv[])
{
	test();

	if (argc != 2)
	{
		printf("0 or 2+ arguments");
		exit(1);
	}

	//letter must be lowercase so that uppercase rule defined in 1_vowel.c can be put in effect
	Letter vowels[5] = { {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0} };

	for (int i = 0; i < 5; i++)
	{
		countLetter(argv[1], &vowels[i]);
	}
	printf("Your sentence contains the following vowels :\n");
	printf("a: %d, e : %d, i : %d, o : %d, u : %d", vowels[0].count, vowels[1].count, vowels[2].count, vowels[3].count, vowels[4].count);

	return 0;
}


void test()
{
	{
		Letter a_count = { 'a', 0 };
		countLetter("aaabbc", &a_count);
		Letter b_count = { 'b', 0 };
		countLetter("aaabbc", &b_count);
		Letter c_count = { 'c', 0 };
		countLetter("aaabbc", &c_count);
		Letter d_count = { 'd', 0 };
		countLetter("aaabbc", &d_count);
		assert(a_count.count == 3);
		assert(b_count.count == 2);
		assert(c_count.count == 1);
		assert(d_count.count == 0);
	}
}