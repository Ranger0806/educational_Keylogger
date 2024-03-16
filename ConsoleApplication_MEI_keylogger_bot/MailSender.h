#pragma once
#include "Sender.h"
#include "curl/curl.h"
#include "fstream"
#include <ctime>
#include <time.h>
#include <string>

class MailSender : public Sender
{
private:
	std::string monthes[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	std::string email = "0";
	const std::string FROM_ADDR = "kraka.tau0806@yandex.ru";
	const char* USERNAME = "kraka.tau0806@yandex.ru";
	const char* PASSWORD = "brslgluyfwnmomfg";
public:
	static char* payload_text;
	struct upload_status {
		size_t bytes_read;
	};
	MailSender(std::string email);
	void send(std::string message) override;
	static size_t payload_source(char* ptr, size_t size, size_t nmemb, void* userp);
};

