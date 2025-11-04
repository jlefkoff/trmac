unit ieee1284;
{$mode objfpc}{$H+}

interface

type
  Pchar = ^char;
  Pdword = ^dword;
  Plongint = ^longint;
  Pparport = ^parport;
  Pparport_list = ^parport_list;

  parport = record
    name: Pchar;
    base_addr: ptruint;
    hibase_addr: ptruint;
    priv: pointer;
    filename: Pchar;
  end;

  parport_list = record
    portc: longint;
    portv: ^Pparport;
  end;

function ieee1284_find_ports(list: Pparport_list; flags: longint): longint; cdecl;
procedure ieee1284_free_ports(list: Pparport_list); cdecl;
function ieee1284_open(port: Pparport; flags: longint; capabilities: Plongint): longint; cdecl;
function ieee1284_close(port: Pparport): longint; cdecl;
function ieee1284_claim(port: Pparport): longint; cdecl;
procedure ieee1284_release(port: Pparport); cdecl;
procedure ieee1284_write_data(port: Pparport; dt: byte); cdecl;
function ieee1284_read_status(port: Pparport): longint; cdecl;
function ieee1284_read_control(port: Pparport): longint; cdecl;
procedure ieee1284_write_control(port: Pparport; ct: byte); cdecl;
procedure ieee1284_frob_control(port: Pparport; mask: byte; val: byte); cdecl;

implementation

function ieee1284_find_ports(list: Pparport_list; flags: longint): longint; cdecl;
begin
  Result := 0;
end;

procedure ieee1284_free_ports(list: Pparport_list); cdecl;
begin
  // nothing to free
end;

function ieee1284_open(port: Pparport; flags: longint; capabilities: Plongint): longint; cdecl;
begin
  Result := 0;
end;

function ieee1284_close(port: Pparport): longint; cdecl;
begin
  Result := 0;
end;

function ieee1284_claim(port: Pparport): longint; cdecl;
begin
  Result := 0;
end;

procedure ieee1284_release(port: Pparport); cdecl;
begin
  // do nothing
end;

procedure ieee1284_write_data(port: Pparport; dt: byte); cdecl;
begin
  // do nothing
end;

function ieee1284_read_status(port: Pparport): longint; cdecl;
begin
  Result := 0;
end;

function ieee1284_read_control(port: Pparport): longint; cdecl;
begin
  Result := 0;
end;

procedure ieee1284_write_control(port: Pparport; ct: byte); cdecl;
begin
  // do nothing
end;

procedure ieee1284_frob_control(port: Pparport; mask: byte; val: byte); cdecl;
begin
  // do nothing
end;

end.
