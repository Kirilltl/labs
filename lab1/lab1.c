# include <stdio.h>
int main()
{
	double nums[10] = { -1.9993545, -2.5654, 5.6575, 2.34, 4.222, 3.45, 3.555, 7.787, 1.367, 5.56 };

	for (int i = 0; i < 10;i++)
	{
		int cell = (int)nums[i]; // izmenenie tipa s drobogo na celoe

		nums[i] = nums[i] - cell; // ubrali celuyu chast'

		printf("%f  ---  %d \n", nums[i]  , cell);
	}

	// poisk minimal'noj drobnoj chasti
	double min = 1;
	for (int i = 0; i < 10; i++)
	{
	if (abs(nums[i]) < min)
		{
			min = nums[i];
		}
	}

	printf("mini %f", min);


	return 0;
}