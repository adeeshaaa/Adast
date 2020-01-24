
Debian
====================
This directory contains files used to package 1eurd/1eur-qt
for Debian-based Linux systems. If you compile 1eurd/1eur-qt yourself, there are some useful files here.

## 1eur: URI support ##


1eur-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install 1eur-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your 1eurqt binary to `/usr/bin`
and the `../../share/pixmaps/1eur128.png` to `/usr/share/pixmaps`

1eur-qt.protocol (KDE)

