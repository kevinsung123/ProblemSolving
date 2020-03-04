### sort algorithm
- <algorithm>파일헤더에 존재
- sort(start, end) 를 이용하여 [start,end) 범위에있는인자를 오름차순 정렬
	- start는 포함, end는 미포함
- quick sort 기반으로 구현되어있어 시간 복잡도는 O(nlogn)
### 1. 원형 및 사용법
```
template <typename T>
1) void sort(T start, Tend)

2) void sort(T start, Tend,Compare comp)
```
- 3번째 인자 comp에따라 정렬 가능
```
sort(arr,arr+n);
sort(v.begin(), v.end());
sort(v.begin(), v.end(),compare); //사용자정의함수
sort(v.begin(), v.end(),greater<자료형>()); //내림차순
sort(v.begin(), v.end(),less<자료형>()); //오름차순

```

