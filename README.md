# Man Links Project

I use *man* pages very frequently, but I often struggle to find
specific topics in *man* pages.  For example, I constantly reference
the *bash* man page, but I may have trouble finding the section on
*Parameter Expansion*. Because it's internally referenced, a search
for *Parameter Expansion* often moves somewhere other than the
section head.  Other times, the problem is that I know something is
there, but I don't remember associated words with which to search for
it.

## manlinks Program

This project includes an implementation of [Bash Patterns][bash_patterns]
sources that shows a list of topics, the selection of which will open
a man page to an appropriate section of the man page.

## manlinks Usage

If **manlinks** is installed, you can access it anywhere.  Start the
script with:

~~~sh
user@home:~$ manlinks
~~~

You'll see a list of topics.  Select a topic with the arrow keys, then
press ENTER to see that man page topic.

## manlinks Installation

**manlinks** uses the [Bash Patterns sources resource][bash_patterns_sources]
to run the user interface.  There are instructions and explanations
for installing the resource.

The following shows how I have installed it on my system.  I do not
provide a set of copy-paste commands because it's not likely that our
directory structure is the same.  Look at the commands and replicate the
intent as appropriate on your system.

~~~sh
user@host:~$ cd work
user@host:~/work$ git clone www.github.com/cjungmann/bash_patterns.git
user@host:~/work$ git clone www.github.com/cjungmann/manlinks.git
user@host:~/work$ cd manlinks
user@host:~/work$ ln -s ~/work/bash_patterns/sources sources
user@host:~/work$ cd ~/.local/bin
user@host:~/.local/bin$ cp -s ~/work/manlinks/manlinks .
~~~

- The first two **git** lines copy the necessary content to the system.

- Lines four and five prepare the **manlinks** directory with access
  to the **bash_patterns** sources through a sym-link to the sources
  directory.

- Lines six and seven install the program with a sym-link to the
  executable script.  On my system, *~/.local/bin* is on my path,
  so I can type **manlinks** anywhere to access the resource.






[bash_patterns]:         <https://www.github.com/cjungmann/bash_patterns.git>                             "Bash Patterns"
[bash_patterns_sources]: <https://github.com/cjungmann/bash_patterns/blob/master/README.d/tui_sources.md> "sources"

