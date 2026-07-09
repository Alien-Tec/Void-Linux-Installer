/*
 * lang_de.c
 * German translations
 */
#include "lang.h"
#include <string.h>
#include <stddef.h>

static const LangInfo lang_de = {
    .code = "de",
    .name = "Deutsch",
    .language = "Sprache:",
    
    // Welcome
    .welcome_title = "Willkommen bei GNUSlashLinux",
    .welcome_body = "Basierend auf Void Linux mit Niri, DankMaterialShell, Kitty, Tor Browser.",
    .welcome_title_markup = "<span size='xx-large' weight='bold'>Willkommen bei GNUSlashLinux</span>",
    .welcome_body_markup = "<span size='large'>Basierend auf Void Linux mit Niri, DankMaterialShell, Kitty, Tor Browser.</span>",
    
    // Install Type
    .install_type_title = "Installationsart auswählen:",
    .clean_install = "Festplatte löschen und Void Linux installieren",
    .install_alongside = "Neben einem anderen Betriebssystem installieren",
    .clean_install_desc = "Alle Daten auf der Festplatte werden gelöscht und Partitionen automatisch erstellt.",
    .alongside_desc = "Die bestehende Partition wird verkleinert, um Platz für das neue System zu schaffen.",
    
    // Partitions
    .disk = "Festplatte:",
    .disk_title = "Festplatte auswählen:",
    .disk_note = "Hinweis: Sie können Partitionen mit GParted ändern und unten konfigurieren.",
    .existing_parts = "Bestehende Partitionen",
    .install_parts = "Installations-Partitionen",
    .manual_partitioning = "Partitionen manuell konfigurieren",
    .btn_add = "Hinzufügen",
    .btn_edit = "Bearbeiten",
    .btn_delete = "Löschen",
    .btn_reset = "Zurücksetzen",
    .btn_gparted = "Partitionieren (GParted)",
    .part_mount = "Einhängepunkte:",
    
    // Bootloader
    .boot_detect = "Erkenne Firmware...",
    .grub_install = "GRUB installieren auf:",
    
    // System
    .hostname = "Hostname:",
    .country = "Land:",
    .locale = "Sprachregion:",
    .region = "Region:",
    .city = "Stadt:",
    .timezone = "Zeitzone:",
    
    // Users
    .root_pass = "Root-Passwort:",
    .user_account = "Benutzerkonto:",
    .fullname = "Vollständiger Name:",
    .username = "Benutzername:",
    .password = "Passwort:",
    .confirm = "Bestätigen:",
    .autologin = "Automatische Anmeldung aktivieren",
    
    // Install
    .install_btn = "Installation starten",
    .reboot_btn = "System neu starten",
    .back = "Zurück",
    .next = "Weiter",
    
    // Privilege Manager
    .tab_privilege = "Sicherheit",
    .priv_title = "Rechteausweitung",
    .priv_desc = "Wählen Sie zwischen dem traditionellen sudo oder dem leichtgewichtigen doas:",
    .priv_sudo_label = "sudo",
    .priv_sudo_desc = "Standardwerkzeug. Weitgehend kompatibel, komplexe Codebasis.",
    .priv_doas_label = "doas",
    .priv_doas_desc = "Minimale Alternative. Einfacher, weniger Angriffsflächen. Empfohlen.",
    
    // Tabs
    .tab_welcome = "Willkommen",
    .tab_install_type = "Installationsart",
    .tab_partitions = "Partitionen",
    .tab_bootloader = "Bootloader",
    .tab_system = "System",
    .tab_users = "Benutzer",
    .tab_install = "Installieren",
    
    // Partition dialog
    .select_partition = "Partition auswählen:",
    .filesystem = "Dateisystem:",
    .mount_point = "Einhängepunkt:",
    .format_partition = "Partition formatieren?",
    .encrypt_luks = "Verschlüsseln (LUKS)?",
    .general = "Allgemein",
    .encryption = "Verschlüsselung",
    .dialog_add = "Partition hinzufügen",
    .dialog_edit = "Partition bearbeiten",
    .dialog_update = "Aktualisieren",
    .save = "_Hinzufügen",
    .cancel = "_Abbrechen",
    
    // Messages
    .error_root_password = "Fehler: Root-Passwort fehlt.",
    .error_no_partitions = "Fehler: Keine Partitionen konfiguriert.",
    .error_no_root = "Fehler: Root-Partition (/) nicht konfiguriert.",
    .error_usr_not_supported = "Fehler: /usr als separate Partition wird nicht unterstützt!",
    .error_efi_partition = "Fehler: EFI-Systempartition (/boot/efi) wird für EFI benötigt!",
    
    // Window title
    .window_title = "GNUSlashLinux Installationsprogramm",
    
    // Success
    .success_title = "GNUSlashLinux ist BEREIT!!!",
    .success_body = "Die Installation wurde erfolgreich abgeschlossen.\nDas System kann neu gestartet werden.",
    .success_reboot = "JETZT NEU STARTEN",

    // Validation messages
    .val_select_disk    = "Bitte wählen Sie eine Festplatte aus, bevor Sie fortfahren.",
    .val_no_root        = "Keine Root-Partition (/) konfiguriert. Fügen Sie mindestens eine hinzu.",
    .val_grub_disk      = "Bitte wählen Sie eine Festplatte für die GRUB-Installation aus.",
    .val_hostname       = "Bitte geben Sie einen Hostnamen ein.",
    .val_username       = "Bitte geben Sie einen Benutzernamen ein.",
    .val_password       = "Bitte geben Sie ein Benutzerpasswort ein.",
    .val_password_match = "Die Benutzerpasswörter stimmen nicht überein.",
    .val_root_pass      = "Bitte geben Sie ein Root-Passwort ein.",
    .val_incomplete     = "Unvollständige Konfiguration",
};

const LangInfo* lang_de_module(void) {
    return &lang_de;
}
