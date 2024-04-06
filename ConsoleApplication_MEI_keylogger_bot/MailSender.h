#pragma once
#include "Sender.h"
#include "fstream"
#include <ctime>
#include <time.h>
#include <string>
#include "Poco/Net/MailMessage.h"
#include "Poco/Net/MailRecipient.h"
#include "Poco/Net/SMTPClientSession.h"
#include "Poco/Net/NetException.h"
#include "Poco/Net/SecureSMTPClientSession.h"
#include "Poco/Net/InvalidCertificateHandler.h"
#include "Poco/Net/AcceptCertificateHandler.h"
#include "Poco/Net/SSLManager.h"
#include "Poco/Net/SecureStreamSocket.h"
#include "Poco/Net/MailRecipient.h"

using Poco::Net::InvalidCertificateHandler;
using Poco::Net::AcceptCertificateHandler;
using Poco::Net::Context;
using Poco::Net::SSLManager;
using Poco::Net::SecureStreamSocket;
using Poco::Net::SocketAddress;
using Poco::Net::SecureSMTPClientSession;
using Poco::Net::SMTPClientSession;
using Poco::SharedPtr;
using Poco::Net::MailMessage;
using Poco::Net::MailRecipient;
using namespace std;


class MailSender : public Sender
{
private:
	std::string monthes[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	std::string email = "0";
	const std::string FROM_ADDR = "kraka.tau0806@ya.ru";
	const string USERNAME = "kraka.tau0806@ya.ru";
	const string PASSWORD = "bnrlwtceqdeqhgsh";
public:
	static char* payload_text;
	struct upload_status {
		size_t bytes_read;
	};
	MailSender(std::string email);
	void send(std::string message) override;
	static size_t payload_source(char* ptr, size_t size, size_t nmemb, void* userp);
};

