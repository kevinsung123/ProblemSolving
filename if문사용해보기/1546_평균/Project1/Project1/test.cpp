#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


int main(void)
{

	//int n, m=0, temp;
	//double avg = 0;

	//N�Է� ����
	//scanf("%d", &n);

	//N���� ũ�� vector ����
	//vector<double> arr(n,0);


	//for (int i = 0;i < n;i++)
	//{
	//
 //		scanf("%d", &temp);
	//	if (m < temp) m = temp;  //�ִ밪�� ã��
	//	arr[i] = double(temp);
	//}

	//�� ������ ���ο� ����� ���ϴ� �Լ�
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