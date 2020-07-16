### 위상정렬(topological sort)
- 유항 그래프(DAG,Directed Acyclic Graph)의 정점을 정렬
- 정점을 왼쪽부터 오른쪽 방향으로 쭉 나열해 놓았을떄, 오른쪽에 있는 정정점에서 더 왼쪽의 정점으로 간선이 하나도 없음
![enter image description here](http://postfiles9.naver.net/20160830_216/kks227_1472490641094kuBx3_PNG/1.png?type=w3)
- 위상정렬 후 
![enter image description here](http://postfiles7.naver.net/20160830_134/kks227_1472490641376hrX1i_PNG/2.png?type=w3)
- 위상정렬 결과는 여러개 일수 있음
- 위상정렬 불가능 ``` 그래프에 싸이클이 존재할떄``` 자기 자신으로 가는 크기 1인 싸이클 역시 이 경우 ㅔ포함
- 위상 정렬 가능 조건은 DAG의 형태 (유형directed , acyclic 유항그래프)
- 필요할떄는 반드시 자신보다 선행되어야 할일 다 끝내야만 작업에 들어갈 수 있는 조건이 주어질떄
---
### 구현방법
- 종만북에는 dfs순회결과를 뒤집은 것이 위상정렬
- 다른방법
	1. 들어오는 간선이 없는(indegree =0)인 정점을 큐에 넣음
	2. 정점 개수만큼 이 행동을 반복. 큐의 front원소를 뺴서 그 정점에서 나가는 간선은 모두 삭제한다. 이때 삭제하면서 indegree =0인 새로운 정점이 생기면 그것들도 큐에 넣는다
	3. 이때 큐에서 빼는 정점 순서가 위상 정렬 결과이다
- ```loop를 Edge 개수만큼 돌기전에 큐가 비어리면 위상정렬 불가능```
	- 즉 위의 의미는 cyclic (싸이클이 존재)
- 도중에 ```큐의 크기가 2이상인 경우가 생기면 결과가 2개이상```
	- 결과가 2개 이상이라는 의미
	-  매 선택지가 큐에 들어있는 것 중 아무거나 뺴는 것인데, 왜냐면 큐에 들어있다는 건 그 정점은 indgree=0이란 의미로 아무거나 빼도 위상정렬 결과는 조건을 훼손하지는 않음
- 샘플 코드
```
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
int main(){
    int N, M, indegree[1000] = {0};
    vector<int> adj[1000];
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int K, prev, curr;
        scanf("%d", &K);
        if(K == 0) continue;
 
        scanf("%d", &prev);
        for(int i=1; i<K; i++){
            scanf("%d", &curr);
            indegree[curr-1]++;
            adj[prev-1].push_back(curr-1);
            prev = curr;
        }
    }
 
    int result[1000];
    queue<int> Q;
    // 위상 정렬 시작: 큐에 indegree가 0인 정점을 다 넣음
    for(int i=0; i<N; i++)
        if(indegree[i] == 0) Q.push(i);
 
    // 위상 정렬
    for(int i=0; i<N; i++){
        // 도중에 큐가 비면 불가능
        if(Q.empty()){
            puts("0");
            return 0;
        }
 
        int curr = Q.front();
        Q.pop();
        result[i] = curr+1;
        // 인접한 정점을 순회하면서 indegree 1씩 감소. 0이 되면 큐에 넣음
        for(int next: adj[curr])
            if(--indegree[next] == 0) Q.push(next);
    }
 
    // 결과 출력
    for(int i=0; i<N; i++)
        printf("%d\n", result[i]);
}
```
