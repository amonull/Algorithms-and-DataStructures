# Cells
Cells have 2 parts to them the data (i.e. the element/value) and next which either points to another [cell](#Cells) or points to [null](https://en.wikipedia.org/wiki/Null_pointer)

# How to think of it
Since there is no actual array that is being used here you have to think of lists as data that can be located anywhere on the memory and each keeps a reference to the next cell to work like an array (but can be dynamically resized since size is not fixed and can be changed as the user pleases).