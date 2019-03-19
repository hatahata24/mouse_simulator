#pragma once
/*
 Name        : macro.h
 Description : 標準プログラムのmacro.hのうち探索に必要な部分のみ抜粋。
*/

#ifndef MACRO_H_
#define MACRO_H_


//型の置き換え、環境特有の型を一般的な型に置き換える。移植時にはここを変えればいいので楽になる(全部置き換わっていない気もするけど...)
// 8-bit, int8_t=signed char
typedef char			CHAR;
typedef unsigned char	UCHAR;
// 16-bit, SHORTなんてなかった
typedef short			INT;
typedef unsigned short	UINT;
// 32-bit
typedef int			    LONG;
typedef unsigned int    ULONG;

#endif