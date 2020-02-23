Make Projects From Simple Project Templates
===========================================

`mkprj` lets you quickly and easily create projects from templates. A project
is a directory containing one or more files and sub-directories. `mkprj`
comes with a set of simple project templates for programming in various
languages, but `mkprj` can be used for non-programming tasks too.

Installation
------------

* Clone / download the [Github project](http://github.com/matthewg42/mkprj) 
* Put `bin/mkprj` in your PATH
* Set the `MKPRJ_TEMPLATE_DIR` environment variable to the path of the 
  templates directory

Usage
-----

* List templates with: `mkprj -l`
* List templates (verbosely) with: `mkprj -L`
* Create a skeleton project from a template with: `mkprj templatename newdir`
  - A new directory `newdir` will be created in the current working directory, 
    which will be a copy of `$MKPRJ_TEMPLATE_DIR/templatename`
  - If `$MKPRJ_TEMPLATE_DIR/templatename/mkprj-replace` exists, `mkprj` will 
    prompt for each replacement value (see Replacements)

Replacements
------------

The file `.mkprj-replace` in a template directory contains a list is
strings to be replaced in the new project files.  Each line of the file
contains a string to be replaces, and optionally the default value for the
replacement. Some default values have special meanings, as described below.

For example:

```
__ONE_LINE_DESCRIPTION__
__PROGRAM_NAME__=my_new_program
__AUTHOR__=$fullname
__YEAR__=$date:%Y
```

`mkprj` will prompt for the value of `__ONE_LINE_DESCRIPTION__`, with no default
available. `__PROGRAM_NAME__` will then be prompted for with the default value 
of `my_new_program`. The default value is accepted is RETURN is pressed without
specifying another value.

The default values of `__AUTHOR__` and `__YEAR__` are special values which 
`mkprj` will replace as follows: 

* `$date:FMT` - use the current date/time formatted according with `FMT`
  (using formats as described in the date(1) manual page. e.g  `$date:%Y` 
  would expand to the current year
* `$project` - use the name of the new project directory as the default value
* `$username` - use the username of the user who invoked `mkprj`
* `$fullname` - use the full name of the user who invoked `mkprj` (as defined
  in the `/etc/passwd` file)
  
  


