package main

import "fmt"
//import "math"
//import "time"

const s string = "constant"

func main(){
/*	fmt.Println("go" + "lang")
	fmt.Println("1 + 1 =", 1+ 1)
	fmt.Println("7.0/3.0 =",7.0/3.0)
	fmt.Println(true && false)
	fmt.Println(true || false)
	fmt.Println(!true)
	fmt.Println("======================")

	var a string = "initial"
	fmt.Println(a)

	var b,c int = 1,3
	fmt.Println(b,c)

	var d = true
	fmt.Println(d)

	var e int
	fmt.Println(e)

	f := "short"
	fmt.Println(f)
	fmt.Println("======================")

	fmt.Println(s)

	const n = 5000000

	const d = 3e20 / n
	fmt.Println(d)

	fmt.Println(int64(d))

	fmt.Println(math.Sin(n))

	i := 1
	for i <= 3{
		fmt.Println(i)
		i = i + 1
	}

	for j := 7; j <= 9; j++{
		fmt.Println(j)
	}

	for{
		fmt.Println("loop")
		break
	}


	if num := 9; num < 0{
		fmt.Println(num,"is negative")
	} else if num < 10{
		fmt.Println(num,"has 1 digit")
	} else {
		fmt.Println(num,"has multiple digits")
	}

	i := 2
	fmt.Println("write",i,"as")
	switch i{
	case 1:
		fmt.Println("one")
	case 2:
		fmt.Println("two")
	case 3:
		fmt.Println("three")
	}

	switch time.Now().Weekday(){
	case time.Saturday,time.Sunday:
		fmt.Println("it's the weekend")
	default:
		fmt.Println("it's a weekday")
	}

	t := time.Now()
	switch{
	case t.Hour() < 12:
		fmt.Println("it's before noon")
	default:
		fmt.Println("it's after noon")
	}

	var a [5] int
	fmt.Println("emp:",a)

	a[4] = 100
	fmt.Println("set:",a)
	fmt.Println("get:",a[4])

	fmt.Println("len:",len(a))

	b := [5]int{1,2,3,4,5}
	fmt.Println("dcl:",b)

	var twoD [2][3]int
	for i := 0; i < 2; i++{
		for j:= 0; j<3; j++{
			twoD[i][j] = i + j
		}
	}
	fmt.Println("2d:",twoD)


	s := make([]string,3)
	fmt.Println("emp:",s)

	s[0] = "a"
	s[1] = "b"
	s[2] = "c"
	fmt.Println("set:",s)
	fmt.Println("get:",s[2])

	fmt.Println("len:",len(s))

	s = append(s,"d")
	s = append(s,"e","f")
	fmt.Println("apd:",s)

	c := make([]string,len(s))
	copy(c,s)
	fmt.Println("cpy:",c)

	l := s[2:5]
	fmt.Println("sl1:",l)

	l = s[:5]
	fmt.Println("sl2:",l)

	l = s[2:]
	fmt.Println("sl3:",l)

	t:= []string{"g","h","i"}
	fmt.Println("dcl:",t)

	twoD := make([][]int,3)
	for i := 0; i < 3; i++{
		innerLen := i + 1
		twoD[i] = make([]int,innerLen)
		for j := 0; j < innerLen; j++{
			twoD[i][j] = i + j
		}
	}
	fmt.Println("2d:",twoD)

	m := make(map[string]int)

	m["k1"] = 7
	m["k2"] = 13
	fmt.Println("map:",m)

	v1 := m["k1"]
	fmt.Println("m[k1]:",m["k1"])
	fmt.Println("v1:",v1)

	fmt.Println("len:",len(m))

	delete(m,"k2")
	fmt.Println("map:",m)

	_,prs  :=m["k2"]
	fmt.Println("prs:",prs)

	n := map[string]int{"soo":1,"bar":2}
	fmt.Println("map:",n)
*/

	nums := []int{2,3,4}
	sum := 0
	for _,num := range nums{
		sum += num
	}
	fmt.Println("sum:",sum)

	for i,num := range nums{
		if num == 3{
			fmt.Println("index:",i)
		}
	}

	kvs := map[string]string{"a":"apple","b":"banana"}
	for k,v := range kvs{
		fmt.Printf("%s -> %s\n",k,v)
	}
	for i,c := range "ab"{
		fmt.Println(i,c)
	}
}
