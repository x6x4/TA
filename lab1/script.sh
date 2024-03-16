TIMEFORMAT="%R"

for i in 10 50 100 500 750 1000 2500 5000 7500 10000 17500 25000 
do
    #./build/std_regex_gen.out $i
    #time ./build/my_regex.out < ./data/match$i.data 
    time ./build/my_regex.out < ./data/unmatch$i.data 
done

