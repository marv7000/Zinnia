project(
    'zinnia',
    'c',
    license: 'MIT',
    version: '0.1.0',
    meson_version: '>=1.1.0',
    default_options: [
        'c_std=gnu23',
        'werror=true',
        'warning_level=2',
    ],
)

add_project_arguments(
    '-Wno-unused',
    '-Wno-unused-parameter',
    language: 'c',
)

add_project_link_arguments(
    '-znoexecstack',
    '-Wl,--gc-sections',
    '-Wl,--build-id=none',
    language: 'c',
)

common_includes = include_directories('include')

# Config file
common_cfg = configuration_data()
common_cfg.set_quoted('ZINNIA_VERSION', meson.project_version())
common_cfg.set_quoted('ZINNIA_ARCH', target_machine.cpu_family())
c_compiler = meson.get_compiler('c')
common_cfg.set_quoted('ZINNIA_COMPILER_ID', c_compiler.get_id() + ' ' + c_compiler.version())
common_cfg.set_quoted('ZINNIA_LINKER_ID', c_compiler.get_linker_id())

subdir('kernel')
subdir('lib')
subdir('servers')
