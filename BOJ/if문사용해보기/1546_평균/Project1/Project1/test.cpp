#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


int main(void)
{

	//int n, m=0, temp;
	//double avg = 0;

	//N입력 받음
	//scanf("%d", &n);

	//N개의 크기 vector 선언
	//vector<double> arr(n,0);


	//for (int i = 0;i < n;i++)
	//{
	//
 //		scanf("%d", &temp);
	//	if (m < temp) m = temp;  //최대값을 찾음
	//	arr[i] = double(temp);
	//}

	//각 점수의 새로운 평균을 구하는 함수
	//for (int i = 0;i < n;i++)
	//{
	//	arr[i] = arr[i] / m * 100;
	//	avg += arr[i];
	//}

	//printf("%f\n", avg / n);

	int n, m = 0;
	double sum = 0, avg = 0, max = 0;

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &m);
		if (m > max) max = m;
		sum += m;
	}

	printf("%lf\n", 100 * sum / (max*n));
		
}