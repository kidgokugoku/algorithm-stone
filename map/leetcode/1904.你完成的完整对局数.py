#
# @lc app=leetcode.cn id=1904 lang=python3
#
# [1904] 你完成的完整对局数
#
# https://leetcode.cn/problems/the-number-of-full-rounds-you-have-played/description/
#
# algorithms
# Medium (30.35%)
# Likes:    16
# Dislikes: 0
# Total Accepted:    4.9K
# Total Submissions: 16.2K
# Testcase Example:  '"09:31"\n"10:14"'
#
# 一款新的在线电子游戏在近期发布，在该电子游戏中，以 刻钟 为周期规划若干时长为 15 分钟 的游戏对局。这意味着，在 HH:00、HH:15、HH:30
# 和 HH:45 ，将会开始一个新的对局，其中 HH 用一个从 00 到 23 的整数表示。游戏中使用 24 小时制的时钟 ，所以一天中最早的时间是
# 00:00 ，最晚的时间是 23:59 。
#
# 给你两个字符串 startTime 和 finishTime ，均符合 "HH:MM" 格式，分别表示你 进入 和 退出
# 游戏的确切时间，请计算在整个游戏会话期间，你完成的 完整对局的对局数 。
#
#
# 例如，如果 startTime = "05:20" 且 finishTime = "05:59" ，这意味着你仅仅完成从 05:30 到 05:45
# 这一个完整对局。而你没有完成从 05:15 到 05:30 的完整对局，因为你是在对局开始后进入的游戏；同时，你也没有完成从 05:45 到 06:00
# 的完整对局，因为你是在对局结束前退出的游戏。
#
#
# 如果 finishTime 早于 startTime ，这表示你玩了个通宵（也就是从 startTime 到午夜，再从午夜到 finishTime）。
#
# 假设你是从 startTime 进入游戏，并在 finishTime 退出游戏，请计算并返回你完成的 完整对局的对局数 。
#
#
#
# 示例 1：
#
#
# 输入：startTime = "12:01", finishTime = "12:44"
# 输出：1
# 解释：你完成了从 12:15 到 12:30 的一个完整对局。
# 你没有完成从 12:00 到 12:15 的完整对局，因为你是在对局开始后的 12:01 进入的游戏。
# 你没有完成从 12:30 到 12:45 的完整对局，因为你是在对局结束前的 12:44 退出的游戏。
#
#
# 示例 2：
#
#
# 输入：startTime = "20:00", finishTime = "06:00"
# 输出：40
# 解释：你完成了从 20:00 到 00:00 的 16 个完整的对局，以及从 00:00 到 06:00 的 24 个完整的对局。
# 16 + 24 = 40
#
#
# 示例 3：
#
#
# 输入：startTime = "00:00", finishTime = "23:59"
# 输出：95
# 解释：除最后一个小时你只完成了 3 个完整对局外，其余每个小时均完成了 4 场完整对局。
#
#
#
#
# 提示：
#
#
# startTime 和 finishTime 的格式为 HH:MM
# 00
# 00
# startTime 和 finishTime 不相等
#
#
#

# @lc code=start
class Solution:
    def numberOfRounds(self, loginTime: str, logoutTime: str) -> int:
        res = 0
        login = list(map(int, loginTime.split(':')))
        logout = list(map(int, logoutTime.split(':')))
        if login[0] > logout[0] or (login[0] == logout[0] and login[1] > logout[1]):
            logout[0] += 24
        if not login[1] % 15 == 0:
            login[1] += 15-login[1] % 15
        if not logout[1] % 15 == 0:
            logout[1] -= logout[1] % 15
        login[1] += login[0]*60
        logout[1] += logout[0]*60
        print(f"{login},{logout}")
        if logout[1] >= login[1]:
            res += logout[1]//15 - login[1]//15
        else:
            res += logout[1]//15 - login[1]//15
        return res if res > 0 else 0


# @lc code=end
print(Solution.numberOfRounds(Solution, "12:01", "12:44"))  # 1
print(Solution.numberOfRounds(Solution, "09:31", "10:14"))  # 1
print(Solution.numberOfRounds(Solution, "00:47", "00:57"))  # 0
print(Solution.numberOfRounds(Solution, "21:30", "03:00"))  # 22
