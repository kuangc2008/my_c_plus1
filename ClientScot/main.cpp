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

//================字符串拷贝
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

//=========================查找字符串中某字符出现的次数

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

int main(int argc, const char * argv[]) {
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