/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : sesame_glue_pudding.c
 * Author : Clode@RevivalWorld
 * Date   : 2009-12-22
 * Note   : 芝麻湯圓
 * Update :
 *  o 2003-00-00  

 -----------------------------------------
 */

#include <ansi.h>
#include <inherit.h>
#include <condition.h>
#include <feature.h>

inherit STANDARD_OBJECT;
inherit FOOD;

void create()
{
	set_idname(WHT"sesame "HIW"glue pudding"NOR, WHT"芝麻"HIW"湯圓"NOR);
	
	if( this_object()->set_shadow_database() ) return;

	set("long", "　冬至應景食品，可短時間提升個人魅力與體力。");
	set("unit", "粒");
	set("capacity", 0);
	set("mass", 10);
	set("value", 100);
	set("badsell", 1);
	set("special", 1);
}

int do_eat(object me)
{
	msg("$ME吞下了$YOU，一股暖意從體內漫延而出。\n", me, this_object(), 1);

	me->start_condition(SESAME_GLUE_PUDDING);

	return 1;
}
