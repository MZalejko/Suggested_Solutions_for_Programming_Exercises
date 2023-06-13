#ifndef TV_RM_HXX
#define TV_RM_HXX

#include <iostream>

#define DEFAULT_VOLUME 5
#define MAX_VOLUME 20
#define DEFAULT_CHANNEL 2
#define MAX_CHANNEL_NUM 125
#define FIRST_CHANNEL 1

constexpr const char* on_Statement{"ON"};
constexpr const char* off_Statement{"OFF"};
constexpr const char* mode_Antena{"Antena"};
constexpr const char* mode_Cable{"Cable"};
constexpr const char* input_TV{"TV"};
constexpr const char* input_DVD{"DVD"};
constexpr const char* remote_Mode_Normal{"Normal"};
constexpr const char* remote_Mode_Interactive{"Interactive"};

class Remote;

class Tv
{
    private:
        short state;
        short volume;
        short maxchannel;
        short channel;
        short mode;
        short input;

    public:
        friend class Remote;
        enum {Off, On};
        enum {MinVal, MaxVal = MAX_VOLUME};
        enum {Antena, Cable};
        enum {TV, DVD};

        Tv(short s = Off, short mc  = MAX_CHANNEL_NUM) : state(s), volume(DEFAULT_VOLUME), maxchannel(mc),
            channel(DEFAULT_CHANNEL), mode(Cable), input(TV) {};
        void On_Off() {state = (state == On) ? Off : On;};    
        bool isOn() const {return state == On;};
        bool volUp();
        bool volDown();
        void chanUp();
        void chanDown();
        void setMode() {mode = (mode == Antena) ? Cable : Antena;};
        void setInput() {input = (input == TV) ? DVD : TV;};
        void showSettings(const Remote& contr_remote) const;
        void change_remote_mode(Remote& contr_remote);
};

class Remote
{
    private:
        short tv_mode;
        short remote_mode;

    public:
        enum {Normal, Interactive};
        Remote(short tv_m = Tv::TV, short rt_m = Normal) : tv_mode(tv_m), remote_mode(rt_m) {};
        friend void Tv::showSettings(const Remote& contr_remote) const;
        friend void Tv::change_remote_mode(Remote& contr_remote);
        void On_Off(Tv& contr_Tv);    
        bool volUp(Tv& contr_Tv);
        bool volDown(Tv& contr_Tv);
        void chanUp(Tv& contr_Tv);
        void chanDown(Tv& contr_Tv);
        void setMode(Tv& contr_Tv);
        void setInput(Tv& contr_Tv);
        void setChannel(Tv& contr_Tv, short chann);
        void set_remote_mode(const Tv& contr_TV);
        void show_remote_mode() const {std::cout << "Remote mode " << ((remote_mode == Normal) ? remote_Mode_Normal : remote_Mode_Interactive) << std::endl;};

};

inline void Remote::On_Off(Tv& contr_Tv) {contr_Tv.On_Off();};    
inline bool Remote::volUp(Tv& contr_Tv) {return contr_Tv.volUp();};
inline bool Remote::volDown(Tv& contr_Tv) {return contr_Tv.volDown();};;
inline void Remote::chanUp(Tv& contr_Tv) {contr_Tv.chanUp();};
inline void Remote::chanDown(Tv& contr_Tv) {contr_Tv.chanDown();};
inline void Remote::setMode(Tv& contr_Tv) {contr_Tv.setMode();};
inline void Remote::setInput(Tv& contr_Tv) {contr_Tv.setInput();};
inline void Remote::setChannel(Tv& contr_Tv, short chann) {contr_Tv.channel = chann;};

inline void Tv::change_remote_mode(Remote& contr_remote) {contr_remote.set_remote_mode(*this);};






#endif // TV_RM_HXX