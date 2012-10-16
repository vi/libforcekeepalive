libforcekeepalive.so.0.0.0: override.c Makefile
		gcc -shared -Wall -fPIC -o libforcekeepalive.so.0.0.0 override.c -ldl
		ln -fs libforcekeepalive.so.0.0.0 libforcekeepalive.so.0
		ln -fs libforcekeepalive.so.0.0.0 libforcekeepalive.so
