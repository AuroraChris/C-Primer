// 当使用一个迭代器遍历一个 map，multimap，set 或者 multiset 时，迭代器按照
// 关键字升序遍历元素

// map 和 set 的关键字都是const的，即不能修改，因此不能用迭代器(inserter、
// back_inserter)等修改它们中元素的值。正确的方法是使用关联容器特有的insert操作
// 如 insert, emplace等。

// 使用 lower_bound 和 upper_bound 时，如果目标元素不在容器中，则他们两个都会
// 返回目标元素应该插入的那个位置的迭代器，如 {1,2,3,4,5,8,9,11}，目标元素是6，
// 则他们都返回指向 8 的迭代器

