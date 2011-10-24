#pragma once

#include <time.h>

#include "../include/aftypes.h"

#include "address.h"
#include "afnode.h"
#include "msg.h"
#include "name_af.h"
#include "netif.h"

namespace af
{
/// Afanasy's registered client ( Render, Talk).
class Client : public Node
{
public:

/// Construct client, getting values from environment.
   Client( int flags, int Id);

   enum Flags{
      DoNotGetAnyValues    = 0,
      GetEnvironment       = 1,
   };

   virtual ~Client();

   inline long long getTimeLaunch()         const { return time_launch;   }  ///< Get client launch time.
   inline long long getTimeRegister()       const { return time_register; }  ///< Get client register time.
   inline long long getTimeUpdate()         const { return time_update;   }  ///< Get client last update time.
   inline int       getRevision()           const { return revision;      }  ///< Get client revison.
   inline const std::string & getVersion()  const { return version;       }  ///< Get client version.
   inline const std::string & getUserName() const { return username;      }  ///< Get client user name.

   inline const Address & getAddress() const { return address;} ///< Get client address.
   inline bool addrEqual( const Client * other ) const          ///< Compare address with other.
               { return address.equal(other->address);}

   inline void setAddressIP( const Address & other) { address.setIP( other);}

/// Set registration time ( and update time).
   virtual void setRegisterTime();

   inline virtual bool isOnline() const { return true; }///< Whether the client is online.

   inline void updateTime() {  time_update   = time( NULL );} ///< Update client last update time.

   virtual int calcWeight() const; ///< Calculate and return memory size.

protected:
   void clearNetIFs();
   void grabNetIFs( std::vector<NetIF*> & otherNetIFs);

protected:
   int64_t     time_launch;   ///< Client launch time.
   int64_t     time_register; ///< Client registration on server time.
   int64_t     time_update;   ///< Client last update time.
   int32_t     revision;      ///< Client build revision.
   std::string version;       ///< Client version.
   std::string username;      ///< Client user name.
   Address     address;       ///< Client computer address.

   std::vector<NetIF*> netIFs;

private:
};
}
