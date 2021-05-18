/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : zen_mydas_bracers.c
 * Author : Clode@RevivalWorld
 * Date   : 2007-07-16
 * Note   : �I�D�����@��
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
	set_idname(HIW"zen "NOR HIG"mydas "NOR GRN"bracers"NOR, HIW"�I"NOR WHT"�D"NOR HIG"����"NOR GRN"�@��"NOR);
	set_temp("status", HIW"�v"NOR WHT"��");

	if( this_object()->set_shadow_ob() ) return;
	
	set("long", "�@�Ʊq�����t�W�������v���@�áC\n");
	set("unit", "��");
	set("mass", 500);
	set("value", 10000);
	set("flag/no_amount", 1);
	set("special", 1);

	set("disassemble", ([ "/obj/gem/gem4" : 6 ]));

	set(DEFEND, 6);
	set(BUFF_PHY, 3);

	set(BUFF_FULLSUIT+BUFF_PHY, 3);

	::setup_equipment(EQ_BRACERS, HIY"�@"NOR YEL"��"NOR);
}

