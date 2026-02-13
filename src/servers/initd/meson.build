executable(
    'initd',
    'main.c',
    # The init process is linked statically because the dynamic loader can't be read before posixd is up.
    link_args: '-static',
    include_directories: common_includes,
    install: true,
)
