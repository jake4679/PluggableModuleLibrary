#include <iostream>
#include <string>

using namespace std;

#include "Registry.h"
#include "Registrant.h"

int main (
    int argc,
    char* argv[]) {
  Registry<string, Registrant*>* registry = Registry<string, Registrant*>::create();

  Registrant* registee = registry->get_registrant("harry");
  if(NULL == registee) {
    cout << "Expected non null registee" << endl;
    return 1;
  }
  
  registee->callback();

  registee = registry->get_registrant("sally");

  if(NULL != registee) {
    cout << "Expected null registee" << endl;
    return 1;
  }

  return 0;
}
