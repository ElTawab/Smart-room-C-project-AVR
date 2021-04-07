#define set_bit(var,bit_num) var=var|(1<<bit_num)
#define clr_bit(var,bit_num) var=var&(~(1<<bit_num))
#define toogle_bit(var,bit_num) var=var^(1<<bit_num)
#define get_bit(var,bit_num) ((var>>bit_num)&1)
