# one occurrence
# multiple occurrences on different lines and on same line
# no space-separated occurrences
# replace with same string
# no match

# no arguments handled
# empty infile
# only newlines file
# no permissions infile
# no permissions outfile

#!/bin/bash


# Compile with make
if ! make; then
    echo "Compilation failed!"
    exit 1
fi

# Set executable name
EXE=filehell

inputs=(
  "testing/input1.txt arg1 arg2"
  "testing/input2.txt foo bar"
  "testing/input3.txt hello world"
)

expected_outputs=(
  "testing/expected/test1.txt"
  "testing/expected/test2.txt"
  "testing/expected/test3.txt"
)

for i in "${!inputs[@]}"; do
	echo "Test $((i+1)):"
	# Run the program with the arguments for this test
	./"$EXE" ${inputs[$i]} > testing/output.txt

	# Compare output to expected
	if diff testing/output.txt "${expected_outputs[$i]}" > /dev/null; then
		echo -e "Test $((i+1)) passed!"
	else
		echo -e "Test $((i+1)) FAILED!"
		diff testing/output.txt "${expected_outputs[$i]}"
	fi
done
