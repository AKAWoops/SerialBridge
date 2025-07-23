This ia a plugin for UNITY so you can use serial communication again over USB after DotNet 2.1 dropped serial functionality in unity 6.0 was dropped 

Just download and run solution in visual studio 2022
Then build using release and x64 
Copy dll into UNITY project folder Assets Make an / x64 folder copy dll in there 
Reload UNITY and do calls in unity c# scripptsd as normal in script

dont forget to add the line in unity scripts to do calls for your dll using DLLimport and set portname and baudrades for write and close and open

:-)

Helps with usb serial communications that has been dropped since dot net 2.1 in unty 6.0
