struct card_inserted
{
    std::string account;
};
class atm
{
    messaging::receiver incoming;
    messaging::sender bank;
    messaging::sender interface_hardware;
    void (atm::*state)();
    std::string account;
    std::string pin;
    void waiting_for_card()  // 1
    {
        interface_hardware.send(display_enter_card()); // 2
        incoming.wait() // 3
            .handle<card_inserted>(
                [&](card_inserted const& msg) // 4
                {
                    account=msg.account;
                    pin="";
                    interface_hardware.send(display_enter_pin());
                    state=&atm::getting_pin;
                }
                );
    }
    void getting_pin();
public:
    void run() // 5
    {
        state=&atm::waiting_for_card; // 6
        try
        {
            for(;;)
            {
                (this->*state)(); // 7
            }
        }
        catch(messaging::close_queue const&)
        {
        }
    }
};
