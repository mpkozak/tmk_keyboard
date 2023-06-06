#!/bin/bash



echo "<< TMK Kozak >>"



# dirs
TMK_HOME="$HOME/tmk_keyboard"
KOZAK="$TMK_HOME/_kozak"
BUILDS="$KOZAK/builds"



# active board dirs
_m0110="$TMK_HOME/converter/m0110_usb"

# custom keymaps
_m0110km="$_m0110/keymap_kozak.c"



# fs aliases
alias b='open $BUILDS'

# edit aliases
alias m='cd $_m0110; e'
alias km='e $_m0110km'
alias ek='e "$KOZAK"'



# build fn
function build {
  local sha="$(git rev-parse --short HEAD)"
  local board_name="m0110"
  local keymap=""

  cd "$_m0110"

  if [[ "$1" != "" ]]; then
    keymap="$1"
  else
    keymap="kozak"
  fi

  if [ ! -f "keymap_$keymap.c" ]; then
    echo "invalid selection: $1"
    return
  fi

  local fw_name="$board_name-$keymap"_"$sha"
  local makefile="Makefile.$fw_name"

  if [ -f "makefile" ]; then
    rm "$makefile"
  fi

  echo "TARGET = $fw_name" > "$makefile"
  echo "MCU = atmega16u2" >> "$makefile"
  echo "include Makefile" >> "$makefile"

  echo "building the $board_name..."
  make -f "$makefile" clean
  make -f "$makefile" KEYMAP="$keymap"

  mkdir "$fw_name"
  mv ".dep" "$fw_name/.dep"
  mv "obj_$fw_name" "$fw_name/obj_$fw_name"
  mv "$fw_name.eep" "$fw_name/$fw_name.eep"
  mv "$fw_name.elf" "$fw_name/$fw_name.elf"
  mv "$fw_name.hex" "$fw_name/$fw_name.hex"
  mv "$fw_name.lss" "$fw_name/$fw_name.lss"
  mv "$fw_name.map" "$fw_name/$fw_name.map"
  mv "$fw_name.sym" "$fw_name/$fw_name.sym"

  mv "$fw_name" "$BUILDS"

  rm "$makefile"

  echo "build successful!"
}
