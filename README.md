# GNUSlashLinux_Void_Installer

# 🌀 GNUSlashLinux Void Installer

Der offizielle, systemeigene Installer für **GNUSlashLinux**. Dieses Werkzeug ermöglicht es Endanwendern, das vorkonfigurierte Live-System mit wenigen Klicks oder über ein geführtes Terminal-Menü direkt auf eine Festplatte zu installieren.

Das Tool bindet sich nahtlos in die Live-Umgebung ein und sorgt für eine saubere Partitionierung, Übertragung des Dateisystems sowie die Konfiguration des Bootloaders.

---

# Screenshots

(assets/Screen_1.png)

(assets/Screen_2.png)

(assets/Screen_3.png)

(assets/Screen_4.png)

(assets/Screen_5.png)

(assets/Screen_6.png)

(assets/Screen_7.png)

(assets/Screen_8.png)

(assets/Screen_9.png)

---

## 📂 Projektstruktur

* **`src/` & `include/`:** Der Kern-Quellcode und die Header-Dateien des Installers.
* **`downloader/`:** Module für das Abrufen notwendiger Systemkomponenten oder Updates während der Installation.
* **`assets/` & `logo.png`:** Visuelle Medien, Icons und Logos für das Frontend.
* **`gnuslashlinux_installer.desktop`:** Die Starter-Datei, um den Installer direkt aus dem Anwendungsmenü des Live-Systems aufzurufen.
* **`build.sh` & `Makefile`:** Skripte zur einfachen Kompilierung und Paketierung des Installers.

---

## 🛠️ Kompilierung & Build

Um den Installer aus den Quellen zu bauen, führe die folgenden Befehle im Terminal aus:

1. Repository klonen und in den Ordner wechseln:
   ```bash
   git clone https://github.com/GNUSlashLinux/GNUSlashLinux_Void_Installer.git
   cd GNUSlashLinux_Void_Installer
   ```

2. Das Build-Skript ausführbar machen und starten:
   ```bash
   chmod +x build.sh
   ./build.sh
   ```

3. Alternativ die Kompilierung direkt über das `Makefile` anstoßen:
   ```bash
   make
   ```

---

## 🚀 Integration im Live-System

Nach dem erfolgreichen Build wird die Datei `gnuslashlinux_installer.desktop` nach `/usr/share/applications/` kopiert. Dadurch taucht das Installations-Werkzeug als Icon auf dem Desktop sowie im Anwendungsmenü deiner Niri-Umgebung auf und kann vom Endanwender sofort gestartet werden.
