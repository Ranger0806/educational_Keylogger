#include "MailSender.h"

char* MailSender::payload_text = nullptr;

MailSender::MailSender(std::string email) {
	this->email = email;
}

void MailSender::send(std::string text)
{
    if (text != "") {
        int port = 465;
        string host = "smtp.yandex.ru";
        std::string subject = "Logs";
        MailMessage message;

        try {
            SharedPtr<InvalidCertificateHandler> pCert = new AcceptCertificateHandler(false);
            Context::Ptr pContext = new Poco::Net::Context(Context::TLS_CLIENT_USE, "", Context::VERIFY_NONE, 9, true);
            SSLManager::instance().initializeClient(0, pCert, pContext);

            SecureStreamSocket pSSLSocket(pContext);
            pSSLSocket.connect(SocketAddress(host, port));
            SecureSMTPClientSession secure(pSSLSocket);

            secure.login(SMTPClientSession::AUTH_LOGIN, USERNAME, PASSWORD);

            message.setSender(FROM_ADDR);
            message.addRecipient(MailRecipient(MailRecipient::PRIMARY_RECIPIENT, email));
            message.setSubject(subject);
            message.setContentType("text/plain; charset=UTF-8");
            message.setContent(text, MailMessage::ENCODING_8BIT);

            secure.sendMessage(message);
            secure.close();

        }
        catch (Poco::Net::SMTPException& e) {
            cout << e.code() << endl;
            cout << e.message() << endl;
            cout << e.what() << endl;
            cout << e.displayText().c_str() << endl;
        }
        catch (Poco::Net::NetException& e) {
            cout << e.code() << endl;
            cout << e.message() << endl;
            cout << e.what() << endl;
            cout << e.displayText().c_str() << endl;
        }
    }
}