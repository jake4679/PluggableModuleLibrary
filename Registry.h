#ifndef __REGISTRY_H__
#define __REGISTRY_H__

#include <map>
#include <string>

using namespace std;

/// Registration interface to demonstrate basic module register on load.  Implements
/// Singleton pattern.
template<class KeyType, class RegistrantType>
class Registry {
  public:
    static Registry<KeyType, RegistrantType>* create(
        void) {
      // If current singleton instance has not been created then create it
      if(NULL == singleton_) {
        singleton_ = new Registry();
      }

      return singleton_;
    };

    static void destroy(
        void) {
      // @TODO Placeholder for now
    };

    void register_module(
        KeyType        key,
        RegistrantType registrant) {
      registrants_[key] = registrant;
    };

    void unregister_module(
        RegistrantType registrant) {
    }

    RegistrantType get_registrant(
        KeyType key) {
      return registrants_[key];
    };
    
  protected:
    Registry(
        void) {
      // No implementation required for this example
    };

    virtual ~Registry(
        void) {
      // No implementation required for this example
    };

  private:
    static Registry<KeyType, RegistrantType>* singleton_;

    map<KeyType, RegistrantType> registrants_;
};

template <class KeyType, class RegistrantType>
Registry<KeyType, RegistrantType>* Registry<KeyType, RegistrantType>::singleton_ = NULL;

#endif
