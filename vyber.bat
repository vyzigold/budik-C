@ECHO off
IF NOT EXIST Air_alert.mp3 REN aktual.mp3 Air_alert.mp3
IF NOT EXIST Big_alarm.mp3 REN aktual.mp3 Big_alarm.mp3
IF NOT EXIST Budicek.mp3 REN aktual.mp3 Budicek.mp3
IF EXIST aktual.mp3 DEL aktual.mp3
IF NOT EXIST ano.txt (
ECHO Zd† se, ße bud°k spouÁt°te poprvÇ, proto si nyn° vyberte zvonÿn°,
ECHO kterÇ se v†m nejv°ce l°b°.
ECHO.
ECHO Pokud si budete pozdÿji cht°t vybrat jinÇ zvonÿn°, staü° spustit soubor
ECHO vyber.bat ve sloßce s bud°kem.
ECHO.
PAUSE
CLS
DIR >> ano.txt)
:ZACATEK
ECHO 1...........Air_alert
ECHO 2...........Big_alarm
ECHO 3...........Budicek
ECHO.
ECHO 4...........NapiÁte ü°slo 4 pro vÏbÿr zvonÿn°, kterÇ se v†m nejv°ce l°b°.
ECHO 5...........NapiÁtÿ ü°slo 5 pro zad†n° cesty k vlastn°mu zvonÿn° ve form†tu mp3.
ECHO.
SET /P vyber=NapiÁtÿ ü°slo zvonÿn°, kterÇ si chcete poslechnout a stisknÿtÿ enter:
cls
IF NOT %vyber% == 1 (
IF NOT %vyber% == 2 (
IF NOT %vyber% == 3 (
IF NOT %vyber% == 4 (
IF NOT %vyber% == 5 (
ECHO Nezadal jste spr†vnÇ ü°slo.
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
ECHO 4...............................NapiÁte ü°slo 4 pro n†vrat zpÿt.
SET /P vyberOstry=NapiÁtÿ ü°slo zvonÿn°, kterÇ chcete vybrat a stisknÿtÿ enter:
cls
IF NOT %vyberOstry% == 1 (
IF NOT %vyberOstry% == 2 (
IF NOT %vyberOstry% == 3 (
IF NOT %vyberOstry% == 4 (
ECHO Nezadal jste spr†vnÇ ü°slo.
PAUSE
CLS
GOTO :VYBER))))

IF %vyberOstry% == 1 REN Air_alert.mp3 aktual.mp3
IF %vyberOstry% == 2 REN Big_alarm.mp3 aktual.mp3
IF %vyberOstry% == 3 REN Budicek.mp3 aktual.mp3
IF %vyberOstry% == 4 GOTO :ZACATEK
GOTO :KONEC

:CESTA
SET /p cesta=Zadejte cestu k vaÁemu zvonÿn°, nebo napiÁte 1 pro n†vrat zpÿt:
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
ECHO Nezadal jste spr†vnou cestu.
PAUSE
CLS
GOTO :CESTA)

:KONEC
ECHO VaÁe zvonÿn° bylo £spÿÁnÿ vybr†no.                    