// 如果函数的形参在函数中不会被改变，我们最好将其设置为const，因为const
// 形参可以接收const对象、字面值或者需要类型转换的对象。如：
// function(const string &s) 不仅可以接收const string，还可以接收
// 字符串字面值，即C风格的字符串。但如果不设为const则不行
// function("world") 合法
// 如果 function(string &s), 则 function("world") 非法

/**
 * 不能返回局部对象的引用或指针：
 * const string &func()
 * {
 *     string ret = "world";
 *     if (!ret.empty())
 *         return ret;  非法，我们返回了ret这个局部变量的引用
 *     else
 *         return "empty";  非法，我们返回了一个函数内的临时局部变量
 * }
 * 如果把函数返回类型改为 const string func() 那么上面的函数将是合法的，
 * 因为我们并没有返回局部变量的引用或指针，我们返回的是一个经过拷贝的变量或
 * 临时值。
 **/ 

/**
 * 当要返回数组的指针时，有以下几种方法：
 * 1. 使用类型别名：
 * typedef int arrT[10] 或者 using arrT = int[10]
 * arrT *func(int i)
 * 
 * 2. 声明数组的返回类型：
 * int (*func(int i))[10] 返回一个 int[10]
 * 
 * 3. 使用尾置返回类型：
 * auto func(int i) -> int(*)[10]
 * 
 * 4. 使用decltype:
 * int arrT[10];
 * decltype(arrT) *func(int i)
 **/

/**
 * 当要返回函数的指针时，有以下几种方法：
 * 1. 使用using类型别名：
 * using F = int(int*, int) 或者 using PF = int(*)(int*, int)
 * F *func(int) 或者 PF func(int)
 * 
 * 2. 使用typedef类型别名：
 * typedef int(*PF)(int*, int);
 * PF func(int)
 * 
 * 3. 使用尾置返回类型：
 * auto func(int) -> int(*)(int*, int)
 * 
 * 4. 使用decltype：
 * decltype(PF) *func(int)
 **/

// 函数重载时对顶层的const判定为同一个函数，而对底层的const判定为合法重载。
// 当传递一个非常量或者指向非常量对象的指针时，编译器会有限使用非常量版本的重载函数

// 在不同的作用域中无法重载函数名，因为内层作用域的同名对象（不一定也是函数）会隐藏
// 外层作用域的同名函数，导致无法重载，如
// string read();
// void func()
//     bool read = true;
//     string s = read();  调用上一行的 bool read，非法。外层read函数被隐藏


// 用作默认实参的名字在函数声明所在的作用域内解析，但这些名字的求值过程发生在函数调用时：
// int a = 10;
// string s = "world";
// string screen(int c = a, string d = s)
// void func()
// {
//     a = 20;
//     string s = "hello";
//     screen();  调用的是 screen(20, "world")
// }

// 内联函数的定义对编译器而言必须是可见的，以便编译器能够在调用点内联展开该函数的代码，
// 所以仅有函数的原型不够。并且，与一般函数不同，内联函数有可能在程序中定义不止一次，此时
// 必须保证在所有源文件中定义完全相同，把内联函数的定义放在头文件中可以确保这一点。


