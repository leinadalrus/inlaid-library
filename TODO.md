# TODO

build on windows with:
`gcc src/main.c -lraylib -lopengl32 -lgdi32 -lwinmm`

F:/Projects/Repos/inlaid\\\_library $ gcc src/main.c -lraylib -lopengl32 -lgdi32 -lwinmm
src/main.c: In function 'main':
src/main.c:197:5: warning: 'free' called on unallocated object 'bundle\\\_instance' [-Wfree-nonheap-object]
197 | free(bundled);
| ^~~~~~~~~~~~~
src/main.c:154:5: note: declared here
154 | } bundle\\\_instance = {
| ^~~~~~~~~~~~~~~
F:/Projects/Repos/inlaid\\\_library $
