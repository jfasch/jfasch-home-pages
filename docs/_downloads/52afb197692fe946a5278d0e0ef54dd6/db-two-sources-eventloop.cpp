#include "database.h"
#include "eventloop.h"
#include "udp-db.h"
#include "stdin-db.h"

int main()
{
    Database db;
    UDPToDatabase udp("0.0.0.0", 1234, db);
    StdinToDatabase stdin(db);

    Eventloop loop;
    udp.hookup(loop);
    stdin.hookup(loop);

    loop.run();

    db.commit();
    return 0;
};
