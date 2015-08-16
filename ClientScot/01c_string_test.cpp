//
//  main.cpp
//  ClientScot
//
//  Created by 成 匡 on 15/7/16.
//  Copyright (c) 2015年 成 匡. All rights reserved.
//

#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ctssocket.h"

//================1 字符串拷贝
void copy_str1(char* from, char* to) {
    for(; *from != '\0'; from++, to++) {
        *to = *from;
    }
    *to = '\0';
}

int copy_str2(char* from, char* to) {
    int ret = 0;
    if(from == NULL || to == NULL) {
        ret = -1;
        printf("func copy_str2(); %d (from = =null|| to == null)", ret);
        return ret;
    }
    
    while( (*to++ = *from++) != '\0') {
    }
    return ret;
}


int main2(int argc, const char * argv[]) {
    // insert code here...
    //test 1
    char from[100] = {};
    char to[100] = {};
    char *from2;
    strcpy(from, "heheniMeiA");
    copy_str2(from, to);
    copy_str2(from2, to);
    printf("%s", to);
    
    return 0;
}

//=========================2 查找字符串中某字符出现的次数

int main3(int argc, const char * argv[]) {
    // insert code here...
    //test 1
    char *source = "abc123,2abc343,abc,13434,abc";
    char *searchStr = "2abc";
    char *pos = NULL;
    pos = strstr(source, searchStr);  //返回指向特定字符的首字母串的指针
    if(pos == NULL) {
        printf("NULL");
    } else {
        printf("pos is %s", pos);
    }
    return 0;
}

int main4(int argc, const char * argv[]) {
    // insert code here...
    //test 1
    char *source = "abc123,2abc343,abc,13434,abc";
    char *searchStr = "abc";
    char *pos = NULL;
    int count = 0;
  
    do {
        pos = strstr(source, searchStr);
        if(pos == NULL) {
            break;
        } else {
            source = pos + strlen(searchStr);
            count++;
        }
    } while( *pos != NULL);
    
    
    printf("count is %d", count);
    return 0;
}

int get_char_count(char* srouce, char* sub, int *count);
int main5(int argc, const char * argv[]) {
    // insert code here...
    //test 1
    char *source = "abc123,2abc343,abc,13434,abc";
    char *searchStr = "abc";
   
    int a;
    get_char_count(source, searchStr, &a);
    printf("count is %d", a);
    return 0;
}

int get_char_count(char* srouce, char* sub, int *count) {
    int strCount = 0;
    while( srouce = strstr(srouce, sub)) {
        strCount++;
        srouce = srouce + strlen(sub);
        if( *srouce == '\0') {
            break;
        }
    }
    *count = strCount;
    return 0;
}


//========================================3 string  trim
int main6(int argc, const char * argv[]) {
    char *source = "     ababab    ";
    int len = strlen(source);
    
    for(int i=0; i<len;i++) {
        printf("%c\n", *(source + i));
    }
    
    int start;
    for(start = 0 ; *(source + start) != '\0'; start++) {
        if( *(source + start) != ' ') {
            break;
        }
    }
    
    int end ;
    for(end = len - 1; *(source + end) != '\0'; end--) {
        if( *(source + end)  != ' ') {
            break;
        }
    }
    
    char dest[len];
    for( int i = start; i<= end; i++) {
        *(dest + i - start) = *(source + i);
    }
    *(dest + end - start + 1) = '\0';
    
    printf("%s\n", dest);
    return 0;
}


void trim(char *source, char* out) {
    
    int start;
    for(start = 0 ; *(source + start) != '\0'; start++) {
        if( *(source + start) != ' ') {
            break;
        }
    }
    
    int len = strlen(source);
    int end;
    for(end = len - 1; *(source + end) != '\0'; end--) {
        if( *(source + end)  != ' ') {
            break;
        }
    }
    
    memcpy(out, source + start, end - start + 1);
    
}

int main7(int argc, const char * argv[]) {
    char *source = "     ababab    ";
    int len = strlen(source);
    char dest[len];
    trim(source, dest);
    
    printf("%s\n", dest);
    return 0;
}


int main8(int argc ,const char * argsv[] ) {
    char *source = "123";
    char hehe[] = "abc";
    
    *hehe = 'd';
  //  *source = 'e';  //指向的内存块是常量；   char[] souce是非常量
    //  char *s = "abc";
    //  char s[] = "abc"  ====   char *s = abc;   strcpy(s, "abc";
    
    printf("%s", source);
    printf("%s", hehe);
    return 0;
    
}



//***********************4 5string reverse

void swap(char* i, char* j) {
    char w = *i;
    *i = *j;
    *j = w;
}

void reverse(char *string) {
    size_t start = 0, end = strlen(string) -1 ;
    while(start < end) {
        swap( string + start, string + end);
        start ++;
        end --;
    }
}

int main9(int argc ,const char * argsv[] ) {
    
    char hehe[] = "abcdscsdcsdfef";
    reverse(hehe);
    printf("%s", hehe);
    return 0;
}



//******************* 5 const
int hehe_const(const char *);

int main10(int argc ,const char * argsv[] ) {
    const char a= 10;
    int const b = 12;  //same
    
    const char *c;     //如果const在*之前，修饰的是c指向的值
    char *const d = NULL;    //如果const在*之后，修饰d，d是指针变量;  不可改变指针，可改变指向值
    const char *const e = NULL;
    
    return 0;
}


//****************6  二级指针:  分割一个字符串，返回字符数组以及大小
int splitStr(const char *ss, const char c, char ssArray[20][10], int *len) { //这个地方为什么不能用*号呢
    int size = 0;
    char *find_ss;
    int start;
    char *tmpString;
    while ( (find_ss = strchr(ss, c)) != NULL) {  //123,456 ->  ,456
        start = (find_ss - ss);
     //   tmpString = ssArray[size];
        memcpy(ssArray[size], ss, start);
        ssArray[size][start] = '\0';
        size++;
        ss = find_ss + 1;
    }

    tmpString = ssArray[size];
    memcpy(tmpString, ss, strlen(ss));
               size++;
    
    *len = size;
    
    return 0;
}

int printArray(char array[][10], int size) {
    for(int i=0; i<size; i++) {
        printf("%s\n", *(array + i));
    }
    return 0;
}

int main11(int argc ,const char * argsv[] ) {
    const char *ss = "abc,edf,gette,grgrg,grdgrdg, fesfe  ,,b";
    const char c = ',';
    char ssArray[20][10];
    int len = 0;
    splitStr(ss, c, ssArray, &len);
    
    printArray(ssArray, len);
    
    return 0;
}


//****************7  二位指针
int main12() {
    char **myArray = (char**) malloc(10 * sizeof(char*));
    if(myArray == NULL) {
        return -1;
    }
    
    for(int i=0; i<10; i++) {
        myArray[i] = (char*) malloc(100);
    }

    //do
    
    
    
    for(int i=0; i<10; i++) {
        free(myArray[i]);
    }
    free(myArray);
    
    
    return 0;
}


//******************分割字符串更正规的做法；  在函数中分配内存，再回首
char** splitStr2(const char *ss, const char c, int *len) { //这个地方为什么不能用*号呢
    int size = 0;
    char *find_ss;
    int start;
    char *tmpString;
    
    char **ssArray = (char**) malloc(10 * sizeof(char*));
    if(ssArray == NULL) {
        return NULL;
    }
    
    for(int i=0; i<10; i++) {
        ssArray[i] = (char*) malloc(100);
    }
    
    
    while ( (find_ss = strchr(ss, c)) != NULL) {  //123,456 ->  ,456
        start = (find_ss - ss);
        //   tmpString = ssArray[size];
        memcpy(ssArray[size], ss, start);
        ssArray[size][start] = '\0';
        size++;
        ss = find_ss + 1;
    }
    
    tmpString = ssArray[size];
    memcpy(tmpString, ss, strlen(ss));
    size++;
    
    *len = size;
    
    return ssArray;
}

int printArray2(char **array, int size) {
    for(int i=0; i<size; i++) {
        printf("%s\n", *(array + i));
    }
    return 0;
}

int splitStr2_release(char **myArray, int len) {
    for(int i=0; i<len; i++) {
        free(myArray[i]);
    }
    free(myArray);
    return 0;
}

int main13(int argc ,const char * argsv[] ) {
    const char *ss = "abc,edf,gette,grgrg,grdgrdg, fesfe  ,,b";
    const char c = ',';
    int len = 0;
    char **ssArray = splitStr2(ss, c, &len);
    
    printArray2(ssArray, len);
    
    splitStr2_release(ssArray, len);
    return 0;
}

//****************************数组类型
int main14() {
    typedef int (MYINT5)[5];
    MYINT5 hehe; // int hehe[5];   MYINTS为数据类型

    for(int i=0; i<5; i++) {
        *(hehe + i) = i + 1;
    }
    
    for(int i=0; i<5; i++) {
        printf("%d", hehe[i]);
    }
    
    //注意点：
    printf("size;%d; %d, %d %d ", sizeof(hehe), &hehe, &hehe + 1, hehe+1);  //注意点： 步长的概念
    return 0;
}



//******************** 数组类型的指针
int main() {
    typedef int (MYINT)[5];
    MYINT *arrayPoint;
    
    int a[] = {1, 2, 3, 4, 5};
    arrayPoint = &a;
    
    for(int i=0; i<5; i++) {
        printf("%d", (*arrayPoint)[i]);
    }
    
    
    int a1[] = {1, 2, 3};
//    a1 = 0x1111;  //编译不不过，因为是指针常量，系统这么做肯定是为了资源回收
    int *p1 = a1;
    
    return 0;
}








