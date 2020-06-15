// 一般而言C++有三个内存，分为 static memory, automatic memory, dynamic
// memory (static memory, stack memory, heap memory)。static memory
// 分为局部static对象，类static数据成员，定义在任何函数之外（global scope）
// 的变量。要注意，局部（函数中）static和类static和全局static互不影响。

// 接受指针参数的智能指针构造函数是 explicit 的。因此我们不能将一个内置指针隐式
// 转换为一个只能指针，必须使用直接初始化形式来初始化一个只能指针。如
// shared_ptr<int> p1 = new int(1024);  非法
// shared_ptr<int> p2(new int(1024));   合法
//
// shared_ptr<int> clone(int p) {
//     return new int(p);   非法
//     return shared_ptr<int>(new int(p))  合法
// }
// 
// void process(shared_ptr<int> x) {
//     .....
// }
// auto p = new int();
// process(new int());  非法，无法从int*转为shared_ptr<int>
// process(p);  非法，无法从int*转为shared_ptr<int>


/**
 * void process(shared_prt<int> ptr)
 * {
 *     // 使用 ptr
 * }
 * 
 * 如果用以下调用方法：
 * shared_ptr<int> p(new int(40));
 * process(p);
 * int i = *p;  合法，因为经过process之后p的引用计数依然为1
 * 
 * 但如果用以下调用方法：
 * int *p(new int(40));
 * process(shared_ptr<int>(p));
 * int j = *p;  非法，因为 shared_ptr<int>(p)是一个临时对象，当传入函数时首先
 * 将p的引用数+1，因为我们创建了一个临时对象。然后我们再+1，因为值传递时被拷贝。但
 * 当进入函数时临时对象已经被自动销毁，然后在函数结束后再递减p的引用计数。导致引用
 * 计数为0后p指向的内存被释放了。故在函数外面，p已经变成了一个空悬指针
 **/

// 如果两个shared_ptr是互相独立创建的（哪怕是指向同一个指针），他们的引用计数也是
// 分开的，如：
// int *p = new int(4);
// shared_ptr<int> ptr1(p);  ptr1引用计数为1
// shared_ptr<int> ptr2(p);  ptr2引用计数为1
// 但是：
// shared_ptr<int> ptr3(ptr1); ptr1和ptr3是关联创建的，所以它们的引用计数为2


// 就算函数之中发生了异常，且未被捕获，shared_ptr也能在函数退出（中断）后正常被销毁




