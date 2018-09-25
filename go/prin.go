package main
import (
	"fmt"
	"strings"
	"strconv"
)

type Ustr string
func (us Ustr) String() string{
	return strings.ToUpper(string(us))
}

func (us Ustr) GoString() string{
	return `"` + strings.ToUpper(string(us)) + `"`
}

func (u Ustr) Format(f fmt.State, c rune){
	write := func(s string){
		f.Write([]byte(s))
	}
	switch c{
	case 'm','M':
		write("旗标:[")
		for s := "+- 0#"; len(s) > 0; s = s[1:] {
			if f.Flag(int(s[0])) {
				write(s[:1])
			}
		}
		write("]")
		if V, ok := f.Width(); ok {
			write(" | 宽度: " + strconv.FormatInt(int64(V),10))
		}
		if V,ok := f.Precision(); ok{
			write(" | 精度: " + strconv.FormatInt(int64(V),10))
		}
	case 'S','V':
		if c == 'V' && f.Flag ('#'){
			write(u.GoString())
		} else {
			write(u.String())
		}
	default:
		write ("无效的格式: " + string(c))
	}
}

func main(){
	u := Ustr("Hello World!")
	fmt.Printf("%-+ 0#8.5m\n",u)
	fmt.Printf("%+  0#8.5M\n",u)
	fmt.Println(u)
	fmt.Printf("%S\n",u)
	fmt.Printf("%#V\n",u)
	fmt.Printf("%d\n",u)
}
