### 유니온파인드 
- union-find = disjoin-set 구조라고도 부름
- union연산과 find연산 기본적으로 단 2개만을 지언
- disjoint한 집합들을 표현하는 자료구조
- 어떤 두 집합 사이에도 교집합의 원소가 하나도 없고, 모든 집합의 합집합은 전체집합이다
- 트리 컴포넌트들은 각각의 하나의 집합 
- 같은 집합이더라도 표현할 수 있는 방법은 수없이 많음
- find 연산
	-  두 원소가 같은 집합에 속해 있는지 확인하는 방법은 각각의 루트를 찾아서 둘이 같이 비교!  
	- 어떤 정점의 루트를 찾음
	- 자신이 루트이면 리턴
	- 개선버전은 손자자식들의 부모를 루트로 변형하는것
	- 재귀함수로 경로의 모든 노드의 부모를 루트로 재설정
	- 크기가 N인 유니온-파인드구조에서 M번 find연산 => O(Mlog*N)
```
int find(int n)
{
	if(parent[n] <0 ) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}
- parent[n]: n번 노드의 부모를 가리키는 배열 (최초 -1로 초기화)
- 
```

![enter image description here](https://blogfiles.pstatic.net/20160819_83/kks227_1471603215265DKr3x_PNG/6.png?type=w3)
![enter image description here](https://blogfiles.pstatic.net/20160819_192/kks227_1471603215676Kw9Xv_PNG/7.png?type=w3)
- union 연산
	- 두 집합을 하나로 합쳐줌
	- 둘 중 하나의 루트를 다른 하나의 루트의 자식이 되게 연결 시킴
	![enter image description here](https://blogfiles.pstatic.net/20160819_150/kks227_14716042144018beyG_PNG/8.png?type=w3)
=> union(3,7) 결과
![enter image description here](https://blogfiles.pstatic.net/20160819_149/kks227_14716042623990T08N_PNG/9.png?type=w3)
```
void merge(int a, int b)
{
	a=find(a);
	b=find(b);
	if(a==b) return ;
	p[a]+=p[b];
	p[b]=a;
}
```
