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


void copy_str1(char* from, char* to) {
    for(; *from != '\0'; from++, to++) {
        *to = *from;
    }
    *to = '\0';
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
  //  std::cout << "Hello, World!\n";
    
    
    
    
    //test 1
    char from[100] = {};
    char to[100] = {};
    strcpy(from, "heheniMeiA");
    copy_str1(from, to);
    printf("%s", to);
    
    return 0;
}
