package main

import "fmt"

func plus(a int,b int)int{
	return a + b
}

func vals() (int,int){
	return 3,7
}

/*
	res := plus(1,2)

	fmt.Println("1 + 2 =",res)

	a,b := vals()
	fmt.Println(a)
	fmt.Println(b)

	_,c := vals()
	fmt.Println(c)


func sum(nums ...int){
		fmt.Print(nums," ")
		total := 0
		for _,num := range nums{
			total += num
		}
		fmt.Println(total)
	}


func intSeq() func() int{
	i := 0
	return func() int{
		i += 1
		return i
	}
}

func fact(n int) int{
	if(n == 0){
		return 1
	}
	return n * fact(n - 1)
}
*/

func zeroval(ival int){
	ival = 0
}

func zeroptr(iptr *int){
	*iptr = 0
}
func main(){
	i := 1
	fmt.Println("initial:",i)

	zeroval(i)
	fmt.Println("zeroval:",i)

	zeroptr(&i)
	fmt.Println("zeroptr:",i)

	fmt.Println("pointer:",&i)
}

