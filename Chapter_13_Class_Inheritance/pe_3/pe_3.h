#ifndef PE_3_H
#define PE_3_H
#include <iostream>
#include <cstring>
#include <string>

class Ma{
    private:
        char* label;
        int rating;
    protected:
        char* ret_label()const {return label;}
        int ret_rating()const {return rating;}    
    public:
        Ma(const char* lbl = "None", int rat = 0);
        Ma(const Ma& Ma_next);
        virtual ~Ma();
        Ma& operator=(const Ma& Ma_next);
        virtual void View() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Ma& base);
};

class baseDma : public Ma{
    public:
        baseDma(const char* lbl, int rat);
        baseDma(const baseDma& base_next);
        virtual ~baseDma();
        baseDma& operator=(const baseDma& base_next);
        virtual void View() const;
        friend std::ostream& operator<<(std::ostream& os, const baseDma& base);

};

class lacksDma : public Ma{
    private:
        enum{COLOR = 40};
        char color[COLOR];
    public:
        lacksDma(const char* lbl, const char* clr, int rat);
        lacksDma(const lacksDma& lacks_next);
        virtual ~lacksDma();
        lacksDma& operator=(const lacksDma& lacks_next);
        virtual void View() const;
        friend std::ostream& operator<<(std::ostream& os, const lacksDma& base);

};

class hasDma : public Ma{
    private:
        char* style;
    public:
        hasDma(const char* lbl, const char* stl, int rat);
        hasDma(const hasDma& has_next);
        virtual ~hasDma();
        hasDma& operator=(const hasDma& has_next);
        virtual void View() const;
        friend std::ostream& operator<<(std::ostream& os, const hasDma& base);
};



#endif //PE_3_H