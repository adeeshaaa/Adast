
Debian
====================
This directory contains files used to package Adastd/Adast-qt
for Debian-based Linux systems. If you compile Adastd/Adast-qt yourself, there are some useful files here.

## Adast: URI support ##


Adast-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install Adast-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your Adastqt binary to `/usr/bin`
and the `../../share/pixmaps/Adast128.png` to `/usr/share/pixmaps`

Adast-qt.protocol (KDE)

