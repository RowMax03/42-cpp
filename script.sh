find . -name Makefile -type f | while read dir; do
	echo "Running make fclean in $(dirname "$dir")"
	(cd "$(dirname "$dir")" && make fclean)
done