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
    
    printf("%s", source);
    printf("%s", hehe);
    return 0;
    
}



//***********************string reverse



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

int main(int argc ,const char * argsv[] ) {
    
    char hehe[] = "abcdscsdcsdfef";
    reverse(hehe);
    printf("%s", hehe);
   

}

