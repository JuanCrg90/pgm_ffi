# Encapsulating a C library using FFI

## Motivation

Recently I read an article called **[Ruby Bindings and Extensions](https://medium.com/stuart-engineering/ruby-bindings-and-extensions-91c794eb9acd)**
where the author shows how in his company they were given the task of encapsulating a C library called [H3](https://github.com/uber/h3) using Ruby
and after evaluate the available options they decided to use [FFI](https://github.com/ffi/ffi) to do this work.

This repository contains a little test that I performed after read the article. I decided to create a little library that receives a PGM Image and return
a inverted colors image.

## How to run this
Install dependencies and compile the C library:

```bash
bin/setup
```

## Example of use

Start an irb console with the library loaded
```bash
$ bin/console
```

```ruby
# Create in memory the instances that will store the images
pgm = PGM::Bindings::Structs::Pgm.new
pgm_out = PGM::Bindings::Structs::Pgm.new

# Load the image
PGM::Functions.load_pgm(pgm, './example/in.pgm')

# Invert colors
PGM::Functions.invert_colors(pgm, pgm_out)

# Save image in disk
PGM::Functions.save_pgm(pgm_out, './example/out.pgm')
```

## Contributing
Bug reports and pull requests are welcome!
