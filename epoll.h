

#include <sys/epoll.h>
class Epoll {
private:
	int32_t epfd_;
	int32_t max_limit_;
public:
	Epoll(int32_t max_limit) {
		max_limit_ = max_limit;
		epfd_ = epoll_create(max_limit_+1);
	}
	~Epoll(){
		close(epfd_);
	}

	bool add (int32_t fd);

	bool modify(int32_t fd, struct epoll_event*);

	bool del(int32_t fd);

	bool monitor_accept();

	bool monitor_listen();


}