function my_fibonacci(param_1) {
  if (param_1 < 0) 
    return -1;
  else if (param_1 == 0) 
    return 0;
  else if (param_1 == 1) 
    return 1;
  else if (param_1 == 2) 
    return 1;
  else if (param_1 >= 2) 
    return my_fibonacci(param_1 - 2) + my_fibonacci(param_1 -1)
};

console.log(my_fibonacci(3));