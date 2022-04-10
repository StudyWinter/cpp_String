/*************************************************************************
 > File Name: String.h
 > Author: Winter
 > Created Time: 2022年04月10日 星期日 16时45分28秒
 ************************************************************************/
#ifndef _STRING_
#define _STRING_

#include <iostream>
#include <cstring>

class String {
public:
    String();                                   // 空构造函数
    String(const char* str);                    // 普通构造函数
    String(const String& other);                // 拷贝构造函数
    String& operator=(const String& other);     // 拷贝赋值函数
    ~String();                                  // 析构函数

    String(String&& other) noexcept;            // 移动构造函数
    String& operator=(String&& other) noexcept; // 移动赋值函数

    char& operator[](size_t index);             // 重载[]操作符
    bool operator==(const String& other);       // 重载==运算符
    String operator+(const String& other);      // 重载+运算符

    const char* c_str() const;                  // 转换成c风格的字符串
    size_t length();                            // 获得字符串长度

    friend std::ostream& operator << (std::ostream& out, const String& str);        // 友远重载<<运算符
    friend std::istream& operator >> (std::istream& in, String& str);               // 友元重载>>运算符

private:
	void _init(const char* str);               // 分配内存
	void _clean();                             // 清除内存
	void _swap(String& other);             // 交换，用于移动构造

private:
    char* m_data;                        // 数组首地址
    size_t m_size;                       // 数组长度

};

#endif
