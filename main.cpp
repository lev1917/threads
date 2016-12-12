#include<conio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include<chrono>
int x;
int flag = 0;
std::mutex lock;
std::mutex lock0;
void threadFunction1()
{
	for (int i = 0; i < 1000003; ++i) {
		while (flag != 0) {
			
		}
		lock.lock();
		if (flag == 0) {
			flag = 1;
			x++;
		}
		lock.unlock();
		
	}
}

void threadFunction2()
{
	for (int i = 0; i < 1000000; ++i) {
		while(flag!=1){}
		lock.lock();
		if (flag == 1) {
			if ((x % 2) == 0) {
				std::cout << "x = " << x << std::endl;
				

			}
			flag = 0;
		}
		lock.unlock();
	}

}

int main()
{
	std::thread t1(threadFunction1);
	std::thread t2(threadFunction2);
	t1.join();
	t2.join();
	_getch();
	return 0;
}
