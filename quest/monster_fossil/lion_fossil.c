/* This	program	is a part of RW	mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File	  : lion_fossil.c
 * Author : Clode@RevivalWorld
 * Date	  : 2009-12-24
 * Note	  : エ劇てホ
 * Update :
 *  o 2000-00-00  

 -----------------------------------------
 */

#include <ansi.h>
#include <inherit.h>

inherit	STANDARD_OBJECT;

void create()
{
	set_idname(HIC"fossil "NOR CYN"lion"NOR, NOR CYN"エ劇"HIC"てホ"NOR);
	set_temp("status", HIC"�}"NOR CYN"Τ");

	if( this_object()->set_shadow_ob() ) return;

	set("long", "�o喰てホ藻藻�o�X妥���A���GΤ斎���紀困O�q�弗L�笋ぁA�粒\┷�譽@�~�P�k�捷D�o�Oぐ賜�C");
	set("unit", "喰");
	set("value", 100);
	set("mass", 100);
	set("flag/no_amount", 1);
}
