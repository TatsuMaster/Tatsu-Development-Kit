# Tatsu-Development-Kit
Software Development Kit for engineering Tatsu applications and drivers. This kit provides
headers, libraries, a test framework and tools to develop applications and drivers for the Tatsu
operating system. The current target language is the C programing language. Support for more
languages may follow in the future. This kit can be applied to target all CPU architectures
supported by the Tatsu Operating System.

# Kit Content

TBD

# APIs

There are three APIs provided by the Tatsu Development Kit.

1. POSIX Compatible API

One goal of the Tatsu Operating System and its TDK layer is to achive compatiblity to the
POSIX (Portable Operating System Interface) standard defined in IEEE 9945. This compatibility
should make it more easy to port existing applications to the Tatsu ecosystem. The current state
of implementation can be tracked in this document (a "Google Account" may be required):

https://docs.google.com/spreadsheets/d/1vdAJHGYbVqO3q-et0-A_xYhxsc7EptzhYqG6t3ffhnY/edit?usp=sharing

This document gets updated immediately as soon as new implementations are available.

2. Tatsu System API

Application interface for developing and deploying software based on the Tatsu Operating System.
This interface covers everything required for developing Tatsu applications. It is more richfull
and less a pain to use than the POSIX API (e.g. it can be used to develop GUI applications,
system services, ...).

3. Tatsu Device Driver API

The Tatsu Device Driver API can be used, if it is required to develop device drivers for any kind
of peripherals not supported by the device drivers included in Tatsu. More information about
the device driver API will be published in the future.

TBD

# Requirements

TBD

# Known Issues

TBD

