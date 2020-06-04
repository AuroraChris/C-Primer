// "定义"(非声明）在类内部的函数是隐式的inline函数

// 内置的赋值运算符把它左侧的运算对象当成左值返回，且返回的类型是引用
// int a = 10;
// (a+=1) = 20;  结果 a => 20
// decltype(a+=1) => int&
// 这个特性当我们在设计内置运算符的重载时很重要，因为我们要尽可能与原本
// 的内置运算符的特性保持一致。估我们通常也是要返回一个引用

// IO类型如istream, ostream等属于不能被拷贝的类型，所以我们只能通过
// 引用来传递它们。而且因为读取和写入的操作会改变流的内容，所以这两个函数
// 接受的都是普通饮用而非对常量的引用

// 构造函数不同于其他成员函数，它不能被声明成const的。当我们创建类的一个
// const对象时，直到构造函数完成初始化过程，对象才能真正取得其“常量”属性。
// 因此，构造函数在const对象的构造过程中可以向其写值。

// 编译器创建的合成的默认构造函数会按照以下规则来初始化类的数据成员：
// 1. 如果存在类内的初始值，则会直接用它们来初始化成员
// 2. 否则就默认初始化该成员，一般内置类型如int, double会被初始化成一个
// 奇异值，而string会被初始化成空字符串

// 友元的声明仅仅指定了访问的权限，而非一个通常意义上的函数声明。因此我们
// 必须在友元声明之外专门对友元函数进行声明。通常我们会将这些友元函数的再次
// 声明放在同一个头文件（但在类的外部）
