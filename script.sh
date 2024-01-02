for dir in */
do
	echo "Checking directory $dir"
	if [ -f "$dir/Makefile" ]; then
		echo "Running make fclean in $dir"
		(cd "$dir" && make fclean)
	else
		echo "No Makefile in $dir"
	fi
done