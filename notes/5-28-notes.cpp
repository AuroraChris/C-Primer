/* 
在MacOS里“文件结束符”输入是 control+D

大多数机器的1个字 = 4 or 8 字节，1一个字节 = 8个bit（位）

最好不要将带符号数与无符号数一起做运算（因为带符号数会自动转换为无符号数），
在做无符号数运算的时候也要小心，因为很有可能运算的结果是负数，那么对于无符
号数来说会自动进行意向不到的转换

字面值常量包括：
1. 整型和浮点型字面值如 20（十进制），024（八进制）， 3.14159（浮点型）
2. 字符字面值如 'a', 'b'
3. 字符串字面值如 "a", "b", "abc" 字符串字面值的类型实际上是一个由
常量字符构成的数组（array），编译器会自动地在每个字符串的结尾处（也就是
array的最后一位添加一个空字符'\0'，因此字符串字面值的实际长度要比它的内容
多1。即 "abc"的长度为4
4. bool型字面值如 true，false
4. 指针型字面值如 nullptr

！！！在C++里初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，
而赋值的含义是把对象的当前值擦除，以一个新的值来替代！！！
*/


// 变量初始化有很多种方法，其中有一种叫做列表初始化（list initialization）。
// 当用于内置类型的变量时，列表初始化有一个重要的特点：如果初始值存在丢失信息
// 的风险，则编译器将报错：
long double ld = 3.1415926536;
// int a{ld}, b = {ld}; 
// 报错 error: type 'long double' cannot be narrowed to 'int' in initializer list
int c(ld), d = ld;
// 正确执行转化，但却丢失了部分值
