TIMEFORMAT="%R"

for i in 15
do
    ./build/std_regex_gen.out $i
    ./build/my_regex.out < ./data/unmatch$i.data  
    ./build/my_regex.out < ./data/match$i.data
done