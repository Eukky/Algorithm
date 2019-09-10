// 简单表达式计算

// 给定一个合法的表达式字符串，其中只包含非负整数、加法、减法以及乘法符号（不会有括号），例如7+3*4*5+2+4-3-1，请写程序计算该表达式的结果并输出；

// 输入描述:
// 输入有多行，每行是一个表达式，输入以END作为结束

// 输出描述:
// 每行表达式的计算结果

// 输入例子1:
// 7+3*4*5+2+4-3-1
// 2-3*1
// END

// 输出例子1:
// 69
// -1


//本地通过，牛客网段错误
#include <iostream>
#include <stack>
using namespace std;
int priority(char c){
    if(c == '*' || c == '/'){
        return 2;
    }else{
        return 1;
    }
}
int cal(char c, int a, int b){
    if(c == '*'){
        return (a * b);
    }else if(c == '/'){
        return (b / a);
    }else if(c == '+'){
        return (a + b);
    }else{
        return (b - a);
    }
}

int main(){
    string s;
    while(getline(cin, s)){
        stack<int> nums;
        stack<char> op;
        int num = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] - '0' <= 9 && s[i] - '0' >= 0){
                nums.push(s[i] - '0');
            }else{
                if(op.empty()){
                    op.push(s[i]);
                }else{
                    if(priority(op.top()) >= priority(s[i])){
                        int a = nums.top();
                        nums.pop();
                        int b = nums.top();
                        nums.pop();
                        nums.push(cal(op.top(), a, b));
                        op.pop();
                        op.push(s[i]);
                    }else{
                        op.push(s[i]);
                    }
                }
            }
        }
        while(!op.empty()){
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(cal(op.top(), a, b));
            op.pop();
        }
        cout << nums.top() << endl;
    }
    return 0;
}