/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : mapnpc.c
 * Author : Clode@RevivalWorld
 * Date   : 2007-07-14
 * Note   : �a�Ϩt�ΤW�� NPC �w��P����
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#include <daemon.h>

#define MAP_ID		"sixcastle"
#define MAP_NUM		3

inherit __DIR__"_mapnpc.c";

array npc =
({
	// �����t
	(["group":(["/obj/npc/boss/chelonia_mydas" : 1,]), "x":({ 45, 47 }), "y":({ 66, 68 }), "move_speed" : 600,"reborn_time" : range_random(180, 360), ]),
});

array query_npc_data()
{
	return npc;
}

void create()
{
	::load_mapnpc(ref npc, MAP_ID, MAP_NUM);
}

int remove()
{
	::unload_mapnpc(ref npc);	
}

void heart_beat()
{
	::mapnpc_heart_beat(ref npc, MAP_ID, MAP_NUM);
}