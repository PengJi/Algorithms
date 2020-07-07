# priority_queue
`priority_queue<Type, Container, Functional>`
Type为数据类型， Container为保存数据的容器，Functional为元素比较方式。  
如果不写后两个参数，那么容器默认用的是vector，比较方式默认用operator<，也就是优先队列是大顶堆，队头元素最大。

## 大顶堆
```c
#include<iostream>
#include<queue>
using namespace std;
 
int main(){
    priority_queue<int> p;
    p.push(1);
    p.push(2);
    p.push(8);
    p.push(5);
    p.push(43);
    for(int i=0;i<5;i++){
        cout<<p.top()<<endl;
        p.pop();
    }
    return 0;
}
```

## 小顶堆
```c
#include<iostream>
#include<queue>
using namespace std;
 
int main(){
    priority_queue<int, vector<int>, greater<int> >p;
    p.push(1);
    p.push(2);
    p.push(8);
    p.push(5);
    p.push(43);
    for(int i=0;i<5;i++){
        cout<<p.top()<<endl;
        p.pop();
    }
    return 0;
}
```

## 自定义优先级
### 重载运算符
```c
// 重载 < 运算符，实现小顶堆 
bool operator<(My_Type a,My_Type b)
{
    // 定义排序规则 
    if(a.x==b.x) return a.y>b.y;
    return a.x>b.x; 
}
```
### 仿函数
```c
// 仿函数，实现小顶堆 
struct cmp
{
    // 定义排序规则 
    bool operator() (My_Type a,My_Type b )
    { 
        if(a.x==b.x) return a.y>b.y;
        return a.x>b.x; 
    }
}; 
```
示例
```c

#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
struct Node{
    int x,y;
    Node(int a=0, int b=0):
        x(a), y(b) {}
};
 
struct cmp{
    bool operator()(Node a, Node b){
        if(a.x == b.x)  return a.y>b.y;
        return a.x>b.x;
    }
};
 
int main(){
    priority_queue<Node, vector<Node>, cmp>p;
    
    for(int i=0; i<10; ++i)
        p.push(Node(rand(), rand()));
        
    while(!p.empty()){
        cout<<p.top().x<<' '<<p.top().y<<endl;
        p.pop();
    }//while
    //getchar();
    return 0;
```
