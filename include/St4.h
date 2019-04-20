#ifndef ST4_H
#define ST4_H

#include <Axis.h>
class St4
{
private:
    Axis ra;
    Axis dec;
  
public:
    
    String OK;
    String KO;

    St4(Axis ra, Axis dec);
    ~St4();
    void setup();
    void reset();
    String process(String cmd);
};
#endif //ST4_H
