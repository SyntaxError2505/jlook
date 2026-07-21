# Contributing to jlook
Jlook is a small and simple codebase so rules on contributing are made to
implement changes fast. You may have a gripe, want a feature or fix
gripes/requests of others.

## Writing a good issue
### The Title
The title is an objective and short describtion of your message. It contains
exactly and only the information that is needed for me to get
annoyed at the issue and not at you

Juvenile issue
```md
Dumb help arg will not fuckin print
```
Indescribitve issue
```md
Not printing
```
Perfect issue
```md
Help arg not printing when indent length specified
```

### Everything else
Issues can consist of bug reports or bigger requests.
It is standardised to make out exactly what your problem is in the first few
lines of the message. The next lines consist of anny needed info like
error messages, screenshots or feature describtions (for feature requests).
On the last line please give a complement about me or the project. Thx <3!

## Pull requests
### General
Please run ```make format``` and ```make``` before pushing.
Also run the produced executable to confirm functionality.
As of now, there are no tests in the codebase.
A singular "format"-commit at the end of the pr is perfectly fine.
As long as your code is valid C, this will automatically make it follow our style guide.
For formatting `clang-format` is required to be installed.
I am working on implementing some Github actions magic
to at least give you warnings when pushing.

### Fixes
Please always markdown-link your issue you fixed in at least the title or the
describtion of your pr. This helps me close the issue and describe it in
releases. For this both its ID (weird string of chars next to it)
or github-link are okay. Please also describe how you fixed it. For a title
a plain "fixed <Issue>" is acceptable.

### New Features
It is always nice to first send an issue with a feature request so it can be
discussed. If the feature does not fit in my vision, I cannot accept your pr
no matter how much work you have put into it. If you are keen on
making the change yourself, you can mention so in the issue.
If an issue exists, please link it in either title or describtion using its
ID or its github-link. Also describe how you implemented it on a high level:

To low-level:
```md
Used a (proceeds to explain what a hashmap is...)
```

Perfect:
```md
Used a hashmap
```

To high-level:
```md
Used claude
```
