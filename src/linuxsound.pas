unit linuxsound;
{$mode objfpc}{$H+}
{$modeswitch objectivec1}  

interface

uses
  SysUtils, Classes, CocoaAll, process;

var
  BeepSoundCardEnable: boolean;
  dvpsetup: boolean = false;
  sounddevice: string[80] = 'default';

procedure LSound(hz: LongInt);
procedure LNoSound;
procedure BeginSound;
procedure EndSound;
procedure openconsole;
procedure playfile(f: PChar; msdelay: LongInt);
procedure soundmode(m: LongInt);
function playingfile: boolean;

implementation

var
  BeepHz: LongInt = 0;
  BeepTimer: NSTimer;
  filename: PChar = nil;
  delay: LongInt = 0;
  mode: LongInt = 0; // 0=beep,1=file,2=stop file
  playing: LongInt = 0;

procedure StopBeep;
begin
  if BeepTimer <> nil then
  begin
    BeepTimer.invalidate;
    BeepTimer := nil;
  end;
end;

procedure TimerCallback(sender: NSTimer); cdecl;
begin
  NSBeep; // Play a simple system beep
end;

procedure LSound(hz: LongInt);
begin
  if hz > 0 then
    NSBeep; // Use macOS system beep
end;

procedure LNoSound;
begin
  StopBeep;
end;

procedure BeginSound;
begin
  // Nothing to initialize for macOS system beep
end;

procedure EndSound;
begin
  StopBeep;
end;

procedure openconsole;
begin
  // no console device on macOS, nothing to do
end;

procedure playfile(f: PChar; msdelay: LongInt);
var
  outputstring: string;
begin
  if f <> nil then
    RunCommand('afplay', [string(f)], outputstring);
end;

procedure soundmode(m: LongInt);
begin
  mode := m;
end;

function playingfile: boolean;
begin
  playingfile := (playing = 1);
end;

end.
