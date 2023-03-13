# environment

## SDL2

执行下面的命令[^sdl install]

```bash
sudo apt-get install libsdl2-dev
```

---

搜索安装的位置

```bash
dpkg -L libsdl2-dev
```

## SDL2 extension

命令如下[^foo install]

```bash
sudo apt-get install libsdl2-image-dev # SDL2_image
sudo apt-get install libsdl2-ttf-dev # SDL2_ttf
sudo apt-get install libsdl2-mixer-dev # SDL2_mixer
```

```bash
sudo apt-get install libsdl2-image-dev # SDL2_image
sudo apt-get install libsdl2-ttf-dev # SDL2_ttf
sudo apt-get install libsdl2-mixer-dev # SDL2_mixer
```

```bash
sudo apt-get install libsdl2-image-dev # SDL2_image
sudo apt-get install libsdl2-ttf-dev # SDL2_ttf
sudo apt-get install libsdl2-mixer-dev # SDL2_mixer
```

```bash
sudo apt-get install libsdl2-image-dev # SDL2_image
sudo apt-get install libsdl2-ttf-dev # SDL2_ttf
sudo apt-get install libsdl2-mixer-dev # SDL2_mixer
```

## xmake

编译带资源文件的项目如下 [^sample] [^add rule] :

```lua
add_requires("libsdl")

-- Define a build rule for a assets file
rule("assetsfile")
    on_build_file(function (target, sourcefile)
        os.cp(sourcefile, path.join(target:targetdir(), path.filename(sourcefile)))
        -- print(sourcefile)
        -- print(path.join(target:targetdir(), path.filename(sourcefile)))
    end)

target("test-sdl")
    set_kind("binary")
    add_files("test/SDL/*.cpp")
    add_files("test/SDL/assets/*", {rule = "assetsfile"})
    add_packages("libsdl")
```

---

对于 SDL extension, 可以使用 [`add_links`](https://xmake.io/#/manual/project_target?id=targetadd_links) 添加链接 [^foo install 1]

```lua
target("test-sdl-mixer")
    set_kind("binary")
    add_files("test/SDL-mixer/*.cpp")
    add_files("test/SDL-mixer/assets/*", {rule = "assetsfile"})
    add_packages("libsdl")
    add_links("SDL2_image", "SDL2_ttf", "SDL2_mixer")
```

### tips

- 多使用'print'帮助自己, 写 xmake script
- show the building process in detail

  ```bash
  xmake b -r -v
  ```

- xmake 运行 lua

  ```bash
  xmake l path.filename "./hello/hi.c"
  ```

## References

1. [-sdl install] [Installing SDL](https://wiki.libsdl.org/SDL2/Installation)
2. [-foo install] [-foo install 1] [Setting up SDL Extension Libraries on g++](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/linux/cli/index.php)
3. [-sample] [xmake-examples/sdl2-scaffold: A minimal SDL2 project template](https://github.com/xmake-examples/sdl2-scaffold)
4. [-add rule] [Project Target - xmake add rule](https://xmake.io/#/manual/project_target?id=targetadd_rules)
