UNIX tabanlı işletim sistemleri için şifreli not defteri uygulamasıdır.
Sadece çıktı dosyası olan "encrypted_notepad" dosyasını indirip gerekli izni verdikten sonra kullanabilirsiniz.
Veya isterseniz kaynak dosyaları indirip terminalden "make" komutunu girerek yeni bir derleme ve çıktı dosyası oluşturabilir, bu dosyayı kullanabilirsiniz.
Veya son derlenmiş hali olan "encrypted_notepad" uygulamasını indirip kullanabilirsiniz. Bazı sistemlerde ilk indirdiğinizde çalışmamakta çünkü dosyanın izinlerini vermeniz gerekiyor.
Uygulamanın çalıştırma iznini vermek için terminalden uygulamanın bulunduğu dizine girip:
"chmod +x encrypted_notepad" şeklinde izin vermeniz yeterlidir.
örnek:
1) Terminali açın ve dosyanın yüklendiği konuma gidin:
   cd /Downloads/encrypted_notepad/
2) Dosyaya çalıştırma izni verin:
   chmod +x encrypted_notepad
3) Uygulamayı çalıştırın:
   ./encrypted_notepad (veya dosyaya çift tıklama)
