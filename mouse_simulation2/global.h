#pragma once
/*
 Name        : global.h
 Description : 標準プログラムのglobal.hのうち探索に関係のあるものだけを抜粋した。
*/

#ifndef GLOBAL_H_
#define GLOBAL_H_

/*============================================================
		各種定数・変数宣言
============================================================*/
/*------------------------------------------------------------
		探索系
------------------------------------------------------------*/
//----ゴール座標----
#define GOAL_X 7	//7
#define GOAL_Y 7	//7

/*------------------------------------------------------------
		共用・構造体の定義
------------------------------------------------------------*/
//共用・構造体とは、共用体と構造体を組み合わせたもので、
//内部の一括操作も、メンバ単位での操作も可能なものである。
//例えば、以下のmouse_flags共用・構造体のMFでは、
//MF.FLAGS = 0x10;と全体を一括変更できるほか、
//MF.FLAG.DECL = 1;とメンバを指定して単体で変更することも出来る。
//参考：
//https://www.grapecity.com/tools/support/powernews/column/clang/033/page02.htm

//----フラグ共用・構造体----
//順番は間違ってません
#ifndef __MOUSE_FLAGS__				//対応ファイルで一度も読み込まれていない場合以下を定義
#define __MOUSE_FLAGS__				//読み込んだことを表す
typedef union {						//共用体の宣言
	unsigned char FLAGS;
	struct ms_flags {				//構造体の宣言
		unsigned char RSV : 1;		//予備ビット(B0)		(:1は1ビット分の意味、ビットフィールド)
		unsigned char SCND : 1;		//二次フラグ(B1)
		unsigned char SLAL : 1;		//旋回フラグ(B2)
		unsigned char CTRL : 1;		//制御フラグ(B3)
		unsigned char ACCL : 1;		//加速フラグ(B4)
		unsigned char DECL : 1;		//減速フラグ(B5)
		unsigned char DEF : 1;		//定速フラグ(B6)
		unsigned char STOP : 1;		//停止フラグ(B7)
	}FLAG;
} mouse_flags;
#endif

/*グローバル変数の定義*/
volatile mouse_flags MF;			//モータステータスをまとめた共用・構造体



//----現在地格納共用・構造体----
#ifndef __MAP_COOR__				//対応ファイルで一度も読み込まれていない場合以下を定義
#define __MAP_COOR__				//読み込んだことを表す
union map_coor {					//共用体の宣言
	UCHAR PLANE;					//YX座標
	struct coor_axis {				//構造体の宣言
		UCHAR X : 4;				//X座標
		UCHAR Y : 4;				//Y座標
	}AXIS;
};
#endif

/*グローバル変数の定義*/
volatile union map_coor PRELOC;		//現在地の座標を格納する共用・構造体


#endif