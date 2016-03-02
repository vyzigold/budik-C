@ECHO off
IF NOT EXIST Air_alert.mp3 REN aktual.mp3 Air_alert.mp3
IF NOT EXIST Big_alarm.mp3 REN aktual.mp3 Big_alarm.mp3
IF NOT EXIST Budicek.mp3 REN aktual.mp3 Budicek.mp3
IF EXIST aktual.mp3 DEL aktual.mp3
IF NOT EXIST ano.txt (
ECHO Zd� se, �e bud�k spou�t�te poprv�, proto si nyn� vyberte zvon�n�,
ECHO kter� se v�m nejv�ce l�b�.
ECHO.
ECHO Pokud si budete pozd�ji cht�t vybrat jin� zvon�n�, sta�� spustit soubor
ECHO vyber.bat ve slo�ce s bud�kem.
ECHO.
PAUSE
CLS
DIR >> ano.txt)
:ZACATEK
ECHO 1...........Air_alert
ECHO 2...........Big_alarm
ECHO 3...........Budicek
ECHO.
ECHO 4...........Napi�te ��slo 4 pro v�b�r zvon�n�, kter� se v�m nejv�ce l�b�.
ECHO 5...........Napi�t� ��slo 5 pro zad�n� cesty k vlastn�mu zvon�n� ve form�tu mp3.
ECHO.
SET /P vyber=Napi�t� ��slo zvon�n�, kter� si chcete poslechnout a stiskn�t� enter:
cls
IF NOT %vyber% == 1 (
IF NOT %vyber% == 2 (
IF NOT %vyber% == 3 (
IF NOT %vyber% == 4 (
IF NOT %vyber% == 5 (
ECHO Nezadal jste spr�vn� ��slo.
PAUSE
CLS
GOTO :ZACATEK)))))

IF %vyber% == 1 Air_alert.mp3
IF %vyber% == 2 Big_alarm.mp3
IF %vyber% == 3 Budicek.mp3
IF %vyber% == 4 GOTO :VYBER
IF %vyber% == 5 GOTO :CESTA
GOTO :ZACATEK

:VYBER
ECHO 1...............................Air_alert
ECHO 2...............................Big_alarm
ECHO 3...............................Budicek
ECHO.
ECHO 4...............................Napi�te ��slo 4 pro n�vrat zp�t.
SET /P vyberOstry=Napi�t� ��slo zvon�n�, kter� chcete vybrat a stiskn�t� enter:
cls
IF NOT %vyberOstry% == 1 (
IF NOT %vyberOstry% == 2 (
IF NOT %vyberOstry% == 3 (
IF NOT %vyberOstry% == 4 (
ECHO Nezadal jste spr�vn� ��slo.
PAUSE
CLS
GOTO :VYBER))))

IF %vyberOstry% == 1 REN Air_alert.mp3 aktual.mp3
IF %vyberOstry% == 2 REN Big_alarm.mp3 aktual.mp3
IF %vyberOstry% == 3 REN Budicek.mp3 aktual.mp3
IF %vyberOstry% == 4 GOTO :ZACATEK
GOTO :KONEC

:CESTA
SET /p cesta=Zadejte cestu k va�emu zvon�n�, nebo napi�te 1 pro n�vrat zp�t:
cls
IF %cesta% == 1 GOTO :ZACATEK
MKDIR C:\ydxflda
MOVE *.mp3 C:\ydxflda
COPY %cesta%
REN *.mp3 aktual.mp3
MOVE c:\ydxflda\*.*
RD C:\ydxflda
CLS
IF NOT EXIST aktual.mp3 (
ECHO Nezadal jste spr�vnou cestu.
PAUSE
CLS
GOTO :CESTA)

:KONEC
ECHO Va�e zvon�n� bylo �sp��n� vybr�no.                    