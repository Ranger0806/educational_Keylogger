#include "MailSender.h"

char* MailSender::payload_text = nullptr;

MailSender::MailSender(std::string email) {
	this->email = email;
}

void MailSender::send(std::string message)
{
	if (message != "") {
        CURL* curl;
        CURLcode res = CURLE_OK;
        struct curl_slist* recipients = NULL;
        struct upload_status upload_ctx = { 0 };
        const char* FROM_MAIL = email.c_str();

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "http://smtp.yandex.ru:465");
            curl_easy_setopt(curl, CURLOPT_MAIL_FROM, FROM_ADDR.c_str());
            curl_easy_setopt(curl, CURLOPT_USERNAME, USERNAME);
            curl_easy_setopt(curl, CURLOPT_PASSWORD, PASSWORD);
            curl_easy_setopt(curl, CURLOPT_VERBOSE, TRUE);
            recipients = curl_slist_append(recipients, FROM_MAIL);
            curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
            curl_easy_setopt(curl, CURLOPT_READFUNCTION, MailSender::payload_source);
            curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
            curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
            const std::time_t t = std::time(0);
            std::tm* now = new tm();
            localtime_s(now, &t);
            std::string text = "Date:" + std::to_string(now->tm_mday) + " " + monthes[now->tm_mon] + " " + std::to_string(now->tm_year + 1900) +
                " " + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec) + "\r\nTo: " + email + "\r\nFrom: " + FROM_ADDR +
                "\r\nSubject: SMTP example message\r\n\r\n" + message;
            int size = text.size() + 1;
            MailSender::payload_text = new char[text.size() + 1];
            strncpy_s(MailSender::payload_text, size, text.c_str(), size);
            try {
                res = curl_easy_perform(curl);
            }
            catch(std::exception e) {
                std::ofstream f("mailerrors.log", std::ios::app);
                f << e.what() << std::endl;
                f.close();
            }
            if (res != CURLE_OK) {
                std::ofstream f("mailerrors.log", std::ios::app);
                f << curl_easy_strerror(res) << std::endl;
                f.close();
            }
            else {
                std::ofstream f("statsMail.log", std::ios::app);
                f << "OK 200\n" << message << std::endl;
                f.close();
            }
            curl_slist_free_all(recipients);
            curl_easy_cleanup(curl);
        }
	}
}

size_t MailSender::payload_source(char* ptr, size_t size, size_t nmemb, void* userp)
{
    struct upload_status* upload_ctx = (struct upload_status*)userp;
    const char* data;
    size_t room = size * nmemb;

    if ((size == 0) || (nmemb == 0) || ((size * nmemb) < 1)) {
        return 0;
    }

    data = &payload_text[upload_ctx->bytes_read];

    if (data) {
        size_t len = strlen(data);
        if (room < len)
            len = room;
        memcpy(ptr, data, len);
        upload_ctx->bytes_read += len;

        return len;
    }

    return 0;
}
