for i in 10 50 100 500 1000 5000 10000 50000 100000
do
    ./build/std_regex_gen.out $i
    time ./build/my_regex.out < ./data/matching.data 
    time ./build/my_regex.out < ./data/unmatching.data 
done

