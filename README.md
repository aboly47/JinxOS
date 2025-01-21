# JinxOS
JinxOS is a fork of an old project I worked on before losing my other account. all development will continue here.
I can't believe how cringe-worthy my old readme was. I've grown as a developer and as a person. *Maybe not so much as a developer. :)*

# What is it?
PowderOS is an operating system I'm working on. for now, it's limited. (Like, really limited.) but I'm planning on developing it as much as I can.

PowderOS is based on [FrOS](https://github.com/FRosner/FrOS/).

# Components
ShineOS contains the following components:
1. Boot loader
2. Operating system kernel, including
    1. ISRs to handle CPU interrupts
    2. VGA driver
    3. Keyboard driver
    4. Shell
    5. Dynamic memory allocation

# Installation guide

in unix like operating systems (like linux and MacOS), install brew and run:

`brew install qemu nasm gcc`

you can also find these packages on other package managers.

now, type:

`cd PATH_TO_POWDEROS`

NOTE: change `PATH_TO_POWDEROS` accordingly.

type:

`make run`

to compile and run the os in qemu.

type:

`make debug` 

for debug purposes,

type:
`make clean` to clean any binary files generated from the compilation.

# The name?
![Jinx/Powder](https://github.com/aboly47/PowderOS/blob/main/logo.jpeg)
![Jinx/Powder](https://github.com/aboly47/PowderOS/blob/main/logo1.jpeg)
![Jinx/Powder](https://github.com/aboly47/PowderOS/blob/main/logo2.jpeg)
I'm a massive Arcane fan, and Jinx is where the name comes from.

## Resources if you're interested in OS developement

- [Writing a Simple Operating System — from Scratch](https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf)
- [OS Dev Wiki](https://wiki.osdev.org/Meaty_Skeleton)
- [JamesM's Kernel Development Tutorials](https://web.archive.org/web/20160412174753/http://www.jamesmolloy.co.uk/tutorial_html/index.html)
- [BrokenThorn Entertainment's Operating System Development Series](http://www.brokenthorn.com/Resources/OSDevIndex.html)
- [The Little Book About OS Development](https://littleosbook.github.io/)
- [C Memory Allocation Functions](http://www.sunshine2k.de/articles/coding/cmemalloc/cmemory.html)
