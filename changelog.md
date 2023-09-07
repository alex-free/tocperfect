# Changelog

## Version 1.1.1 (9/3/2023)

*	[tocperfect-v1.1.1-windows-x86\_64](https://github.com/alex-free/tocperfect/releases/download/v1.1.1/tocperfect-v1.1.1-windows-x86_64.zip) _For Windows 10 64-bit or newer_

*	[tocperfect-v1.1.1-linux-x86\_64](https://github.com/alex-free/tocperfect/releases/download/v1.1.1/tocperfect-v1.1.1-linux-x86_64.zip) _For x86_64 Linux Distributions_

Changes:

*   Updated Tonyhax International to version 1.3.9.

## Version 1.1 (9/2/2023)

*	[tocperfect-v1.1-windows-x86\_64](https://github.com/alex-free/tocperfect/releases/download/v1.1/tocperfect-v1.1-windows-x86_64.zip) _For Windows 10 64-bit or newer_

*	[tocperfect-v1.1-linux-x86\_64](https://github.com/alex-free/tocperfect/releases/download/v1.1/tocperfect-v1.1-linux-x86_64.zip) _For x86_64 Linux Distributions_

Changes:

*   Fixes absolute LBA addressing in-game issues.

*   Added support for patching games with `.DA` files that only reference a CD Audio track and that do not contain any audio data (such as Tekken 3).

*   Updated `mkpsxiso` to v2.0.3, and now uses`dumpsxiso`+`binmerge` to rip which significantly increases patching compatibility.

*  Should now be just as powerful as the TOCPerfect patch mode found in [PS1 DemoSwap Patcher](https://alex-free.github.io/ps1demoswap).

*   Windows release is now completely self-contained and portable, MSYS2 being installed is no longer required.

*   Portable Linux releases now available.

*   Switched from my original [modified](https://github.com/alex-free/tonyhax/tree/v1.0tp) [tonyhax](https://github.com/socram888) v1.4.3 to my [Tonyhax International](https://alex-free.github.io/tonyhax-international) v1.3.8 fork. This adds support for Japanese consoles at long last.

*   Added support for early launch Japanese PSX.EXE games which don't have a SYSTEM.CNF.

*   Supports EDC protected games (burn them in RAW mode like described in Tonyhax International).

## Version 1.0 (11/3/2021)

*   [TOCPerfect v1.0 _for Windows 7 64 bit and above_](https://github.com/alex-free/tonyhax/releases/download/v1.0tp/tocperfect-1.0-windows.zip)