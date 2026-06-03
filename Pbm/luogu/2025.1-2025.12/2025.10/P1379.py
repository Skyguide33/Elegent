# 2025/10/7 重构
from collections import deque
from time import time
from random import randint
from heapq import heappush, heappop
from math import hypot

# 此类为工具类
class Tool:
    pow_10 = (1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000)  # 预处理10的乘方
    direction = ((-1, 0), (0, 1), (1, 0), (0, -1)) # 预处理移动方向
    
    # 获取空白格子的位置
    @staticmethod
    def blank_pos(state: int) -> tuple:
        temp = state
        for idx in range(8, -1, -1):
            if temp%10 == 0:
                return (idx//3, idx%3)
            temp //= 10          
    
    # 生成一个状态的所有相邻状态
    @staticmethod
    def generate_near_states(state: int, x: int, y: int) -> list:
        direction = Tool.direction
        pow = Tool.pow_10
        pos_rev = 8-3*x-y
        next_states = []
        for idx in range(4):
            nx, ny = x+direction[idx][0], y+direction[idx][1] 
            if(0 <= nx < 3 and 0 <= ny < 3): 
                n_pos_rev = 8-3*nx-ny
                new_num = state//pow[n_pos_rev]%10
                next_state = state-new_num*(pow[n_pos_rev]-pow[pos_rev])
                next_states.append((next_state, idx, nx, ny)) 
                 
        return next_states  

    # 随机生成状态
    @staticmethod
    def generate_state() -> int:
        hash = [0]*9
        state = 0
        for _ in range(9):
            rnum = randint(0, 8)
            while hash[rnum]:
                rnum = randint(0, 8)
            hash[rnum] = 1
            state = state*10+rnum
        return state      
    
    @staticmethod
    def inverse_number(nums: list):
        res = 0
        leng = len(nums)
        for i in range(leng):
            if nums[i]:
                for j in range(i+1, leng):
                    if nums[j] and nums[i] > nums[j]: res += 1
        return res
        
    @staticmethod
    def exist_solution(init_state, goal_state) -> bool:
        inverse_number = Tool.inverse_number
        init_state_list = [int(num) for num in str(init_state)]
        goal_state_list = [int(num) for num in str(goal_state)]
        if (inverse_number(init_state_list)-inverse_number(goal_state_list)) % 2:
            return False
        return True
    
    # 生成测试样例, 可设定样例个数和是否排除无解样例
    @staticmethod
    def get_test_case(round=500, check=True) -> tuple:
        generate_state = Tool.generate_state
        exist_solution = Tool.exist_solution
        cnt = 0
        test_case = [True if check != False else False]
        while cnt < round:
            init_state = generate_state()
            goal_state = generate_state()
            if check != False and not exist_solution(init_state, goal_state): 
                continue
            test_case.append((init_state, goal_state))
            cnt += 1
        return tuple(test_case)
    
    
# 返回结果列表格式: method 0, param 1, success 2, direction 3, path 4, pathlen 5, nodes_expanded 6, max_queue_size 7, time 8
# IDDFS二分返回结果格式: success 0, direction 1, path 2, nodes_expanded 3, max_queue_size 4

# IDDFS求解器
class IDDFS:
    method = "iddfs"
    # max_depth: 最大路径长度   
    @staticmethod
    def dfs_solve(init_state: int, goal_state: int, max_depth: int) -> dict:
        generate_near_states = Tool.generate_near_states
        
        # 初始化队列和已访问节点集合, 队列格式: 状态, x, y, 当前路径长度
        queue = deque()
        x, y = Tool.blank_pos(init_state)
        queue.append((init_state, x, y, 0))
        visited = {init_state: 0}
        
        # 记录各节点的父节点和移至该节点的移动方向
        pre_states = {init_state: None}
        directions = {init_state: None}
        
        # 初始化访问节点次数和队列最大长度
        nodes_expanded = 0
        max_queue_size = 1
        
        while queue:
            current_state, x, y, depth = queue.popleft() 
            nodes_expanded += 1
            
            # 访问到目标状态时返回
            if current_state == goal_state:
                path = []; moves = []
                while current_state:
                    path.append(current_state)
                    moves.append(directions[current_state])
                    current_state = pre_states[current_state]
                path.pop()
                path.reverse()
                moves.pop()
                moves.reverse()
                
                return [True, moves, path, nodes_expanded, max_queue_size]
            
            # 若当前路径长度超过最大路径长度则跳过
            if depth < max_depth:
                depth += 1
                for next_state, direction, nx, ny in generate_near_states(current_state, x, y)[::-1]:
                    if next_state not in visited or depth < visited[next_state]:
                        visited[next_state] = depth
                        queue.appendleft((next_state, nx, ny, depth))
                        pre_states[next_state] = current_state
                        directions[next_state] = direction
                max_queue_size = max(max_queue_size, len(queue))
        
        return [False, None, None, nodes_expanded, max_queue_size]
        
    @staticmethod
    def solve(init_state: int, goal_state: int, param) -> dict:
        start_time = time()
        param = None
        check = IDDFS.dfs_solve
        result = [IDDFS.method, param, False, None, None, None, 0, 0, 0]
        
        # 二分查找最短路径 r = 31+1
        l = 0; r = 32
        while l < r:
            mid = (l+r)>>1
            temp = check(init_state, goal_state, mid)
            
            # 每次查找后统计访问节点次数，更新结果
            result[6] += temp[3]
            result[7] = max(result[7], temp[4])
            if temp[0]:
                result[2:5] = temp[0:3]
                r = mid
            else: l = mid+1
        if result[2]: result[5] = len(result[4])
        end_time = time()
        result[8] = end_time-start_time
        return result
        
# BFS求解器
class BFS:
    method = "bfs"
    @staticmethod
    def solve(init_state: int, goal_state: int, param) -> dict:
        start_time = time()
        param = None
        generate_near_states = Tool.generate_near_states
        
        # 初始化队列和已访问节点集合, 队列格式: 状态, x, y
        queue = deque()
        x, y = Tool.blank_pos(init_state)
        queue.append((init_state, x, y))
        visited = {init_state}
        
        # 记录各节点的父节点和移至该节点的移动方向
        pre_states = {init_state: None}
        directions = {init_state: None}
        
        # 初始化访问节点次数和队列最大长度
        nodes_expanded = 0
        max_queue_size = 1
        
        while queue:
            current_state, x, y = queue.popleft()
            nodes_expanded += 1
            
            # 最早抵达目标状态的路径一定属于最短路径, 直接返回
            if current_state == goal_state:
                path = []; moves = []
                while current_state:
                    path.append(current_state)
                    moves.append(directions[current_state])
                    current_state = pre_states[current_state]
                path.pop()
                path.reverse()
                moves.pop()
                moves.reverse()
                
                end_time = time()
                return [BFS.method, param, True, moves, path, len(path), nodes_expanded, max_queue_size, end_time-start_time]
                
            for next_state, direction, nx, ny in generate_near_states(current_state, x, y):
                if next_state not in visited:
                    visited.add(next_state)
                    queue.append((next_state, nx, ny))
                    pre_states[next_state] = current_state
                    directions[next_state] = direction
            
            max_queue_size = max(max_queue_size, len(queue))
        
        end_time = time()
        return [BFS.method, param, False, None, None, None, nodes_expanded, max_queue_size, end_time-start_time]
        
# 自定义优先队列类
class PriorityQueue:
    def __init__(self):
        self._queue = []
    
    def push(self, priority: int, item):
        heappush(self._queue, (priority, item))
        
    def pop(self):
        return heappop(self._queue)[-1]
    
    def size(self) -> int:
        return len(self._queue)
          
# A*求解器
class Astar:
    method = "astar"
    
    # 以下三者均为启发函数
    @staticmethod
    def score_l0(current_state: tuple, goal_state: int) -> int:
        temp_c, temp_g = current_state[0], goal_state
        diff_cnt = 0
        for _ in range(9):
            if (temp_c-temp_g)%10:
                diff_cnt += 1
            temp_c //= 10; temp_g //= 10
        return current_state[1]+diff_cnt
    
    @staticmethod
    def score_l1(current_state: tuple, goal_state: int) -> int:
        temp_c, temp_g = current_state[0], goal_state
        hash_c = [0]*9; hash_g = [0]*9
        diff_dist = 0
        for i in range(8, -1, -1):
            hash_c[temp_c%10] = hash_g[temp_g%10] = (i//3, i%3)
            temp_c //= 10; temp_g //= 10
        for i in range(9):
            diff_dist += abs(hash_c[i][0]-hash_g[i][0])+abs(hash_c[i][1]-hash_g[i][1])
        return current_state[1]+diff_dist

    @staticmethod
    def score_l2(current_state: tuple, goal_state: int) -> float:
        temp_c, temp_g = current_state[0], goal_state
        hash_c = [0]*9; hash_g = [0]*9
        diff_dist = 0
        for i in range(8, -1, -1):
            hash_c[temp_c%10] = hash_g[temp_g%10] = (i//3, i%3)
            temp_c //= 10; temp_g //= 10
        for i in range(9):
            diff_dist += hypot((hash_c[i][0]-hash_g[i][0]), (hash_c[i][1]-hash_g[i][1]))
        return current_state[1]+diff_dist
    
    @staticmethod
    def solve(init_state: int, goal_state: int, param) -> dict:
        start_time = time()
        
        # 选择启发函数
        if param == "l0": score = Astar.score_l0
        elif param == "l2": score = Astar.score_l2
        else: param = "l1"; score = Astar.score_l1
            
        generate_near_states = Tool.generate_near_states
        
        # 初始化优先队列队列和已访问节点集合, 队列格式: 优先级(预估路径长度), (当前状态, 当前路径长度), x, y
        queue = PriorityQueue()
        x, y = Tool.blank_pos(init_state)
        queue.push(score((init_state, 0), goal_state), ((init_state, 0), x, y))
        visited = {init_state: 0}
        
        # 记录各节点的父节点和移至该节点的移动方向
        pre_states = {init_state: None}
        directions = {init_state: None}
        
        # 初始化访问节点次数和队列最大长度
        nodes_expanded = 0
        max_queue_size = 1
        
        while queue.size():
            [current_state, depth], x, y = queue.pop()
            nodes_expanded += 1
            
            # 访问到目标状态时返回
            if current_state == goal_state:
                path = []; moves = []
                while current_state:
                    path.append(current_state)
                    moves.append(directions[current_state])
                    current_state = pre_states[current_state]
                path.pop()
                path.reverse()
                moves.pop()
                moves.reverse()
                
                end_time = time()
                return [Astar.method, param, True, moves, path, len(path), nodes_expanded, max_queue_size, end_time-start_time]
                
            for next_state, direction, nx, ny in generate_near_states(current_state, x, y):
                if next_state not in visited or depth < visited[next_state]:
                    visited[next_state] = depth+1
                    pre_states[next_state] = current_state
                    directions[next_state] = direction
                    next_state = (next_state, depth+1)
                    queue.push(score(next_state, goal_state), (next_state, nx, ny))
            
            max_queue_size = max(max_queue_size, queue.size())
        
        end_time = time()
        return [Astar.method, param, False, None, None, None, nodes_expanded, max_queue_size, end_time-start_time]

# 求解器调用类
class EightPuzzle:
    
    def __init__(self, solver="astar"):
        if solver == "iddfs": self.kernal = IDDFS()
        elif solver == "bfs": self.kernal = BFS()
        else: self.kernal = Astar()
            
    def solve(self, init_state_code, goal_state_code, param=None, check=True):
        if check != False:
            if Tool.exist_solution(init_state_code, goal_state_code):
                self.values = self.kernal.solve(int(init_state_code), int(goal_state_code), param)
            else: self.values = [None, None, False, None, None, None, 0, 0, 0]
        else: self.values = self.kernal.solve(int(init_state_code), int(goal_state_code), param)
        return self.values

    def result(self):
        keys = ["solver", "param", "success", "direction", "path", "path_len", "nodes_expanded", "max_queue_size", "time"]
        return dict(zip(keys, self.values))
        
        
if __name__ == "__main__":
    src = input()
    solver = EightPuzzle(solver="bfs")
    print(solver.solve(init_state_code=src, goal_state_code="123804765", param="l0")[5])
        
        

    
    