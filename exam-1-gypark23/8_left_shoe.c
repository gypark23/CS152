#include <stdio.h>
/*
12198215
Kyu Park
Midterm 8_left_shoe.c
*/


typedef struct _Shoe
{
	char brand[15];			//brand name, maximum length of 15
	char name[30];			//shoes name, maximum length of 30
	float size;				//shoes size in float, since some shoes has half size like 13.5
	float price_usd;		//shoes price in float since cents are represented in decimals
}Shoe;

Shoe* load();
Shoe Shoes[4];		//global variable that will have shoes in. Size was declared 4 since there were only 4 shoes to load.
					//it was declared globally so that it won't get destroyed when load() terminates.



int main()
{
	Shoe* Shoes_pointer = load();
	for (int i = 0; i < 4; i++)
	{
		printf("Shoe: %s %s :: Size: %.1f :: Price: $%.2f\n", Shoes_pointer->brand, Shoes_pointer->name, Shoes_pointer->size, Shoes_pointer->price_usd);
		Shoes_pointer++;
	}
}

//loads the shoes to the global Shoe array Shoes
//and returns the pointer towards Shoes
Shoe* load()
{
	Shoe Shoe1 = { "Nike", "Kyrie 6", 13, 49.99 };
	Shoe Shoe2 = { "Nike", "Air Vapormax Plus", 8, 79.99 };
	Shoe Shoe3 = { "Adidas", "Ultraboost DNA", 11.5, 65.00 };
	Shoe Shoe4 = { "Puma", "Enzo 2", 12, 32.5 };

	Shoes[0] = Shoe1;
	Shoes[1] = Shoe2;
	Shoes[2] = Shoe3;
	Shoes[3] = Shoe4;

	Shoe* pointer = Shoes;
	return pointer;
}