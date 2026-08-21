{
	description = "CJ C++ Order Book";

	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
	};

	outputs = { nixpkgs, ... }:
		let 
			system = "x86_64-linux";
			pkgs = nixpkgs.legacyPackages.${system};
		in {
			# the dev shell - when you get when you run 'nix develop'
			devShells.${system}.default = pkgs.mkShell {
				packages = with pkgs; [
					gcc
					cmake
					gnumake
					gdb
					valgrind
					clang-tools # Gives clangd (LSP), clang-format, clang-tidy
				];
				# Header-only libs go here so the compiler wrapper adds -isystem
				buildInputs = with pkgs; [
					plog
				];
			# Optional: set env vars for the shell session
			shellHook = ''
				# clangd uses compile_flags.txt, not NIX_CFLAGS_COMPILE, so it
				# needs the include dirs through the clang driver's own env var
				export CPLUS_INCLUDE_PATH="${pkgs.lib.makeSearchPathOutput "dev" "include" [ pkgs.plog ]}''${CPLUS_INCLUDE_PATH:+:$CPLUS_INCLUDE_PATH}"
				echo "C++ dev shell ready"
			'';
		};

		# Optional: a proper Nix package build of your project
		packages.${system}.default = pkgs.stdenv.mkDerivation {
			name = "cpp_order_book";
			src = ./.;
			nativeBuildInputs = with pkgs; [ cmake gnumake ];
			buildInputs = with pkgs; [
				# runtime dependencies go here (openssl, boost, ccache, ninja, lcov, doxygen, boost, openssl, pkg-config)
			];
		};
	};
}
