if [ "$(id -u)" -ne 0 ]; then
	echo "This script requires sudo."
	exit 1
fi

echo $?

if grub-file --is-x86-multiboot sun.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi

mkdir -p isodir/boot/grub

cp bin/sun.bin isodir/boot/sun.bin

grub-mkrescue -o sun.iso isodir
