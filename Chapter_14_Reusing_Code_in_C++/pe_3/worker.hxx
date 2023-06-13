#ifndef WORKER_HXX
#define WORKER_HXX


#include <string>
#define DEFVALUE 0

constexpr int numOfVoices{7};

void clearBuffor();

class Worker{

    private:
        std::string fullName;
        long id;
    
    protected:
        virtual void Data() const;
        virtual void Get();

    public:
        Worker()  : fullName("None"), id(0L) {};
        Worker(const std::string & name, long num) : fullName(name), id(num) {};
        virtual ~Worker() = 0; 
        virtual void Set() = 0;
        virtual void Show() const = 0;     
};

class Waiter : virtual public Worker{

    private:
        int panache;
    
    protected:
        void Data() const;
        void Get();
    
    public:
        Waiter() : Worker(), panache(DEFVALUE) {};
        Waiter(const std::string& name, long num, int panc = DEFVALUE) : Worker(name, num), panache(panc) {};
        Waiter(const Worker& worker, int panc = DEFVALUE) : Worker(worker), panache(panc) {};
        void Set();
        void Show() const;

};

class Singer : virtual public Worker{

    protected:
        enum voices{other, alt, kontralt, sopran, bas, baryton, tenor};
        enum {voiceTypes = numOfVoices};
        void Data() const;
        void Get();
    
    private:    
        static const char *pv[voiceTypes];
        int voice;

    public:
        Singer() : Worker(), voice(other) {};
        Singer(const std::string& name, long num, int v = other ) : Worker(name, num), voice(v) {};
        Singer(const Worker& worker, int v = other) : Worker(worker), voice(v) {};
        void Set();
        void Show() const;

};

class SingingWaiter : public Singer, public Waiter{

    protected:
        void Data() const;
        void Get();

    public:
        SingingWaiter() {};
        SingingWaiter(const std::string& name, long num, int panc = DEFVALUE, int vc = other) : Worker(name, num), Waiter(name, num, panc), Singer(name, num, vc) {};
        SingingWaiter(const Worker& worker, int panc = DEFVALUE, int vc = other) : Worker(worker), Waiter(worker, panc), Singer(worker, vc) {};
        SingingWaiter(const Waiter& waiter, int vc = other) : Worker(waiter), Waiter(waiter), Singer(waiter, vc) {};
        SingingWaiter(const Singer& singer, int panc = DEFVALUE) : Worker(singer), Waiter(singer, panc), Singer(singer) {};
        void Set();
        void Show() const;       

};

#endif // WORKER_HXX