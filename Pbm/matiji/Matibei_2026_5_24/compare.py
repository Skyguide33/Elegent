import sys
import os

def detect_encoding(file_path):
    """尝试检测文件编码"""
    encodings = ['utf-8', 'gbk', 'gb2312', 'iso-8859-1', 'cp936']
    
    for encoding in encodings:
        try:
            with open(file_path, 'r', encoding=encoding) as f:
                f.read(1024)  # 尝试读取一部分
                return encoding
        except UnicodeDecodeError:
            continue
    
    return 'utf-8'  # 默认返回 utf-8

def compare_files(file1_path, file2_path):
    """
    逐行比较两个文本文件，忽略行尾空格。
    发现第一处不同时输出位置信息，否则报告文件相同。
    """
    # 检查文件是否存在
    if not os.path.exists(file1_path):
        print(f"错误：文件 '{file1_path}' 不存在")
        return
    if not os.path.exists(file2_path):
        print(f"错误：文件 '{file2_path}' 不存在")
        return
    
    # 检测编码
    encoding1 = detect_encoding(file1_path)
    encoding2 = detect_encoding(file2_path)
    
    try:
        with open(file1_path, 'r', encoding=encoding1) as f1, \
             open(file2_path, 'r', encoding=encoding2) as f2:

            line_number = 0
            while True:
                line1 = f1.readline()
                line2 = f2.readline()

                # 两个文件同时到达 EOF → 完全相同
                if not line1 and not line2:
                    print("文件相同")
                    return

                # 其中一个文件提前结束 → 不同
                if not line1 or not line2:
                    line_number += 1
                    if not line1:
                        print(f"文件1在第{line_number}行结束，文件2还有更多内容")
                    else:
                        print(f"文件2在第{line_number}行结束，文件1还有更多内容")
                    return

                line_number += 1

                # 忽略行尾空格（仅移除右侧空白）
                s1 = line1.rstrip()
                s2 = line2.rstrip()

                if s1 != s2:
                    # 查找第一个不同字符的位置
                    min_len = min(len(s1), len(s2))
                    column = 0
                    for i in range(min_len):
                        if s1[i] != s2[i]:
                            column = i + 1  # 列号从 1 开始
                            break
                    else:
                        # 前 min_len 个字符相同，但长度不同
                        column = min_len + 1

                    print(f"文件在第{line_number}行第{column}列不同")
                    return

    except Exception as e:
        print(f"处理文件时出错：{e}")
        sys.exit(1)


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("用法：python compare.py <文件1> <文件2>")
        print("示例：python compare.py a.txt b.txt")
        sys.exit(1)

    compare_files(sys.argv[1], sys.argv[2])