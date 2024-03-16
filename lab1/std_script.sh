TIMEFORMAT="%R"

for i in 100 110 120 130 140 150 160 170 180 190 200 
do
    ./build/std_regex_gen.out $i
    time ./build/my_regex.out < ./data/match$i.data 
done

