#include "config.h"
//global instance: config

Config* conf = new Config;
int main() {
	conf.init();

	uint16_t pid = fork();
	bool server_run = false;
	if(!pid){
		//child
		while(!server_run){}
		Client* cli = new Client;
		cli.init();
		cli.connect("ip:port");
		cli.push_cmd("set "abc" 123");
		cli.send();
		char* rec = cli.receive();
		cout << rec << endl;
	} else {
		//father
		server_run = true;
		Server* server = new Server;
		server.init();
	}
	return 0;
}

