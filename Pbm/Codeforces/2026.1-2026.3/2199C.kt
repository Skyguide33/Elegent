import java.io.PrintWriter
import java.util.StringTokenizer

fun solve(out: PrintWriter) {
    val k = readLine()!!.toInt()

    if (k == 1) {
        out.println("YES")
        out.println(1)
        out.println("*")
        out.println(".")
        return
    }

    val s1Builder = StringBuilder()
    var remainingK = k
    var flag = false

    // Condition 1: Check if (k-3) or (k-6) is divisible by 5
    if ((remainingK - 3) % 5 == 0 || (remainingK - 6) % 5 == 0) {
        remainingK -= 3
        s1Builder.append("*.")
        flag = true
    }

    // Condition 2: Check if k or (k-3) is divisible by 5
    if (remainingK % 5 == 0 || (remainingK - 3) % 5 == 0) {
        val num = remainingK / 5
        remainingK -= num * 5
        repeat(num) {
            s1Builder.append(".*.")
        }
        flag = true
    }

    // Final addition
    if (remainingK == 3) {
        s1Builder.append(".*")
    }

    val s1 = s1Builder.toString()

    if (flag) {
        out.println("YES")
        out.println(s1.length)
        out.println(s1)
        repeat(s1.length) {
            out.print('.')
        }
        out.println()
    } else {
        out.println("NO")
    }
}

fun main() {
    val out = PrintWriter(System.out.bufferedWriter(), false)
    val T = readLine()!!.toInt()
    repeat(T) {
        solve(out)
    }
    out.flush()
}