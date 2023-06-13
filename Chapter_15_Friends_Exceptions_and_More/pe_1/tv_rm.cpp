#include "tv_rm.hxx"

//TV class

bool Tv::volUp()
{
    if(volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Tv::volDown()
{
    if(volume > MinVal)
    {
        volume --;
        return true;
    }
    else
    {
        return false;
    }
}

void Tv::chanUp()
{
    if(channel < MAX_CHANNEL_NUM)
    {
        channel++;
    }
    else 
    {
        channel = FIRST_CHANNEL;
    }
}

void Tv::chanDown()
{
    if(channel > FIRST_CHANNEL)
    {
        channel--;
    }
    else
    {
        channel = MAX_CHANNEL_NUM;
    }
}

void Tv::showSettings(const Remote& contr_remote) const
{
    if(isOn())
    {
        std::cout << "Tv is " << on_Statement << std::endl;
        std::cout << "Volume " << volume << std::endl;
        std::cout << "Channel " << channel << std::endl;
        std::cout << "Mode " << ((mode == Antena) ? mode_Antena : mode_Cable) << std::endl;
        std::cout << "Input " << ((input == TV) ? input_TV : input_DVD) << std::endl;
        contr_remote.show_remote_mode();
    }

    else
    {
        std::cout << "Tv is" << off_Statement << std::endl;
    }
}

//Remote class

void Remote::set_remote_mode(const Tv& contr_tv)
{
    if(contr_tv.isOn())
    {
        remote_mode = (remote_mode == Normal) ? Interactive : Normal;
    }
    else
    {
        std:: cout << "Tv is" << off_Statement << std::endl;
    }
}