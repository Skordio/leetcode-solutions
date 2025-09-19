from typing import List, Dict

# task int order: userId, taskId, priority
class TaskManager:
    tasks: List[List[int]]
    indexForId: Dict[int, int]

    def __init__(self, tasks: List[List[int]]):
        self.tasks = tasks
        self._sort_by_priority()
    
    def _sort_by_priority(self):
        self.tasks.sort(key=lambda x: (x[2], x[1]), reverse=True)
        self._index_all_tasks()

    def _index_all_tasks(self):
        self.indexForId = {}
        for i, task in enumerate(self.tasks):
            self.indexForId[task[1]] = i

    def add(self, userId: int, taskId: int, priority: int) -> None:
        insertIndex = len(self.tasks)
        if len(self.tasks):
            for i, task in enumerate(self.tasks):
                if task[2] > priority or (task[2] >= priority and task[1] > taskId):
                    continue
                insertIndex = i
                break
            for i in range(insertIndex, len(self.tasks)):
                self.indexForId[self.tasks[i][1]] += 1
        else:
            insertIndex = 0
        self.tasks.insert(insertIndex, [userId, taskId, priority])
        self.indexForId[taskId] = insertIndex


    def edit(self, taskId: int, newPriority: int) -> None:
        task = self.tasks[self.indexForId[taskId]]
        edited = [task[0], task[1], newPriority]
        self.rmv(taskId)
        self.add(*edited)

    def rmv(self, taskId: int) -> None:
        index = self.indexForId[taskId]
        self.tasks.pop(index)
        if len(self.tasks):
            for i in range(index, len(self.tasks)):
                self.indexForId[self.tasks[i][1]] -= 1
        else:
            self.indexForId = {}

    def execTop(self) -> int:
        try:
            task = self.tasks[0]
        except:
            return -1
        self.rmv(task[1])
        return task[0]
        

# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()