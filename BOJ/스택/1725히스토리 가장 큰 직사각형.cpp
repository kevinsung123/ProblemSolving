#include<stdio.h>
#include<stdlib.h>
int a[100000];

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
	Stack *S = (Stack *)malloc(sizeof(Stack));
	init(S);
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 0;i < n;i++)
	{
		int left = i;
		while (!isEmpty(S) && a[Top(S)] > a[i])
		{
			int height = a[Top(S)];
			pop(S);
			int width = i;
			if (!isEmpty(S)) width = i-Top(S)-1;
			if (ans < width*height) ans = width * height;
		}
		push(S, i);
	}
	while (!isEmpty(S))
	{
		int height = a[Top(S)];
		pop(S);
		int width = n;
		if (!isEmpty(S)) width = n - Top(S) - 1;
		if (ans < width*height) ans = width * height;
	}

	printf("%d\n", ans);
}