/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : bugs.c
 * Author : Clode@RevivalWorld
 * Date   : 2002-3-15
 * Note   : bugs�^���O
 * Update :
 *  o 2000-00-00
 *
 -----------------------------------------
 */

#include <inherit.h>

inherit BULLETIN_BOARD;

void create()
{
	set_idname("bugs board", "�Т�զ^���d���O");
	
	// �Q�� shadow_ob �޳N�Ӱ����������G��, �Y�ɸ�Ƭ��x�s�� shadow_ob �W
	if( clonep() ) 
		set("shadow_ob", find_object(base_name(this_object())));
	
	else
	{
		set("boardid", "bugs");
		set("capacity", 2000);
		
		initialize_board();
	}
	startup_action();
}