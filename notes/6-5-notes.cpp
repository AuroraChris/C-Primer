/**
 * C++在同一定义域里不允许重复定义，无论是在类的定义域，还是在函数的定义域中。如
 * struct X 
 * {
 *     int a = 10;
 *     string a = "w";  非法，redefinition
 *     a = 20;  非法，在类中变量前必须带有类型名
 * }
 * 
 * int main()
 * {
 *     int x = 10;
 *     double x = 20.00;  非法，redefinition
 *     x = 20;  合法
 * }
 **/

// 在类外我们不能用 class::variable 的形式访问类中的 non-static 变量，我们只能用
// object或者object的指针、引用来访问。但我们可以在类外使用类中定义的类型，
// 即通过 class::type

/**
 * 类的定义分两步骤：
 * 1. 首先编译成员的声明
 * 2. 直到类全部可见后才编译函数体
 * 
 * class X 
 * {
 *     void foo(int a)
 *         {
 *            cout<<a<<endl;  这里a是传入的参数，和后面的成员a无关
 *         }
 *     int a = 20;
 * }
 * 
 * 如果改成:
 * 
 * int a = 10;
 * class X 
 * {
 *     void foo()
 *         {
 *            cout<<a<<endl;  这里会直接使用成员a，而不会使用全局a
 *         }
 *     int a = 20;
 * }
 * 
 * 再比如改成:
 * 
 * int a = 10;
 * class X 
 * {
 *     void foo()
 *         {
 *            cout<<a<<endl;
 *            此时会使用全局a，是因为首先成员函数定义域中无a，然后成员无a,s
 *            最后才会去类外作用域查找
 *         }
 * }
 **/

// 成员函数以外（类内）的作用域只有对成员函数体内可见，但对成员函数的返回类型，
// 参数类型都不可以见（它们只能看见成员函数定义之前的东西），比如:
// struct X {
//     pos foo(pos height) {  此行的两个pos未定义
//         pos width = 10;  此行的这个pos已定义，即之后类型别名定义
//     }
//     using pos = int; 或者 typedef int pos;
// }
// 但如果在将 using pos = int; 或者 typedef int pos 放在foo这个成员函数
// 定义之前，那么一切都将可见（成员函数的返回类型和参数类型无法提前看见之后定义的类型
// 或者定义的成员）

// 定义在类外的成员函数，函数名前必须加上类的声明符，以表示这个函数是类的成员函数。
// 而函数的返回值可以不加类的声明符，若不加，则表明这个返回类型是类外定义的；若加了，
// 则表示这个返回类型是在类中定义的。但对函数的参数则没有必要加类的声明符，因为编译器
// 已经默认将函数的参数的作用域归于类的作用域，故不加也能看见类中定义的东西
// using pos = int;
// struct X {
//     using pos = string;
//     pos foo(pos);   
// }
// pos X::foo(pos) {  这里的返回类型pos是int，但参数pos是string
//    ....
// }
// 如果改成：
// X::pos X::foo(pos) 则两个都是string
// 但要注意 using pos = string 一定要放在声明 foo 前，否则如前大段只是点所述，
// 成员函数的返回类型和参数类型是不能提前看见之后定义的类型的

