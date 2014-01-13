/***************************************************************************
 * 
 * Copyright (c) 2014 zju && Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file myserver.h
 * @author liujun05(liujun0923@zju.edu.cn)
 * @date 2014/01/05 16:46:13
 * @brief 
 *  
 **/


#ifndef  __MYSERVER_H_
#define  __MYSERVER_H_

#include "mylog.h"
#include "myconf.h"
#include "myserver_define.h"
#include "epollserver.h"
#include "queue.h"

/* 创建一个服务器*/
my_server_t* my_server_create(const char* conf_path, const char* conf_file, const char* server_name);

/* 运行一个服务器*/
int my_server_run(my_server_t* server);

/* 关闭一个服务器*/
int my_server_close(my_server_t* server);

/* 设置线程回调函数 */
int my_server_set_callback(my_server_t* server, callback_proc call_func);


/* 获得线程读大小 */
uint32 my_server_get_read_size();

/* 获得线程读数据 */
void* my_server_get_read_buf();

/* 获得线程最大写大小*/
uint32 my_server_get_write_size();
/* 获得线程最大写数据 */
void* my_server_get_write_buf();

/* 设置线程实际返回写数据大小 */
int my_server_set_write_size(uint32 write_size);



/**************************以下函数无需关注 *************************/

/* 服务器配置初始化 */
my_server_conf_t* my_server_init_conf(const char* conf_path, const char* conf_file, const char* server_name);

/* 服务器线程数据初始化 */
my_server_t* my_server_init_data(my_server_conf_t* server_conf);



#endif  //__MYSERVER_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
