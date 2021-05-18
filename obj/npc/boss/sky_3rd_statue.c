/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : sky_3rd_statue.c
 * Author : Clode@RevivalWorld
 * Date   : 2009-12-23
 * Note   : 
 * Update :
 *  o 2000-00-00
 *
 -----------------------------------------
 */

/*
	系統預設之 NPC 反應函式
	void reply_emote(object me, string verb, string args);
	void reply_say(object me, string msg);
	void reply_catch_tell(object me, string verb, string args);
	void reply_get_object(object me, object ob, mixed amount);
	void reply_get_money(object me, string unit, mixed money);
*/

#include <ansi.h>
#include <inherit.h>
#include <gender.h>
#include <daemon.h>
#include <condition.h>
#include <buff.h>

inherit STANDARD_MONSTER;

mapping defeat_titles =
([
	10 		:	HIW"天"NOR WHT"魁"HIY"獵"NOR YEL"人"NOR,
	100		:	HIW"天"NOR WHT"魁"HIB"剋"NOR BLU"星"NOR,
	1000	:	HIW"天"NOR WHT"魁"HIR"殺"NOR RED"手"NOR,
	2000	:	HIW"天"NOR WHT"魁"HIM"噬"NOR MAG"者"NOR,
	5000	:	HIW"天"NOR WHT"魁"WHT"死"HIW"神"NOR,
]);

private mapping fightart = allocate_mapping(0);

void do_command(string cmd);

/*
void reply_say(object me, string msg)
{

}
*/

void stop_stun(object attacker, object defender)
{
	if( !objectp(attacker) || !objectp(defender) || !COMBAT_D->in_fight(attacker, defender) )
		return;
		
	COMBAT_D->stop_fight(attacker, defender);
	msg("\n$ME終於回神過來，停止了對$YOU的攻擊...\n\n"NOR, attacker, defender, 1);
	
	map_delete(fightart, attacker);
	map_delete(fightart, 0);
}

void reply_emote(object me, string verb, string args)
{
	broadcast(query_temp("location", me), this_object()->query_idname()+"高聳的眼睛突然往下瞪了過來，伴隨大量的碎石落下！\n");
}

int target_gone(object me)
{

}


/*
void reply_get_object(object me, object ob, mixed amount)
{

}
*/

// 死亡時的事件
void reply_die()
{
	object ob = new("/obj/inlay/sky_3rd_secret_art");
	
	ob->move(this_object());

	TREASURE_D->get_treasure(this_object());
	
	foreach(object attacker, object *defenders in fightart)
	{
		if( !objectp(ob) || !arrayp(defenders) ) continue;	
		
		foreach(object defender in defenders)
		{
			if( !objectp(defender) ) continue;
				
			stop_stun(attacker, defender);
		}
	}
}

// 被擊敗時的事件
void reply_defeat(object* attackers)
{
	::start_cooldown(attackers, SKY_3RD_STATUE);	
	::reply_defeat(attackers);
}

// 檢查是否為合法戰鬥目標
int valid_enemy(object enemy)
{
	return ::check_cooldown(enemy, SKY_3RD_STATUE);
}

// 攻擊時的訊息
varargs string combat_attack_message(object target, object weapon)
{
	switch(random(5))
	{
		case 0:
			return "$ME舉起龐大石拳往$YOU猛力擊去，";
			break;
		case 1:
			return "$ME怒吼往下衝撞$YOU，";
			break;
		case 2:
			return "$ME抬起萬噸石腳往$YOU所在位置猛力踩下，";
			break;
		case 3:
			return "$ME揮動巨大的石臂往下掃往$YOU，";
			break;
		case 4:
			return "$ME猛力地往$YOU衝撞攻擊，";
			break;
	}
}

// 防禦時的訊息
varargs string combat_defend_message(object attacker, object weapon)
{
	
	
}

// 特殊攻擊
void special_attack(object attacker, object defender)
{
	if( !random(100) )
		shout(HIB"遠方"NOR"-"+AREA_D->query_area_name(environment(attacker)->query_area())+"發生劇烈異變，陣陣深沉怒吼傳來憾動大地...。\n");
		
	if( !random(15) )
	{
		msg("\n$ME雙手一揮，大量「"WHT"烏黑碎石"NOR"」自地下竄出附著在$YOU身上，$YOU臉色瞬間發青，"HIG"有毒！！\n\n"NOR, attacker, defender, 1);
		
		defender->start_condition(MAGNETIC_STONE, 60, 1, attacker);

		return;
	}

	if( !random(30) )
	{
		object *enemies = COMBAT_D->query_fighting_targets(attacker);
		object enemy;
		
		if( sizeof(enemies) > 0 )
		{		
			msg("\n$ME朝天大吼：「"HIY"莫敢不從！！！"NOR"」，浩然震波直貫$YOU耳中，$YOU被震得頭昏腦脹！！\n"NOR, attacker, defender, 1);
			msg("$ME朝天大吼：「"HIY"莫敢不從！！！"NOR"」，浩然震波直貫$YOU耳中，$YOU被震得頭昏腦脹！！\n"NOR, attacker, defender, 1);	
			msg("$ME朝天大吼：「"HIY"莫敢不從！！！"NOR"」，浩然震波直貫$YOU耳中，$YOU被震得頭昏腦脹！！\n"NOR, attacker, defender, 1);	

			enemy = enemies[random(sizeof(enemies))];
			
			msg("$ME"HIR"昏昏沉沉的突然開始對$YOU"HIR"進行攻擊！！\n\n"NOR, defender, enemy, 1);	
			
			COMBAT_D->start_fight(defender, enemy);
			defender->start_delay("sky_3rd_statue", 1, pnoun(2, defender)+"目前頭昏腦賬，無法做任何動作");
			
			if( !arrayp(fightart[defender]) )
				fightart[defender] = ({ enemy });
			else
				fightart[defender] += ({ enemy });

			call_out( (: stop_stun :), range_random(2, 5), defender, enemy );
		}
	}
}

int is_boss()
{
	return 4;
}

void create()
{
	set_idname(HIW"sky 3rd "WHT"statue"NOR, HIW"天"NOR WHT"魁"NOR);

	set("unit", "尊");
	set("age", 650000);
	set("gender", MALE_GENDER);
	
	set("attr/str", 300);
	set("attr/phy", 350);
	set("attr/int", 300);
	set("attr/agi", 300);
	set("attr/cha", 300);

	set("abi/stamina/max", 80000);
	set("abi/stamina/cur", 80000);
	set("abi/health/max", 80000);
	set("abi/health/cur", 80000);
	set("abi/energy/max", 80000);
	set("abi/energy/cur", 80000);
	set("job/name", HIW+"★★★★"+NOR);

	set("skills/unarmed/level", 160);
	set("skills/dodge/level", 160);

	set_temp("buff/"+BUFF_FATAL_CHANCE, 10);
	set_temp("buff/"+BUFF_ANTIFATAL_CHANCE, 20);
	
	set("prestige", 1);// 死亡後給予玩家的聲望

	set("long", "　遠古諸神遺留在人間的巨大石像，與其他兩座石像並列在這塊大地上，遠遠望見一些\n白鳥在石像頂端盤旋，但附近卻是一點聲音也沒有，似乎隱藏著一些不為人知的秘密。");

	startup_living();
}

int remove()
{
	destruct(all_inventory(this_object()));
}
