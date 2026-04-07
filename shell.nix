{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    arduino-cli
    gnumake
    # Required for some internal arduino-cli tools
    python3
  ];

  shellHook = ''
    # Create a local data directory so it doesn't try to write to /home/
    export ARDUINO_DIRECTORIES_DATA=$PWD/.arduino15
    export ARDUINO_DIRECTORIES_DOWNLOADS=$PWD/staging
    export ARDUINO_DIRECTORIES_USER=$PWD/user
  '';
}
