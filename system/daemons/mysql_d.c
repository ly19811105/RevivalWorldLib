/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : mysql_d.c
 * Author : Clode@Revival World
 * Date   : 2005-12-24
 * Note   : Mysql 精靈
 *
 -----------------------------------------
 */

#include <daemon.h>

mapping mysql;
 
#define DEFAULT_HOSTNAME 	"localhost"
#define DEFAULT_DATABASE	"rw"
#define DEFAULT_USERNAME	"web"
 
#define MSG(x, y)		CHANNEL_D->channel_broadcast("nch", "MYSQL_D["+x+"]: "+y)

varargs mixed exec(int handle, string sql);

// 建立 MYSQL 連線
varargs mixed connect(string hostname, string database, string username)
{
	mixed handle;
	
	if( undefinedp(hostname) )
		hostname = DEFAULT_HOSTNAME;

	if( undefinedp(database) )
		database = DEFAULT_DATABASE;

	if( undefinedp(username) )
		username = DEFAULT_USERNAME;

	handle = db_connect(hostname, database, username, 0);
	
	if( intp(handle) )
	{
		mysql[handle] = ({ hostname, database, username });
		MSG(handle, "connect to "+hostname+"(database:"+database+", user:"+username+") successfully");
		exec(handle, "SET CHARACTER SET BIG5");
	}
	else
		MSG(0, handle); 
		
	return handle;
}
 
// 關閉 MYSQL 連線
varargs int close(int handle)
{
	if( undefinedp(handle) )
	{
		foreach(handle, string *data in mysql)
		{
			MSG(handle, "close connection");
			db_close(handle);
		}
		mysql = allocate_mapping(0);
	}
	else
	{
		MSG(handle, "close connection");
		map_delete(mysql, handle);
		return db_close(handle);
	}
	
	return 1;
}


// 執行 SQL 指令
varargs mixed exec(int handle, string sql)
{
	mixed value;
	
	value = db_exec(handle, sql);
	
	//if( !value )
	//	MSG(handle, "exec \""+sql+"\"");
	//else
	if( value )
		MSG(handle, "exec "+value);
	
	return value;
}

string status()
{
	return db_status();
}

int rollback(int handle)
{
	return db_rollback(handle);
}

mixed fetch(int handle, int set)
{
	return db_fetch(handle, set);
}

int commit(int handle)
{
	return db_commit(handle);
}

void create()
{
	mysql = allocate_mapping(0);
}

void updatetime(int handle, string table)
{
	exec(handle, "UPDATE `update` SET `time`=NOW() WHERE `table`='"+table+"'");
}

int remove()
{
	close();
}
string query_name()
{
	return "MYSQL 資料庫系統(MYSQL_D)";
}
