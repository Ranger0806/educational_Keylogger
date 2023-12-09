#pragma once
class TGSender
{
	void send();
};

//TgBot::Bot bot("6374688261:AAEHPkpT06dTrBu07_muKx3TXjvcSymM9vM");
//bot.getApi().sendMessage("1332422290", "Hi!");
//bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
//    bot.getApi().sendMessage(message->chat->id, "Hi!" + std::to_string(message->chat->id));
//    });
//bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
//    printf("User wrote %s\n", message->text.c_str());
//    if (StringTools::startsWith(message->text, "/start")) {
//        return;
//    }
//    bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
//    });
//try {
//    printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
//    TgBot::TgLongPoll longPoll(bot);
//    while (true) {
//        printf("Long poll started\n");
//        longPoll.start();
//    }
//}
//catch (TgBot::TgException& e) {
//    printf("error: %s\n", e.what());
//}
//return 0;

