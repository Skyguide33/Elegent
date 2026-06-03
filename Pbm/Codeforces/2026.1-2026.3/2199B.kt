import kotlin.math.max
import kotlin.math.min

fun solve() {
    // 读取四个整数，与C++的 `cin >> a >> b >> c >> d` 对应
    val (a, b, c, d) = readln().split(" ").map { it.toInt() }
    // 计算公式: c + d - a - b - max(0, min(c, d) - max(a, b))
    val result = c + d - a - b - max(0, min(c, d) - max(a, b))
    println(result)
}

fun main() {
    // 读取整数T，对应C++的 `int T; cin >> T;`
    var T = readln().toInt()
    // 循环T次执行solve函数
    while (T-- > 0) {
        solve()
    }
}