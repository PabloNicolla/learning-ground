# Useful Windows 11 Command Line Commands for Network Queries

- [Useful Windows 11 Command Line Commands for Network Queries](#useful-windows-11-command-line-commands-for-network-queries)
  - [Basic Network Information](#basic-network-information)
    - [`ipconfig`](#ipconfig)
    - [`ping`](#ping)
    - [`tracert`](#tracert)
    - [`pathping`](#pathping)
    - [`nslookup`](#nslookup)
    - [`netstat`](#netstat)
    - [`netsh`](#netsh)
    - [`arp`](#arp)
    - [`getmac`](#getmac)

## Basic Network Information

### `ipconfig`

```sh
# Displays all current TCP/IP network configuration values.
ipconfig

# Displays detailed information about all network adapters, including MAC address, DHCP status, and DNS information.
ipconfig /all

# Releases the current DHCP-assigned IP address.
ipconfig /release

# Renews the DHCP-assigned IP address.
ipconfig /renew

# Flushes the DNS resolver cache.
ipconfig /flushdns
```

### `ping`

```sh
# Checks the connectivity to a specific IP address or domain.
ping <hostname_or_ip>
```

### `tracert`

```sh
#Traces the route taken by packets to reach a destination.
tracert <hostname_or_ip>
```

### `pathping`

```sh
# Combines the features of ping and tracert to provide detailed information about network latency and packet loss.
pathping <hostname_or_ip>
```

### `nslookup`

```sh
# Queries DNS servers to look up domain name information.
nslookup <domain>
```

### `netstat`

```sh
# Displays active TCP connections, ports on which the computer is listening, Ethernet statistics, the IP routing table, and IPv4/IPv6 statistics.
netstat

# Shows all active connections and listening ports with numeric addresses.
netstat -an

# Displays the routing table.
netstat -r

# Shows all active connections + PID
netstat -ano
```

### `netsh`

```sh
# A versatile command that can be used to configure almost any aspect of networking on Windows.
netsh interface show interface

# Example: Reset TCP/IP stack
netsh int ip reset
```

### `arp`

```sh
# Displays the ARP (Address Resolution Protocol) table.
arp -a
```

### `getmac`

```sh
# Displays the MAC address of all network adapters.
getmac
```
