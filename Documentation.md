# Sun Kernel Developers Documentation
This file contains the documentation for developers using the Sun Kernel - distro developers and software developers alike.

# Syscalls
Currently, the syscalls are rather limited. These are the ones you can currently call:

* print
* printcolour
* clear
* terminal_set_cursor
* outb
* inb
* inw
* outw
* sys_error
* sys_warn
* sys_info
* sys_success
* sys_stop

# Print
The Print syscall is simple. It is the equivalent of printf, Console.WriteLine, etc. It is part of the 'vgabuffer' header.
This is it in use:

* `#include "vgabuffer.h"`
* `int main()`
* `{`
* `  print("Hello World!");`
* `}`

# Printcolour
The print colour syscall is simply changing the colour of the text. It is part of the 'vgabuffer' header. This is it in use:
* `#include "vgabuffer.h"`
* `int main()`
* `{`
* `  printcolour(VGA_COLOUR_GREEN, VGA_COLOUR_BLACK);`
* `}`

The first colour is changing the *foreground* to green, the second colour is changing the *background* to black.

# Clear
This syscall clears the screen. It is part of the 'vgabuffer' header. This is it in use:

* `#include "vgabuffer.h"`
* `int main()`
* `{`
* `  clear();`
* `}`

# Terminal_Set_Cursor
This sets the terminal cursor to any given position. It will not be shown here yet as it is still WIP.
It will be part of the 'vgabuffer' header.

# Outb, inb, inw and outw
These are all IO related syscalls. They are included in the 'io.h' header. There is info readily available online for
these functions, however they are primarily for driver-writing and will likely not be of use to software developers*

# Sys_info, Sys_warning, etc
These are all quality-of-life features. Everything here can be used in place of manually writing out logs (eg, writing
out a full colour change, a print and a colour change back). They are part of the 'logs' header

This is (one) in action:
* `#include "vgabuffer.h"`
* `int main()`
* `{`
* `  error("Hello World!");`
* `}`

Upon execution, this would show in red text and display as:
* `[ERROR]: Hello World!`
