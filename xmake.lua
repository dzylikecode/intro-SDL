add_rules("mode.debug", "mode.release")
add_requires("libsdl")

-- Define a build rule for a assets file
rule("assetsfile")
    on_build_file(function (target, sourcefile)
        os.cp(sourcefile, path.join(target:targetdir(), path.filename(sourcefile)))
    end)


target("hello-world")
    set_kind("binary")
    add_files("example/hello-world/src/*.cpp")
    add_files("example/hello-world/res/*", {rule = "assetsfile"})
    add_packages("libsdl")
target_end()

-- target("test-sdl-mixer")
--     set_kind("binary")
--     add_files("test/SDL-mixer/*.cpp")
--     add_files("test/SDL-mixer/assets/*", {rule = "assetsfile"})
--     add_packages("libsdl")
--     add_links("SDL2_image", "SDL2_ttf", "SDL2_mixer")

