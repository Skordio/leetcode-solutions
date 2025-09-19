from .sol import TaskManager

tasks = [[1, 101, 10], [2, 102, 20], [3, 103, 15]]
obj = TaskManager(tasks)
print(None)
print(obj.add(4,104,5))
print(obj.edit(102,8))
print(obj.execTop())
print(obj.rmv(101))
print(obj.add(5, 105, 15))
print(obj.execTop())

print("\n")

tasks = [[1,101,8],[2,102,20],[3,103,5]]
obj = TaskManager(tasks)
print(None)
print(obj.add(4, 104, 5))
print(obj.edit(102, 9))
print(obj.execTop())
print(obj.rmv(101))
print(obj.add(50, 101, 8))
print(obj.execTop())

print("\n")

tasks = [[2,26,15],[6,1,19]]
obj = TaskManager(tasks)
print(None)
print(obj.edit(26, 15))
print(obj.execTop())


print("\n")

tasks = [[10,12,4],[2,15,2],[9,1,23],[5,21,2],[6,19,26],[10,7,47],[4,28,14],[1,10,6],[8,0,15]]
obj = TaskManager(tasks)
print(None)
print(obj.add(6, 3, 0))
print(obj.execTop())
print(obj.add(7, 27, 46))
print(obj.add(6, 20, 46))
print(obj.rmv(21))
print(obj.execTop())