// forward_list 没有 size 操作

// 与vector和deque不同，list的迭代器不支持 < 运算，只支持递增、递减、==以及！=运算。
// 因为vector和deque将元素在内存中连续保存，而list则是将元素以链表的方式储存，因此前
// 者可以方便地实现迭代器的大小比较（类似指针的大小比较）来体现元素的前后关系。而在list
// 中，两个指针的大小关系与它们指向的元素的前后关系不一定是吻合的，所以实现 < 运算将会
// 非常困难和低效

/**
 * 形如 C c1(c2) 或者 C c1=c2 容器拷贝时，两个容器类型以及容器元素类型必须相同。 
 * 但形如 C c(iter1, iter2) 容器拷贝，或 seq.assign(iter1, iter2)时，两个
 * 容器类型可以不相同, 但容器元素类型必须相容（可以互相转换）
 **/

/**
 * 除 array 外，swap 不对任何元素进行拷贝、删除或插入操作，因此可以保证在常数时间内完成。
 * 
 * 元素不会被移动的事实意味着，除string外，指向容器的迭代器、引用和指针在swap操作之后都
 * 不会失效。它们仍然指向swap操作之前所指的那些元素。但是在swap之火，这些元素已经属于不同
 * 的容器了。比如，iter 在swap之前指向 vec1[3]这个string元素，那么在swap之后它指向了
 * vec2[3]这个string元素。与其他容器不同，对一个string调用swap会导致迭代器、引用和指针失效。
 * 
 * 与其他容器不同，swap两个array会真正交换他们的元素
 * 
 * 对于array，在swap操作之后，指针、引用和迭代器所绑定的元素保持不变，但元素值已经与另一个
 * array中对应的元素值进行了交换
 **/

// 我们只能将相同容器类型且具有相同容器元素类型的两个容器进行运算符比较

// 当我们用一个对象来初始化容器，或者将一个对象插入到容器中时，实际上放入到容器中的是对象值
// 的一个拷贝，而不是对象本身。对容器中元素的任何改变都不会影响到原始对象，反之亦然

/**
 * 向容器添加元素后：
 * 1. 对于 vector 和 string，如果存储空间被重新分配，则指向容器的迭代器、指针和引用都会
 * 失效。如果存储空间未重新分配，指向插入位置之前的元素的迭代器、指针和引用仍然有效，但指向
 * 插入位置之后元素的迭代器、指针和引用都会失效。
 * 2. 对于 deque，插入到除首尾位置之外的任何位置都会导致迭代器、指针和引用失效。如果在首尾
 * 位置添加元素，迭代器都会失效，但指向存在的元素的引用和指针不会失效。
 * 3. 对于 list 和 forward_list，指向容器的迭代器(包括尾后迭代器和首前迭代器)、指针和引用
 * 仍然有效。
 * 
 * 从容器中删除元素后：
 * 1. 对于 list 和 forward_list，指向容器其他位置的迭代器（包括尾后迭代器和首前迭代器）、
 * 引用或指针也会失效。
 * 2. 对于 deque，如果在首尾之外的任何位置删除元素，那么指向被删除元素外其他元素的迭代器、引用
 * 或指针也会失效。如果是删除deque的尾元素，则尾后迭代器也会失效，但其他迭代器、引用和指针不受
 * 影响；如果是删除首元素，这些也不会受影响。
 * 3. 对于 vector 和 string，指向被删除元素之前元素的迭代器、引用和指针仍有效。当我们删除元素
 * 时，尾后迭代器总会失效。
 **/






