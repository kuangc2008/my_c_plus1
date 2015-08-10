//
//  ctssocket.h
//  ClientScot
//
//  Created by 成 匡 on 15/7/16.
//  Copyright (c) 2015年 成 匡. All rights reserved.
//

#ifndef __ClientScot__ctssocket__
#define __ClientScot__ctssocket__

#include <stdio.h>

int ctsSocket_init(void **handle);

int ctsSocket_senddata(void *handle, unsigned char *buf, int buflen);

int ctsSocket_resvdata(void *handle, unsigned char *buf, int *buflen);

int ctsSocket_destory(void **handle);

#endif /* defined(__ClientScot__ctssocket__) */
