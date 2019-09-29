#include <stdlib.h>
#include <stack>
#include <stdio.h>
using namespace std;
int a[100001];
int ans;
typedef struct _stack {
	int top;
	int arr[100000];
}Stack;

void init(Stack *s)
{
	s->top = -1;
}
int isEmpty(Stack *s)
{
	if (s->top == -1) return 1;
	else return 0;
}
void push(Stack *s, int data)
{
	s->top++;
	s->arr[s->top] = data;
}
void pop(Stack *s)
{
	s->top--;
}
int Top(Stack *s)
{
	return s->arr[s->top];
}

int main()
{
	int n;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0) break;
		//Stack * s = (Stack *)malloc(sizeof(Stack));
		stack<int> s;
		//init(s);
		ans = -1e9;
		for (int i = 0;i < n;i++)scanf("%d", &a[i]);
		for (int i = 0;i < n;i++)
		{
			int left = i;
			while (!s.empty() && a[s.top()] > a[i])
			{
				int height = a[s.top()];
				s.pop();
				int width = i;
				if (!isEmpty(s)) width = i - Top(s) - 1;
				if (ans < width*height) ans = width * height;

			}
			push(s, i);
		}
		while (!isEmpty(s))
		{
			int height = a[Top(s)];
			pop(s);
			int width = n;
			if (!isEmpty(s)) width = n - Top(s) - 1;
			if (ans < width*height) ans = width * height;
		}
		printf("%d\n", ans);
		free(s);
	}
	

	printf("%d\n", ans);
}