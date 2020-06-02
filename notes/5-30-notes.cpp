// 位于头文件的代码中一般不应该使用using声明，这是因为头文件的内容会拷贝
// 到所有引用它的文件中去，如果头文件里有某个using声明，那么每个使用了该
// 头文件的文件都会有这个声明，那么很有可能会产生名字冲突

// 触发getline函数返回的那个换行符实际上被丢弃了，得到的string对象中并
// 不包含该换行符

// 切记string.size()返回的类型是string.size_type，它是一个无符号类型，
// 故不可与有符号类型如int一起做运算

// 当把string对象和字符字面值及字符串字面值混在一条语句中使用时，必须确保
// 每个加法运算符（+）的两侧的运算对象至少有一个是string

// 在C++里string类型其实就是C语言里的 const char*，因此对string进行
// 索引操作得到的就是 &char。空字符即 '\0'

/**
 * 在使用范围for循环，即 for (declaration: expression)时不能改变expression
 * 的大小。因为范围for循环其实等价于传统for循环：
 * for (auto declaration: expression.begin(), end=expression.end(); beg!=end; ++beg)
 * 其中预存了迭代器 end()，所以改变expression的大小会影响 end()
 **/




