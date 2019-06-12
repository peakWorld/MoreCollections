#include<iostream>
// 数据类型: 数据的意义和可以在数据上进行的操作; 算术类型 和 空型
// 算术类型: 字符、整型、布尔值和浮点型

// 字节(B) => 可寻址的最下内存块, 一般8bit
// 1MB = 1024KB = 1024 * 1024B
// 字 => 存储的基本单元, 通常由几个字节组成
// 地址 => 与一块内存关联的数字
// 为了赋予内存中某个地址明确的含义, 必须知道存储在地址的数据类型; 类型决定数据所占的比特值以及如何解释这些比特的内容

// 浮点型: float/double 一般使用double型

// 有符号整型: short(2)/int(2)/long(4)/long long(8)  
// 有符号整数 首位bit 0表示整数, 1表示负数;  
// 负数的二进制: 绝对值的二进制 取反 加1

// 无符号整型: unsigned/unsigned short/unsigned long
// 无符号整数 不会小于0 

// 类型转换: 有符号整数转成无符号整数(赋值操作), 如果有符号整数是负数, 那么该负数的二进制表示全部当成数值位计算

// 有符号整数 和 无符号整数 混合计算
// 2个数正常计算, 得到的结果是一个无符号整数; 但是如果这个数是一个负数, 那么其表示符号的bit位也会当成数值

// 字面值常量
// 字符字面量 'a'  
// 字符串字面量 "abc!" 每一个字符串字面量的结尾都会加一个空字符'\0'
// 布尔字面量 bool b = false

// 变量(对象): 具名的、可供程序操作的存储空间。(具有数据类型的内存空间)
// 初始化: 是指在创建变量的时候赋初始值
// 赋值: 将当前值擦除赋予新值
// 尽量初始化内置类型的变量

// 声明变量: 定义变量类型和名字; 不能赋初始值, 赋值就会忽略extern, 变成声明定义;  
// extern int i; 
// 定义变量: 一般赋初始值; 不仅定义变量类型和名字, 还申请内存空间, 可能赋值
// int i;

// 符合类型 引用和指针

// 引用: 变量别名,始终指向初始化对象,对引用的操作即是对初始对象的修改; 引用初始化时必须是对象(不能是字面量), 不能给引用赋值引用
// 引用类型和引用数据类型必须一致
// int a = 2; int &b = a;

// 指针: 指针类型 和 指针指向对象类型 必须一致; 给指针赋值, 就是指向一个新对象
// 定义指针和去地址符 int *pi = &i;
// 解引用 取指向对象 *pi; 只适用明确指向对象的指针(指针 内存空间下一位, 空指针, 无效指针, 均无效)
// 空指针定义 int *pi = 0/nullptr; (对指针*pi只能初始化0[此时指针指向地址0x0], 其他任何赋值0都会报错)
// void型指针 void *vi = p; p可以是任意类型指针。
// 指向指针的指针 int **ppi = &pi;
// 指向指针的引用 int *&r = pi;

// const 限定符: 必须赋初始值, 后续不能修改
// const int c = 512;
// const 变量, 在编译阶段, 会使用值替换所有变量; 一般在单文件中生效, 如果要在多文件中生效, 那么在声明和定义变量的时候必须加上extern关键字
// 对常量的引用: const int &cr = c; 不能通过引用cr 修改 常量c的值[可以转成int即可]
  // 不能使用普通引用 指向 常量(int &cr = c 是错误的, 这样可以使用cr修改c的值)
  // 只对引用可进行的操作做了限定, 对引用 指向对象 未做限定[可以是常量和非常量]
// 指向常量的指针: const int *p = c; 不能通过指针p修改对象c的值
  // 只对引用可进行的操作做了限定, 对引用 指向对象 未做限定
// 常量指针: 指针自身是对象, 所以也可以用const限定
  // int *const pi = &c;  指针这个对象的值不改变, 即指向的对象始终不变
  // 可以通过*pi修改对象的值
// 顶层const 对象自身为常量; int *cont pi = &i;
// 底层const 复合类型的基本类型为常量; const int *pi = &c; [引用 肯定是 底层const]
  // 底层的const变量 赋值 左右必须类型一致

// 常量表达式
  // 在编译阶段 计算结果 constexpr int i = get_size();

// 类型别名
  // 1. typedef double wages;  2. using wages = double;
  // typedef char *pchar; 明确 pchar是一个char型指针
  // const pchar s = 0;  明确 const限定类型pchar, 则s是一个常量指针, 且为空指针。
  // const pchar *ps; 明确 ps 是一个指针, *ps 是一个常量指针。

// auto i = 1, *p = &i; 更具值的类型来确定变量的类型。 但是一条语句中所有变量的基本类型必须一致。

// decltype(表达式) 根据表达式 确定类型
  // decltype(c) ci = 12; ci是const int 类型, 因为c是const int 类型
  // decltype((c)) cr = &c; cr是 对象c的引用, 因为c加了括号, 这样始终是引用类型

// 预处理器: 在编译之前执行的一段代码
  // 定义预定义变量 #define
  // #ifdef 变量已定义为真 | #ifndef 变量未定义为真  执行到遇见 #endif
  // 预编译, 将变量用值替换, 比如 #include<> 会将其替换成相应的头文件定义代码

int main() {

  int a = -42;
  unsigned b = 10;

  float c = 3.14159l;

  bool check = strcmp("a","a");

  std::cout << "有符号整数相加 a(int -42) + a(int -42) : " << a + a << std::endl;
  // 有符号整数和无符号整数相加, 将有符号整数转化为无符号整数, 但是负的有符号整数首位为1, 所以转为无符号整数后值变大( 正的有符号整数无影响 )
  std::cout << "有符号整数和无符号整数相加 a(int -42) + b(unsigned 10): " << a + b << std::endl;

  int d = {c};

  // a = c;
  std::cout << c << std::endl;
  int *p = &a; // int型指针p初始化赋值对象a的地址; 
  std::cout << "输出int型指针p指向的对象地址:" << p << "  对象的值:" << *p << std::endl;
  *p = b; // 指针的指向的内存(对象)没有改变, 对象数据改变 
  std::cout << "修改指针p的 指向地址 对应对象 的数据:" << *p << std::endl;
  p = &d; // 指针的指向内存发生改变, 那么对象肯定改变
  std::cout << "修改指针p的指向地址:" << p << "----" << *p << std::endl;

  int m = 1; // 定义int变量
  int &t = m; // m的引用t
  int *p2; // int型指针
  p2 = &m; // 取地址 赋值指针
  int s = *p2; // 解引用
  int *p1 = nullptr; // 空指针(推荐)
  int *p3 = 0; // 空指针
  void *p4 = &m; // void型指针可以赋值任何类型数据的地址
  int **pp = &p3; // 指针的指针: p3是个int型指针, &p3取指针的地址
  int *&r = p3; // 指针的引用: p3是个int型指针, r是对指针地址的引用

  const int c2 = 3; // 常量, 限定符(const); 默认文件生效
  const int &c2c = c2; // 常量引用, 对象不管是不是常量都可以赋值, 但是不能通过该引用修改对象
  const int &c3c = m; // c2是常量, m不是常量; 不能通过c2c,c3c修改对象的值, 但是可以通过其他方式修改m的值
  const int *p5 = &c2; // 指向常量的指针, 不能通过 *p5修改对象c2的值
  // int *p7 = &c2;
  // int &r7 = c2;
  // 对于常量c2, 指向常量的指针(p5)或引用(c2c)必须使用const限定; 但是使用const的限定的定义语句可以使用非常量赋值(c3c引用的对象是m)

  int *const p6 = &m; // 常量指针, 指针本身是一个常量, 即指针指向的对象不能改变, 但是还可以通过*p6修改对象的值
  const int *const p8 = &c2; // p8指针自身是一个常量指针, 但是需要该指针指向常量, 那么必须使用限定赋修饰该指针

  // m = c2;

  return 0; 
}

// 复合类型: 引用,指针
// 引用: int i = 0, int &r = i; 引用必须指向对象, 不能指向字面量
// 指针: int *p = &i; 指针的值是对象地址。
// 取地址: &i; 获取对象的地址
// 解引用: *p; 获取指针指向的对象, 可以通过解引用修改对象数据
// 指针引用: int *&rp = p; 指针自身是一个对象, 可以对指针进行引用
// 常量: const int j = 0; 限定符 类型 变量 = 值, 变量的值无法修改。常量必须初始化。

// 对常量的引用: const int &r1 = i/j/1;  
// 1. 正确的数据应该是j/1(常量/字面量) 额外2情况: 1. 可以转化成int类型的数据类型(double 可以转成 int) 2. 非常量的int数据 i

// 指向常量的指针: const int *p1 = &i/&j;
// 1. 正确的数据应该是 &j 额外情况: 1. 非常量的int数据 &i
// 对常量使用引用或指针, 初始化时必须使用限定符。


// 常量指针: int *const p2 = &i/&j; 指针的值不能改变(即指针的指向对象不能改变, 但是该对象的值可以改变 *p2)

// 指向常量的常量指针: const int *const p3 = &j; p3是一个常量指针, 且该指针指向一个常量. 即该指针的值 和 指针指向对象的值都不能改变
// p3是一个const型指针,且为int型指针, 指向对象为常量。