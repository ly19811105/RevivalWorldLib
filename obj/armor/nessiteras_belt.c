/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : nessiteras_belt.c
 * Author : Clode@RevivalWorld
 * Date   : 2007-08-20
 * Note   : 尼斯腰帶
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
#include <daemon.h>

inherit STANDARD_OBJECT;
inherit EQUIPMENT;

void create()
{
	set_idname(HIB"nessiteras"NOR MAG" belt"NOR, HIB"尼斯"NOR MAG"腰帶"NOR);
	set_temp("status", HIG"傳"NOR GRN"奇");

	if( this_object()->set_shadow_ob() ) return;
	
	set("long", "一副從尼斯湖水怪上掉落的腰帶。\n");
	set("unit", "副");
	set("mass", 500);
	set("value", 10000);
	set("flag/no_amount", 1);
	set("special", 1);

	set("disassemble", ([ "/obj/gem/gem6" : 4 ]));

	set(DEFEND, 5);
	set(BUFF_STR, 1);
	set(BUFF_INT, 1);
	set(BUFF_AGI, 1);

	set(BUFF_FULLSUIT+BUFF_ENERGY_MAX, 20);
	set(BUFF_FULLSUIT+BUFF_AGI, 1);

	::setup_equipment(EQ_BELT, HIY"腰"NOR YEL"帶"NOR);
}

