#!/bin/bash

outputs=(
	"testing/input/input0.txt.replace"
	"testing/input/input1.txt.replace"
	"testing/input/input2.txt.replace"
	"testing/input/input3.txt.replace"
	"testing/input/input4.txt.replace"
	"testing/input/input5.txt.replace"
	"testing/input/input6.txt.replace"
	"testing/input/input7.txt.replace"
	"testing/input/input8.txt.replace"
)

for output in "${outputs[@]}"; do
	rm -f "$output"
done

make fclean
