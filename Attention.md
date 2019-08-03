# 关于C++刷题需要注意的小地方

1. 输出保留x为小数

   - C++中的写法

   ```c++
   #inlcude <iomanip>
   //只需设置一次，对之后所有输出数字都有效
   cout.setf(ios::fixed);
   cout << setprecision(x);
   ```

   - C中的写法

   ```C
   #include <stdio.h>
   //%.xf\n中的x就是需要保留的小数位数，默认6位
   printf("%.xf\n", result);
   ```

2. 中字符串的相互比较

    ```C++
    char a[] = "aaa", b[]="aaa";
    cout << strcmp(a, b) << endl; //输出0为相等，非0为不等

    string A = "AAA", B = "AAA";
    cout << A.compare(B) << endl; //输出0为相等，非0为不等
    cout << (A == B) << endl; //输出1为相等，0为不等
    ```

3. 删除字符串中的指定字符

    ```C++
    //其中a为删去的特定字符
    str.erase(std::remove(str.begin(), str.end(), 'a'), str.end());
    ```

4. 删去容器中特定元素

    ```C++
    #include <algorithm>    // std::remove_if
    ```
