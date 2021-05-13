// Fibonacci 

first = 0 ; 
second = 1; 

for(i = 0 ; i < 10 ; i ++){
    t = second ; 
    second = first + second; 
    first = t; 
}

result = first;  // 55 