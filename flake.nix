{
    description = "Flake for jlook, the pipeable json prettyfier";

    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    };

    outputs = { self, nixpkgs }:
    let
        pkgs = nixpkgs.legacyPackages.x86_64-linux.pkgs;
    in {
        devShells.x86_64-linux.default = pkgs.mkShell {
            name = "Jlook dev shell";
            buildInputs = with pkgs; [
                gnumake
                gcc
            ];
        };
    };
}
