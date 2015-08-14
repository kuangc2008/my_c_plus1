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



int main(int argc, const char * argv[]) {
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
    
    printf("%s\n", dest);
    
}










