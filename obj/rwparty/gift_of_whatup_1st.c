/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : gift_of_whatup_1st.c
 * Author : Clode@RevivalWorld
 * Date   : 2006-05-14
 * Note   : Whatup 的性感胸毛
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#include <ansi.h>
#include <inherit.h>
#include <feature.h>
#include <equipment.h>
#include <buff.h>

inherit STANDARD_OBJECT;
inherit EQUIPMENT;
inherit __DIR__"_action_dignose.c";

mapping actions;

void do_dignose(object me, string arg);

void create()
{
	set_idname("gift of whatup", HIY"Whatup 的"NOR YEL"性感胸毛"NOR);
	set_temp("status", HIC"網聚"NOR CYN"紀念版");

	if( this_object()->set_shadow_database() ) return;

	set("long", "第一屆重生的世界網聚(2006/05/13)紀念品。\n");
	
	set("unit", "個");
	set("mass", 0);
	set("value", 10);
	set("badsell", 1);
	set("flag/no_amount", 1);
	set("flag/no_drop", 1);
	set("flag/no_give", 1);
	set("flag/no_import", 1);

        set(BUFF_ENERGY_REGEN, 2);
        set(BUFF_LOADING_MAX, 5);
        set("buff/status", NOR BLINK WHT"囧"NOR);
        ::setup_equipment(EQ_NOSE, HIG"鼻"NOR GRN"孔"NOR);
        	
        actions = ([ "dignose" : (: do_dignose :) ]);
}
