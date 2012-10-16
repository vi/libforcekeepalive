Sometimes you may want to use TCP Keepalive feature, but it is not enabled by default, programs need to specify SO_KEEPALIVE explicitly for the sockets.

This library automatically sets SO_KEEPALIVE for all connected and accepted sockets.

Usage:

    make
    LD_PRELOAD=`pwd`/libforcekeepalive.so   nc 1.2.3.4 5678
    
You can tune keep-alive options in

    /proc/sys/net/ipv4/tcp_keepalive_intvl
    /proc/sys/net/ipv4/tcp_keepalive_probes
    /proc/sys/net/ipv4/tcp_keepalive_time