/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : dignose.c
 * Author : Clode@RevivalWorld
 * Date   : 2005-05-16
 * Note   : 
 * Update :
 *  o 2000-00-00  

 -----------------------------------------
 */
 
#include <ansi.h>
#include <buff.h>
#include <feature.h>
#include <daemon.h>

inherit CONDITION_MOD;

string id 		= "dignose";
string name 	= NOR WHT"鼻屎纏身"NOR;
string type 	= CONDITION_TYPE_NEGATIVE;
int time 		= 60;
int heartbeat 	= 5;

// 啟動狀態時的效果
void start_effect(object ob)
{
	::start_effect(ob);
}

// 結束狀態時的效果
void stop_effect(object ob)
{
	::stop_effect(ob);
}

// 狀態進行中的效果
void heart_beat_effect(object ob)
{
	object caster = query(query_key()+"/caster", ob);

	if( !objectp(ob) || ob->is_faint() || ob->is_dead() || !objectp(caster) ) return;
	
	msg("$ME受到「"+query_condition_name()+"」的侵蝕，受到小小的傷害。\n", ob, 0, 1);
	
	COMBAT_D->cause_damage(caster, ob, 20);
}

