package main
import(
	"log"
	"os"
	_"match/matchers"
	"match/search"
)

func init(){
	log.SetOutput(os.Stdout)
}
//哈哈啊哈
func main(){
	search.Run("president")
}
