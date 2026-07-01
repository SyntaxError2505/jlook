# Jlook
because your json deserves better
## Usage
After installing jlook, it is really easy to use. Just call the executable trough a shell like

```shell
jlook
```

It will ask for a single-line input of valid JSON and, after confirming by pressing enter, try to print out a goodlooking and readable version of whatever you typed in. Also, so you don't have to copy it in every time, you can `pipe` a string into it like this in `bash`:

```bash
cat test.json | jlook
```

It will just print out the pretty result which you can `pipe` pipe into any utility you like. E.g `tee` to write output into a file like this:

```shell
cat test.json | jlook | tee pretty_test.json
```

## Building
Jlook does not depend on any libraries beyond glibc. You will need the gnu c compiler `gcc` and the `make` build system. It is designed to be used on a unix-like-system which means that it will probably compile on something else but is not tested.  

A build process would look like this:  

```shell
git clone https://github.com/SyntaxError2505/jlook.git
cd jlook

# If you just want to build it:
make DEBUG=0 # Remove DEBUG if you wan't a debug build. Debug builds are slower and bigger.

# If DEBUG mode was on, remove debug exectutable before installation
make clean

# Installing it globally
sudo make install DEBUG=0 # Debug builds are not intended for installation. This is how to install a release build. Specify install directory by setting PREFIX:
sudo make install PREFIX=path/to/install/directory # Default is /usr/local/bin/
```

## Uninstalling
We offer a uninstall target that you can use in the directory like this:  

```shell
sudo make uninstall
```

it does the same as:

```shell
sudo rm -f $(which jlook)
```
