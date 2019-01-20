# Encapsulating a C library using FFI

## Motivation

Recently I read an article called **[Ruby Bindings and Extensions](https://medium.com/stuart-engineering/ruby-bindings-and-extensions-91c794eb9acd)**
where the author shows how in his company they were given the task of encapsulating a C library called [H3](https://github.com/uber/h3) using Ruby
and after evaluate the available options they decided to use [FFI](https://github.com/ffi/ffi) to do this work.

This repository contains a little test that I performed after read the article. I decided to create a little library that receives a PGM Image and return
a inverted colors image.

## How to run this
1. compile the library in your local.
  a. go to `ext/src` directory and run `make shared`
2. execute a `irb` console and import the library

## Example of use
```
>> require './pgm'
=> true
>>
>> pgm = PGM::Bindings::Structs::Pgm.new
=> #<PGM::Bindings::Structs::Pgm:0x007fc443825c30>
>> PGM::Functions.load_pgm(pgm, './Feep.pgm')
=> #<FFI::Pointer address=0x00000000000000>
>> pgm_out = PGM::Bindings::Structs::Pgm.new
=> #<PGM::Bindings::Structs::Pgm:0x007fc44208a918>
>> PGM::Functions.invert_colors(pgm, pgm_out)
=> nil
>> PGM::Functions.save_pgm(pgm_out, './feep_out')
=> #<FFI::Pointer address=0x00000000000000>
>> PGM::Functions.save_pgm(pgm_out, './feep_out.pgm')
=> #<FFI::Pointer address=0x00000000000000>
```
## Contributing
Bug reports and pull requests are welcome!
