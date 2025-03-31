# MapGenerator_So-Long

~ Started on: 31/03/2025 ~ *** ~ Ended on: In progress

[![Stars](https://img.shields.io/github/stars/Sulig/MapGenerator_So-Long?color=ffff00&label=Stars&logo=Stars&style=?style=flat)](https://github.com/Sulig/MapGenerator_So-Long)
[![Size](https://img.shields.io/github/repo-size/Sulig/MapGenerator_So-Long?color=blue&label=Size&logo=Size&style=?style=flat)](https://github.com/Sulig/MapGenerator_So-Long)
[![Activity](https://img.shields.io/github/last-commit/Sulig/MapGenerator_So-Long?color=orange&label=Last%20Commit&style=flat)](https://github.com/Sulig/MapGenerator_So-Long)
***

## What is this?
Is a **Map Generator** for [`so-long`](https://github.com/Sulig/So_Long) project. <br />
It will generate for you a closed random map:
  - With random width & height
  - Random number of coins
  - Random position of player
  - Random positon of exit

## How to use it ->
You have several options:
  - `Clone` this repository with:
    ```
    git@github.com:Sulig/MapGenerator_So-Long.git
    ```
    Go inside it, and ejecute
    ```
    make all
    ```

  - (Not ready) Dowload the executable <br />
    I will upload in a especific branch -> `executable` <br />
    And you will need only to execute it <br />
       _with_ or _without_ the number of maps desired

  - (Considering) Visit my (not created yet) web for generate a map!
     
### Well, I cloned the repo, What I can do?
#### Change the Max valors of `Map Width` and `Map Height`
You can control the `MAX_WIDTH` && `MAX_HEIGHT` of the maps, just edite `map_const.h` included in `/inc` <br />
> [!NOTE]\
> By default, the `MAX_WIDTH` && `MAX_HEIGHT` are defined with the `MAX_INT` definition.
> `MAX_INT` definition = 2147483647
> The values **can't** be more small than:
> 3 in WIDTH & 5 in HEIGHT
> or
> 5 in WIDTH & 3 in HEIGHT

#### Change the HEIGHT and WIDTH of map
You can directy set the desired `HEIGHT` and `WIDTH` of the maps! <br />
Only set that valors on `map_const.h` included in `/inc` <br />
> [!NOTE]\
> By default, the `WIDTH` && `HEIGHT` are defined with `0`
> If the values of `WIDTH` && `HEIGHT` are more small than:
> 3 in WIDTH & 5 in HEIGHT
> or
> 5 in WIDTH & 3 in HEIGHT
> The `WIDTH` && `HEIGHT` will be random.

#### Set the Cuantity of coins
Just set the `NUM_OF_COINS` with diferent number, on `map_const.h` included in `/inc` <br />
> [!NOTE]\
> By default, the `NUM_OF_COINS` are defined with `0`
> * If = 0 -> Number of coins will be random. (Can't be 0)
> * > 0    -> Number of coins will be that number.

#### More interesting things
In my `Makefile` you will encounter two variables you can edit.
  - The `MAPNUM` -> Number of maps to create (each one in diferent file)
  - The `MAPDIR` -> Directory where you will encounter the file maps

> [!NOTE]\
> If you leave `MAPNUM` at 0, the Generator will generate at least one map
> If you leave `MAPDIR` in some bad value, the maps will be saved in current directory
> ** In same directory where `map_gen` is allocated
***

##### MORE THINGS IN GOING!

***
~ Made by sadoming ~
***
