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
#include <buff.h>

inherit PRODUCT_ACTION_MOD;

mapping inlay_effect =
([
	"/obj/gem/gem4" : (: addn(BUFF_CHA, standard_calculate($1) * 2, $2) :),
	"/obj/gem/gem5" : (: addn(SPEED, standard_calculate($1) * 2, $2) :),
]);

array enhancement = 
({ 
	(: addn(BUFF_CHA, $1, $2) :),
	(: addn(SPEED, $1, $2) :),
});

// ��m���~
void do_action(object me, string arg)
{


}

// �]�w����ʧ@
nosave mapping action_info =
([
	"help"	: "�|���غc�����C",
	"action":
		([
			//"action"	: (: do_action :),
		]),
]);

// �]�w������
nosave mapping product_info = 
([	
	//����W��
	"name":		"�N�L",
	
	//�^��W��
	"id":		"guitar",

	//���ƻݨD
	"material":	([ "man_made_fibers":6, "refined_timber":15, "steel":6, "mechanical_structure":1 ]),

	//�ޯ�ݨD
	"skill":	([ "instrument-fac":50, "technology":50 ]),

	//�Ͳ��u�t
	"factory":	"instrument",
]);