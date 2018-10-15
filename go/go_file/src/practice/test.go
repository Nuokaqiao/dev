package main
import(
	"fmt"
)

func main(){
	slice := []int{10,20,30,40,50}
	newSlice := slice[2:3:3]
	
	fmt.Println(slice)
	newSlice[0] = 90
	newSlice = append(newSlice,33)
	slice[0] = 99
	fmt.Println("slice:",slice)
	fmt.Println(newSlice)
}
