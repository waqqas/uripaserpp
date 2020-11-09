# uripaserpp
C++ wrapper on uriparser library

Building library
---

- `mkdir build`
- `cd build`
- `cmake -DCMAKE_INSTALL_PREFIX:PATH=`pwd`/usr ..`
- `cmake --build . --config Release --target install -- -j $(nproc)`
