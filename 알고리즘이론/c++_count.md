**# int cout (InputIterator first, InputIterator last, const T& val)**

- Iterable한 것(배열, 스트링 등)에서 값 val이 몇 개 존재하는지 개수를 반환함

- #include <algorithm> 을 포함시켜주어야 함

**# 이 함수의 인자로 사용되는 값을 이해하기 위한 예시코드**

- iterator(배열 혹은 스트링)에다가 begin, end를 붙여주면 주소값을 가리키는듯 하다.  
여기에 + 혹은 -를 해주면 다음 혹은 이전 원소가 있는 주소를 가리키게됨.

```
#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);

    string s = "abc";

    cout << *s.begin() << endl;        // 'a' 출력
    cout << *(s.begin()+1) << endl;    // 'b' 출력
    cout << *(s.end()-1) << endl;      // 'c' 출력
    cout << *s.end() << endl;          // ''  출력(아무것도 출력하지 않음)
}
```

**# 정수 배열에서 숫자 6의 개수를 카운트하는 예시코드**

```
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);

    // 첫 번째 방법
    int a[] = {1, 2, 3, 4, 5, 6, 6};
    cout << count(a, a+7, 6) << endl; // 2 출력       여기서 7은 원소의 개수를 의미함

    // 두 번째 방법
    vector<int> myvector(a, a+7);
    int cnt = count(myvector.begin(), myvector.end(), 6);  // begin, end는 벡터에서 사용되는 표현인가봄
    cout << cnt << endl;              // 2 출력
}
```

**# string에서 알파벳 개수를 카운트하는 예시코드**

```
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    for (int i = 'a'; i <= 'z' ; i++)
    {
        cout << count(s.begin(), s.end(), i) << ' ';     // 1 1 0 0 1 0 0 0 .....  0 0 0
    }
}
```
