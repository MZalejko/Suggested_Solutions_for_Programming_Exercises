#include "tv_rm.hxx"

void make_space() {std::cout << std::endl;};

int main()
{

    Tv somy;
    Remote remote_somy;
    make_space();
    std::cout << "Default settings of the Tv: " << std::endl;

    somy.showSettings(remote_somy);
    remote_somy.show_remote_mode();
    somy.change_remote_mode(remote_somy);

    make_space();
    somy.On_Off();
    somy.chanUp();
    somy.change_remote_mode(remote_somy);

    make_space();
    std::cout << "New settings of the Tv: " << std::endl;
    somy.showSettings(remote_somy);

    make_space();
    remote_somy.setChannel(somy, 45);
    remote_somy.volUp(somy);
    remote_somy.volUp(somy);
    somy.showSettings(remote_somy);

    Tv new_somy(Tv::On);
    make_space();
    new_somy.showSettings(remote_somy);
    new_somy.setMode();
    new_somy.change_remote_mode(remote_somy);
    remote_somy.setChannel(new_somy, 24);
    make_space();

    std::cout << "Settings of New_Somy Tv: " <<std::endl;
    new_somy.showSettings(remote_somy);

    return 0;
}