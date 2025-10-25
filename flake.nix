{
	description = "Text based city builder";

	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
	};

	outputs = { self, nixpkgs }: let
		supportedSystems = [ "x86_64-linux" "aarch64-linux"  "x86_64-darwin" "aarch64-darwin" ];
		forAllSystems = (fun:
			((nixpkgs.lib.genAttrs supportedSystems) (system:
				let pkgs = nixpkgs.legacyPackages.${system};
					in fun {
						system = system;
						pkgs = pkgs;
						libs = with pkgs; [ llvmPackages_21.libcxxClang ];
					}
			))
		);
	in {
		devShells = forAllSystems ({ system, pkgs, libs }: {
			text-city-builder = pkgs.llvmPackages_21.libcxxStdenv.mkDerivation {
				name = "text-city-builder";

				nativeBuildInputs = with pkgs; [
					gnumake
					llvmPackages_21.clang-tools
					bear
				];
				buildInputs = libs;

				shellHook = ''
					exec zsh;
				'';
			};
			default = self.devShells.${system}.text-city-builder;
		});
		packages = forAllSystems ({ system, pkgs, libs }: {
			text-city-builder = pkgs.llvmPackages_21.libcxxStdenv.mkDerivation {
				name = "text-city-builder";
				version = "0.1.0";

				nativeBuildInputs = with pkgs; [
					gnumake
				];
				buildInputs = libs;

				CPATH = pkgs.lib.makeSearchPathOutput "dev" "include" (libs ++ [ pkgs.glibc ]);

				src = ./.;
				buildPhase = ''
					${pkgs.gnumake}/bin/make tcb
				'';
				installPhase = ''
					mkdir -p $out/bin
					cp pf $out/bin/
					chmod 755 $out/bin/tcb
				'';
			};
			default = self.packages.${system}.text-city-builder;
		});
		apps = forAllSystems ({ system, pkgs, libs }: {
			text-city-builder = {
				type = "app";
				program = "${self.packages.${system}.text-city-builder}/bin/tcb";
			};
			default = self.apps.${system}.text-city-builder;
		});
	};
}
