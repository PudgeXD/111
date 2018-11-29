#include"global.h"
enum mode {local,multi,distribute}
class Config
{
private:
	bool mode_; //运行模式：本地、伪分布式、分布式
	//最大可接受连接的客户端数量
	uint16_t max_client_count_; 
	//初始化服务器上数据库的数量
	uint16_t db_count_;
	//小于该值则value的类型为int，否则为string
	uint16_t int_type_limit_; 
	//允许客户端发送内容的最大字节长度
	uint32_t command_len_;
	//持久化程度
	/*待填*/

	bool read_config_file();
public:
	Config(){}
	~Config(){}
	//read_config_file() and set variable
	bool set_property();
	bool init_conf() {
		return set_property();	
	}
};