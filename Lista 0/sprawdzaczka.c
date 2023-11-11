//Dominik Muc, 345952, lista 0 sprawdzaczka

#include <stdio.h>

int main(void)
{
    unsigned temp = 0;
    unsigned n = 0;
	scanf("%u", &n);
	for(unsigned i = 0; i <= 1000; i++)
	{
		unsigned r = n+i;
		unsigned bk = 1;
		for(unsigned d = 2; d <= r; d++)
		{
			temp = 0;
			while(r%d == 0)
			{
				if(temp == d)
				{
					bk = 0;
				}
				temp = d;
				r = r/d;
			}
		}
		if(bk == 1)
		{
			printf("%u \n", n+i);
			return 0;
		}
	}
	printf("BRAK");
	return 0;
}
