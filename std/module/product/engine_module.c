/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : module.c
 * Author : Clode@RevivalWorld
 * Date   : 2005-04-06
 * Note   : 
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#include <feature.h>

inherit PRODUCT_ACTION_MOD;

// 放置物品
void do_action(object me, string arg)
{


}

// 設定物件動作
nosave mapping action_info =
([
	"help"	: "尚未建構說明。",
	"action":
		([
			//"action"	: (: do_action :),
		]),
]);

// 設定物件資料
nosave mapping product_info = 
([	
	//中文名稱
	"name":		"引擎",
	
	//英文名稱
	"id":		"engine",

	//材料需求
	"material":	([ "mold":5, "mechanical_structure":3, "integrated_circuit":1 ]),

	//技能需求
	"skill":	([ "machinery-fac":70, "technology":70 ]),

	//生產工廠
	"factory":	"machinery",
]);
