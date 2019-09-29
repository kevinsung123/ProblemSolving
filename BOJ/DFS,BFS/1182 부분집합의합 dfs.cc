#include <stdio.h>
int n,s,cnt,a[30];

void find(int i,int sum){
    if(sum+a[i]==s) cnt++;
    if(i==n-1) return;
    find(i+1,sum); find(i+1,sum+a[i]);
}

int main(){
	scanf("%d %d",&n,&s);
    for(int i=0; i<n; i++){
    	scanf("%d",&a[i]);
    }
    find(0,0);
	printf("%d",cnt);
}
