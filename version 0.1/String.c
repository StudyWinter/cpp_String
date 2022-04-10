/*************************************************************************
  > File Name: String.c
  > Author: Winter
  > Created Time: 2022年04月10日 星期日 17时05分18秒
 ************************************************************************/


#include "String.h"

// 空构造函数
String::String():m_data(nullptr), m_size(0) {}    

// 普通构造函数
String::String(const char* str) {
    std::cout<<"普通构造函数的调用"<<std::endl;
    if (str == nullptr) {
        this->m_data = nullptr;
        this->m_size = 0;
    } else {
        this->m_size = strlen(str);                     // 得到长度
        this->m_data = new char[this->m_size + 1];      // 申请内存空间
        strncpy(this->m_data, str, this->m_size + 1);   // 复制内容
    }
}

// 拷贝构造函数
String::String(const String& other) {
    std::cout<<"拷贝构造函数的调用"<<std::endl;
    if (other.m_data == nullptr) {
        this->m_data = nullptr;
        this->m_size = 0;
    } else {
        this->m_size = strlen(other.m_data);                     // 得到长度
        this->m_data = new char[this->m_size + 1];               // 申请得到内存空间
        strncpy(this->m_data, other.m_data, this->m_size + 1);   // 复制内容
    }
}

// 拷贝赋值函数
String& String::operator=(const String& other) {
    std::cout<<"赋值构造函数的调用"<<std::endl;
    // 先判断是不是自身
    // 是自身，直接返回
    if (&other != this){
        // 不是自身，要进行深拷贝
        // 1 先释放原内存
        if (this->m_data != nullptr && this->m_size != 0) {
            delete [] this->m_data;
            this->m_data = nullptr;
        }
        this->m_size = 0;
        // 2 进行深拷贝
        this->m_size = strlen(other.m_data);
        this->m_data = new char[this->m_size + 1];
        strncpy(this->m_data, other.m_data, this->m_size + 1);
    }
    return *this;
}

// 析构函数
String::~String() {
    std::cout<<"析构函数的调用"<<std::endl;
    if (this->m_size != 0 && this->m_data != nullptr) {
        delete [] this->m_data;
        this->m_data = nullptr;
    }
    this->m_size = 0;
}

// 移动构造函数
/**
 *  所谓移动语义，指的就是以移动而非深拷贝的方式初始化含有指针成员的类对象。
 *  简单的理解，移动语义指的就是将其他对象（通常是临时对象）拥有的内存资源“移为已用”。
 */
String::String(String&& other) noexcept {
    std::cout<<"移动构造函数的调用"<<std::endl;
    // 先清理原来的内存
    if (this->m_size != 0 && this->m_data != nullptr) {
        delete [] this->m_data;
        this->m_data = nullptr;
    }
    this->m_size = 0;

    // 再调用移动
    this->m_data = nullptr;                    // 将原data置空
    this->m_data = other.m_data;
    this->m_size = other.m_size;
    
    other.m_data = nullptr;                    // 将other的data置空
    other.m_size = 0;                          // 将other的size置0
}

// 移动赋值函数
String& String::operator=(String&& other) noexcept {
    std::cout<<"移动赋值函数的调用"<<std::endl;
    // 如果不是自身
    if (&other != this) {
        // 先清理原来的内存
        if (this->m_size != 0 && this->m_data != nullptr) {
            delete [] this->m_data;
            this->m_data = nullptr;
    }   
        this->m_size = 0;
        // 再调用移动
        this->m_data = nullptr;                    // 将原data置空
        this->m_data = other.m_data;
        this->m_size = other.m_size;
    
        other.m_data = nullptr;                    // 将other的data置空
        other.m_size = 0;                          // 将other的size置0
    }
    return *this;
}

// 重载[]操作符
char& String::operator[](size_t index) {
    if (index >= this->m_size) {
        // 越界
        throw std::out_of_range("index out of range");
    }
    return this->m_data[index];
}

// 重载==运算符
bool String::operator==(const String& other) {
    // 长度不想等，直接返回false
    if (this->m_size != other.m_size) {
        return false;
    }
    return strcmp(this->m_data, other.m_data) == 0;
}

// 重载+运算符
String String::operator+(const String& other) {
    // 重新开辟一段空间
    String s;
    s.m_size = this->m_size + other.m_size;                             // 计算长度
    s.m_data = new char[s.m_size + 1];                                  // 分配空间
    strncpy(s.m_data, this->m_data, this->m_size);                      // 赋值原空间内容
    strncpy(s.m_data + this->m_size, other.m_data, other.m_size + 1);   // 复制加上部分的内容
    return s;
}

// 转换成c风格的字符串
const char* String::c_str() const {
    return this->m_data;
}

// 获得字符串长度
size_t String::length() {
    return this->m_size;
}         

// 友远重载<<运算符
std::ostream& operator << (std::ostream& out, const String& str) {
    if (str.m_data == nullptr) {
        out << "";
    } else {
        out << str.m_data;
    }
    return out;
}

// 友元重载>>运算符
std::istream& operator >> (std::istream& in, String& str) {
    std::cout<<"please input string size:";
    in >> str.m_size;
    str.m_data = new char[str.m_size + 1];
    std::cout<<"please input string data:";
    in >> str.m_data;
    int len = strlen(str.m_data);
    if (len > str.m_size) {
        std::cout<<"error! data len > size" << std::endl;
        exit(1);
    }
    return in;
}