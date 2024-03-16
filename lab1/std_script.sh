TIMEFORMAT="%R"

for i in 10 100 150 200 250 300
do
    ./build/std_regex_gen.out $i
    time ./build/my_regex.out < ./data/match$i.data 
done

