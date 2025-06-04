# 0. no match
# 1. one occurrence
# 2. multiple occurrences on different lines and on same line
# 3. replace with same string
# 4. empty infile
# 5. only newlines file
# 6. replacer empty string
# 7. to be replaced empty string

# 8. incorrect amount of arguments
# 9. no permissions infile
# 10. no permissions outfile

#!/bin/bash

# Compile with make
if ! make > /dev/null 2>&1; then
	echo "Compilation failed!"
	make
	exit 1
fi

# Set executable name
EXE=filehell

# Set up permission test directory
TEST_DIR="testing/readonly_dir"
TEST_FILE="$TEST_DIR/input10.txt"

# Create directory and file, then make directory read-only for test 10
mkdir -p "$TEST_DIR"
echo "Some content in infile" > "$TEST_FILE"
chmod 444 "$TEST_DIR"  # Read-only directory

# Create file for test 9

# Test cases for argument count and basic errors
error_test_cases=(
	"E0:testing/input8.txt"
	"E1:testing/input9.txt:only_one"
	"E2:nonexistent.txt:arg1:arg2"
	"E3:$TEST_FILE:old:new"
)

echo "=== Testing Error Cases ==="
for i in "${!error_test_cases[@]}"; do
	echo "Error Test $i:"

	# Parse test case
	IFS=':' read -a PARTS <<< "${error_test_cases[$i]}"
	test_id="${PARTS[0]}"
	input_file="${PARTS[1]}"
	arg1="${PARTS[2]:-}"
	arg2="${PARTS[3]:-}"

	# Build command
	if [[ ${#PARTS[@]} -eq 2 ]]; then
		cmd=("./$EXE" "$input_file")
	elif [[ ${#PARTS[@]} -eq 3 ]]; then
		cmd=("./$EXE" "$input_file" "$arg1")
	else
		cmd=("./$EXE" "$input_file" "$arg1" "$arg2")
	fi

	# Run the program
	timeout 1s "${cmd[@]}" 2> tmp_err.txt
	exit_code=$?

	if [[ $exit_code -ne 0 ]] && [[ -s tmp_err.txt ]]; then
		echo "Error Test $i passed! (Program correctly failed/errored)"
	else
		echo "Error Test $i FAILED! (Program should have failed but didn't or wrote to incorrect stream)"
	fi
	rm -f tmp_err.txt
done

echo ""
echo "=== Testing Functional Cases ==="

# Functional test cases - all have exactly 3 arguments
functional_test_cases=(
	"testing/input0.txt:arg1:arg2"
	"testing/input1.txt:ipsum:1234"
	"testing/input2.txt:Lorem:Helloworld"
	"testing/input3.txt:Lor:Lor"
	"testing/input4.txt:a:b"
	"testing/input5.txt:a:b"
	"testing/input6.txt:o:"
	"testing/input7.txt::b"
)

outputs=(
	"testing/input0.txt.replace"
	"testing/input1.txt.replace"
	"testing/input2.txt.replace"
	"testing/input3.txt.replace"
	"testing/input4.txt.replace"
	"testing/input5.txt.replace"
	"testing/input6.txt.replace"
	"testing/input7.txt.replace"
)

expected_outputs=(
	"testing/expected/test0.txt"
	"testing/expected/test1.txt"
	"testing/expected/test2.txt"
	"testing/expected/test3.txt"
	"testing/expected/test4.txt"
	"testing/expected/test5.txt"
	"testing/expected/test6.txt"
	"testing/expected/test7.txt"
)

for i in "${!functional_test_cases[@]}"; do
	echo "Test $i:"

	# Parse test case - all have exactly 3 parts after test number
	IFS=':' read -ra PARTS <<< "${functional_test_cases[$i]}"
	input_file="${PARTS[0]}"
	arg1="${PARTS[1]}"
	arg2="${PARTS[2]}"

	# Call with 3 arguments
	timeout 1s ./"$EXE" "$input_file" "$arg1" "$arg2" 2> tmp_err.txt
	exit_code=$?

	if [[ $exit_code -eq 124 ]]; then
		echo "Test $i FAILED! (Program timed out)"
		continue
	fi

	# Check if output file exists
	if [[ ! -f "${outputs[$i]}" ]]; then
		echo "Test $i FAILED! (Output file not created)"
		rm -f tmp_err.txt
		continue
	fi

	# Compare output files
	if diff "${outputs[$i]}" "${expected_outputs[$i]}" > /dev/null; then
		echo "Test $i passed!"
	else
		echo "Test $i FAILED! (Output differs)"
		echo "Differences:"
		diff "${outputs[$i]}" "${expected_outputs[$i]}"
	fi
	rm -f tmp_err.txt
done

# Clean up
chmod 755 "$TEST_DIR" 2>/dev/null
rm -rf "$TEST_DIR" 2>/dev/null
