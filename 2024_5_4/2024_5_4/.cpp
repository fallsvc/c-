//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>

//int main()
//{
//	double n = 20.0;
//	int count = 0;
//	while (n >=1){
//		count += (int)n;
//		n = (int)n*0.5;
//	}
//	printf("%d\n", count);
//	return 0;
//}

//int main()
//{
//	int n = 13;
//	//上半部分
//	for (int i = 0; i < n / 2 + 1; i++)
//	{
//		for (int j = 0; j < n/2 - i; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < i * 2 + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//下半部分
//	for (int i = 0; i < n / 2 ; i++)
//	{
//		for (int j = 0; j < i+1; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < (n/2-i-1)* 2 + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

////水仙花数
//int isLilyNumber(int i) {
//	int ws = 0;
//	int tmp = i;
//	//求位数
//	while(tmp!=0){
//		tmp /= 10;
//		ws++;
//	}
//	//
//	int sum = 0;
//	tmp = i;
//	while (tmp != 0) {
//		sum += pow(tmp % 10, ws);
//		tmp /= 10;
//	}
//	if (i == sum) {
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	for (int i = 0; i < 100000; i++) {
//		if (isLilyNumber(i)) {
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，

//例如：2 + 22 + 222 + 2222 + 22222
//int addSumn(int n) {
//
//	int number = 0;
//	int sum = 0;
//	for (int i = 0; i < 5; i++) {
//		number = number * 10 + n;
//		sum += number;
//	}
//
//	return sum;
//}
//
//int main() 
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1) {
//		int ret = addSumn(n);
//		printf("%d\n", ret);
//	}
//	return 0;
//}