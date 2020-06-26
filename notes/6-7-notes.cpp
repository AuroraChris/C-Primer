// 如果成员是const，引用或者属于某种未提供默认构造函数的类类型，我们必须通过构造函数
// 初始值列表为这些成员提供初始值，而不能选择通过构造函数体内赋值的方法。因为如果没有
// 在构造函数的初始值列表中显式地初始化成员，则该成员将在构造函数函数体执行之前进行
// 默认初始化，那么对于const，引用和未提供默认构造函数的类类型来说，它们无法在构造函
// 数函数体执行之前顺利进行默认初始化，编译器会报错

// 成员的初始化顺序与它们在类定义中的出现顺序一致：第一个成员先被初始化，然后第二个，
// 以此类推。构造函数初始值列表中初始值的前后位置关系不会影响实际的初始化顺序。

// 通过书写形如 T() 的表达式可以显式地进行值初始化，如
// int a(10);  a => 10
// string s("world");  s => "world"

// 当我们使用 explicit 关键字声明构造函数时，它将只能以直接初始化的形式使用（不能
// 用于拷贝初始化）。而且编译器将不会在自动转换过程中使用该构造函数
// 我们用过的一些标准库中的类含有单参数的构造函数：
// 1. 接受一个单参数的 const char* 的 string 构造函数不是 explicit 的，所以
// 当我们需要使用string的时候，我们可以直接用 const char* (即一个C风格的字符串)
// 来直接替代。
// 2. 接受一个容量参数的vector构造函数是 explicit 的，所以我们在需要使用一个容量
// 为10的vector时，显然不能直接用10代替

// static关键字只能出现在类内部的声明语句中，虽然我们仍然可以将成员函数在类外定义，
// 但不能加上static关键字。只能在类内的声明里加上

// 对于只声明过但没有定义过的类，我们称之为不完全类型。不完全类型只能在非常有限的情景
// 下使用：可以定义指向这种类型的指针或引用，也可以声明（但是不能定义）以不完全类型
// 作为参数或者返回类型的函数。但静态数据成员则不受上述限制，即不完全类型可以定义一个
// 静态数据成员

// 如果程序崩溃，输出缓冲区不会被刷新：当一个程序崩溃后，它所输出的数据很可能停留在输出
// 缓冲区中等待打印。所以当我们用打印的方法调试一个已崩溃的程序时，需要确定数据已经被刷新
// 了。不然很容易出现误判

// 当一个 fstream 对象被销毁时，close会自动被调用。因此我们在循环中创建一个 fstream
// 对象后，不需要显式调用close

