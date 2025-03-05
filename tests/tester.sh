#!/bin/bash

# Compilation du programme
make

# Fonction pour effectuer un test et vérifier la valeur de retour
test_execution() {
  test_id="$1"
  test_name="$2"
  command="$3"
  expected_return="$4"
  $command
  actual_return="$?"
  if [ "$actual_return" -eq "$expected_return" ]; then
    passed_count=$((passed_count + 1))
    printf "\033[32mTest [%s] %s passed\033[0m\n" "$test_id" "$test_name"
  else
    error_count=$((error_count + 1))
    printf "\033[31mTest [%s] %s failed: expected %s, got %s\033[0m\n" "$test_id" "$test_name" "$expected_return" "$actual_return"
  fi
}

# Initialisation des compteurs
error_count=0
passed_count=0

# Création des fichiers de test
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nlive %1" > valid.s
echo ".name \"Invalid name\"\n.comment \"Valid comment\"\nlive %1" > invalid_name.s
echo ".name \"Valid name\"\n.comment \"Invalid comment\"\nlive %1" > invalid_comment.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\ninvalid_instruction" > invalid_instruction.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nlabel: live %1\nzjmp label" > valid_label.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nld %1, r1" > valid_instruction_params.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nld %invalid, r1" > invalid_instruction_params.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nadd r1, r2, r3" > valid_multiple_params.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nadd r1, r2, %invalid" > invalid_multiple_params.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nlive %1\nlabel: live %1\nzjmp label" > multiple_lines.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\n\n\nlive %1" > empty_lines.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nlive %1\n;This is a comment" > comment_line.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nlabel: live %1\nzjmp label\ninvalid_instruction" > label_invalid_instruction.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nsti r1, %:label, %1" > sti_instruction.s
echo ".name \"Valid name\"\n.comment \"Valid comment\"\nld %1, r1\nadd r1, r2, r3\nsti r1, %:label, %1" > multiple_instructions.s

# Tests
test_execution "1" "Help" "./asm -h" 0
test_execution "2" "No args" "./asm" 84
test_execution "3" "Valid file" "./asm valid.s" 0
test_execution "4" "Invalid file" "./asm invalid_file.s" 84
test_execution "5" "Invalid name" "./asm invalid_name.s" 84
test_execution "6" "Invalid comment" "./asm invalid_comment.s" 84
test_execution "7" "Invalid instruction" "./asm invalid_instruction.s" 84
test_execution "8" "Valid label" "./asm valid_label.s" 0
test_execution "9" "Valid instruction params" "./asm valid_instruction_params.s" 0
test_execution "10" "Invalid instruction params" "./asm invalid_instruction_params.s" 84
test_execution "11" "Valid multiple params" "./asm valid_multiple_params.s" 0
test_execution "12" "Invalid multiple params" "./asm invalid_multiple_params.s" 84
test_execution "13" "Multiple lines" "./asm multiple_lines.s" 0
test_execution "14" "Empty lines" "./asm empty_lines.s" 0
test_execution "15" "Comment line" "./asm comment_line.s" 0
test_execution "16" "Label invalid instruction" "./asm label_invalid_instruction.s" 84
test_execution "17" "sti instruction" "./asm sti_instruction.s" 0
test_execution "18" "Multiple instructions" "./asm multiple_instructions.s" 0

# Affichage du résumé des tests
echo "Tests passed: $passed_count"
echo "Wrong value: $error_count"

# Nettoyage
make clean
rm -f valid.s invalid_name.s invalid_comment.s invalid_instruction.s valid_label.s valid_instruction_params.s invalid_instruction_params.s valid_multiple_params.s invalid_multiple_params.s multiple_lines.s empty_lines.s comment_line.s label_invalid_instruction.s sti_instruction.s multiple_instructions.s
