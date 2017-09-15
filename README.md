# ImmoClock

ImmoClock is a high resolution (nanosecond level), cross-platform c/c++ clock header-only library based on C++11 modern syntax and std::chrono.
This library is sophisticated yet tiny and fast with user-friendly extendible interaces, and which is widely used in production.
The library contains 3 parts.

ImmoClock 是一个跨平台高精度（纳秒级）时钟库，基于C++11的现代语法与std::chrono时钟库。其设计精巧但文件短小（仅需包含头文件即可使用），拥有极高的性能以及用户友好的可扩展接口；该库目前正使用于多个实际应用的项目。
ImmoClock主要包含以下三个主要类；

1. Timer       a handy and easy-to-use Timer which intialize the timer at consturctor, simply calling "elapsed()" to get the time elapsed.
2. Clock       provides utilities such as get current time, providing conversions between different time/date types.
3. Stopwatch   an thread-safe atomic Stopwatch that can be used for performance test.
	  
Examples#1:

int main()
{
	Timer t;	//timer started...
	for(int i=0;i<10000;++i)
		//do some stuff;

	std::cout << "Timer started since " << t.begin() << std::endl;	//returns a std::high_resolution_clock
	std::cout << t.seconds() << " seconds" << std::endl;
	std::cout << t.elapsed() << " milliseconds" << std::endl;
	std::cout << t.elapsed_micro() << " microseconds" << std::endl;

	t.restart();
	for(int i=0;i<10000000;++i)
		//do some other heavy stuff;
	std::cout << "Timer restarted since " << t.begin() << std::endl;	
	std::cout << t.elapsed_minutes() << " minutes" << std::endl;
	std::cout << t.elapsed_hour() << " hours" << std::endl;		
}

Example#2:
{
	std::cout << "Today " << Clock::today() << std::endl;
	std::cout << "Tomorrow" << Clock::tomorrow() << std::endl;
	std::cout << "Yesterday" << Clock::yesterday() << std::endl;

	Timer t; //timer started...
	for(int i=0;i<10000;++i)
	{
	}
}


