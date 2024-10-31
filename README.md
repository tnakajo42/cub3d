#### cub3d
___
> 3d game project at 42

[!['cub3d'](https://tsfcm.jp/wp-content/uploads/2024/11/42_cub3d_halloween.gif)](https://youtu.be/zaKGzGfHjAQ)
# DOWNLOAD MLX42

first, you need to install [MLX42](https://github.com/codam-coding-college/MLX42) library.
MLX42 is a performant, easy to use, cross-platform, minimal windowing graphics library to create graphical applications without having to work directly with the native windowing framework of the given operating system.

```shell
$ make download_mlx42
```

if you do not have cmake in your laptop, try:

```shell
$ brew install cmake
```

# DOWNLOAD MUSIC

Berore play, please download miniaudio to add music.

```shell
$ make download_music
```

> I download a music from the url below

https://downloads.khinsider.com/game-soundtracks/album/dragon-quest-game-music-super-collection-vol.1


# PLAY GAME

```shell
$ make music
```

if you fail to make, try:

```shell
$ brew install glfw
```

There are several maps in `./map` folder. Try one of them. \n
for example:

```shell
$ ./cub3D ./map/map10.cub
```
