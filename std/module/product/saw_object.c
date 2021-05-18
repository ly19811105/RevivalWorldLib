/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : object.c
 * Author : Clode@RevivalWorld
 * Date   : 2006-01-14
 * Note   : 
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#include <inherit.h>

inherit STANDARD_MODULE_PRODUCT;

varargs void create(string file, string type)
{
	::create(file, type);

	set("unit", "��");	
	set("mass", 100);
	set("value", query_value());

	set("endurance", 1000);
	set("quality", 110);
	set("collection_tool", "wood");

	setup_inlay();
}
