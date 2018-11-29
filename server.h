#include "global.h"
#include "clietnStatus.h"
#include <time.h>
class server
{
private:
	DB* db_list_;
	LinkedClientStatus* client_list_;

	LLpair* save_parameter_ ; //???
	uint64_t dirty_;
	time_t last_save_;
	Config* conf_;
	Parser* parser_;

	//port
	//addr

	

public:
	server();
	~server();
	bool init(){
		parser_ = new Parser;
		parser_.init(); //建立命令哈希表
		//设置其他私有变量
		//
	}
	//多路复用
	void epoll();

	DB* get_db_by_index(uint16_t index);
	DB* get_db_by_name(char* db_name);



	
};