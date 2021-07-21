#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define LOG1 "hello"
#define LOG2 "good-bye"
#define LOG3 "nice to meet you"
#define LOG4 "fine thank you"
#define LOG5 "how are you"
#define LOG6 "good morning"
#define LOG7 "good day to die"

typedef enum
{
	ERROR = 0,
	WARN,
	INFO,
	DEBUG,
} LOG_LEVEL;

typedef enum
{
	RU = 0,
	CU,
	DU,
} DEVICE;

int get_log_level()
{
	int random = 0;
	random = rand() % 4;
	return random;
}

int get_device()
{
	int random = 0;
	random = rand() % 3;
	return random;
}

int get_message()
{
	int random = 0;
	random = rand() % 7;
	return random; 
}

int main()
{
	time_t t;
	struct tm tm;
	LOG_LEVEL log_level;
	DEVICE device;
	int message;

	srand(time(NULL));
	for(;;)
	{
		t = time(NULL);
		tm = *localtime(&t);
		log_level = get_log_level();
		device = get_device();
		message = get_message();

		printf("[%02d-%02d-%02d %02d:%02d:%02d][%s][Cgenerator][%s]%s\n",
				tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
				tm.tm_hour, tm.tm_min, tm.tm_sec,
			  	(log_level==ERROR)?"ERROR":
				(log_level==WARN)?"WARN":
				(log_level==INFO)?"INFO":"DEBUG",
				(device==RU)?"RU":
				(device==CU)?"CU":"DU",
				(message==0)?LOG1:
				(message==1)?LOG2:
				(message==2)?LOG3:
				(message==3)?LOG4:
				(message==4)?LOG5:
				(message==5)?LOG6:LOG7);
		sleep(1);
	}
}
