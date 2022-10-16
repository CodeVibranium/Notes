# OS

Require
`const OS=require("os")`

## EOL

- Tell about operating system end of the line marker
- for ex windows C:/
- in POSIX, mac linux \ root

## arch()

- Tells about the architecture of th processor

## constants

- Tells about commonly used operating system-specfic constants
  1.  Error code
  2.  Process signals
  3.  etc..

## cpus()

- Tell about each logical CPU cure
  1. Model
  2. Speed in MHZ
  3. time etc..

## devNull()

- Gives platfom specific file path of the null device

## endianess()

- **NEED TO KNOW**

## freemem()

- Tell about free mem (RAM) available in bytes

## homedir()

- Tells about the path of users home dir

## hostname()

- Tells about user host name

## loadavg()

- Tells about cpu load avg in
  1.  1min, 5min, and 15mins load avg

## networkInterfaces()

- **NEED TO KNOW**

## platform()

- Tells about os platofrm,
  1.  os.platform()== process.platform

## release()

- Tells about os release version

## tnpdir()

- Tells about tmp dir path for that os
  1.  used to place tmp files
  2.  Data will be deleted on restart()

## totalram()

- Tells about total ram of that machine

## type()

- Tells about os type
  1.  os.type()!= os.platform()

## uptime()

- Tells about machine uptime from last start in no of seconds

## userInfo()

- Tells about user related data

## version()

- Tells about os kernel version

## machine()

- Tells about about os arch type
  1. available only in node 18.9.0

## Left over

1. os.setPriority
2. os.networkInterfaces()
3. getPriority
4. endianess
5. diff b/w machine and arch
