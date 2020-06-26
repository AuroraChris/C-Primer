// 如果父类的虚函数是private或是protected的，但这些非public的虚函数
// 同样会存在于虚函数表中，所以，我们同样可以先通过虚函数指针vptr找到虚
// 函数表，然后通过指针操作访问到虚函数表中任意一个虚函数（哪怕它是private
// 或者是protected的）


// 必须明确一点：每个类都负责定义各自的接口，要想与类的对象交互必须要使用
// 对象的接口，即使这个对象是派生类的基类部分也是如此。尽管从语法上来说我
// 们可以在派生类构造函数体内给它的公有或受保护的基类成员赋值，但是最好不要
// 这样做。


// 即使一个基类指针或者引用绑定在一个派生类对象上，我们也不能执行从基类向
// 派生类的转换，如：
// Derived d;
// Base *b = &d;
// Derived *p = b;  错误，不能将base转换成derived

// 如果一个派生类Derived中有一个新的虚函数，而这个虚函数在基类Base中没有,
// 那么我们不能通过 Base *b = &d 或者 Base &b = d 来动态调用Derived中
// 的那个独有的新的虚函数。


// 当我们用一个派生类对象为一个基类对象初始化或者赋值时，只有该派生类对象中
// 的基类部分会被拷贝、移动或赋值，它的派生类部分会被忽略掉。如：
// Derived d;
// Base b(d);
// b = d;
// 当构造b时，我们只能处理base被derived继承的那部分成员，同时忽略derived
// 独有的那些成员。因为我们只是借用derived中继承自base的那部分来初始化base。
// 相当于derived被切掉了只属于它而不属于base的那部分成员

// 通常情况下，如果我们不使用某个函数，则无需为该函数提供定义。但是我们必须
// 为每一个虚函数提供定义，而不管它是否被用到。

// 派生类的成员或者友元只能通过派生类对象来访问基类的受保护成员，派生类对于一个
// 基类对象中的受保护成员没有任何访问权。换句话说，假如基类Base有一个protected
// 的成员 mem，则它的派生类Derived可以在它里面的成员函数或者友元函数里通过
// d.mem (d是一个Derived的对象)或者直接 mem (就是隐式的this.mem)来访问mem，
// 因为可以看出，这里两种方式的访问其实都是访问Derived中继承的Base的部分，而不是
// 直接访问一个Base对象中的protected部分。因此我们不能在Derived的成员函数或
// 友元函数中用 b.mem (b是一个Base对象)来访问mem。当然，我们不能在类外用 d.mem,
// s.mem（因为是protected），或者 Base::mem, Derived::mem（因为不是static）

// 当Base中某个private的构造函数（也有可能是default的构造函数）在Derived类的
// 某个构造函数中被显式调用时，它将报错为inaccessible，而这个Derived的构造函数
// 会被隐式delete

// 派生访问说明符对于派生类的成员及其友元能否访问其直接基类的成员没有什么影响，对
// 基类成员的访问权限只与基类中的访问说明符有关。而派生访问说明符目的是控制派生类
// 用户（包括派生类的派生类在内）对于基类成员的访问权限。我们可以这样认为，如果
// Derived: private Base，那么对于Derived从Base继承来的那部分所有的成员都将
// 在Derived拥有private的权限。如果Derived: protected Base，那么Derived从
// Base中继承来的那部分原来是public和protected的会拥有protected的权限，而private
// 仍然保持private的权限

/** 派生类向基类转换的可访问性：
 * Derived: public Base -> 用户代码可以使用Derived向Base的转换，否则不能；
 * 无论是何种继承方式，Derived向Base的转换对于Derived的成员和友元来说永远可行；
 * Derived: public(protected) -> Derived的派生类中的成员和友元可以使用Derived
 * 向Base的转换，否则不能
 **/

/**
 * class Base {
 *     friend class Pal;
 *     protected:
 *         int prot_mem;
 * }
 * 
 * class Sneaky: public Base {
 *     int j;
 * }
 * 
 * class Pal {
 *     public:
 *         int f(Base b) {return b.prot_mem;}  正确，Pal是Base的友元
 *         int f2(Sneaky s) {return s.j;}  错误，Pal不是Base的友元
 *         int f3(Sneaky s) {return s.prot_mem;}  正确，Pal是Base的友元
 * }
 * 
 * f3是正确的，因为Pal是Base的友元，Pal的成员函数能访问Base对象的成员，这种成员
 * 包括Base对象内嵌在其派生类Sneaky对象中的情况。也就是Sneaky中有一部分是从Base
 * 继承来的，这部分我们仍然可以用Base的友元来访问。但要注意友元的派生类就没有类似的
 * 特殊访问功能
 **/

// 如果派生类中拥有一个与基类中某个成员同名的成员，那么派生类的名字将会隐藏基类的名字。
// 但这种隐藏只是相当于在搜索中先找到了派生类的这个成员所以才停止搜索，而并非真的在内存
// 中覆盖（内存中同时有两块区域分别储存这两个同名成员）。同样的，如果派生类中有一个与基类
// 中某个成员函数同名的成员函数（不管它们是否具有相同的参数列表），就像内层作用域中的同名
// 函数无法重载外层作用域中的同名函数一样，派生类中的这个成员函数也会直接隐藏基类中的那个
// 同名成员函数。当我们从派生类调用一个成员函数，如果在派生类里顺利找到了这个成员函数，且
// 参数列表匹配，那么我们成功调用。但如果因为参数列表不匹配，则编译器会直接报错而不会向上
// (基类)查找。只有在派生类中没有找到这个名字的函数时，我们才会向上搜索同名函数



