#!/bin/sh
file=$1".c"
echo "#include <stdio.h>\n\nint main()\n{\n  return 0;\n}" > $file
vim $file
