#include <iostream>

#include "Registry.h"
#include "Registrant.h"

static Registrant instance_("I am Harry");

Registrant::Registrant (
    string name) {
  name_ = name;

  Registry<string, Registrant*>* registry = Registry<string, Registrant*>::create();

  registry->register_module("harry", this);
}

Registrant::~Registrant (
    void) {
}

void Registrant::callback (
    void) {
  cout << "Registrant::callback(" << name_ << ")" << endl;
}
