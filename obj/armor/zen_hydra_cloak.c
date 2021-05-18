/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : zen_hydra_cloak.c
 * Author : Clode@RevivalWorld
 * Date   : 2007-08-20
 * Note   : 禪．海德拉披風
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
	set_idname(HIW"zen "NOR HIREV HIW"hydra"WHT" cloak"NOR, HIW"禪"NOR WHT"．"NOR HIREV HIW"海德拉"WHT"披風"NOR);
	set_temp("status", HIW"史"NOR WHT"詩");

	if( this_object()->set_shadow_ob() ) return;
	
	set("long", "一副從九頭蛇海德拉上掉落的史詩披風。\n");
	set("unit", "副");
	set("mass", 500);
	set("value", 10000);
	set("flag/no_amount", 1);
	set("special", 1);

	set("disassemble", ([ "/obj/gem/gem3" : 12 ]));

	set(DEFEND, 15);
	set(BUFF_PHY, 3);
	set(BUFF_INT, 3);
	set(BUFF_STR, 3);

	set(BUFF_FULLSUIT+BUFF_STAMINA_MAX, 60);
	set(BUFF_FULLSUIT+BUFF_STR, 3);

	::setup_equipment(EQ_CLOAK, HIY"披"NOR YEL"風"NOR);
}

