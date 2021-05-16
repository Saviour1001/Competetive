
array=[0]
for i in range(1,101):
    e=1
    w=1
    counter=2
    ratio = (e/(e+w))*100
    while(ratio!=i):
        if(ratio<i):
            e+=1
            counter+=1
            ratio = (e/(e+w))*100
            continue
        if(ratio>i):
            w+=1
            counter+=1
            ratio = (e/(e+w))*100
            continue
    array.append(counter)

for i in array:
    println(i)