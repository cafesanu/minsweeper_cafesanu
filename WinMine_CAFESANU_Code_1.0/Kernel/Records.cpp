//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Records.h"

//---------------------------------------------------------------------------
//Constructor
Records::Records()
  {
    for(int i=0;i<21;i++)
      {
        for(int j=0;j<10;j++)
          {
            time[i][j]=-1;
            nick[i][j][0]='\0';
          }
      }
  }

//Destructor

Records::~Records()
  {
  }

//-------------Analizadores-------------
string
Records::getNick(const int &nivel, const int &posTime)
  {
    return string(nick[nivel][posTime]);
  }

int
Records::getTime(const int &nivel, const int &posTime)
  {
    return time[nivel][posTime];
  }
  
//-------------Modificadores-------------

void
Records::setNick(const int &nivel, const int &posTime,const string &nNick)
  {
    strcpy( nick[nivel][posTime], nNick.c_str( ) );
  }

void
Records::setTime(const int &nivel, const int &posTime,const int &nTime)
  {
    time[nivel][posTime]=nTime;
  }


#pragma package(smart_init)
