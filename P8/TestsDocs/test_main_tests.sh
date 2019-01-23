make clean
make
bash main_tests.sh &> main_tests_actual
diff main_tests_actual main_tests_expected
