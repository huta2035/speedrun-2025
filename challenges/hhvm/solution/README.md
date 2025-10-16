The challenge is split into two parts: reverse engineering and web.  

First, you must reverse the provided HHVM bytecode. Once the code is understood, identify a `loose comparison` vulnerability and use a *magic hash* as the password to authenticate.

For example `QNKCDZO` is working, as `md5("QNKCDZO") = 0e830400451993494058024219903391`.
