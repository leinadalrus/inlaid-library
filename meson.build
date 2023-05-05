project('sinecurio_containers', 'c', version : ‘0.1.0’, default_options : [‘warning_level=3’, ‘c_std=c99’])

my_incs = include_directories('inc')
my_libs = static_library('ext')
my_deps = dependency(link_with: my_libs, include_directories: my_incs)

executable('sinecurio_containers', 'src/main.c',
    win_subsystem: 'windows',
    dependencies: my_deps)
