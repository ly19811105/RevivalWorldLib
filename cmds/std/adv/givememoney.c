/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : givememoney.c
 * Author : Clode@RevivalWorld
 * Date   : 2003-04-13
 * Note   : givememoney ���O
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */
 
#include <feature.h>
#include <ansi.h>
#include <message.h>
#include <daemon.h>

inherit COMMAND;

string help = @HELP
	�з� givememoney ���O
HELP;

private void command(object me, string arg)
{
	int money;
	string unit;

	if( !is_command() ) return;
	
	if( !arg || sscanf(arg, "$%s %s", unit, arg) != 2 )
		return tell(me, "�п�J���B�A�ҡG$CT 100�C\n");

	if( !MONEY_D->money_unit_exist(unit) )
		return tell(me, "�S�� "+unit+" �o�سf���C\n");
		
	money = to_int(big_number_check(arg));
	
	if( money <= 0 )
		return tell(me, "�п�J���T�����B�ƥءC\n");

	me->earn_money(unit, money);
	
	msg("$ME���Y���W��M�ƤU�ӤF"+HIY+QUANTITY_D->money_info(unit, money)+NOR" ���r���A$ME���W�|�_������Ƨ�i�f�U�̡C\n", me,0,1);
}