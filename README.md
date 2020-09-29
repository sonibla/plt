# PLT

## Getting started

This project aims to remake the game [Magic: The Gathering Online](https://en.wikipedia.org/wiki/Magic:_The_Gathering_Online).

## Build instructions

### Environment

We use Ubuntu, but it also works on most Linux distributions.
Following instructions will install build dependencies on Debian.

```
sudo apt install git dia ghostscript cmake g++ lcov gcovr libxml2-dev libsfml-dev libboost-test-dev
git clone https://github.com/sonibla/plt.git
```

### Build binaries

```
mkdir build
cd build
cmake ..
make -j
```

Binaries are generated in *bin/* folder

### Report

Install LaTeX dependencies :

```
sudo apt install texlive texlive-math-extra texlive-science texlive-latex-extra texlive-lang-french
```

After running CMake, use the following command to generate the report :

```
make Rapport
```

## Authors

* [**Maxime Marroufin**](https://github.com/Marroufin)
* [**Quentin Chhean**](https://github.com/quenchhe)
* **Abinaya Mathibala**
* [**Alban Benmouffek**](https://github.com/sonibla)

See also the list of [contributors](https://github.com/sonibla/plt/contributors) who participated in this project.
