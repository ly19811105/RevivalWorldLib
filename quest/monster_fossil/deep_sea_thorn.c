/* This	program	is a part of RW	mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File	  : deep_sea_thorn.c
 * Author : Clode@RevivalWorld
 * Date	  : 2009-12-24
 * Note	  : �`�����
 * Update :
 *  o 2000-00-00  

 -----------------------------------------
 */

#include <ansi.h>
#include <inherit.h>

inherit	STANDARD_OBJECT;

void create()
{
	set_idname(NOR BLU"deep sea"HIB" thorn"NOR, HIW"�j"NOR WHT"���D"NOR BLU"�`��"HIB"���"NOR);
	set_temp("status", HIG"��"NOR GRN"�_");

	if( this_object()->set_shadow_ob() ) return;

	set("long", "�ҥj�Ǯa�q�@���_�h�`�B���X���ƥۡA�G�����w�o�S�j������ơA���G�O�s�@�˳ƪ��n���~�C");
	set("unit", "��");
	set("value", 100);
	set("mass", 100);
	set("special", 1);
}