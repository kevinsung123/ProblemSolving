#include<cstdio>
using namespace std;

int main(void)
{
	//int n, first = 0, second = 0, temp = 0, cycle = 0, m = 0;
	//scanf("%d", &n); //n을 입력받음
	//first = n / 10;
	//second = n % 10;
	/*do
	{
		temp = first + second;
		first = second;
		second = temp % 10;
		m = first * 10 + second;
		cycle++;
	} while (n != m);
	printf("%d\n", cycle);*/


	int n = 0, m = 0, temp = 0, cycle = 0, origin;
	scanf("%d", &n);
	origin = n;
	do
	{
			
			temp = n/10 + n%10;
			m = (n%10)*10+ temp%10;    //틀린이유 19인경우 n이 한자리수일때 처리를 제대로 못함
			cycle++;
			n = m;
		
		
	} while (origin != m);
	printf("%d\n", cycle);
	return 0;
}