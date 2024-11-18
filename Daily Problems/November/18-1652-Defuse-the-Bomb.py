class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        size = len(code)
        def calc_sum(index, dir) -> int:
            cur_sum = 0
            loop_num = abs(k)
            if dir > 0:
                index += 1
                for i in range(loop_num):
                    cur_sum += code[index % size]
                    index += 1
            elif dir < 0:
                index -= 1
                for i in range(loop_num):
                    cur_sum += code[index % size]
                    index -= 1
            return cur_sum
                


        res = []
        for i in range(len(code)):
            if k < 0:
                res.append(calc_sum(i, -1))
            else:
                res.append(calc_sum(i, 1))
        return res
