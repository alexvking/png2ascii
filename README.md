# png2ascii: lightning fast ASCII image generator

png2ascii is a fast ASCII image generator written in C. It was made to be the fastest way to make ASCII versions of your favorite images.

### Why?

Good question. It's not like tools like this are hard to find, but it *is* hard to find one that doesn't make a mess of requiring external libraries, or one that actually performs quickly. png2ascii is lightweight and does only what it needs to do.

### Features

  - Super fast PNG conversion to ASCII, tuned with KCachegrind for performance.
  - The LodePNG library is required for use and is included here. There are no external dependencies.
  - Size and image format conversion easily done with piping. See "Usage" below for details.
  

### Performance
png2ascii was tuned for speed, which is a large reason why it was written in C. KCachegrind was used to squeeze as much performance out of the tool as possible. png2ascii is fast, converting a 10MP, 10.6MB PNG into ASCII in just over 1 second on an Intel Core M processor. Compare that to *45 seconds* for a comparable conversion with a Python utility. Though there's little reason you'd ever need to produce a single image that large, png2ascii can be used to batch convert frames to produce cool ASCII GIFs.

### Todo
- Native support of  using convert to pipe input

### Usage

- Run "make" at the command line to build the project with GCC.
- png2ascii expects 

### Version
0.5.0
- Initial release

