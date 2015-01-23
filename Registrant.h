#ifndef __REGISTRANT_H__
#define __REGISTRANT_H__

#include <string>

using namespace std;

class Registrant {
  public:
    Registrant(
        string name);
    virtual ~Registrant(
        void);
    void callback(
        void);

  private:
    string name_;
};

#endif
